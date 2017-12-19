+++
title = "Javascript Introduction"
date = 2017-12-14
edit-date = 2017-12-14
draft = true
+++

This is my intro to Javascript course notes.

# Table of Contents
1. [Introduction](#introduction)
2. [Variables](#variables)
3. [Scope](#scope)
4. [Arrays](#arrays)
5. [For Loops](#for-loops)
6. [For Of Loops](#for-of-loops)
7. [Functions](#functions)
8. [Objects](#objects)
9. [Methods](#methods)
9. [Inheritance](#inheritance)
11. [Possible other topics](#other)
    * [JSON](#json)
    * AJAX
    * Etc.

# Introduction

# Variables
In javascript, the syntax to declare a variable with no initial value is the following:

```javascript
var myVariable;
```

In every line after the above, `myVariable` will be used to refer to the variable we have created with that name.
For lines prior to the declaration (the line with `var` followed by the variable name), `myVariable` does not exist, and if we try to use it, we will get an error from the javascript interpreter. 

# Scope

I don't yet know scope rules in Javascript. Fill this in.

# Arrays

An array can be thought of as a variable that has a list of data inside it.

```javascript
var myArray = [1, 2, 3, 4];
```

We can access a member of the array using its index. The first element in an array in Javascript has the index `0`. Thus the statement `myArray[1]` would evaluate to the value `2` based on the above declaration.

```javascript
for (var i = 0; i < 15; i++){}
for (a of b) {
    document.getElementById(a.id).innerHTML = a.text;
}
```
