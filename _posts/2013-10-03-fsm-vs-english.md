---
layout: post
title: "FSM vs. English"
tagline: "from class demo"
description: ""
category: teaching
tags: [lecture, class, verilog]
---
{% include JB/setup %}

Yesterday, I managed to put together the in-class demo 
[I discussed previously]({% post_url 2013-10-01-interactive-lecture %}).
In this post I'd like to give a brief explanation of what I showed and
how it demonstrates the proper use of SystemVerilog to describe a
finite state machine (FSM).

What I saw many students doing in their 3rd lab, was to use an English
language description of the behavior they wanted that they translated
directly to behavioral SystemVerilog.
This is a fundamentally different procedure than I had intented to
teach in the class, which was to take the English description of the
behavior they want, and translate it to a FSM.
The next step is to use that FSM and describe it using a standard
SystemVerilog implementation. 
This includes 2 pieces of combinational logic, and a single sequential
state register.

The first thing I showed in my demo is the following behavioral
description based on the English description:

{% highlight systemverilog %}
module student_beh( input logic clk, sleep, output logic smile );

endmodule
{% endhighlight %}

This module synthesized into the following RTL circuit diagram:

* Picture goes here

The next implementation I displayed uses a traditional FSM description
in SystemVerilog:

{% highlight systemverilog %}
module student_fsm( input logic clk, sleep, output logic smile );

always_ff @(posedge clk) begin

endmodule
{% endhighlight %}

This module syntheizes into a much nicer looking FSM as shown:

* FSM picture here


