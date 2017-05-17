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
* [In the Media](http://josef.spjut.me/media/)

## Teaching

Summer 2015: [Siggraph Build Your own Game Controller](class/game-controller).

I used to advise the [Charlab](http://charlab.github.io/) research group.

[Other classes](teaching) I've taught.

For (former) students: [How to Request a Letter of Recommendation](recs)

## Other links

* [Indie Game Share](http://itch.io/)
* [Web-based equation tool](http://www.sciweavers.org/free-online-latex-equation-editor)
* [Web-based FSM tool](http://madebyevan.com/fsm/)
* [Web-based diff tool](diff.html)
* [Procedural Jigsaw Puzzles](http://n-e-r-v-o-u-s.com/projects/puzzles/)
* [Python strftime formats](http://strftime.org/)
* [site pages](pages.html)
* VLC stuff
  * [VLC command lines](https://www.videolan.org/doc/streaming-howto/en/ch04.html)
  * [VLC GUI stuff](http://www.videolan.org/doc/streaming-howto/en/ch02.html)
  * [webcam testing](https://help.ubuntu.com/community/Webcam)

## My NCAA College Football Rankings

I decided I didn't like the rankings made by the tournament committee
or the voters in the polls so I made [my own rankings](ncaaf.html)
driven by a simple python script. 

## Recent [Blog](/blog/) Posts

<ul class="posts">
  {% for post in site.posts limit:8 %}
    <li><span>{{ post.date | date_to_string }}</span> &raquo; <a href="{{ BASE_PATH }}{{ post.url }}">{{ post.title }}</a></li>
  {% endfor %}
</ul>
