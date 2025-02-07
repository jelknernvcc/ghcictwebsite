<!--
Instructor notes:

-->

## What we'll do in class

### Class Charter
I have a draft! I'd love some feedback. [See the draft here](https://docs.google.com/document/d/1YJwfaeJMPwO4wveRAYpc40Xwx0RQHpeF-7e4urK-Ndg/edit?usp=sharing)

### Grade Calculator Presentations 
We'll start class with our grade calculator presentations. [See the project details here](../projects/project.html?id=01gradecalc). 

### Environment Setup, NVCC Login, Markdown
For the next few classes, we'll be working with [Jupyter Notebooks](https://jupyter.org/).

There are a few ways to do this, but I'll recommend that we use Jupyter Notebooks in [Visual Studio Code](https://code.visualstudio.com/). We'll also publish our Notebooks to our Github repos.

We'll spend some time in class setting up our Development Environments. As a first step, I'd like to try setting up [pyenv](https://realpython.com/intro-to-pyenv/). To do that, open a Terminal and try running this code:

`curl -L https://github.com/pyenv/pyenv-installer/raw/master/bin/pyenv-installer | bash`

After that, run this in the terminal:

`PYENV_ROOT="${HOME}/.pyenv"`

`echo "export PATH=\"${PYENV_ROOT}/bin:\$PATH\"" >> ~/.zshrc`

`echo "eval \"\$(pyenv init -)\"" >> ~/.zshrc`

`echo "eval \"\$(pyenv virtualenv-init -)\"" >> ~/.zshrc`

I'm not positive that you'll have the right permissions to do this. If it works, we'll talk more about what it is and how to use it.

We'll also learn about [Markdown](https://www.markdownguide.org/getting-started/) - a useful markup language for text editing that works well with Jupyter. Our goal will be to create and publish a simple Notebook that contains only Markdown. 

For the next few classes, we'll also be using an e-textbook, **Python for Excel**. You can access this for free  through your VCCS account at [O'Reilly
for Higher Ed](https://www-oreilly-com.eznvcc.vccs.edu/library-access/) 


## Homework

### Start Learning about Numpy, and take notes in a Jupyter Notebook

For Homework today, work through Chapter 4 of Python for Excel, which introduces NumPy. Produce your own Jupyter Notebook that does two things:

- Use Markdown to summarize some of the most important topics. Here are some topics I'd expect you to include:
    - The differences between a NumPy ndarray and nested lists in Python
    - How to construct an ndarray
    - NumPy's axis numbering system
    - How to access and modify values in an ndarray
    - Viewing vs Copying (this topic is important, and I don't think the text does a good enough job explaining it. Write a few examples to play with it and make sure you feel comfortable with the difference)
    - NumPy operations - vectorization, broadcasting, and ufuncs
- Write some Python cells that play with these concepts. You're welcome to reproduce some of the examples from the book, but at least use your own numbers. Try changing some of the dimensions or making up your own examples to test your understanding.

I'm looking for thoughtful blending of Markdown and Python - don't just write a bunch of Markdown at the top and a bunch of Python at the bottom.


### Extension: Explore publishing with Jupyter-Books
We'll discover today that Jupyter Notebooks are very powerful, and that they lose a lot of their power when we view them on Github Pages. There is an awesome tool called Jupyter-Books that does a better job of publishing Jupyter Notebooks online. [Here is a nice example of what it looks like](https://python.quantecon.org/sir_model.html). If you're interested, I'd love to have someone explore this and share it with the rest of the class!

## Next Class

I will be out at a meeting next class. Please check for the website.

I'll expect you to do the same thing next class, but for the next chapter. That chapter is long and the content is more challenging, so I'll choose a few sub-sections for you to read.