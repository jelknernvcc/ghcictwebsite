<!--
Instructor notes: 
-->
### Lesson Objectives
By the end of this lesson, you should:
- Understand the basics of NumPy and its efficiency in handling large datasets.
- Know how to use Jupyter magic commands, specifically `%%timeit`, to measure code execution time.
- Be able to compare the performance of traditional Python loops with NumPy ufuncs.
- Be able to identify and investigate an open dataset

### What we'll do in class
Thanks for doing the reading about Numpy and Pandas last week! We'll start class with a discussion of everything that you read and practiced with (we'll include Jupyter, Markdown, and Git in this conversation). After that,  we'll focus on practicing with these concepts. 


#### Assignment: Explore NumPy Efficiency
I hope your takeaway was that NumPy is pretty cool - it's specifically engineered to make working with large datasets very efficient. We won't directly use NumPy much, but its power will be under the hood of most Python data stuff that we'll do. For this assignment, you'll quantify just how efficient it is.

Complete this assignment in a Jupyter notebook and commit to one group member's git repo. We'll do this assignment in groups, and at the beginning of next class each group will share. As always, make sure to include a thoughtful amount of Markdown in your notebook that explains your reasoning and conclusions.

We'll also discuss a bit about 'magic commands' (aka 'magics') - special functions that are built into Jupyter. You should also make use of `%%timeit` - a magic command that allows you to quickly measure the execution time of a piece of code. We will play with this command in class together, and you can read more at the [official IPython documentation on timeit](https://ipython.readthedocs.io/en/stable/interactive/magics.html#magic-timeit).

#### Instructions
1. **Setup**: Create a large NumPy 2D array of random integers (1 million rows x 10 columns). You can use `rng.integers` as described in the [NumPy quickstart documentation](https://numpy.org/doc/2.0/reference/random/index.html#random-quick-start)

2. **Task 1**: Using traditional nested for loops, visit and modify each element of the array (use [ndarray.shape](https://numpy.org/doc/stable/reference/generated/numpy.ndarray.shape.html#numpy.ndarray.shape)). Execute and time this function using `%%timeit`. For an extra challenge, you might consider writing this a few ways - using loops, list comprehension, etc and seeing what is fastest.

3. **Task 2**: Do the same thing to the same array, but use the corresponding NumPy ufunc. Again, execute this code with `%%timeit`.

4. **Task 3**: Compare the two timings in a Markdown block. Explain:
    - Both versions of your code
    - Quantify the efficiency difference between the traditional calculation and the ufunc.

We will start next class with presentations.

#### Group Assignments
<style>
table, th, td {
  border: 1px solid black;
  border-collapse: collapse;
}
</style>
| Group Members            | Function    |
| ------------------------ | ------ |
| Adam, Miguel, and Lehiem | natural log    |
| Blu and Rachel           | sin    |
| Jack and Alex            | modulo    |

Each group should start by discussing your NumPy and Pandas notebooks, and working together to resolve any confusion with the content, with Jupyter notebooks, or with publishing your work to Github.


### Homework - Find an open dataset
Next class, we'll play with Pandas. Everyone should find a dataset that you're interested in using.

To do this, do a google search for "open dataset" and explore around until you find one that looks interesting.

For now, try to find a dataset that looks like it has a very simple format. Unless you want an extra challenge, look for data that is presented in a single file, and stay away from data presented in JSON.

For the dataset that you choose, do some additional investigation to see if you can find out where it came from. Be prepared to discuss these questions next class:

- Where did the data come from?
- How recently was it compiled?
- How was it gathered? Why?
- Who owns the data? With what usage rights is it being made available?



