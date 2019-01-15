---
title: "Gaming Toxicity for Developers"
date: 2019-01-15T22:00:24-05:00
draft: false
categories: 
- game design
tags:
- game design
- game development
- technology
- gaming
- toxicity
---

Toxicity is a huge problem in online video games. Some of the most well-known toxic online gaming communities include League of Legends, Dota and your favorite console shooters. While console shooters have generally included voice chat and a range of "your mom" insults screamed by the 13 year olds on the other end of the line, PC games typically include text chat, and a clearly visible record of every toxic statement. I'm going to focus my remarks at this time on the text-based medium, even though clearly voice chat and vocal insults are a huge part of the problem.

This is part 1 of a 2 part series on toxicity. You can find [part 2 here]({{< ref gaming-toxicity-for-players >}}) (when finished).

## Systems for Dealing with Toxicity
Years ago when I still played League of Legends, they introduced [The Tribunal](http://leagueoflegends.wikia.com/wiki/The_Tribunal), which was given as their solution to toxicity among the player base. The basic idea is that players are given the ability to report others when they see bad behavior in game. Then a small group of volunteer players are given a chance to review the text logs (and some in-game events) to see if these reports justify action or not. The theory was that a group of your peers would be able to effectively determine when you have violated the implicity standards of good sportsmanship and behavior. The Tribunal had a good run, but was eventually discontinued in 2014. I suspect that part of the problem with the system was that Riot had to incentivize participation by providing rewards to those who vote in the tribunal, and the rewards were tied to achieving consensus, which led to nearly all participants always voting to confirm toxicity, even when there was none present. They've since replaced the system.

Another approach that I've seen applied in many games from Puzzle Pirates to Overwatch is to automatically replace certain "bad words" with other more innocuous statements. I mentioned Puzzle Pirates because they [did a particularly interesting thing](https://yppedia.puzzlepirates.com/List_of_known_filtered_words) where they replaced common swear words from modern English with things that sound piratey. It was extremely common to see people say, "billions of blue blistering barnacles", but that was just a replacement for another exclamation. More recently, [Overwatch replaced "gg ez"](https://overwatch.fandom.com/wiki/Text_Chat) with a range of phrases meant to soften the blow. It's become a bit of a running joke among players to send "gg ez" now to see what phrases they end up getting.

With the rising interest of the computing world on artificial intelligence(AI), there are many looking into ways to use AI to help police or reduce toxicity in online interaction. [Perspective API](https://www.perspectiveapi.com/) is one such company that provides AI-driven tools to identify how toxic a particular phrase might be. These emerging technologies may be extremely useful in helping developers and players improve the experience of interacting with others online. Of course while these tools can help reduce negative experiences, if misused, they could lead us to an extremely controlled authoritarian online experience and community.

## Censorship Ethics
It should go without saying, but just to be sure, this blog post is my own words and does not necessarily represent the position of my employers, my family or anyone else. 

I strongly believe that freedom of expression is an important human right that should be granted to all people. Only in extreme circumstances should that basic human right of freedom of expression be restricted. Today most people in the west believe in freedom of speech, and the only disagreement tends to come when determining which circumstances are worthy of restricting the otherwise free speech. I'm going to do my best here to take no position on which things should be restricted and instead focus on an approach that I believe to be fair to everyone, and should avoid putting game developers and content owners in a position of explicitly deciding what to censor. This approach is accomplished in 2 parts:

1. People can say whatever they want
2. People can ignore whatever they don't want to hear

First, people should be able to say whatever they want. Let them type messages and hit send. As long as those messages aren't causing arbitrary code to be executed on your server, or represent some automated attack, they can be fairly treated and given the same chance to arrive at the server prior to distribution to others in the game. Perhaps even more importantly, those messages should be shown on the screen of the sender to confirm that they were able to send the message. It's okay if it doesn't show up until after a server round trip, and in fact, that is sort of good because it lets the user know when the server has had a chance to distribute the message. I often use that feature to test if I'm experiencing [network connectivity problems](https://www.youtube.com/watch?v=LinpRhB4aWU&t=21).

Second, people should be able to opt out of hearing what they don't want to hear. This is where the more exotic tools can be used, and even many of the traditional tools. Game developers can provide a set of filters that allow players to opt out of seeing certain words, or even just replace those words with more friendly alternatives. Players should be able to explicitly mute others who they believe to be offensive, or even just uninteresting. It's also okay to identify groups of people who demonstrate certain kinds of behavior (harsh sarcasm for instance), and allow players to opt in or opt out of communicating with those people as a group. The truth is that your players are smart, and they know what they don't want to hear or what they can't bear, and should be able to make these decisions on their own.

One possible way to use AI-based toxicity detection would be to find chat messages that player A enters, and when they reach a higher level of toxicity, recommend that they opt out of certain incoming communications that might be triggering this bad behavior. That way, they get an easy way to reduce their internal negative emotions, but aren't forced into it. Maybe things that are being viewed by the system as toxic are actually old friends joking about something from their childhood, and that context may be lost in the medium. It would truly be a travesty if we lose out on the richness of human interaction just because we couldn't trust our players enough. Give the power to the players!

## What **Not** to Do
Game developers and publishers hold a lot of power in their hands. They build platforms that are used by large numbers of users, and develop into large, vibrant communities. Of particular note are the large number of young adults that find a home in these communities. As an example, in the last year, [Fortnite](https://fortnite.com) has become the home to a huge number of players and has permeated popular discourse. Developers need to be mindful of the public perception of their platform, and make visible steps to improve the situation if things are going poorly, particularly with respect to toxicity.

However, it would be quite easy to overstep your bounds as a game developer, and take too much control over what your players are able to do. Obviously if there are clear game design or plot reasons for communication restrictions, I consider that a part of the art, and believe they are totally appropriate. A good example of doing this right is [Journey](https://en.wikipedia.org/wiki/Journey_(2012_video_game)), which happens to be one of my favorite games. In it, you are matched at random with other players on the same level as you, but you cannot communicate except through occasional pings with an audio and visual cue. This fits in quite naturally with the rest of the game's story, and lets you work around the restriction to effectively collaborate on solving the puzzles before you.

The thing I'm most worried about is a situation where developers think that the only way to deal with bad behavior is to punish offenders. Obviously there's some room for sticks (in the [carrot/stick paradigm](https://en.wikipedia.org/wiki/Carrot_and_stick) ), but I believe they should be used sparingly. If punishments are too harsh, the people being punished have no chance to learn and grow from the experience. I believe that when done right, online games and communities provide excellent opportunities for humans to develop into successful members of society. As a game developer, you're effectively being placed in a position of legal authority over the behavior of your game, but without multiple branches of government to balance out your power. Please keep your use of tools and punishments metered.

Players bear a large part of the responsibility for good behavior, so stay tuned for [my next post]({{< ref gaming-toxicity-for-players >}}) on that part of the problem.

