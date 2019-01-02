---
title: "Console to PC Game Port Requests"
date: 2019-01-02T16:51:24-05:00
draft: false
categories: 
- game development
tags:
- game design
- game development
- technology
- gaming
---

Over the holiday break, I had a chance to play a number of different games. Among these games, I tried out a few PC ports of primarily console-focused games, and I was reminded of some things that frustrate me when I have my "PC Gamer" hat on. Without calling out any particular developer or publisher, I'd like to take this change to suggest a few recommendations for PC ports that I wish every developer would follow.

1. Don't use the mouse like a joystick
1. Use my default PC resolution on first boot
2. Test your (primarily shooter) game with gaming mice
3. Provide an option for unlocked framerate
4. Allow 3D render resolution to be set independently from 2D resolution
6. Allow borderless window fullscreen mode

# Mouse like a joystick?

This is my number one complaint with PC ports of console games, and it doesn't make sense how anyone releases games with such a terrible user experience any more. The mouse is expected to have a linear mapping from motion on desk to motion in game. I've played a few games that turn the linear motion into an acceleration or set a velocity of motion with at most a spring constant of damping that doesn't make sense. I understand that I could get out a controller to play the game, and I do appreciate that control scheme at times, but if your game isn't even playable with mouse, just tell me up front and disable the mouse entirely.

A sub-point about mouse behavior is that if you allow mouse input in your game on PC, please make the mouse work like a mouse in your menus. A common shortfall here is creating an inventory management system built for controller input and then treating it the same on PC where "wasd" controls the object selection and only the mouse button (or even worse the spacebar) selects the highlighted item. If I have a mouse, you can expect me to be ready to click on things and to drag and drop inventory items to be where I want them to be. Decades of desktop operating system use has trained nearly all of humanity how this works. Why would you build a game interface in 2019 that throws away things we learned [in 1968](https://en.wikipedia.org/wiki/Computer_mouse)?

# Boot resolution

I don't have much to say about this, except it's super irritating to have all of your windows resize themselves because a game decided that on first boot it had to be absolutely sure it would start by setting a fullscreen resolution of 640x480. If you can't be bothered to query the OS for the right resolution, could you please at least start in windowed mode to not throw off everything else I have going on my PC? Thanks.

# Gaming mice

This one isn't relevant to every type of game, and is primarily related to shooter games and other games that use the mouse to aim. I've been learning a lot about mice as input devices for shooter games lately, and hope to write more on that topic soon. However, I've started a few games recently which are shooter games. I'm not particularly mad about the ones that have mouse acceleration turned on by default as long as there's an option to turn it off. But some of these games have had mouse sensitivity settings that are much too high by default, and often won't even go low enough without resorting to editing `.ini` files manually. For reference, standard issue mice have a built in DPI setting of 800 but gaming mice default to 2400-3200, which is 3-4x *higher* than what a normal mouse has. If you can't afford to buy $50 gaming mice for your QA testers, could you at least take your mouse sensitivity range and make sure it goes to values 4x lower than the lowest setting that your testers are comfortable with?

# Unlock framerate

I know this is the classic PC gamer complaint, but 30 fps vsync on is extremely frustrating, especially when I just finished playing a few rounds of Overwatch at 240Hz. The difference is jarring. Thankfully most game ports now default to a limit of 60 after some successful complaint campaigns, but you could avoid having problems if you just query the OS for what it thinks the display framerate can go up to, and allow that. Then you won't have to patch your game 5 years from now when everyone is complaining that you don't support 480Hz, or whatever the fps of the moment is.

# Independent 2D and 3D resolution

The first time I remember seeing this option was on [Champions Online](www.champions-online.com/) and it completely blew my mind. Having looked a bit deeper at how game engines produce their images, it is relatively straightforward to set your text and UI elements to full display resolution while allowing the in-game resolution to scale down (or up) to match the capabilities of the GPU in the system. This gives the user a better experience and allows them to customize based on their situation (laptop gamers especially enjoy these settings!).

# Borderless window

I like to do multiple things with my computer. In particular, I really like to be able to stay in contact with my friends. When you launch a fullscreen application in windows, the alt-tab switch to my messenger client of choice (Discord these days) both hides your game, and takes entirely too long to switch to and from. If you're a fullscreen application and I end up involved in a discussion about when and where our next group meetup is going to happen, I may never return, either because I forget you're there in the background or because I get too frustrated to keep going back.
