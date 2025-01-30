## Lesson Objectives
By the end of this lesson, you should:
- **Know**: 🕸️ That HTML is the language for web pages, and the basic structure of HTML
- **Understand**: 💻 How HTML documents are retrieved from the server and rendered in a browser 
- **Be Able To**: 👩‍💻 Write and publish your own valid, semantic HTML page

## What We'll Do In Class

### Reading Quiz
As promised, we'll start with a "reading" quiz based on the assigned videos from 
[https://www.dj4e.com/lessons/html](https://www.dj4e.com/lessons/html).

### Discussion - Static vs Dynamic Pages, Source vs DOM
There was a lot of good content in the videos about how webpages are generated,
and how the HTML page is parsed by the broswer to produce the DOM. These
differences are important, so We'll do a quick review of this topic to make sure
everyone is comfortable with it.

### Write and publish your own web page
The videos spent a lot of time talking about the importance of:
- writing valid HTML
- keeping the content of the web page separate from the formatting

Our goal for today will be to write a simple, valid, semantic HTML page and publish it for the world to see. We'll do this using [Codeberg Pages](https://docs.codeberg.org/codeberg-pages/). Click on that link for instructions about how to create your page.

### Validation
We'll focus on making this page valid (none of the examples in Dr. Chuck's video were valid!). To keep ourselves honest, we'll incorporate an automatic page validator. To do this:
1. Make a directory in your website repo called `js`
2. Download my file `init.js` file [from my repo](https://github.com/CJonesExample/CJonesExample.github.io/tree/main/js) and place it in your new `js` directory
3. Add this line into the head of your html document: `<script src="js/init.js"></script>`

## Homework
### Finish your HTML page
If you didn't get this finished in class, make sure that you get your HTML page
completed, and use git to publish it to your `pages` repo. Then open you page at
`{your username}.codeberg.page`

### CSS Reading
Go through the videos on [https://www.dj4e.com/lessons/css](https://www.dj4e.com/lessons/css). This is *a lot* of content. We'll have a reading quiz next class, but we'll keep it high level. Focus on the high-level purpose of CSS, external stylesheets, and syntax. We won't ask about any specific CSS attribute names (but we expect that you'll know them eventually!)