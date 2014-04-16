---
layout: post
title: "A Busy Semester"
description: ""
category: teaching
tags: [class, lecture, blog, ARM, ARMv7]
---
{% include JB/setup %}

This semester has been extremely exciting. In particular, E85 has been
updated from MIPS to use the ARM v7 instructions set.
This has been a good experience for me despite some difficulties and a
few moments of intensity where I wasn't sure things would come
together in time.
In doing this, I've come to learn a lot about the ARM ISA, and I've
decided I like it a lot.
In particular, I think it strikes a reasonably good balance between
RISC and CISC instructions where there are a couple nice addressing
modes for stack manipulation that aren't quite RISC, but are close
enough.

An example of the niceness can be seen by the following code for stack
manipulation:

```
ADD SP, SP, #-12
STR R0, [SP, #8]
STR R1, [SP, #4]
STR R2, [SP, #0]
...
LDR R0, [SP, #8]
LDR R1, [SP, #4]
LDR R2, [SP, #0]
ADD SP, SP, #12
```

This code can be effectively replaced by the following which updates
the stack pointer as the values are written or read from the stack:

```
STR R0, [SP, #-4]!
STR R1, [SP, #-4]!
STR R2, [SP, #-4]!
...
LDR R2, [SP], #4
LDR R1, [SP], #4
LDR R0, [SP], #4
```

MIPS did not have the option to manipulate the stack pointer while
changing it from a single instruction.
I think this additional understanding will be useful for many of the
students in the class in their future careers.
