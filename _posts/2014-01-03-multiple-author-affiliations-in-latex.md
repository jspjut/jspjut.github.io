---
layout: post
title: "Multiple Author Affiliations in LaTeX"
description: ""
category: latex
tags: [latex, journal, article, paper]
---
{% include JB/setup %}

I've recently had the pleasure of updating a recent journal article
submission with my list of affiliations. 
On the article, there are 5 authors, and among them, I am the only one
with different affiliations, though I share the other affiliation with
the rest of the authors.
After some quick googling on how I should perform this, I came up with
the following snippet of code that should have worked.

```latex
\usepackage{authblk}

\author[1]{Daniel Kopta}
\author[1]{Konstantin Shkurko}
\author[1,2,3]{Josef Spjut}
\author[1]{Erik Brunvand}
\author[1]{Al Davis}
\affil[1]{School of Computing, University of Utah, Salt Lake City, UT, USA\\
       \{dkopta, kshkurko, sjosef, elb, ald\}@cs.utah.edu}
\affil[2]{NVIDIA Research}
\affil[3]{Department of Engineering, Harvey Mudd College, Claremont, CA, USA}
\renewcommand\Authands{ and }
```

The `authblk` package seems to be beautiful for performing this
function, however it has one problem when used with the other styles
for this particular article. It causes `\maketitle` to fail
complaining about some spacing error, and I couldn't figure out how to
fix it.
Instead, I opted for the poor man's solution to the problem with the
following set of lines:

```latex
\author[D. Kopta et al.]
       {D. Kopta$^1$, K. Shkurko$^1$, J. Spjut$^{1,2,3}$,
       E. Brunvand$^1$, and A. Davis$^1$%\thanks{email: \{dkopta,
       kshkurko, sjosef, elb, ald\}@cs.utah.edu}$^{1}$
       \\
       $^1$School of Computing, University of Utah, Salt Lake City,
       UT, USA\\
       \{dkopta, kshkurko, sjosef, elb, ald\}@cs.utah.edu\\ 
       $^2$NVIDIA Research\\
       $^3$Department of Engineering, Harvey Mudd College, Claremont,
       CA, USA\\
       }
```

This code generates into the following on the pdf.

![Author Affiliations]({{ site.url }}/blog/images/2014/01/authors.png)

It's not as graceful as the `authblk` code, but it works and it's a
simple hack that you only have to do once per article.
