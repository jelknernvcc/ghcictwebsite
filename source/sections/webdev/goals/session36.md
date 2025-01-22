

## What We'll Do In Class

### Course Evaluations
<p style="color: red;">
Please complete your course evaluations. To do that, go here:
<a href="https://nova.mce.cc">https://nova.mce.cc</a> and login: your username is your VCCS email, and your password is your 7-digit NOVA ID (which I can help you find).
NOVA really wants student participation here, and
your willingness to complete this task reflects well on your instructors, so
thank you in advance for doing it.
</p>

### Prepare for the final exam
We'll have our final exam on:
- Friday (A Day)
- Monday (B Day)

Our final exam will be cumulative of **everything** we've done this semester. Because there's so much content, it'll be a bit longer than our previous tests:
- 30 multiple choice questions
- 3 free response questions
- 70 minutes

You can expect these questions to be very similar to the four unit tests that we've had... you might even recognize some of the questions 😉. So the best way to prepare is to review your previous tests. You should also go back through the content on this website to make sure you remember what we've learned.

As always, you're allowed to bring one sheet of hand-written notes. 

Here's a thorough list of things you should study for the exam:

- Unit 1: Using your computer
    - Directory navigation: 
        - `cd`/`ls`
        - `mkdir`
    - File manipulation: 
        - `echo`
        - `>`
        - `mv`
        - `cp`
        - `rm`
    - git commands:
        - The difference between git on your computer and github.com
        - `git add`
        - `git commit -m "message"`
        - `git push`
    - vim: 
        - move the cursor around using `h/j/k/l`
        - switch into insert mode using `i` or `A`
        - switch back to normal mode using `esc`
        - quit without saving using `:q`
        - save and quit using `:wq`
    - Markdown / Latex (What they are, I won't ask questions about syntax)

- Unit 2: How the internet works
    - four layers of the TCP/IP model
    - packets
    - routers
    - problems that can occur in packet-switched networks, and how TCP/IP protocols address them
    - information that is contained in the TCP/IP header
    - TCP vs UDP
    - Binary vs Decimal vs Hex (I'll only ask really simple conversion questions)
    - ASCII
    - Symmetric vs asymmetric encryption
    - "Adversary in the middle"
    - Internet vs World Wide Web
    - Request/response cycle, DNS, and HTTP

- Unit 3: HTML
    - What kinds of projects should consider using Wordpress
    - The role of HTML, CSS, and Javascript, and how they work together. 
    - Why we care about valid, semantic HTML
    - The DOM
    - Block vs in-line elements
    - Semantic elements for text formatting, 
    - HTML tables, lists, and hyperlinks

- Unit 4: CSS
    - Favicons
    - In-line, internal, and external styles
    - Colors - in names, RGB, Hex
    - Selectors: element names, classes, ids
    - Priority and cascade rules
    - Sizing using percentage, px, em, vw
    - box model
    - background-clip
    - text-align and text-transform
    - Fonts vs Typefaces
    - Serifs, x-heights, ascenders/descenders, spacing, and kerning
    - Web-safe fonts
    - Font families
    - CSS Grid (and the special fr unit)

- Here's some things that I won't ask you:
    - Specific markdown/LaTeX syntax (I need you to know what they are, not any syntax)
    - How to resolve any specific errors with git or the command line
    - Any specifics about what is included in the TCP/IP packet header
    - Details about how we implemented the asymmetric encryption activity
    - The activity we did about providing multiple different image resolutions via `srcset`
    - To recognize any specific fonts
    - Any specific HTML elements or CSS attributes that we haven't specifically discussed in class

## Other Review Activitiese (A Day - choose one of these to complete for a grade)

### CSS Grid Pixel Art
One fun way to practice with CSS grid and selectors is to create pixel art - you can create a square grid and use selectors to individually color selected squares.

For today's classwork grade, make some nice pixel art using this technique. You can [see some nice examples here](https://css-tricks.com/fun-times-css-pixel-art/), and [I wrote some starter code for you here](https://github.com/CJonesExample/CJonesExample.github.io/blob/main/art_example.html)

### Redesign a website's CSS

We'll play in class with a fun CSS extension called [Stylus](https://github.com/openstyles/stylus/), which allows you to write your own CSS for existing websites. The easiest way to install it is via the [Chrome Web Store](https://chromewebstore.google.com/detail/stylus/clngdbkpkpeebahjckkjfobafhncgmne?hl=en)

For this assignment, you'll choose a website and add custom styles to it. You'll need to spend some time reading the source code for the website to identify which elements you want to style, and then write custom CSS for them.

You should:
- Add your own colors
- Change the font (probably easiest to use a web-safe font here)
- Use the box model to change the size/position of some elements
- If you want an extra challenge: Find an element that has a bunch of sub-elements, and turn that element into a custom grid

To submit this assignment, commit your custom CSS to your repo, and write a new Markdown journal entry. Include a screenshot of your version of the page, and a link to your custom CSS script.

This is also due before the final exam!
