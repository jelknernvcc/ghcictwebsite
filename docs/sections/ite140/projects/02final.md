# ITE140 Final Project

# Project Introduction

We've learned a ton this semester, all following the theme of structuring and understanding data. For this project, we'll put it all together into one cohesive project.

In this project, you'll:
- Model a database using an ER diagram
- Implement that database using Postgres
- Populate your database with some sample data
- Create some useful views on your database
- Use Pandas to extract data from your database into Excel
- Develop some helpful Excel summary reports based on your data

# Resources
You'll continue to find these two resources very helpful for this project:
- [Postgres Cheat Sheet](https://gist.github.com/Kartones/dd3ff5ec5ea238d4c546)
- [Postgres Data Types](https://www.postgresql.org/docs/current/datatype.html)

# Project Requirements

## ER Diagram

For this project, you'll draw your own entity-relationship diagram on a topic of your choice. We will discuss some possible choices in class.

Your diagram must represent at least 5 entities. Each entity must have:

- a name, reasonable attributes, with appropriate data types.
- Primary Keys / Foreign Keys identified
- Cardinality identified using [crows-feet notation](https://vertabelo.com/blog/crow-s-foot-notation/)
- For full credit, you must have at least one pair of entites that have a many-to-many relationship, which will be represented using a join table.

You are welcome to hand-draw this diagram (my preferred method, but I need to be able to read your hand-writing), or to find an use any computer-aided tool (I really like [excalidraw](https://excalidraw.com/)). Either way, you'll include a screenshot in your final report.

## Database Implementation
You'll create a single sql script that creates this database and loads some data into it.

A few things to consider for this step:

- Idempotency - Remember that your sql script needs to be **idempotent**. I should be able to run this script any number of times, regardless of the initial state of the database, and be guaranteed the final state.
- Views - Include at least one helpful view that you'll use to extract data to your Excel sheet.
- Sample Data - remember that we used [Mockaroo](https://www.mockaroo.com/) to generate sample data.
- No Passwords - remember the environment variable trick that we discussed in class. Make sure you don't include your password in the file!

## Pandas Extraction
Write a Python script that runs a `SELECT *` from your view and dumps it into an Excel sheet. 

See [Session 36](https://ict.gctaa.net/sections/db/goals/session.html?num=36) for the starter code I shared for this part.

## Excel Analysis
Create a separate Excel sheet and use **Power Query** to load the data from your `output.xlsx` file.

In this new Excel sheet, create some summary reports that might be helpful for someone who wants to analyze your data. Your reports should at least include at least one **pivot table** and at least one **pivot chart** with some useful slicers. Review our weather data project to jog your memory about how to make these.


## An alternative!
There is lots of professional software that automates this process of connecting to a database and generating reports. If anyone is interested in exploring one of these tools instead of the Excel part of this project, let me know! I've been exploring a tool called [Metabase](https://www.metabase.com/) with a capstone student this year and have some ideas!

# Submission Instructions
Your entire project should be summarized in a single Markdown file linked from your github homepage. This should be completed before class time on Monday, and you will give a brief presentation to the rest of the class then.

Your Markdown file should include a short write-up of each of these steps, and should link to:
- A screenshot of your ER diagram
- Your sql script
- Your python script that extracts from the database
- Your Excel document with reports

# Checkpoints
There are a lot of steps to this project! To encourage everyone to keep making reasonable progress, we'll have a few group checkins:
- On Wednesday, January 15 - be prepared to share the topic that you'll be using for your data model
- On Tuesday, January 21 - everyone will present a first draft of your ER diagram
- On Thursday, January 23 - I'll have one-on-one check-ins with each of you to make sure you're making good progress.

# Grading
# ITE140 Final Project Grading Rubric

This project will be graded on a 14-point scale. 
Partial credit will be given in cases where these requirements are partially met.

| Category                  | Criteria                                                                                        | Points |
|---------------------------|-------------------------------------------------------------------------------------------------|--------|
| **ER Diagram**            | Diagram includes at least 5 entities with appropriate attributes and data types                 | 1      |
|                           | Primary Keys and Foreign Keys are correctly identified                                          | 1      |
|                           | Cardinality is identified using crows-feet notation                                             | 1      |
|                           | Includes at least one many-to-many relationship represented with a join table                   | 1      |
| **Database Implementation** | SQL script is idempotent and runs without errors                                              | 1      |
|                           | Script creates all required entities, relationships, and sample data                            | 1      |
|                           | Includes at least one helpful view                                                              | 1      |
| **Pandas Extraction**     | Python script connects to the database and extracts data from the view                          | 1      |
|                           | Extracted data is written to an Excel file (`output.xlsx`)                                      | 1      |
| **Excel Analysis**        | Excel reporting document connects to `output.xlsx` using PowerQuery                             | 1      |
|                           | Excel document includes at least one pivot table with meaningful data                           | 1      |
|                           | Excel document includes at least one pivot chart with slicers                                   | 1      |
| **Documentation**         | Markdown file in git repo gives a project overview and includes brief discussions of each step  | 1      |
| **Presentation**          | Presentation is clear, concise, and explains the project’s goals and outcomes                   | 1      |
