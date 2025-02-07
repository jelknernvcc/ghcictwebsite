<!--
Instructor notes: 
-->
## Lesson Objectives
We'll continue playing with Spacy for Sentiment/Semantic analysis

Next, let's start playing with SpaCy for sentiment analysis. Here are some tasks that we'll work through:

### Sentiments
Continue with the work from last class realted to sentiment analysis. The goal is to generate histograms that represent sentiment distributions. See last class's page for more instructions and sample code

### Semantic Search
Start by reviewing [Blu's notes about vector embeddings](https://github.com/1bMedina/ite140/blob/main/notebooks/word2vec.ipynb).

We'll want to pass the text through a spellchecker before this step. [here's some example code that does that](https://github.com/MrJonesAPS/ITE140/blob/main/2050/spell_check.ipynb).

Once we have the vector embeddings, let's build a toy search engine. I haven't done this exercise yet, but here's what I imagine:
- The user can type in any prompt
- The code should embed that prompt using the same spacy code as we used to calculate embeddings for all of the comments
- Do a search through the dataframe to find the comment that has the highest similarity to the prompt and return it
    - Should the search return a single comment? Or a few nearest neighbors? Play with it!

For example: if the prompt is "missing middle", the top few comments might be something like "I support missing middle", "missing middle is ruining our county", etc. (Remember - semantics and sentiment are very different!)
