## Lesson Objectives
By the end of this lesson, you should:


## What We'll Do In Class

### Quiz
No reading quiz!


### More Git Collaboration Tips- PRs

Now that we're sharing git repos, we'll take some time to learn a better tool for
coollaboration - pull requests ("PRs"). I'll give a brief intro on the whiteboard,
and then you'll use the activity below to practice.

I've created a new repo called [https://github.com/MrJonesAPS/students/](https://github.com/MrJonesAPS/students/), and I've addded everyone in class as a collaborator
on that repo. Our goal as a class will be to simulate how large software organizations
handle collaboration.

### PR Practice
Follow the steps carefully!x

#### **Step 1: Create an Issue**
1. Go to the **Issues** tab in this repository.
2. Click **New Issue**.
3. Title your issue: `Add name - <Your Name>` Example: `Add name - Alice`
4. In the description, write:  "I am adding my name to the contributors file."
5. Click **Submit new issue**.


#### **Step 2: Create a Branch**
    1. Open your terminal or GitHub Desktop.
    2. Clone this repository if you haven’t already:

    `git clone <repository-url>`

    3. Navigate into the repository:

    `cd <repository-name>`

    4. Create a new branch with your name:

    `git checkout -b add-name-<your-name>`


    Example:

    `git checkout -b add-name-alice`

#### Step 3: Add Your Name

    Open `README.md` in a text editor.
    Add your name on a new line.
    Save the file.

#### Step 4: Commit and Push Your Changes

    Stage your changes:

    `git add README.md`

    Commit your changes with a message:

    `git commit -m "Added my name"`

    Push your branch to GitHub:

        `git push origin add-name-<your-name>`

#### Step 5: Open a Pull Request

    1. Go to the repository on GitHub.
    2. Click Pull Requests > New Pull Request.
    3. Select your branch (add-name-<your-name>) as the source.
    4. In the description, write:

        Closes #<issue-number>

        Example:

        Closes #12

    5. Click Create Pull Request.


#### I'll go through and close all the PRs after class


## Homework


Continue working on the project - but we'll have more time in class next time
and I'll have the official project writeup then.

For the proejct, I'll expect that everyone makes at least one issue, branch,
and PR!

