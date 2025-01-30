<!--
Instructor notes: 
-->
## What we'll do in class


### Present Data Model Project
I'm looking forward to seeing presentations from the data model project!

### Project Check-in 1
Everyone will share what they're thinking of doing for their project

### Connect SQL to Excel

As we prepare for our final project, we'll want to be able to access our SQL data from Excel. Pandas is a great way to do this! We'll talk through this sample code, and we'll make sure that we get it to work on everyone's computers.

<blockquote>
<pre>
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

</pre>
</blockquote>

## Homework
- Continue working on your project, and be prepared for our second check in next time we meet. [See the full write-up for this project here](https://ict.gctaa.net/sections/db/projects/project.html?id=02final)
- If you didn't complete course evaluations yet, please do!

<p style="color: red;">
To do that, go here:
<a href="https://nova.mce.cc">https://nova.mce.cc</a> and login: your username is your VCCS email, and your password is your 7-digit NOVA ID (which I can help you find).
NOVA really wants student participation here, and
your willingness to complete this task reflects well on your instructors, so
thank you in advance for doing it.
</p>