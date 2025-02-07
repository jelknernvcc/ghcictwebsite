## Lesson Objectives
By the end of this lesson, you should:

* **understand** how to use Jinja template features
* **be able to** create simple calculators that combine Python and Jinja code.


## What We'll Do In Class

### Grade the template homework

You know how some teachers make students trade papers to grade each-other's homework? We're going to do the same thing, but virtually!

For this activity, you'll start up your server and then exchange IP addresses with a partner. You and your partner will both point your browser to each-other's websites, and we'll provide a rubric that you'll use to give them a grade.

### Pass variables to templates
You'll take our templates a bit further this time - we'll make our templates
valid HTML and add some GET parameters.

We'll work through two methods for incorporating GET parameters into your
templates - using the request's get() function, and using URL patterns.

## homework
For homework, go back to the three templates you made last time, and make them dynamic.
First, complete each page by making it valid HTML. Then, adjust each so that it takes
a URL parameter and renders it in the template.

Remember that takes a few steps:
- First, you'll need to modify `urls.py` to tell it the name of the parameter you're expecting
- Then, you'll modify `views.py` to add the variable to the inputs for the `get()` function
and to pass that variable as part of a dictionary to the `render()` function.
- Finally, you'll need to use django template syntax in your HTML file to 
access the variable.

At the beginning of next class, we'll open each-other's django apps and 
grade this assignment.