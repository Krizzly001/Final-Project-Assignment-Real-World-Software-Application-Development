# Kage-Personal-Expense-Tracker
Project Overview

1.1 Introduction
The Kage Personal Expense Tracker is a C++ programming application only using visual studios. The application is used to manage and track users' financial earning and spendings. It is simple to record all transactions the user would like to record manually, with features like history, summary, calculation and organized categories. 

The application is similar to a bank account which was inspired by Bank of America but of course with unique features of its own. Including a login system and registry. Users are required to register in order to proceed with its variety of tools available. 
The program relies on text files save and load transactional information. Including a login.txt file to store username, password, first name and last name. This ensures the users information wont be infiltrated. 

The C++ program relies on object-oriented programming concepts. With two classes called frontPage and transactions. The frontPage is login and registration while transactions manages the users financial transactions.

1.2 Problem Statement

Keeping track of transactions could be a hassle especially when banks have not processed a fee the same day. The UI feels overwhelming and complicated to use. Especially for older users and younger ones, who aren't as familuar. It's difficult to keep track of all spendings and splitting up the transaction into categories without having physical paper or files.

The Kage Personal Expense Tracker provides solutions for these problems people deal with on a daily basis. A user can easily access the app and create their personal expense tracker.

1.3 Project Objectives

1. Create personal tracker application that's easy to use
   
3. Users can create or login to account
   
5. Record the expenses anytime
   
7. Review past transactions
   
9. Calculate the total balance
    
11. See spending for each category
    
13. Stores the information locally

2. Target Users and Use Cases
   
2.1 Target Users

Users who want an accessible app to keep track of personal expenses, for all.

2.2 Main Use Cases

Register

Create an account with custom username and password input, including firstname and last name needed.

Login

Users will have to register before login unless they have done profusely, needing username and password to login. With information stored in the login.txt file.


Add Transaction

Users can enter the Title/Name, Amount, Date, Category and Description. Saved in the transaction.txt file.


Delete Transaction

Based on the title, the user can delete a transaction from the file. The files will be rewritten without the deleted transaction. Forever being erased, no backups implemented.


View TRansactions

Users can view all transactions that have been added, withall information included when the user adds this transaction.


Calculate Balance

Determines the total amount of balance


Search Transaction
Users will have to input a title to search for a specific Transaction. If there is no match an error will be displayed.

Spending Summary
The application had organized a summary of each category's spending and earning, already calculated.

3. Technology Used
3.1 Programming Language
Although it was only built on C++, the program uses multiple libraries
<iostream for console input and output
<string>access string variables
<fstream> Read and write files
<limits> handles input buffer
<map> organize the categories
<iomanip> format output


3.3 Development Tools

C++ Development environment is compiled through Visual Studios Code.

Git and Github for visual control and maintenance source.

3.4 Data Storage

Files:

Login.txt

Transactions.txt

Temp.txt


4. Design
Components:

User -> Console Interface -> Application Logic: frontPage, transactions -> File Storage: login.txt, transactions.txt, temp.txt
The main() created the front page which leads to the login page. After successfully logging in, the user has access to the transaction tools.


6. Object-Oriented Design
   
5.1 frontPage Class

The frontPage is responsible for registration and login

Private variables being:

Username

Password

introOption

firstLine

secondLine

thirdLine

fourthLine

It contains a main menu that displays the login and registration options, which loops until user is correct


5.2 transactionsClass

Responsible to managing users financial transactions

Title

Amount

Date

Category

Description

findATitle
