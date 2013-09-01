---
layout: page
title: Josef Spjut
tagline: Researcher and Professor of Computing
---
{% include JB/setup %}

I am a Visiting Professor in the department of Engineering at [Harvey
Mudd College][HMC] and a consulting researcher for [NVIDIA][]. My [CV][CV].

My research interests include Graphics, Architecture, Embedded
Systems, and Real-Time Systems. It is my hope that my research will contribute towards getting real
time ray tracing to replace rasterization as the primary method of
hardware accelerated rendering.
Use the tabs above to see what publications and projects I
have been involved in.
[My Google Scholar Page][GScholar].
I have an [Erdos number of 4][Erdos] through Rajeev Balasubramanian.

   [GScholar]: http://scholar.google.com/citations?user=WzhSQzkAAAAJ
   [Erdos]: http://academic.research.microsoft.com/VisualExplorer#3829195&1112639

I did my Ph.D. in the [School of Computing][SoC] at the [University of
Utah][UofU] and received my B.S. in Computer Engineering from the
[University of California, Riverside][UCR].

   [CV]: http://www.cs.utah.edu/~sjosef/CV.pdf
   [HMC]: http://hmc.edu
   [NVIDIA]: http://research.nvidia.com
   [SoC]: http://www.cs.utah.edu
   [UofU]: http://www.utah.edu
   [UCR]: http://ucr.edu

## Blog Posts

<ul class="posts">
  {% for post in site.posts %}
    <li><span>{{ post.date | date_to_string }}</span> &raquo; <a href="{{ BASE_PATH }}{{ post.url }}">{{ post.title }}</a></li>
  {% endfor %}
</ul>

## Interesting Links

* [Android OpenGL Test App](http://www3.hmc.edu/~jspjut/OpenGLTest-debug.apk)
* [Procedural Jigsaw Puzzles](http://n-e-r-v-o-u-s.com/projects/puzzles/)
