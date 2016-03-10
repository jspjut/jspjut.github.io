---
layout: post
title: "Responsive Videos in Jekyll"
tagline: "thanks Todd"
description: ""
category: website
tags: [jekyll, javascript]
---
{% include JB/setup %}

For my [other blog post]({% post_url 2013-10-15-musical-projects %})
today, I decided I wanted to embed the youtube videos I recorded
earlier.
Since the rest of my website is fully responsive now, I thought it
would be best to find a way to allow embedded videos to also be
responsive to the browser window.
This is one of the main reasons I started using
[bootstrap](http://getbootstrap.com/) in the first place, and
[jekyllbootstrap](http://jekyllbootstrap.com/) for my website.
Luckily I came across the [excellent
post](http://toddmotto.com/fluid-and-responsive-youtube-and-vimeo-videos-with-fluidvids-js/)
Todd Motto made posting his `fluidvids.js` implementation.
I added it to my site, and immediately the youtube videos I had
embedded began to scale responsively as I expect.
I encourage you to go to his site if you want to download the code.


