---
layout: post
title: "An Introductory Cache Problem"
description: "first semester computer architecture"
category: teaching
tags: [lecture, class, cache, memory]
---
{% include JB/setup %}

I recently gave a problem on the final in [E85](http://pages.hmc.edu/jspjut/class/s2015/e85/).
The students didn't do too well on it overall, so I wanted to post the problem and solution in an effort to 
make more resources available for people learning basic cache behaviors. 
First of all, I need to introduce the piece of ARM assembly being used since
it is the basis for a number of questions.

```
		FUNC:
0x0044	SUBS R0, R0, #3
0x0048	BLT DONE
0x004C	STR LR, [SP, #-4]!
0x0050	BL FUNC
0x0054	ADD R0, R0, #1
0x0058	LDR LR, [SP], #4
0x005C	MOV PC, LR
		DONE:
0x0060	MOV R0, #0
0x0064	MOV PC, LR
```

## Program analysis
The first question is the following: Translate `FUNC` to C code. My C version is:

```c
int func(int x)
{
	if (x < 3)
		return 0;
	else
		return func(x-3) + 1;
}
```

This is a simple recursive function that computes the integer value of dividing the input number by 3.

The next part asked for a stack trace including register values for `func(12)`. 
The `SP` starts at `0xFFE0` and the function is first called from a `BL` at `0x0020`.

### `func(12)`

```
R0 = 12
SP = 0xFFE0
LR = 0x0024
```

| Address | Data | SP |
| ---- | ---- | ---- |
| `0xFFE0` | `?` | start/end |
| `0xFFDC` | `0x0024` | `func(9)` |
| `0xFFD0` | `?` | |
| `0xFFD0` | `?` | |
| `0xFFD0` | `?` | |

### `func(9)`

```
R0 = 9
SP = 0xFFDC
LR = 0x0054
```

| Address | Data | SP |
| ---- | ---- | ---- |
| `0xFFE0` | `?` | |
| `0xFFDC` | `0x0024` | start/end |
| `0xFFD8` | `0x0054` | `func(6)` |
| `0xFFD4` | `?` | |
| `0xFFD0` | `?` | |


### `func(6)`

```
R0 = 9
SP = 0xFFDC
LR = 0x0054
```

| Address | Data | SP |
| ---- | ---- | ---- |
| `0xFFE0` | `?` | |
| `0xFFDC` | `0x0024` | |
| `0xFFD8` | `0x0054` | start/end |
| `0xFFD4` | `0x0054` | `func(3)` |
| `0xFFD0` | `?` | |


### `func(3)`

```
R0 = 9
SP = 0xFFDC
LR = 0x0054
```

| Address | Data | SP |
| ---- | ---- | ---- |
| `0xFFE0` | `?` | |
| `0xFFDC` | `0x0024` | |
| `0xFFD8` | `0x0054` | |
| `0xFFD4` | `0x0054` | start/end |
| `0xFFD0` | `0x0054` | `func(0)` |


### `func(0)`

```
R0 = 9
SP = 0xFFDC
LR = 0x0054
```

| Address | Data | SP |
| ---- | ---- | ---- |
| `0xFFE0` | `?` | |
| `0xFFDC` | `0x0024` | |
| `0xFFD8` | `0x0054` | |
| `0xFFD4` | `0x0054` | |
| `0xFFD0` | `0x0054` | start/end |

### Return and move up stack

`R0 < 0` so `func(0)` returns `0` in `R0`.

`func(3)` returns `R0 + 1` in `R0` which is now `1`.

`func(6)` returns `R0 + 1` in `R0` which is now `2`.

`func(9)` returns `R0 + 1` in `R0` which is now `3`.

`func(12)` returns `R0 + 1` in `R0` which is now `4`.

The return value is therefore `4`.

## Data cache
The next question asks for the miss rate in the **data** cache for the same program.
The first step in solving this question is to write down the data access pattern for the program.
The only data memory accessed is in the stack operations, which were written above, but I'll repeat just the loads and stores here with the addresses computed.

```
STR LR 0xFFDC
STR LR 0xFFD8
STR LR 0xFFD4
STR LR 0xFFD0
LDR LR 0xFFD0
LDR LR 0xFFD4
LDR LR 0xFFD8
LDR LR 0xFFDC
```

For the rest of this part, I will refer to each of these memory accesses only by its memory address since loads and stores are treated the same in the memory system.
The data cache configuration for the first question is given as a 16B cache with 8B blocks that is direct mapped. 
This means that there are 2 sets, each of which has 1 block that stores 2 memory addresses.
These 2 addresses will be adjacent words in memory.
The initial state of the cache would likely store two data values that are irrelevant to the program, so I'll model that as both blocks being invalid at the start resulting in compulsory (or cold) misses. Here is the initial cache state:

| Set | Valid | Addresses stored |
| --- | --- | --- |
| 1 | 0 | `????` |
| 0 | 0 | `????` | 

As the program executes, the following behavior will occur:

| Address | Set | Hit/Miss | Cache State                             |
| ------- | :-: | -------- | :-------------------------------------: |
| Start   |     |          |  `??????` `??????`   `??????` `??????`  |
| `0xFFDC`| 1   | miss     |  `??????` `??????` **`0xFFD8` `0xFFDF`**|
| `0xFFD8`| 1   | hit      |  `??????` `??????`   `0xFFD8` `0xFFDF`  |
| `0xFFD4`| 0   | miss     |**`0xFFD0` `0xFFD4`** `0xFFD8` `0xFFDF`  |
| `0xFFD0`| 0   | hit      |  `0xFFD0` `0xFFD4`   `0xFFD8` `0xFFDF`  |
| `0xFFD0`| 0   | hit      |  `0xFFD0` `0xFFD4`   `0xFFD8` `0xFFDF`  |
| `0xFFD4`| 0   | hit      |  `0xFFD0` `0xFFD4`   `0xFFD8` `0xFFDF`  |
| `0xFFD8`| 1   | hit      |  `0xFFD0` `0xFFD4`   `0xFFD8` `0xFFDF`  |
| `0xFFDC`| 1   | hit      |  `0xFFD0` `0xFFD4`   `0xFFD8` `0xFFDF`  |

If we count up the misses and look at the total number of accesses we see that we have **8** accesses and **2** misses giving us a miss rate of 2/8 = 25%.

The next part asks about what happens when the same **data** cache is reorganized to be fully associative instead of direct mapped. 
This means that either block could be placed in either way within a single set.
The result will be the same because we only ever access 2 different blocks of memory, but to show the full trace, I've included the work below.
Note that the way on the left is the least recently used and will be replaced next.

| Address | Set | Hit/Miss | Cache State                             |
| ------- | :-: | -------- | :-------------------------------------: |
| Start   |     |          |  `??????` `??????`   `??????` `??????`  |
| `0xFFDC`| 0   | miss     |  `??????` `??????` **`0xFFD8` `0xFFDF`**|
| `0xFFD8`| 0   | hit      |  `??????` `??????`   `0xFFD8` `0xFFDF`  |
| `0xFFD4`| 0   | miss     |  `0xFFD8` `0xFFDF` **`0xFFD0` `0xFFD4`**|
| `0xFFD0`| 0   | hit      |  `0xFFD8` `0xFFDF`   `0xFFD0` `0xFFD4`  |
| `0xFFD0`| 0   | hit      |  `0xFFD8` `0xFFDF`   `0xFFD0` `0xFFD4`  |
| `0xFFD4`| 0   | hit      |  `0xFFD8` `0xFFDF`   `0xFFD0` `0xFFD4`  |
| `0xFFD8`| 0   | hit      |  `0xFFD0` `0xFFD4`   `0xFFD8` `0xFFDF`  |
| `0xFFDC`| 0   | hit      |  `0xFFD0` `0xFFD4`   `0xFFD8` `0xFFDF`  |

Again, there are **8** accesses and **2** misses for a miss rate of 2/8 = 25%.

## Instruction Cache
The next question deals with an instruction cache. This means we need to know what the cache access pattern is. 
From the first part, we know that the function is called a total of 5 times, the first 4 with the same behavior and the 5th time with the return 0 case.
This access pattern is as follows:

```
0x0044 // func(12)
0x0048
0x004C
0x0050
0x0044 // func(9)
0x0048
0x004C
0x0050
0x0044 // func(6)
0x0048
0x004C
0x0050
0x0044 // func(3)
0x0048
0x004C
0x0050
0x0044 // func(0) 
0x0048
0x0060
0x0064 // return 0
0x0054 // func(3)
0x0058
0x005C // return 1
0x0054 // func(6)
0x0058
0x005C // return 2
0x0054 // func(9)
0x0058
0x005C // return 3
0x0054 // func(12)
0x0058
0x005C // return 4
```

In order to make this response more compact than the previous problem, I'm going to exploit the fact that there is a repeated access pattern here.
The sequence `0x0044`, `0x0048`, `0x004C`, `0x0050` repeats 4 times followed by the sequence `0x0044`, `0x0048`, `0x0060`, `0x0064`. 
After those finish, the sequence `0x0054`, `0x0058`, `0x005C` repeats 4 times. 
The total number of memory accesses is therefore `4 x 4 + 4 + 3 x 4 = 32`.

For each repeated pattern, the access is has compulsory misses the first time, but on subsequent loops repeats the accesses. 
We are first given a 16B cache with 8B blocks that is direct mapped.
Here is the hit miss pattern based on what the contents of the cache are through the trace:

### 8B blocks
Filled blocks in bold

| Address  | 1st time | In Cache (1st time)                     | 2-4  | In Cache (2-4 times)                    | Accesses | Hits | Misses |
| -------- | -------- | :-------------------------------------: | ---- | :-------------------------------------: | :------: | :--: | :----: |
| start    |          |  `??????` `??????`   `??????` `??????`  |      |  `??????` `??????`   `??????` `??????`  |          |      |        |
| `0x0044` | miss     |**`0x0040` `0x0044`** `??????` `??????`  | miss |**`0x0040` `0x0044`** `0x0048` `0x004C`  | 4        | 0    | 4      |
| `0x0048` | miss     |  `0x0040` `0x0044` **`0x0048` `0x004C`**| hit  |  `0x0040` `0x0044`   `0x0048` `0x004C`  | 4        | 3    | 1      |
| `0x004C` | hit      |  `0x0040` `0x0044`   `0x0048` `0x004C`  | hit  |  `0x0040` `0x0044`   `0x0048` `0x004C`  | 4        | 4    | 0      |
| `0x0050` | miss     |**`0x0050` `0x0054`** `0x0048` `0x004C`  | miss |**`0x0050` `0x0054`** `0x0048` `0x004C`  | 4        | 0    | 4      |
| `0x0044` | miss     |**`0x0040` `0x0044`** `0x0048` `0x004C`  | n/a  | n/a                                     | 1        | 0    | 1      |
| `0x0048` | hit      |  `0x0040` `0x0044`   `0x0048` `0x004C`  | n/a  | n/a                                     | 1        | 1    | 0      |
| `0x0060` | miss     |**`0x0060` `0x0064`** `0x0048` `0x004C`  | n/a  | n/a                                     | 1        | 0    | 1      |
| `0x0064` | hit      |  `0x0060` `0x0064`   `0x0048` `0x004C`  | n/a  | n/a                                     | 1        | 1    | 0      |
| `0x0054` | miss     |**`0x0050` `0x0054`** `0x0048` `0x004C`  | hit  |  `0x0050` `0x0054`   `0x0058` `0x005C`  | 4        | 3    | 1      |
| `0x0058` | miss     |  `0x0050` `0x0054` **`0x0058` `0x005C`**| hit  |  `0x0050` `0x0054`   `0x0058` `0x005C`  | 4        | 3    | 1      |
| `0x005C` | hit      |  `0x0050` `0x0054`   `0x0058` `0x005C`  | hit  |  `0x0050` `0x0054`   `0x0058` `0x005C`  | 4        | 4    | 0      |
| Sum      |          |                                         |      |                                         | 32       | 19   | 13     |

The hit rate for this cache configuration and instruction trace is 19/32 which is about **59.38%**.

The final question asks what change to the block size will improve the hit rate the most. 
Since the cache is 16B and each instruction is 4B, the only block sizes that make sense are 4B, 8B, and 16B which correspond to 4 sets, 2 sets, and 1 set respectively.
The access patterns for each are as follows:

### 4B blocks

| Address  | 1st time | In Cache (1st time)                         | 2-4  | In Cache (2-4 times)                | Accesses | Hits | Misses |
| -------- | -------- | :-----------------------------------------: | ---- | :---------------------------------: | :------: | :--: | :----: |
| start    |          |  `??????`   `??????`   `??????`   `??????`  |      | `??????` `??????` `??????` `??????` |          |      |        |
| `0x0044` | miss     |  `??????` **`0x0044`** `??????`   `??????`  | hit  | `0x0050` `0x0044` `0x0048` `0x004C` | 4        | 3    | 1      |
| `0x0048` | miss     |  `??????`   `0x0044` **`0x0048`** `??????`  | hit  | `0x0050` `0x0044` `0x0048` `0x004C` | 4        | 3    | 1      |
| `0x004C` | miss     |  `??????`   `0x0044`   `0x0048` **`0x004C`**| hit  | `0x0050` `0x0044` `0x0048` `0x004C` | 4        | 3    | 1      |
| `0x0050` | miss     |**`0x0050`** `0x0044`   `0x0048`   `0x004C`  | hit  | `0x0050` `0x0044` `0x0048` `0x004C` | 4        | 3    | 1      |
| `0x0044` | hit      |  `0x0050`   `0x0044`   `0x0048`   `0x004C`  | n/a  | n/a                                 | 1        | 1    | 0      |
| `0x0048` | hit      |  `0x0050`   `0x0044`   `0x0048`   `0x004C`  | n/a  | n/a                                 | 1        | 1    | 0      |
| `0x0060` | miss     |**`0x0060`** `0x0044`   `0x0048`   `0x004C`  | n/a  | n/a                                 | 1        | 0    | 1      |
| `0x0064` | miss     |  `0x0060` **`0x0064`** `0x0048`   `0x004C`  | n/a  | n/a                                 | 1        | 0    | 1      |
| `0x0054` | miss     |  `0x0060` **`0x0054`** `0x0048`   `0x004C`  | hit  | `0x0060` `0x0054` `0x0058` `0x005C` | 4        | 3    | 1      |
| `0x0058` | miss     |  `0x0060`   `0x0054` **`0x0058`** `0x004C`  | hit  | `0x0060` `0x0054` `0x0058` `0x005C` | 4        | 3    | 1      |
| `0x005C` | miss     |  `0x0060`   `0x0054`   `0x0058` **`0x005C`**| hit  | `0x0060` `0x0054` `0x0058` `0x005C` | 4        | 3    | 1      |
| Sum      |          |                                             |      |                                     | 32       | 23   | 9      |

hit rate = 23/32 = **71.88%**

### 16B block

| Address  | 1st time | In Cache (1st time)                   | 2-4  | In Cache (2-4 times)                  | Accesses | Hits | Misses |
| -------- | -------- | :-----------------------------------: | ---- | :-----------------------------------: | :------: | :--: | :----: |
| start    |          |  `??????` `??????` `??????` `??????`  |      |  `??????` `??????` `??????` `??????`  |          |      |        |
| `0x0044` | miss     |**`0x0040` `0x0044` `0x0048` `0x004C`**| miss |**`0x0040` `0x0044` `0x0048` `0x004C`**| 4        | 0    | 4      |
| `0x0048` | hit      |  `0x0040` `0x0044` `0x0048` `0x004C`  | hit  |  `0x0040` `0x0044` `0x0048` `0x004C`  | 4        | 4    | 0      |
| `0x004C` | hit      |  `0x0040` `0x0044` `0x0048` `0x004C`  | hit  |  `0x0040` `0x0044` `0x0048` `0x004C`  | 4        | 4    | 0      |
| `0x0050` | miss     |**`0x0050` `0x0054` `0x0058` `0x005C`**| miss |**`0x0050` `0x0054` `0x0058` `0x005C`**| 4        | 0    | 4      |
| `0x0044` | miss     |**`0x0040` `0x0044` `0x0048` `0x004C`**| n/a  | n/a                                   | 1        | 0    | 1      |
| `0x0048` | hit      |  `0x0040` `0x0044` `0x0048` `0x004C`  | n/a  | n/a                                   | 1        | 1    | 0      |
| `0x0060` | miss     |**`0x0060` `0x0064` `0x0068` `0x006C`**| n/a  | n/a                                   | 1        | 0    | 1      |
| `0x0064` | hit      |  `0x0060` `0x0064` `0x0068` `0x006C`  | n/a  | n/a                                   | 1        | 1    | 0      |
| `0x0054` | miss     |**`0x0050` `0x0054` `0x0058` `0x005C`**| hit  |  `0x0050` `0x0054` `0x0058` `0x005C`  | 4        | 3    | 1      |
| `0x0058` | hit      |  `0x0050` `0x0054` `0x0058` `0x005C`  | hit  |  `0x0050` `0x0054` `0x0058` `0x005C`  | 4        | 4    | 0      |
| `0x005C` | hit      |  `0x0050` `0x0054` `0x0058` `0x005C`  | hit  |  `0x0050` `0x0054` `0x0058` `0x005C`  | 4        | 4    | 0      |
| Sum      |          |                                       |      |                                       | 32       | 21   | 11     |

hit rate = 21/32 = **65.63%**

Since the 4B access pattern results in a higher hit rate, reducing the block size for 8B to 4B would increase the hit rate the most. 
This is an interesting example because both 16B and 4B block sizes resulted in a higher hit rate than the 8B block size for this particular example.
The 16B trace does better because it reduces the number of compulsory misses, but it still suffers from the conflicts in the first loop.
The 8B trace does best because, while there are more compulsory misses, it reduces conflicts in each of these loops with 4 or less instructions in it and exploits temporal locality in the instruction access pattern.
This does not indicate that a 4B block size is better in all circumstances, but it is true in this case.

In today's production caches, there are many more blocks in the cache, and they are also typically associative reducing the number of conflict misses. 
As a point of comparison, this is the access pattern for a 8B block size with a fully associative cache and LRU replacement policy.

### 8B block, 2-way associative
I didn't include the cache state here because it wasn't a part of the problem and I wanted to save a little time writing this.

| Address  | 1st time | 2-4  | Accesses | Hits | Misses |
| -------- | -------- | ---- | :------: | :--: | :----: |
| `0x0044` | miss     | miss | 4        | 0    | 4      |
| `0x0048` | miss     | miss | 4        | 0    | 4      |
| `0x004C` | hit      | hit  | 4        | 4    | 0      |
| `0x0050` | miss     | miss | 4        | 0    | 4      |
| `0x0044` | miss     | n/a  | 1        | 0    | 1      |
| `0x0048` | miss     | n/a  | 1        | 0    | 1      |
| `0x0060` | miss     | n/a  | 1        | 0    | 1      |
| `0x0064` | hit      | n/a  | 1        | 1    | 0      |
| `0x0054` | miss     | hit  | 4        | 3    | 1      |
| `0x0058` | miss     | hit  | 4        | 3    | 1      |
| `0x005C` | hit      | hit  | 4        | 4    | 0      |
| Sum      |          |      | 32       | 15   | 17     |

It turns out that making the cache associative is worse because the LRU replacement policy does the wrong thing repeatedly. 
The hit rate is under 50%.

