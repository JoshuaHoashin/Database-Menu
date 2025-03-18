# Database-Menu
Lab 2
Written by Joshua Hoashin     hoash003@umn.edu

Program description paragraph:
    -This program is a menu for a database for records and in this program it has a
     menu with 7 options. which include "print all records", "add record", "delete the last records", 
    "print database size", "print number of changes" and "exit". The program will run the menu until the user
     has selected number 7 to exit the program. It allows the user to add records, print all the records, delete a record, 
     print the database size, number of changes the program, and exit. This program uses memory allocation as well to store data.


Menu definition and usage:
     - The menu has a list of has 7 options that are displayed  and after one is selected it displayes the operation of that function.

     - The menu was implemented with a while loop and a switch case.

Each function defined with:
    -Input type(s) (if any): The only input is entering the menu option number and for adding to the record the user will
    need to enter the required information.

    -Output type: Displays the menu and the function of the selected item on the menu.

    -Algorithm description: The algorithm that is used is not advanced it is the basic coding , stuff like the menu being printed, user input scanner, the switch case.
    Also, printNumChanges(bool print)   used a input boolean as per the instructions and prints te updated modification count. Also we used a static count variable in this function.
    The other funtions just displayed a string indicating the function has been called.

    - We used Structures in this lab which allowed me to group together related data.

    -static type ws used in the print num of changes function

Listing of files required and what type they are (.h header, .c c code, etc..):

I had 2 (.c c code) files which contained the code in steps for my lab 2.
I also have a read.txt that explain the myLab2.
I also have a project2.txt that has a transcription of the code output.

#include <stdio> : was used as it was necessary to run the files.

#include <stdbool.h>: this was used so i could use the boolean for the prinNumChanges function.

#include <stdlib.h>: was need for the exit feature of this program.

#include < string.h> this allowed for the string maniupaltion of strcpy(), strcmp()


Testing Critieria

- The program should compile without any errors.
- Print all records: should print the existing 5records and additional records that are added.
-Add record: should add a record and let you know if you inputed an invaild data sometimes
-Delete a record: deletes the last one
-print num of records: this will print the number records whne one is added or deleted.
-Print database size: will print thr size of database
-print num changes: displays the correct total number of modifications that have occurred so far.
- exit: leaves programs

Invalid inputs are in the main menu if you choosea a number that is not between 1-7 it willl tell you error.
In add records there are invalid data inputs on three of the prompt and if wrong data is entered it will display a message.

Caution: The program will save the wrong data as a record, so you must delete that wrong input record manually by using delete option on the menu.
