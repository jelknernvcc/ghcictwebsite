## Lesson Objectives
By the end of this lesson, you should:
- **Understand** the theoretical relationship between views and templates, and how that maps to Django's directory/file structure
- **Be very comfortable** creating your own simple template views


## What We'll Do In Class

### Quiz
As promised, we'll start with a simple reading quiz about templates.

### Practice making and rendering templates

Last class, we worked through adding the simplest 
template possible. It was a lot of steps. Today, I want you to go through the same process!

#### Steps Summary
Here's a quick summary of the steps that you'll need to follow to create a new template and register it with your Django application. You don't necessarily need to go in this order, but this is my recommendation:

1.  Add a record to `mysite/viewsbasics/urls.py`. (And remember, the `/viewsbasics/` part of this is already mapped in `mysite/urls.py`)
2. Create a new class and function inside of `mysite/viewsbasics/views.py` that sets up a dictionary and calls the `render()` function.
3. Create a new HTML file inside of `mysite/viewsbasics/templates/viewsbasics`. Include some Django template syntax to receive and interpret the dictionary variable.

## Homework

### Make more templates! 

You should make a total of **three** new templates (not counting our icecream example from Monday). Each template should:
- Be linked from your homepage
- Take an input parameter, using the URL template example from Dr. Chuck's video, and display it in the template
    - By the way - if we follow this format and use Django's rendering engine and ORM, we don't need to use the escape() function. These features all have escaping built in!

This assignment is due before the start of class on Friday. Take a peak to Friday's lesson to see how we'll grade it!

### Practice with vim

I've noticed that some of you are struggling because you aren't super comfortable with vim (yet!). We'll keep using vim to edit lots of files, so I strongly encourage you to do some self-study on your own. The best way to get comfortable with vim is [vimtutor](https://vimschool.netlify.app/introduction/vimtutor/). Even if you're already a vim expert, I recommend reviewing this periodically - I learn something new every time I go through it =)
