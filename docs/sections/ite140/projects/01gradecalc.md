# Grade Calculator Project

## Project Introduction

Probably the most common question I get from my students is about grades. This question takes many forms, such as:
- Can you explain why I have a B in this class?
- What can I do to increase my grade by 1%?
- If I submit the homework assignment that I missed, do you think that would bring my grade up to an A?

These are fundamental questions that should be much easier to answer than they are, and Excel is a fantastic tool to help answer this kind of question. I have a handy dandy Excel workbook that I whip out any time I get these kinds of questions. Instead of showing it to you, I'd like you to recreate it for yourself.

For this assignment, pick a class that you're taking this year. Maybe the one where you think you'll be most likely to have to ask these kinds of questions. For that course, study the course syllabus to understand how your grade is calculated. Also review the [Official APS Grading Policy](https://go.boarddocs.com/vsba/arlington/Board.nsf/files/CPRJVG4F0341/$file/I-7.2.3.34%20PIP-2%20Reporting%20Student%20Progress%20and%20Grades%20(Secondary)%20.pdf) to understand the role that `quality points` play in grade calculation.

Then create a workbook where you can input each of your assignment grades and it will calculate your final grades for each quarter and for the year.

We'll also use this project to practice the storytelling part of data analysis. So we'll each present our calculators in class on Tuesday, September 17.

For this project, we're all working on recreating grade calculators for different class syllabus-es
, so you should start your sharing by telling us about the class you've chosen to build a calculator for
, explaining the policies, and why you chose that class.

## Project Requirements
You should build a functional, polished, professional looking grade calculator. 

Your grade calculator must include:

- A documentation tab that includes the language from your course syllabus that explains how your grade is calculated
- whatever functions and organization you need to accurately calculate your course grades (including both numerical average and quality points).
- A scenario evaluation tab, with a few sample scenarios setup



## Sample Project
In case it's helpful, [I've uploaded mine here](../goals/data/WebDev_Grade_Calculator.xlsx).

## Submission Instructions
Submit your grade calculator by posting to your github repo and linking it from your website.
Complete this before the beginning of class on Tuesday, September 17* 

## Grading
I will assign a single letter grade for this project, and it will be used for your week 3 grade. 
Here is a rubric that captures my expectations.

<style>
table, th, td {
  border: 1px solid black;
  border-collapse: collapse;
}
</style>
| **Category**                    | **A**                                                                                                      | **B**                                                                                          | **C**                                                                                          | **D**                                                                                          | **F**                                                                                          |
|----------------------------------|------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
| **Documentation Tab**            | Thorough documentation, including clear, accurate language from the course syllabus on grade calculation.   | Documentation is mostly complete with minor details missing or unclear.                       | Some documentation is included, but it may be incomplete or unclear.                           | Minimal documentation, missing key elements or unclear explanations.                           | No documentation provided or largely inaccurate.                                                |
| **Grade Calculation Accuracy**   | Calculator accurately calculates grades using both numerical averages and quality points.                   | Calculator mostly accurate, but may contain minor errors in grade calculation.                 | Calculator has several errors in grade calculation, but still functions somewhat.               | Calculator has major errors in grade calculation, barely functions as intended.                 | Calculator does not work or does not calculate grades accurately at all.                        |
| **Scenario Evaluation Tab**      | Scenarios clearly set up and demonstrate different grade outcomes effectively.                             | Scenarios are mostly clear, with only minor issues in setup or outcomes.                       | Scenarios are incomplete or do not fully demonstrate the grade outcomes.                       | Scenarios are poorly set up or do not represent useful evaluations of grade outcomes.           | No scenarios are included or are entirely incorrect.                                            |
| **Polish and Professionalism**   | Workbook is polished, organized, easy to read, and visually professional.                                   | Workbook is mostly well-organized, with minor formatting or readability issues.                | Workbook is somewhat organized, but may lack clarity or professionalism in its presentation.    | Workbook is disorganized, hard to read, and lacks polish or professionalism.                   | Workbook is messy, unorganized, and visually unappealing.                                       |
| **Presentation**                 | Clear, confident presentation explaining the class chosen, grade policies, and the calculator functionality. | Presentation is mostly clear, with only minor issues in explanation or delivery.               | Presentation is somewhat unclear or incomplete, but covers the main points of the project.      | Presentation is unclear, lacks important details, or is not well-prepared.                     | No presentation or extremely poor explanation of the project and grade calculator functionality. |


## Footnotes
1. as always, I'll use github commit timestamps to determine submission times

2. "Quality Points" actually means two different things.    
    - First, your final grade for the year is is a letter grade, not a numeric grade. If you look at your transcript, you only see a letter grade. To calculate your GPA, we use Table 2 below. This is where there is a difference in points between AP and IB classes. To avoid confusion, I've called these "GPA Points" instead of "Quality Points" in the table.
    - To get to your final grade for the year, we calculate your average two different ways and keep whichever method gives a higher letter grade:
        - First, we calculate a (weighted) numeric average of the numeric grades received each quarter.
        - Second, We ignore the numeric grade for the quarter and consider only the letter grade. We use Table 1 below to map each letter grade to "Quality Points" and calculate a (weighted) average of using this new number. We look up that number in Table 2 to find the final letter grade for the year.

3. Here are two tables to help you get started. You should be able to copy/paste them into Excel.

Table 1: Quarter letter grades
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

<br>

Table 2: Final Grade Calculation
| QP Average | Letter Grade | GPA Points     | AP GPA     Points |
|------------|--------------|----------------|-------------------|
| 0          | E            | 0              | 0                 |
| 0.75       | D            | 1              | 2                 |
| 1.25       | D+           | 1.5            | 2.5               |
| 1.75       | C            | 2              | 3                 |
| 2.25       | C+           | 2.5            | 3.5               |
| 2.75       | B            | 3              | 4                 |
| 3.25       | B+           | 3.5            | 4.5               |
| 3.75       | A            | 4              | 5                 |