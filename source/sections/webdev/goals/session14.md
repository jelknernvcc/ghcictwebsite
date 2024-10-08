## What We'll Do In Class

Today's focus will be [LaTeX](https://en.wikipedia.org/wiki/LaTeX) - which we'll use to embed equations in our Markdown documents.

### Lesson Objectives

By the end of this lesson, you should:
- Understand how to embed LaTeX equations within Markdown
- Be able to write simple mathematical equations using LaTeX syntax

### Topics Covered:
- Embedding LaTeX in Markdown for equations
    - See the instructions in [Github's official documentation here](https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/writing-mathematical-expressions)
    - Getting this to work in your actual journal requires one more step: create a folder in your github repo folder called `_includes` and add a file in that folder called `head-custom.html`. In that file, [copy the code that i have here](https://github.com/CJonesExample/CJonesExample.github.io/blob/main/_includes/head-custom.html)
- Here's some helpful LaTeX syntax
    - Fractions: `\frac{a}{b}`
    - Special Symbols: `\pi` for π, `\infty` for ∞
    - Limits: `\lim_{x \to 0}`
    - Radicals: `\sqrt{x}`
    - Brackets: `\left( \frac{a}{b} \right)`

### Homework

### Part 1 - Markdown, LaTeX, and Images

- If you haven't yet, finish setting up your journal. See the instructions here: [See the detailed instructions here](../projects/project.html?id=02_journal_setup)
- Add a new journal entry, where you'll summarize a lesson that you learned in a recent math or science class. In your journal entry:
    - Include at least one image
    - Include at least two LaTeX equations
    - Include at least one table with a heading. Center the text in this table
- Grading: This assignment is due by the beginning of next class (for B day, that's October 15 at 11:32AM). To get credit for this assignment, I must be able to find your journal entry by following links from your website homepage. If you write this journal somewhere else or don't link it from your homepage, you will not get credit.
    - You will get an A if you write thoughtful, complete lesson notes and meet all of the above requirements
    - You will get a B if you write thoughtful, complete lesson notes and miss any one of the above requirements, or if you attempt all and have minimal syntax errors that prevent the output from displaying correctly
    - You will get a C if you complete all of the above requirements but do not write thoughtful, complete lesson notes
    - You will get a D for writing any valid Markdown (that isn't just text)
    - You will get an E if you do not submit valid Markdown
