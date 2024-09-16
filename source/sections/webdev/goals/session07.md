<!--
Instructor notes: Internet simulation:

- Arrange classroom into clusters of 2 or 3 desks
- Each cluster has a number (a random number between 10-99, with no meaning), and then each desk in a cluster has a number. put these together to form an IP address (eg 77.1 means cluster 77, desk 1)
- Make an excel sheet that we can use to randomly map sender to receiver
- Draw a picture, tear it into 8 pieces, put the address each piece, and send them into the internet. Pass them aimlessly until they reach the destination
- Build routing tables
    - First, ping nearby tables. Tables should respond to ping with their own table number
    - Then, build out the whole routing table by sending "neighbors" requests. When a table receives a "neighbors" request, it should respond with its immediate neighbors.
    - Each table should continue sending "neighbors" requests until it has mapped the entire network. The goal of the routing table should be to look up the destination and find the next hop

-->

## Lesson Objectives
By the end of this lesson, you should:

- Know the four layers of the TCP/IP model
- Understand the role of packets in networked communication
- Understand the role that routers play on the network
- Understand some of the problems that can occur in packet-switched networks
- Know some of the information that is contained in the TCP/IP header


## What We'll Do In Class

### Quiz
As usual, we'll start with a reading quiz to make sure you're comfortable with the basics of the TCP/IP model that you read about for homework.

### Internet Simulation
We'll spend most of the class working through an internet simulation. The simulation will helps us develop a better understanding of 

## Homework

### Reading
Please complete the below reading assignment, and prepare for a short, simple reading quiz at the beginning of next class.

- TCP vs UDP: [Read this Article](https://www.avast.com/c-tcp-vs-udp-difference) about the differences between these two protocols.
- Binary: [Watch this video](https://www.youtube.com/watch?v=USCBCmwMCDA) About how information is stored on computers. I'll only expect that you go through timestamp 3:30. Everything past that is bonus - but it's still very interesting!

### Send me an Email
My understanding is that everyone should have a gmail account now. If you haven't yet, please complete the introductory email assignment from [Session 2](./session.html?num=02).

Regardless, send me a **new** email with a link to your github repository. I want to be able to get to everyone's repo so that I can start grading! When I get your github repo, I'll be able to put in the following grades:

- The quiz from the beginning of [Session 6](./session.html?num=06) where you added an animal name to your website. 
- Your Markdown journal entry about learning the Terminal from [Session 6](./session.html?num=06). 
- Your Terminal quiz from [Session 5](./session.html?num=05) - you should have saved this quiz as a text file on your computer and then committed it to your repo.