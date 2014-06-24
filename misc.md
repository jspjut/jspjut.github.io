---
layout: page
title: Miscellaneous
tagline: Stuff I couldn't find a better place for
group: navigation
---
{% include JB/setup %}

## Vanity Links

* [My Google Scholar Page](http://scholar.google.com/citations?user=WzhSQzkAAAAJ)
* [My Erdos number of 4](http://academic.research.microsoft.com/VisualExplorer#3829195&1112639)

## Other links

* [Android OpenGL Test App](http://www3.hmc.edu/~jspjut/OpenGLTest-debug.apk)
* [Procedural Jigsaw Puzzles](http://n-e-r-v-o-u-s.com/projects/puzzles/)
* [site pages](pages.html)

## Recent [Blog](/blog/) Posts

<ul class="posts">
  {% for post in site.posts limit:8 %}
    <li><span>{{ post.date | date_to_string }}</span> &raquo; <a href="{{ BASE_PATH }}{{ post.url }}">{{ post.title }}</a></li>
  {% endfor %}
</ul>
