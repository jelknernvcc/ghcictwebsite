<!--
Instructor notes: 
-->
## Lesson Objectives
We'll continue playing with Spacy for Sentiment/Semantic analysis. Today's goal will be to add PCA into the mix.

### Continue Work From Last Class
Last class, we played with spell check, and we used vector similarity to perform [semantic search](https://en.wikipedia.org/wiki/Semantic_search). Today, we'll add Principal Component Analysis - we'll attempt to make a 2D scatter plot visualization of the comment data, and then we'll do some informal visual inspection to try to find outliers.

### Visual Outliers
We know that some of the comments in our survey should be discarded (eg on one postcard a child drew a picture of a shark). We'll attempt to find some of these "outliers" by visualizing the data with a 2D scatter plot. Hopefully, we'll see some obvious clusters and some obvious outliers.

Here are some tips:
- Start by using [Blu's notes about vector embeddings](https://github.com/1bMedina/ite140/blob/main/notebooks/word2vec.ipynb) to convert each comment to a vector
- Then use [Alex's Dimensionality Reduction](https://github.com/aelliott26/ITE140/blob/main/Jupyter_Notebooks/Dimensionality-Reduction.ipynb) code to collapse the data to two dimensions
- Then display this two dimensional data in a scatter plot. We'll need to be able to hover over outlier points and figure out what they say, so [You can use this sample code](https://plotly.com/python/hover-text-and-formatting/#customizing-hover-text-with-plotly-express)

As always, as you come up with outputs, add them to [these google slides](https://docs.google.com/presentation/d/1zFABvqd1Fw3owguRCrZi2I1pqQ6oz_dBwPXGr2riiSk/edit?usp=sharing) 