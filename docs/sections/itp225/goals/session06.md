## Lesson Objectives
By the end of this lesson, you should:

- **Understand** the organization of a Django project
- **Be able to** use generic views to create a minimal app that uses the full MVT stack 

## What We'll Do In Class

Today is an exciting day - over the past several weeks we've spent a lot of time
getting comfortable with models, and with views and templates. Now we'll 
finally use Django's `generic views` to tie these parts all together.

### New Django Chart

We've been working on our own remix of Dr. Chuck's Django diagram. We're all learning
this together, so we want to share and get your feedback!

[You can find our latest version here](../resources/django_flow_chart_cjones_remix.pdf)

### 100 Bottles

We'll show off an interesting project that Jeff recently worked on
to explore more about templates: "100 Bottles ..." page he added to Chris
and his [django_projects](https://git.gctaa.net/ACCICT/django_projects) repo.

The motivation of this little talk is questions Lary asked last class, so the
focus will be on how he went from an *idea* to a working page:

- connecting a
``urls.py`` pattern with a 
- ``views.py`` view, and 
- rendering a template with some fun template engine code to create
- the HTTP response page

### Polls

The django_projects repo includes a sample app called `polls` that includes
some generic views and is based on the [official Django tutorial](https://docs.djangoproject.com/en/4.2/intro/tutorial01/). We'll spend some time reading through that example
and making sure we all understand how it works.

### ToDo

Chris's favorite practice project to learn a new web framework is to build a 
todo list. A functioning todo list requires all three components of the MVT template

In class, we'll discuss the steps that we'll need to go through to setup a new app,
then we'll each work on going through those steps on our own.

For now, our goal will be to setup the app and models, and to create a `ListView`
and a `DetailView`. Just like the polls app, we'll use the admin interface to
add items for now. We'll tackle forms next =)


#### Steps for Todo List
1. Create a new app: `manage.py startapp`
2. Register our app in `settings.py`
3. Write our models in `todo/models.py`
    - One model, called `item`, only a text description
4. Register our model in `todo/admin.py`
5. Migrate: `python3 manage.py makemigrations` `python3 manage.py migrate`
5. Login as admin and create some todo items
6. Make views (using genericviews: ListView and DetailView)
7. Tell DJanngo about those views in `todo/urls.py`
    - Tell the Django project about this urls file on project-level `urls.py`
8. Make new templates
    - Make templates folder
    - Write HTML files

## Homework

This todo app will take a while, and we want to make sure that we're very
comfortable with how this all works. Spend your allotted 90 minutes of homework time
pushing forward on this activity (we'll use git commits for accountability), and we'll check in on progress next time.