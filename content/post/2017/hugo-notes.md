---
title: "Hugo Notes"
date: 2017-07-06T09:49:57-04:00
draft: false
categories: 
- website
tags:
- website
- jekyll
- bootstrap
- hugo
- blog
- academic
---

I recently undertook the effort of moving my website from jekyll using jekyll-bootstrap to Hugo and I wanted to record some notes from my efforts. In particular I want to collect a set of useful links that helped me in making the switch.

For what it's worth, I greatly prefer Hugo now that I've gotten used to it, though there wasn't too much broken about Jekyll.

The most useful thing for developing my site was when I found the [academic theme](https://sourcethemes.com/academic/). It turns out that in Hugo, themes contain a lot of the functionality of a site, and they make it easy to add on functionality either by modifying the theme, or your site in particular. The academic theme is widely used so there a good [reference page](https://sourcethemes.com/academic/post/getting-started/) to help you get started.

The creator of the academic theme also has a [good tutorial](https://georgecushen.com/create-your-website-with-hugo/) on his blog for how to set up a new hugo site from scratch.

I ended up testing a lot of my design on a separate repository so I could test out pushing to github sites. It turns out that github user pages need to push to the `master` branch in order to publish to the web, so my original script to push to a `gh-pages` branch had to be modified. It seems to be working as of July 26, 2017, but there are probably a ton of bugs remaining. If you happen to find any bugs, please leave a comment or sent me a message on twitter to let me know and I'll fix it.
