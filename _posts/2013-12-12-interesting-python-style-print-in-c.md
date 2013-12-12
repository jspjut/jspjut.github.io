---
layout: post
title: "Interesting python style print in C++"
description: ""
category: programming
tags: [c++, python, print, hacks]
---
{% include JB/setup %}

I came across a really interesting piece of C++ code today hidden in
this [list of obscure C++
features](http://madebyevan.com/obscure-cpp-features/?viksra). 
It includes an implementation of some of the `print` syntax
functionality of python 2 implemented in C++.
Here's the code (copied here, but I'm not the original author):

<!-- more -->

```c++
#include <iostream>

namespace __hidden__ {
  struct print {
    bool space;
    print() : space(false) {}
    ~print() { std::cout << std::endl; }

    template <typename T>
    print &operator , (const T &t) {
      if (space) std::cout << ' ';
      else space = true;
      std::cout << t;
      return *this;
    }
  };
}

#define print __hidden__::print(),

int main() {
  int a = 1, b = 2;
  print "this is a test";
  print "the sum of", a, "and", b, "is", a + b;
  return 0;
}
```

While this implementation is interesting, it is missing what I think
is the best feature of python `print` and that is the ability to use
`%` to do C `printf` style printing. 
If I end up with a bundle of extra time, I might actually try adding
that functionality, though it's not immediately apparent to me how to
overload an operator to take an arbitrarily sized list as input...
