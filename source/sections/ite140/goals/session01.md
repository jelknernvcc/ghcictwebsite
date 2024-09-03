## Overview

Welcome to Database Design and Management! This is the second time that ACC has offered this course, and my first time teaching it, so you will be in some ways pioneers in uncharted territory. The big goal will be to learn a collection of useful skills and explore ideas related to [data science](https://en.wikipedia.org/wiki/Data_science).

During the Fall semester, this year-long dual-enrolled course will be dual-enrolled with [ITE 140: Spreadsheeting for Business](https://courses.vccs.edu/courses/ITE140-Spreadsheet%20Software). If you took that course on campus at NVCC, you would find it a course about how to use [Microsoft Excel](https://en.wikipedia.org/wiki/Microsoft_Excel).

My intention and expectation is that we can speed through this content and spend most of the year focusing on how to manipulate data (contained in Excel, databases, and other formats) through Python. We will use several resources throughout this class, including [Python for Excel: A Modern Environment for Automation and Data Analysis](https://www.oreilly.com/library/view/python-for-excel/9781492080992/), which you can access through the [O'Reilly for Higher Education](https://learning-oreilly-com.eznvcc.vccs.edu/home/) account that NVCC provides you.


## What We'll Do In Class

Our main tasks for this week will be to gain access to the educational resources we will need, set up our development environments, and go through a (hopefully basic) Excel exercise.

I'll start today by introducing myself and going through the class syllabus and expectations. I hope to keep this part brief; after that, we'll move into some less-structured practice and setup.

1. If you don't yet have one, create an account for yourself on either [GitHub](https://github.com/) or [Codeberg](https://codeberg.org/). Then create a new repository named `ite140`. Throw a simple README file in there, and a simple index.html. Host this repo through GitHub Pages.

2. **Pre-assessment** - I'll use this in-class exercise to get a sense of how comfortable you are with Excel. Open Excel on your computer, and make a simple workbook that satisfies these requirements:
    - I want to adopt a puppy, and I need to buy all of the accessories that help me care for it. The pet store has [these products available](https://oakdome.com/k5/lesson-plans/excel/images/puppy-pet-adoption-price-list.gif). I have a total budget of $200 to spend.
    - Make a worksheet that contains each of these products and their prices. Next to each product, I would like to be able to enter the quantity that I want to purchase (e.g., I'll put a 1 next to "Puppy Adoption" because I'm adopting 1 puppy. I might put a 0 next to some options that I can't afford, or a number greater than 1 if I want to buy multiple of something).
    - The worksheet should total the amount that I've spent and should separately calculate how much is left in my budget.
    - To make it easy to use, color code the amount left in my budget. If I have a positive (or zero) amount left, highlight the cell in green. If I have a negative amount left, highlight the cell in red.
    - Presentation is everything in Excel - format the currency values appropriately, make the headers and labels stand out, and make it obvious where the calculated totals are.
    - Help me understand how my budget breaks down by creating a pie chart. Each item should be one wedge, and the sizes of the wedges should show how much total I'm spending on that item.

3. When you're done, commit this Excel workbook to your git repo and link to it from your index.html. We'll do a few more of these Excel workbooks, so it might be best to make a subdirectory for them.

## Homework, if needed

If you felt very comfortable with today's Excel exercise, then feel free to skip today's assignment.

If you need more practice with basic Excel, skim through Chapter 1 of this resource: [Beginning Excel 2019](https://openoregon.pressbooks.pub/beginningexcel19/front-matter/introduction/).
