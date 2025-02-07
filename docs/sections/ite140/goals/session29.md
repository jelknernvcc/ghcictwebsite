<!--
Instructor notes: 
-->
## Lesson Objectives
By the end of this lesson, you should:
- Understand
- Know
- Be able to

## Warmup
As a warmup, we'll review the rules for first normal form. We'll practice with a
new example.

### Orders Table
This time, we're working with a cake bakery. Here's an excerpt from the Excel spreadsheet that they've been using to keep track of their orders:

| Customer Name | Contact Info         | Order ID | Order Date | Layers | Cake Layers                | Decorations                 | Total Price | Payment Method |
| ------------- | -------------------- | -------- | ---------- | ------ | -------------------------- | --------------------------- | ----------- | -------------- |
| Alice Smith   | alice@example.com    | 2001     | 2024-04-10 | 2      | Vanilla, Chocolate         | Sprinkles, Edible Flowers   | $45.00      | Cash           |
| Bob Johnson   | 555-1234             | 2002     | 04/11/2024 | 3      | Red Velvet                 | Fondant Decorations         | 50.00       | Credit Card    |
| Carol Lee     | carol.lee@domain.com | 2003     | April 12   | 1      | Lemon, Blueberry           | Citrus Zest                 | $40.75      | Cash           |
| David Kim     | (555) 567-8901       | 2004     | 2024/04/13 | 3      | Carrot, Spice, Chocolate   | Cream Cheese Frosting       | $60.00      | Cash           |
| Alice Smith   | alice@example.org    | 2005     | 04-14-2024 | 4      | Chocolate                  | Sprinkles                   | 30.00       | Debit Card     |
| Eva Green     | eva.green@mail.com   | 2006     | 2024-04-15 | 3      | Strawberry, Vanilla, Mango | Fresh Fruits, Whipped Cream | $70.25      | Cash           |
| ...           | ...                  | ...      | ...        | ...    | ...                        | ...                         | ...         | ...            |


## Dependencies
Before we dive into more advanced versions of normalization, we'll need to get comfortable with dependencies.

There are three types of dependencies that we need to be able to identify: functional, partial, and transitive

We'll start by looking for examples of each of these in the above example, and then we'll play with this more abstract example:

| A   | B   | C   | D   | E   |
| --- | --- | --- | --- | --- |
| a1  | b1  | c1  | d1  | e1  |
| a1  | b2  | c1  | d2  | e2  |
| a2  | b1  | c2  | d1  | e1  |
| a2  | b2  | c2  | d2  | e2  |
| a3  | b1  | c3  | d3  | e3  |
| a3  | b2  | c3  | d4  | e4  |

We'll work together to identify each of the types of dependencies in this example

## 2NF, 3NF
Once we have a good understanding of dependencies, we'll work through second- and third normal forms.

For practice, we'll go all the way through the cake shop example.


## Homework, if needed
Again, [this video is a great review for the normal forms](https://www.youtube.com/watch?v=GFQaEYEc8_8)

And for a more formal explanation of the normal forms, relational algebra, and all of the axioms that we didn't cover, [see this online textbook](https://opentextbc.ca/dbdesign01/chapter/chapter-11-functional-dependencies/)

We'll assign practice examples at the end of class.

For homework, I'd like every to take a crack at normalizing these databases.

I'd like everyone to take a crack at:
- Coming up with a reasonable data type for each column
- Finding the right PK
- Identifying each of the types of dependencies
- Re-structing the tables as necessary to get them to 3NF
- Note down any reasonable assumptions you made based on your real-world knowledge of the business 

Please do this in a Markdown file in your repo, before next class. I'll give some tips about working with tables in Markdown.

I'll count this as a grade, and we'll start next class by sharing what we came up with.


### Gardening Contractor (Lehiem)
```
| Project ID | Client Name | Contact Info       | Project Date | Services                       | Plants Used         | 
| ---------- | ----------- | ------------------ | ------------ | ------------------------------ | ------------------- | 
| P1001      | Sarah Green | sarah@gmail.com    | 2024-05-01   | Lawn Mowing, Hedge Trimming    | Roses, Tulips       | 
| P1002      | Bob Brown   | (555) 234-5678     | 05/02/2024   | Tree Planting                  | Oak                 | 
| P1003      | Alice Blue  | alice.blue@xyz.com | May 3, 2024  | Flower Bed Design, Weeding     | Daisies, Sunflowers | 
| P1004      | Tom White   | tomwhite@abc.net   | 2024/05/04   | Lawn Mowing                    |                     | 
| P1005      | Sarah Green | sarah@gmail.com    | 05-05-2024   | Hedge Trimming, Garden Cleanup | Lavender            | 
| P1006      | Emma Violet | 555-678-1234       | 2024-05-06   | Tree Pruning, Lawn Mowing      | Maple, Ferns        | 
```

### Comic Book Store (Miguel)
```
| Sale ID | Customer Name  | Contact Info         | Sale Date    | Comic Books Purchased                 | Accessories            | 
| ------- | -------------- | -------------------- | ------------ | ------------------------------------- | ---------------------- | 
| S5001   | Jake Peralta   | jake.p@nyc.gov       | 2024-06-01   | "Spider-Man #1", "Batman #50"         | T-Shirt, Action Figure | 
| S5002   | Amy Santiago   | amy.s@nyc.gov        | 06/02/2024   | "Supergirl #5"                        |                        | 
| S5003   | Charles Boyle  | charles.b@nyc.gov    | June 3, 2024 | "X-Men #20", "Iron Man #3", "Hulk #7" | Poster                 | 
| S5004   | Gina Linetti   | gina.linetti@fun.com | 2024/06/04   | "Wonder Woman #12"                    | Sticker Pack, Keychain | 
| S5005   | Jake Peralta   | jake.p@nyc.gov       | 06-05-2024   | "Batman #50"                          | T-Shirt                | 
| S5006   | Terry Jeffords | terry.j@nyc.gov      | 2024-06-06   | "Captain America #10"                 | Action Figure          | 
```


### Pizza Restaurant (Jack and Alex)
```
| Order Number | Customer Name | Contact Info          | Order Date   | Pizzas Ordered                              | Toppings                    | Delivery Address        | Delivery Driver |
| ------------ | ------------- | --------------------- | ------------ | ------------------------------------------- | --------------------------- | ----------------------- | --------------- |
| O3001        | Linda Lee     | linda.lee@example.com | 2024-07-01   | "Margherita", "Pepperoni"                   | Extra Cheese, Olives        | 123 Maple Street, Apt 4 | Tony            |
| O3002        | Mark Spencer  | (555) 345-6789        | 07/02/2024   | "BBQ Chicken"                               | Bacon, Onions               | 456 Oak Avenue          | Gina            |
| O3003        | Nina Patel    | nina.p@domain.com     | July 3, 2024 | "Veggie Delight", "Hawaiian", "Meat Lovers" | Pineapple, Sausage, Peppers | 789 Pine Road, Suite 12 | Tony            |
| O3004        | Jake Taylor   | jake.t@example.org    | 2024/07/04   | "Pepperoni"                                 | Extra Cheese                | 321 Elm Street          | Gina            |
| O3005        | Linda Lee     | linda.lee@example.com | 07-05-2024   | "Margherita"                                | Basil                       | 123 Maple Street, Apt 4 | Tony            |
| O3006        | Omar Khalid   | 555-789-0123          | 2024-07-06   | "BBQ Chicken", "Pepperoni"                  | Bacon, Olives               | 654 Cedar Blvd, Apt 9   | Gina            |
```

### Pet Groomer (Adam and Blu)
```
| Appointment ID | Pet Owner Name | Contact Info         | Appointment Date  | Services Requested                       | Products Used           | Total Cost | Tip Amount     | 
| -------------- | -------------- | -------------------- | ----------------- | ---------------------------------------- | ----------------------- | ---------- | -------------- | 
| A9001          | Olivia Green   | olivia.g@example.com | 2024-09-01        | "Bath", "Haircut"                        | Shampoo, Conditioner    | $45.00     | 1              | 
| A9002          | Ethan Hunt     | (555) 654-3210       | 09/02/2024        | "Nail Trimming"                          | Nail Clippers           | 15.00      | $5             | 
| A9003          | Ava Brown      | ava.b@domain.com     | September 3, 2024 | "Bath", "Ear Cleaning", "Teeth Brushing" | Ear Cleaner, Toothpaste | $60        | Ten Bucks      | 
| A9004          | Liam Smith     | liam.smith@abc.net   | 2024/09/04        | "Haircut"                                | Scissors                | $25.00     | None           | 
| A9005          | Olivia Green   | olivia.g@example.com | 09-05-2024        | "Bath"                                   | Shampoo                 | 20.00      | A cookie       | 
| A9006          | Mia Johnson    | 555-789-0123         | 2024-09-06        | "Haircut", "Nail Trimming"               | Scissors, Nail Clippers | $35.75     | $10            | 
```