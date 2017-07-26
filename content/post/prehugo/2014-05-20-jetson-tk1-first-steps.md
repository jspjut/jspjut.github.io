---
categories:
- programming
date: 2014-05-20T00:00:00Z
description: ""
tags:
- graphics
- blog
- embedded systems
- technology
title: Jetson TK1 First Steps
url: /programming/2014/05/20/jetson-tk1-first-steps/
---

I recently received my [Jetson TK1 Development
Board](https://developer.nvidia.com/jetson-tk1), which I'm evaluating
for potential use in an embedded systems course next Spring. 
This board is attractive to me because it has a high-end quad core ARM
A15 processor as well as a high-end mobile GPU with support for the
latest OpenGL and CUDA development environments.
This post is going to serve as a way for me to record the things
needed to set up the device in the first place, and hopefully more
posts will follow as I manage to develop some examples on the board
that will hopefully turn into lab assignments for the class.

The first thing you notice when you plug in the board and turn it on,
is that it boots to an OS without any setup because the built-in flash
has linux on it from the factory.
However, there is no x11 support out of the box.
Well that's not quite true... 
The support is available, but you must [run a script to install the
driver](http://developer.download.nvidia.com/embedded/jetson/TK1/README.txt).
The instructions from the README are copied and inline here:

```
This README file lists instructions on how to install the NVIDIA
Linux driver binary release on your target located in:
${HOME}/NVIDIA-INSTALLER

Step 1)
Change directories into the NVIDIA installation directory:
    cd ${HOME}/NVIDIA-INSTALLER

Step 2)
Run the installer script to extract and install the Linux driver
binary release:
    sudo ./installer.sh

Step 3)
Reboot the system to have the graphical desktop UI come up.

NOTES:
- The installer.sh should only be run once.
```

More to come...
