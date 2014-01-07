---
layout: page
title: Josef Spjut
tagline: Researcher and Professor of Computing
---
{% include JB/setup %}

Visiting Professor in the department of Engineering at [Harvey
Mudd College][HMC] and consulting researcher for [NVIDIA][].

My research interests include Graphics, Architecture, Embedded
Systems, and Real-Time Systems. It is my hope that my research will contribute towards getting real
time ray tracing to replace rasterization as the primary method of
hardware accelerated rendering.
Use the tabs above to see what publications and projects I
have been involved in.

Ph.D. from the [School of Computing][SoC] at the [University of
Utah][UofU] and B.S. in Computer Engineering from the
[University of California, Riverside][UCR].

   [HMC]: http://hmc.edu
   [NVIDIA]: http://research.nvidia.com
   [SoC]: http://www.cs.utah.edu
   [UofU]: http://www.utah.edu
   [UCR]: http://ucr.edu

## Links

* [Request a Letter of Recommendation]({{ BASE_PATH }}/recs.html)
* My CV in [pdf](files/cv.pdf) and [html](cv.html)
* [My Google Scholar Page](http://scholar.google.com/citations?user=WzhSQzkAAAAJ)
* [My Erdos number of 4](http://academic.research.microsoft.com/VisualExplorer#3829195&1112639)

## Recent [Blog](/blog/) Posts

<ul class="posts">
  {% for post in site.posts limit:8 %}
    <li><span>{{ post.date | date_to_string }}</span> &raquo; <a href="{{ BASE_PATH }}{{ post.url }}">{{ post.title }}</a></li>
  {% endfor %}
</ul>

## Interesting Links

* [Android OpenGL Test App](http://www3.hmc.edu/~jspjut/OpenGLTest-debug.apk)
* [Procedural Jigsaw Puzzles](http://n-e-r-v-o-u-s.com/projects/puzzles/)
* [site pages](pages.html)
