<!--
Instructor notes: 
-->
## Lesson Objectives
By the end of this lesson, you should:
- Understand how to install and use Tampermonkey to add your own enhancements to websites
- Be able to load, explore, and manipulate datasets using Pandas.

## What we'll do in class

### Mini-Lesson - Tampermonkey
Before we start, we'll set up a tool that I've been using to work with Jupyter Notebooks on GitHub. Tampermonkey is a browser extension that allows you to run custom scripts on websites. To install Tampermonkey:

1. Go to the [Tampermonkey website](https://www.tampermonkey.net/) and install the extension for your browser.
2. Once Tampermonkey is installed, [visit this file in GitHub](https://github.com/MrJonesAPS/userscripts/blob/main/jupyter_github_colab.user.js).
3. Click on "Raw" and Tampermonkey should automatically detect and install the script.

After the script is installed, navigate to any `.ipynb` file in GitHub and click on the new yellow button that says "Open in Colab" to launch the notebook in Google Colab.

If you're interested in exploring more userscripts, check out [this awesome list](https://github.com/awesome-scripts/awesome-userscripts).

### Discuss potential Arlington 2050 Project
I've been planning an exciting project. It's a bit of a detour from our planned curriculum, so I only want to proceed if everyone is interested. I'll give my pitch, and then we'll take a class vote on whether to move forward with it.

### NumPy ufunc presentations
Each group will present the universal function (ufunc) they researched last class.

### Pandas practice
We'll work with the same group members as last class. Meet with your group and discuss the datasets that you each researched. As a group, select one dataset to explore together (I recommend choosing the simplest one).

Your group should practice with the same topics that we explored in our Pandas reading:
- Load the dataset into a Pandas DataFrame.
- Ensure each series (column) has the appropriate data type.
- Generate summary statistics for the numeric columns.
- Use the `loc` and `iloc` methods to access specific parts of the DataFrame.
- Modify the DataFrame by replacing values and adding new columns.
- Does your dataset have any missing values? (search for `NaN` or `NaT`)
- Does your dataset have any duplicates? Use the `drop_duplicates` method to remove duplicate data.

## Homework

### Finish your Pandas exercise
If you didn't complete the Pandas exercise today:
- Make sure everyone in your group has access to the work you've done so far.
- Divide up the remaining tasks among your group members.
- Complete the assignment and be prepared to present your findings in the next class.

### Read about Seaborn
There are lots of powerful data visualization libraries that work well with Pandas. The most popular (and the one that's introduced in our textbook) is called [Matplotlib](https://matplotlib.org/). That one is great but has a bit of a learning curve. Instead, we'll learn about Seaborn - which is built on top of Matplotlib, easier, and prettier. It integrates very well with Pandas DataFrames. For some inspiration, check out the [Seaborn gallery here](https://seaborn.pydata.org/examples/index.html).

Give [this tutorial](https://seaborn.pydata.org/tutorial.html) a skim. There's no need to write any code or submit anything for this reading—just familiarize yourself with Seaborn’s capabilities. Next class, we'll use Seaborn to make visualizations from our Pandas datasets.
