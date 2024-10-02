# Markdown Journal Setup Instructions

## Introduction
In this class, we will be using Markdown to build and maintain a journal. Our goal will be to setup a journal that is linked from our homepage, and where we will frequently add entries.

## Journal Structure

To setup the journal, we need a few things:
- A folder in our github repo called `journal`, and inside that folder:
    - A file called `index.md`
    - A folder called `entries`, and inside that folder:
        - One file for each journal entry. The filename should all end in `.md`
- Links from `index.md` to each of the journal entries
- A link to `journal/index.md` from your HTML homepage

## Links
There are two types of links you'll need to make here.

- First, add this to your main index.html page:

`<a href="journal/">Click here to read my journal</a>`

- Then, for each entry, add a link to `journal/index.md` that looks like this:

`- [My first journal entry](entries/01_Intro.md)`

## Demo
You can see my simple journal setup [in my repo here](https://github.com/CJonesExample/CJonesExample.github.io/tree/main/journal)
