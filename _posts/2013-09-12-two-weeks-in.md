---
layout: post
category : teaching
tagline: "Only one full week"
tags : [lecture, systemverilog, class]
---
{% include JB/setup %}

In my [embedded systems class][e155], I decided it would be helpful to start
with a review of SystemVerilog to hopefully keep the students from
falling into the common pitfalls that come with using hardware
description languages to describe hardware.
Some important topics I touched on include the "proper" way to
describe a *Finite State Machine* using SystemVerilog.
As a part of that, I made sure to point out the kinds of things that
you can do in SystemVerilog to accidentally describe sequential logic
when you actually intended for the circuit to be combinational.
The real secret is to always ensure every output variable within an
`always` block is assigned for every possible set of input values to
something that does not imply that previous values must be
remembered. 
The most common way to make this mistake is to list a set of cases,
but forget to cover the `default` case.

In [my other class][e85], I began with what I feel was a decent
introduction to computing and its usefulness and prolific penetration
into a variety of markets.
Then I discussed binary and hexadecimal numbers, including
sign/magnitude and two's complement interpretations of a binary
string. 
My main concern in covering these topics is that some of the people in
the class may have missed some of the point and might be struggling.
It is a challenge to ensure that 40+ students all follow a lecture
since the individual variations in learning preferences leave wholes
in what I can cover in only ~80 minutes.
I like to think my lectures are more engaging this year than they were
last year, but, since I didn't record them last year, and I'm not
recording them this year, it will be very hard to determine whether I
have actually improved.

One thing I hope to be able to do in both classes this year is to
actually work through some problems on the board with the class.
Last year I spent almost the entire time running through lecture
slides to cover material and had no time left over to work through
problems, so it will require a fair amount of agility from me to jump
through the material and work out problems.

   [e85]: http://www3.hmc.edu/~jspjut/class/e85
   [e155]: http://www3.hmc.edu/~jspjut/class/e155
