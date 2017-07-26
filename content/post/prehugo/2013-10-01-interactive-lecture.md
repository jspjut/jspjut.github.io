---
categories:
- teaching
date: 2013-10-01T00:00:00Z
description: ""
tags:
- lecture
- class
- verilog
title: Interactive Lecture
url: /teaching/2013/10/01/interactive-lecture/
---

In grading some labs this week, I noticed a trend among my students to
create something that was essentially a finite state machine (FSM)
without actually explicitly making a finite state machine in their
verilog description.
Typically a FSM has 3 parts, a *state register*, *next state logic*,
and *output logic*.
The only part of the FSM that should be sequential logic is the 
*state register* while the other parts should be purely combinational logic.
That means that the SystemVerilog should have a single 
`always_ff @(posedge clk)` section that only assigns the state register.
Everything else should be combination using `always_comb` or `assign`
statements.

Since this confusion still seems to be prevalent among the students in
the class, I've decided I need to take more action to deliver this
understanding. 
As a result, I am working on an in-class demo showing the RTL
(register transfer level) representation of a couple different
implementations of the same thing in class.
While I believe this live demo will be quite effective, I also run the
risk of failing miserably and spending a significant part of class
debugging the demo and trying to make it work.
If only there were some way to ensure that live demos never have
issues. 
My current plan is to just practice the demo 3-4 times before hand to
hopefully work out any bugs.
