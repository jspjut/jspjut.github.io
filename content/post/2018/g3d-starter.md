---
title: "G3D Starter Project"
date: 2018-06-16T08:24:00-04:00
draft: false
categories: 
- graphics
tags:
- graphics
- programming
- research
---

I've recently been spending a lot of my time working on projects based on the [G3D Innovation Engine](https://casual-effects.com/g3d/www/index.html) by [Morgan McGuire](https://casual-effects.com/morgan/index.html). I personally learned how to program using unix development tools, so I'm used to using the command line for everything, and Makefiles are the build tool I'm most comfortable with. G3D, being a research game engine, primarily for graphics research, has had to focus on Windows-based development for a number of years now. This means the best way to do research on graphics is to use Visual Studio and Windows, which I never took a class to learn how to use. Makefiles on the other hand I had a large number of classes to teach me how they work, and I had used all through undergrad and grad school, for over 10 years of experience with that build process.

Visual Studio's build process is completely opaque to someone coming from Makefiles (xcode and other similar GUI-based tools are no better). If I were to teach someone how Visual Studio's build process works, I would start by telling them that the configuration is hidden in XML files, which have many fields that are option and populated with default values which do something whether they are there or not. Microsoft has a [nice overview](https://docs.microsoft.com/en-us/cpp/ide/project-and-solution-files) of the types of XML files. You probably don't need to know what all of the optional fields do, but some subset of those fields will be quite useful to know and understand. I'll give my top N list here. These can be found by right clicking on a project in Visual Studio and selecting the "Properties" option at the bottom of the menu, then clicking on "VC++ Directories" under "Configuration Properties" on the left side of the Property Page. Note that the "Configuration" drop down at the top allows you to specify different values for "Release", "Debug" or any other build configuration you create, which can be managed from the Property Page by clicking on the "Configuration Manager..." in the top right corner. The second value below is what the field in the Property Page corresponds to in the XML.

1. Include Directories - `IncludePath`
2. Library Directories - `LibraryPath`
3. Executable Directories - `ExecutablePath`

Each of these items does what you would expect it to do based on the name, "Include Directories" managing what headers will be searched when compiling code (useful for ".h not found" errors). "Library Directories" configures which directories to search for statically linked libraries during the linking stage of the compiler. Executable Directories sets the path to use for executables, which is used both for programs you want to run, but also dynamically linked libraries (dlls) that you need to be found by your executable at startup.

In G3D's automated build script and the [Configure and Build](https://casual-effects.com/g3d/G3D10/readme.md.html?#toc3.2) instructions, it recommends setting some global system or user settings which could actually be handled by the vcxproj XML file in a more portable way. I understand why G3D recommends developers use the user and global settings to fix this since all future projects can be created with much fewer settings, however this makes the assumption that no other project or build system will need to modify the user and global settings, or that the developer will be smart enough to figure out how to merge these setting for her or himself. In an effort to help improve portability of my own G3D-based projects, I've started a [g3d-starter](https://github.com/jspjut/g3d-starter) project on github which depends only on a couple G3D-specific environment variables rather than all of the global/user Include, Path and Library settings. Feel free to check it out!

My updated instructions modified from the [G3D Configure and Build](https://casual-effects.com/g3d/G3D10/readme.md.html?#toc3.2) instructions follow below. You'll still need Visual Studio 2017 and an install of python 3 before the following.

# Configure & Build

1. Set your **user** or **system** environment variable `g3d` to the location that you'd like to be the
   root of the G3D tree (such as `c:\g3d`). In Windows 10, do this by &#9881; ==> System ==> About ==> System Info ==> Advanced System Settings ==> Environment Variables...
   (or by searching for "Environment Variables" in the start menu search)

2. Set the **user** or **system** environment variable `G3D10DATA` to
   `%g3d%\G3D10\data-files;%g3d%\data10\common;%g3d%\data10\game;%g3d%\data10\research`

3. SVN check out `https://svn.code.sf.net/p/g3d/code/` to `%g3d%`. This is very large, and likely to timeout if sourceforge has a hickup. Be prepared to `svn cleanup` and `svn up` if it doesn't finish

4. At a command prompt in the `%g3d%\G3D10` directory, run:
   
   `buildg3d local`

5. Copy my [g3d-starter](https://github.com/jspjut/g3d-starter) and follow the rest of the instructions from the [G3D new project guide](http://casual-effects.com/g3d/G3D10/build/manual/guidenewproject.html)


