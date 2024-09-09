<!--
Instructor notes: class went well!
- In class, we worked with the SuperStore dataset.
- Two things that make a successful data analyst: organization and story telling
- and we're practicing the story telling with the presentations at the beginning of class
- Talked about how we'll formally define all this stuff later, for now, trying to develop a "spidey sense"
- Looked at SuperStore dataset:
    - Discussed / identified the PK
        - should it be the surrogate ID column at the front?
        - or orderid / product
    - identified that customer name and id don't need to be repeated
        - Discussed update anomalies
        - in Excel - copy orderid, customer name, customerid into a new sheet, then used "remove duplicates"
        - Used VLOOKUP to put it back
- Introduced gradebook assignment to practice VLOOKUP
    - Did the first few together, based on the APS grade tables:
        - Given a letter grade, lookup the quality points
        - given the numerical average, look up the letter grade (needs ranged lookup)
        - Given the average QP, lookup the final letter grade
-->

### What we'll do in class

We'll start today by showing off the weather reports that we all made for our imaginary friends who are planning to move to Arlington. As before, we'll work hard to encourage and celebrate our peers' accomplishments.

After that, we'll start our slow metamorphosis from Excel to Databases. We'll stay in Excel today, but we'll start to talk about data organization and [normalization](https://en.wikipedia.org/wiki/Database_normalization), which are important concepts to understand when we start designing databases.

We'll return to the [SuperStore data](./data/SuperStoreUS-2015.xlsx) for our discussion of Normalization.


### Grade Calculator
Probably the most common question I get from my students is about grades. This question takes many forms, such as:
- Can you explain why I have a B in this class?
- What can I do to increase my grade by 1%?
- If I submit the homework assignment that I missed, do you think that would bring my grade up to an A?

These are fundamental questions that should be much easier to answer than they are, and Excel is a fantastic tool to help answer this kind of question. I have a handy dandy Excel workbook that I whip out any time I get these kinds of questions. Instead of showing it to you, I'd like you to recreate it for yourself.

For this assignment, pick a class that you're taking this year. Maybe the one where you think you'll be most likely to have to ask these kinds of questions. For that course, study the course syllabus to understand how your grade is calculated. Also review the [Official APS Grading Policy](https://go.boarddocs.com/vsba/arlington/Board.nsf/files/CPRJVG4F0341/$file/I-7.2.3.34%20PIP-2%20Reporting%20Student%20Progress%20and%20Grades%20(Secondary)%20.pdf) to understand the role that `quality points` play in grade calculation.

Then create a workbook where you can input each of your assignment grades and it will calculate your final grades for each quarter and for the year.

Here are two tables to help you get started. You should be able to copy/paste them into Excel.

| Begin Grade | End Grade | Letter | Quality Points |
|-------------|-----------|--------|----------------|
| 0           | 59        | E      | 0              |
| 60          | 66        | D      | 1              |
| 67          | 69        | D+     | 1.5            |
| 70          | 76        | C      | 2              |
| 77          | 79        | C+     | 2.5            |
| 80          | 86        | B      | 3              |
| 87          | 89        | B+     | 3.5            |
| 90          | 100       | A      | 4              |


| QP Average | Letter Grade |
|------------|--------------|
| 0          | E            |
| 0.75       | D            |
| 1.25       | D+           |
| 1.75       | C            |
| 2.25       | C+           |
| 2.75       | B            |
| 3.25       | B+           |
| 3.75       | A            |

Next class, we'll continue working with this sheet to explore Excel's "What-if Analysis" tools.


## Homework, if needed

If you felt very comfortable with today's Excel exercise, then feel free to skip today's assignment.

If you need more practice with the functions we learned today, you'll find VLOOKUP in Chapter 3 section 2 of [Beginning Excel 2019](https://openoregon.pressbooks.pub/beginningexcel19/front-matter/introduction/). Here is a [direct link](https://openoregon.pressbooks.pub/beginningexcel19/chapter/3-2-logical-and-lookup-functions/). XLOOKUP is not covered in that textbook, so here is [Microsoft's official documentation](https://support.microsoft.com/en-us/office/xlookup-function-b7fd680e-6d10-43e6-84f9-88eae8bf5929).
