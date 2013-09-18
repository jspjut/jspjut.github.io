---
layout: post
title: "Jekyll Bootstrap: rake post"
tagline: "making new posts"
description: ""
category: website
tags: [jekyll, jekyll-bootstrap, website, blog, post, rake]
---
{% include JB/setup %}

I recently discovered a new feature that comes with Jekyll bootstrap,
but I'm unsure whether it is only in JB, or if it comes by default
with Jekyll.
There is a Rakefile (which is sort of like a Makefile, but written in
Ruby) that includes a few nice functions.
The one I discovered most recently allows you to create a new blog
post complete with the YAML frontmatter and the proper file name for
Jekyll to do the right thing with.
The usage is as follows:

    # Usage: rake post title="A Title" [date="2012-02-09"] [tags=[tag1, tag2]]

If you omit all of the optional arguments, then `rake post` will
create a new post on today's date titled "New Post" with the default
values for everything else.
I personally prefer to include a title in my rake command to get the
correct file name from the beginning.
