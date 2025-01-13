<!--
Instructor notes: 
-->
## Lesson Objectives
By the end of this lesson, you should:
- Understand
- Know
- Be able to

## What we'll do in class

### Course Evaluations
<p style="color: red;">
First, please complete your course evaluations. To do that, go here:
<a href="https://nova.mce.cc">https://nova.mce.cc</a> and login: your username is your VCCS email, and your password is your 7-digit NOVA ID (which I can help you find).
NOVA really wants student participation here, and
your willingness to complete this task reflects well on your instructors, so
thank you in advance for doing it.
</p>

### Finish up Data Modelling Project
I'll give the first ~30 minutes of class to wrap up the data modelling project that you've been working on. As you transition into writing the sql scripts and mocking up the data, I'd like each team member to take responsibility for at least one table.

For credit, combine everyone's work into a single sql file and commit it to one of your git repos.

At the beginning of Wednesday's class, we'll present this project. Everyone should explain the table(s) they worked on.


### Connect SQL to Excel

As we prepare for our final project, we'll want to be able to access our SQL data from Excel. Pandas is a great way to do this! We'll talk through this sample code, and we'll make sure that we get it to work on everyone's computers.


```
###
# Before running this, you'll need to set the password
# as an environment variable:
#   export PGPASSWORD="your_password"
###


import os
from sqlalchemy import create_engine
import pandas as pd

# Get password from environment variable
password = os.getenv("PGPASSWORD")

# Build the SQLAlchemy connection string
db_name = "seinfeld_foods"
user = "cjones"
host = "dbserver.gctaa.net"
port = "5432"

connection_string = f"postgresql+psycopg://{user}:{password}@{host}:{port}/{db_name}"

# Create the SQLAlchemy engine
engine = create_engine(connection_string)

# Execute a query using Pandas
query = "select * from foods f JOIN food_types t on f.type_id=t.id limit 10;"
df = pd.read_sql_query(query, engine)

# Display or save the DataFrame
df.to_excel("output.xlsx", index=False)
```

### Introduce your final project

As I hinted last time, your final exam for this class will be a project. [See the full write-up for this project here](https://ict.gctaa.net/sections/db/projects/project.html?id=02final), and I'll go over the requirements in class.

## Homework
- Wrap up your data model activity. Be prepared to present the tables you worked on in class
- Start thinking about your project! We'll have our first check-in next class