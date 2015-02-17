---
layout: page
title: Build your own Game Controller
tagline: for PC games
---
{% include JB/setup %}

Students in this course will build the own game controller from
scratch capable of providing input to a variety of PC games. The
course includes instruction on resistors, switches and using Arduino
to behave as a USB keyboard and mouse.

#Overview

This course introduces some concepts of basic resistor circuits and
how they can be read by a microcontroller using an analog to digital
converter. 
In particular, we will look at the use of joystick potentiometers as a
standard sensor element for game controllers as well as tactile
buttons combined with pull-up or pull-down resistors to provide
digital inputs.
Additionally, Arduino software will be developed to treat the
joysticks, buttons and switches as standard USB keyboard and mouse
input that can be used for PC games.
With the rapid increase of maker culture and do-it-yourself projects
in recent years, this course provides an easy introduction to circuits
and microcontrollers for the uninitiated and allows more advanced
students the chance to tune the hardware and software to customize the
user experience.

#Prerequisites

This course is intended for people with little to no experience with
programming or electronic circuits.
If you have some C programming experience or understand resistor
circuits you will more quickly be able to complete the tasks in the
course.

#Materials

You will need the following materials to complete the construction of
your own game controller.

* Arduino Micro (or any arduino capable of USB keyboard+mouse control)
* A computer with the Arduino software development environment installed
* Mini breadboards
* 2 Joystick Potentiometers with breakout boards
* 8 Push-buttons
* 1-2 Switches
* Wires
* Soldering Material (only if you don't have appropriate wires)
* Something to mount these on (this could be wood, metal, tooled plastic, or even 3d printed!)

For best results, you should have your mount moulded or tooled to be
ergonomic and comfortable to hold in your hand.

#Steps

1. Mount everything, don't conceal the electrical connections
2. Connect wires to your arduino on the breadboard
3. Program a sketch to read in the joystick and switch state
4. Use current device state to send USB mouse and keyboard commands
5. ???
6. Profit!

#Proposed schedule

* 5 Minutes: Intro to course objectives
* 10 Minutes: Arduino blink example
* 10 Minutes: Arduino button example
* 20 Minutes: Arduino Joystick mouse example
* 10 Minutes: Place buttons and joysticks on controller base
* 10 Minutes: Wiring
* 10 Minutes: Bring it all together (integrate software and hardware)
* 15 Minutes: Wrap up and gameplay testing

Total: 1 hour 30 minutes

... More to come ...
