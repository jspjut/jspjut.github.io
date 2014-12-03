---
layout: post
title: "Submitting my first article to arXiv"
description: ""
category: research
tags: [blog, research, latex]
---
{% include JB/setup %}

Today I submitted a technical report done by my students over the last academic year. 
It took a while to get the write-up to the level of quality that I felt good about submitting it,
but now that it's there, I figured I should push it out. 
I used [arXiv](http://arxiv.org/) to post it since they make it easy to publish a technical report
while not preventing you from submitting the work to another venue such as a conference or journal
at a later date.
I used Latex to write the paper, and in preparing the submission, there were a 
couple modifications I had to make to get it accepted by the system.

First, I had to include a line that says `\pdfoutput=1` somewhere 
in the first 5 lines of the main tex file I submitted.

Second, I had to include the `main.bbl` file that was generated 
locally as part of my build process.
It appears that they don't actually need the `.bib` file and
only care about the `.bbl`.

Next, my particular document used a style sheet called `jpaper.cls` that
had a strange error with how it includes the `hyperref` package.
The relevant lines that I had to comment out are below (comments added - removed ending `%` because of jekyll):

```latex
% Link and URL formatting.
%\iftoggle{jp@hyperref}{
%  \RequirePackage{hyperref}
%  \hypersetup{
%    unicode=true,%
%    pdfstartview={FitH},%
%    colorlinks=true,%
%    %citecolor=black,%
%    %filecolor=black,%
%    %linkcolor=black,%
%    %urlcolor=black
% }}{}
%\RequirePackage{url}
```

Finally, I had an issue with figures I included that I think had to do with how
I uploaded all of the source material.
Since I submitted each file separately instead of part of a compressed folder, 
the graphics I was trying to include were now a part of the root directory instead
of being present in the `graphics` subdirectory that I use locally.
Luckily, there was a straightforward fix that I think I'll include in my future
documents by default because it's much cleaner than what I've done traditionally.
In the main `.tex` file include a line like the following:

```latex
% graphics path
\graphicspath{ {./graphics/} }
```

Then, instead of including the relative path to everything in the graphics path, 
just include the graphics directly as in this example:

```latex
\begin{figure}
\centering
\includegraphics[width=\columnwidth]{PairedCaches}
\caption{Partly shared instruction caches}
\label{fig:paired}
\end{figure}
```

