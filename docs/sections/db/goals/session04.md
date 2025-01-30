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
Today we'll introduce our first major project - an Excel grade calculator. [See the project details here](../projects/project.html?id=01gradecalc)


## Homework, if needed

If you felt very comfortable with today's Excel exercise, then feel free to skip today's assignment.

If you need more practice with the functions we learned today, you'll find VLOOKUP in Chapter 3 section 2 of [Beginning Excel 2019](https://openoregon.pressbooks.pub/beginningexcel19/front-matter/introduction/). Here is a [direct link](https://openoregon.pressbooks.pub/beginningexcel19/chapter/3-2-logical-and-lookup-functions/). XLOOKUP is not covered in that textbook, so here is [Microsoft's official documentation](https://support.microsoft.com/en-us/office/xlookup-function-b7fd680e-6d10-43e6-84f9-88eae8bf5929).
