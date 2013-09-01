---
layout: post
category : website
tagline: "Starting Fresh"
tags : [intro, jekyll, jekyll-bootstrap, website, blog]
---
{% include JB/setup %}

I happened across jekyll-bootstrap the other day, and I decided I
should move my website to github.io after seeing what jekyll can do.
Among my favorite features are the ability to use markdown for web
pages, which allows a reasonably good citation syntax for adding links
to my co-authors.
As an example, the following is the syntax for one paper along with
the citations to my co-authors:

    1. [Daniel Kopta][dk], **[Josef Spjut][jbs]**, [Erik Brunvand][elb];
    **Grid-Based Ray Tracing for a Parallel Computing Architecture**,
    *High Performance Graphics (HPG'09)*, New Orleans, August 1-3, 2009.
       [dk]: http://www.cs.utah.edu/~dkopta
       [ks]: http://www.cs.utah.edu/~kshkurko
       [jbs]: http://www3.hmc.edu/~jspjut
       [elb]: http://www.cs.utah.edu/~elb

The beauty of this is I now only need to update one spot if anyone
changes their affiliation or home page. Awesome.

Conveniently, jekyll-bootstrap also gives all the niceness of twitter
bootstrap, such as the decent template you now see (I hope to improve
it to my liking more in the future).

As an added benefit, I can now easily post blog entries, and hook into
Disqus for comments. Nice.
