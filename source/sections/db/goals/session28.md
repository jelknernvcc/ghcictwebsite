<!--
Instructor notes: 
-->
## Lesson Objectives
By the end of this lesson, you should:
- Understand the kinds of anomalies that can occur in databases
- Understand that normalization prevents data anomalies
- Know the four normal forms
- Be able to suggest changes to a database to improve its normalization

## What we'll do in class

We'll work through a database normalization exercise together. We'll puzzle through this example together and hopefully we'll discover some of the important concepts related to normalization.

| Animal        | Name     | Date    | Weight     | Food                     | Feeder |
| ------------- | -------- | ------- | ---------- | ------------------------ | ------ |
| Hippo         | Moo Deng | March 3 | 30 kg      | 3 Cabbages, 1 Watermelon | Sharon |
| Horse         | Mr. Ed   | March 3 | 925        | 1 bale of hay            | Alfred |
| Horse         | Mr. Ed   | March 3 | 925        | 2 apples                 | Alfred |
| Crickets      |          | March 3 |            | 1 sweet potato           | Kelly  |
| Komodo Dragon | Spike    | March 3 | 100.2 pounds | 30 crickets              | Kelly  |
...
| Komodo Dragon | Spike    | March 4 | 100.2 pounds | 1 rabbit              | Kelly  |


## Homework

Review the rules for 1NF summarized in the first 10 minutes of [this video](https://www.youtube.com/watch?v=GFQaEYEc8_8).