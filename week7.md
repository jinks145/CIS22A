CIS22A - Notes for Week 7, 11/4-11/7 {style="font-family: Arial; color: rgb(255, 204, 204);"}
------------------------------------

+--------------------------------------------------------------------------+
| ### Announcements and Reminders                                          |
|                                                                          |
| -   [Assignment 6](ass6.html) is due Monday, 11/4                        |
| -   Review your midterm                                                  |
| -   [Tuesday's online time](http://www.conferzoom.org/) (7:00-8:15 pm)   |
| -   [Lab Exercise 7](ex7.html) is due Wednesday, 11/6                    |
| -   [Assignment 7](ass7.html) is due next Monday, 11/11                  |
+--------------------------------------------------------------------------+

* * * * *

+--------------------------------------+--------------------------------------+
| ### Topics                           | ### Terminology                      |
+--------------------------------------+--------------------------------------+
| ### Introduction to Functions        | function\                            |
|                                      |  \                                   |
| What is a function?\                 |  function definition\                |
|  \                                   |  \                                   |
|  Why write functions?\               |  function declaration\               |
|  \                                   |  prototype\                          |
|  How to ... \                        |  \                                   |
| -   Function definition              |  argument\                           |
|                                      |  \                                   |
| -   Function declaration (prototype) |  return value\                       |
|                                      |  return type\                        |
| -   Function call                    |  \                                   |
|                                      |  local variables\                    |
| -   variables inside functions       |  \                                   |
|                                      |  scope                               |
| -   local variables                  |                                      |
|                                      |                                      |
| -   function arguments               |                                      |
|                                      |                                      |
| -   function return values           |                                      |
|                                      |                                      |
| Examples\                            |                                      |
| 1.  Print a simple message           |                                      |
| 2.  Print the sum of two numbers     |                                      |
| 3.  Return the sum of two numbers    |                                      |
| 4.  Return the sum of two random     |                                      |
|     numbers                          |                                      |
| 5.  Return the square root of the    |                                      |
|     sum of two squares (recall the   |                                      |
|     quadratic formula)               |                                      |
| 6.  Print a random card              |                                      |
| 7.  Print an assigned card           |                                      |
| 8.  Return the sum of 4 numbers      |                                      |
| 9.  Return the minimum of 11 numbers |                                      |
|     (think assignments)              |                                      |
| 10. Return an the total of 11        |                                      |
|     assignments (after discarding    |                                      |
|     the minimum)                     |                                      |
|                                      |                                      |
| * * * * *                            |                                      |
|                                      |                                      |
| ### Functions: Pass by value and ret |                                      |
| urn by value                         |                                      |
|                                      |                                      |
| #### Review of function concepts     |                                      |
|                                      |                                      |
| function definition                  |                                      |
| -   function heading                 |                                      |
| -   body of function                 |                                      |
|                                      |                                      |
| function declaration or prototype    |                                      |
| -   It is a good idea to write a     |                                      |
|     function prototype.              |                                      |
| -   It is required to write a        |                                      |
|     function prototype if the        |                                      |
|     function is defined after it is  |                                      |
|     called.                          |                                      |
| -   A prototype's argument types and |                                      |
|     return types must match the      |                                      |
|     function heading.                |                                      |
| -   A prototype's argument names do  |                                      |
|     not have to match the function   |                                      |
|     arguments names.                 |                                      |
| -   A prototype's arguments must     |                                      |
|     include argument types, but not  |                                      |
|     argument names.                  |                                      |
| -   It's a good idea to use function |                                      |
|     argument names that identify     |                                      |
|     their purpose.                   |                                      |
|                                      |                                      |
| function call                        |                                      |
| function arguments                   |                                      |
| -   pass by value                    |                                      |
| -   variables or values that are     |                                      |
|     passed to functions by value are |                                      |
|     copied in stack memory.  It is   |                                      |
|     the copy that is used inside the |                                      |
|     function.  The original variable |                                      |
|     in the calling function is       |                                      |
|     unchanged by the function.       |                                      |
|                                      |                                      |
| function return                      |                                      |
| -   return type                      |                                      |
| -   return value                     |                                      |
| -   return by value\                 |                                      |
| -   How do you use the function      |                                      |
|     return?                          |                                      |
| -   Do you have to use the function  |                                      |
|     return? \                        |                                      |
|      The answer is "no", but make    |                                      |
|     sure you have a good reason not  |                                      |
|     to.                              |                                      |
|                                      |                                      |
| * * * * *                            |                                      |
|                                      |                                      |
| #### Local and Global Variables      |                                      |
|                                      |                                      |
| #### Local Static Variable           |                                      |
|                                      |                                      |
| * * * * *                            |                                      |
|                                      |                                      |
| #### Function Design                 |                                      |
|                                      |                                      |
| How do you decide:\                  |                                      |
| -   should the function have a void  |                                      |
|     argument, one argument, or       |                                      |
|     multiple arguments?              |                                      |
| -   should the function have a void  |                                      |
|     return, or should it return a    |                                      |
|     value?                           |                                      |
|                                      |                                      |
| There may not be an exact right      |                                      |
| answer to the design questions, but  |                                      |
| often there is an easier, more       |                                      |
| obvious, or more direct approach.    |                                      |
|  These questions may help your       |                                      |
| decision:\                           |                                      |
|  \                                   |                                      |
|  What do you want the function to    |                                      |
| do?\                                 |                                      |
| This needs to be clear in your       |                                      |
| mind.\                               |                                      |
| \                                    |                                      |
|  Do you have to provide data to the  |                                      |
| function?\                           |                                      |
| If so, you will need (an)            |                                      |
| argument(s).\                        |                                      |
| \                                    |                                      |
|  Do you have to provide more than    |                                      |
| one value to the function?\          |                                      |
| If so, you will need multiple        |                                      |
| arguments.\                          |                                      |
| \                                    |                                      |
|  Is the function supposed to perform |                                      |
| a calculation and print a value?\    |                                      |
| Maybe the function doesn't need to   |                                      |
| return a value.\                     |                                      |
| \                                    |                                      |
|  Is the function supposed to perform |                                      |
| a calculation and return a value?\   |                                      |
| If so, then you need a return.\      |                                      |
| \                                    |                                      |
|  Is the function supposed to print   |                                      |
| some output or return a value?\      |                                      |
| If it prints, maybe you don't need a |                                      |
| return.  If it returns, maybe it     |                                      |
| doesn't need to print.\              |                                      |
|  "Write a function that prints ..."\ |                                      |
|  "Write a function that returns      |                                      |
| ..."\                                |                                      |
| \                                    |                                      |
|  Where does the function get its     |                                      |
| values?\                             |                                      |
| User input, random generation, no    |                                      |
| values needed, must get values       |                                      |
| externally.\                         |                                      |
| \                                    |                                      |
|  Is the function too trivial?\       |                                      |
| Maybe you don't need it.\            |                                      |
| Is the function supposed to perform  |                                      |
| a calculation and return a value?\   |                                      |
|  \                                   |                                      |
|  Is the function too complicated?\   |                                      |
| If so, "spin off" (an)other          |                                      |
| function(s).\                        |                                      |
|                                      |                                      |
| * * * * *                            |                                      |
|                                      |                                      |
| #### Advice                          |                                      |
|                                      |                                      |
| -   Don't pass arguments that you    |                                      |
|     don't need.                      |                                      |
| -   Don't return a value that is not |                                      |
|     meaningful.                      |                                      |
| -   Keep it as simply as possible.   |                                      |
| -   Think small, think globally,     |                                      |
|     think reuse.                     |                                      |
| -   **Stay away from global          |                                      |
|     variables.**                     |                                      |
|                                      |                                      |
| * * * * *                            |                                      |
|                                      |                                      |
| #### In-class Practice Exercises     |                                      |
|                                      |                                      |
| Write a prototype for each problem.  |                                      |
|  Choose a meaningful function name,  |                                      |
| appropriate function argument(s),    |                                      |
| and a return type.  Note, there is   |                                      |
| not necessarily an exact right       |                                      |
| answer, but there may be a best      |                                      |
| choice.\                             |                                      |
|  \                                   |                                      |
|  Write a function\                   |                                      |
| 1.  that prompts for and prints your |                                      |
|     name.                            |                                      |
| 2.  that prompts the user for an     |                                      |
|     even number and continues        |                                      |
|     prompting until an even number   |                                      |
|     is entered                       |                                      |
| 3.  returns the cube root of a       |                                      |
|     number                           |                                      |
| 4.  prints the cube root of a number |                                      |
| 5.  calculates the cube root of a    |                                      |
|     number                           |                                      |
| 6.  determines the average of 5      |                                      |
|     numbers                          |                                      |
| 7.  returns the maximum of a some    |                                      |
|     numbers in a file                |                                      |
| 8.  checks for the existence of a    |                                      |
|     file                             |                                      |
| 9.  converts inches to feet          |                                      |
| 10. changes an unsigned int to an    |                                      |
|     int                              |                                      |
| 11. changes an int to an unsigned    |                                      |
|     int                              |                                      |
| 12. calculates the area of a         |                                      |
|     triangle                         |                                      |
| 13. determines if a number less than |                                      |
|     100 is prime or not              |                                      |
|                                      |                                      |
| * * * * *                            |                                      |
|                                      |                                      |
| ### Default Arguments                |                                      |
|                                      |                                      |
| A default argument is a value that   |                                      |
| is automatically passed as a         |                                      |
| function argument when the argument  |                                      |
| is not provided by the function      |                                      |
| call.\                               |                                      |
| #### Example                         |                                      |
|                                      |                                      |
| +----------------------------------- |                                      |
| ------------------------------------ |                                      |
| ---+                                 |                                      |
| | ``` {style="background-color: rgb( |                                      |
| 255, 204, 102);"}                    |                                      |
|    |                                 |                                      |
| | #include <iostream>using namespace |                                      |
|  std;int power(int,int = 2); // prot |                                      |
| ot |                                 |                                      |
| | ype with default argument int main |                                      |
| (void){  cout << power(5) << endl;   |                                      |
|  c |                                 |                                      |
| | out << power(2,10) << endl;    cou |                                      |
| t << power(12345) << endl;   return  |                                      |
| 0; |                                 |                                      |
| | }int power(int x, int y){  int num |                                      |
|  = 1;    for (int i = 1; i <= y; i++ |                                      |
| )  |                                 |                                      |
| | num *= x;   return num;}           |                                      |
|                                      |                                      |
|    |                                 |                                      |
| | ```                                |                                      |
|                                      |                                      |
|    |                                 |                                      |
| +----------------------------------- |                                      |
| ------------------------------------ |                                      |
| ---+                                 |                                      |
|                                      |                                      |
| #### Notes                           |                                      |
|                                      |                                      |
| -   Default arguments should be      |                                      |
|     placed in the function           |                                      |
|     prototype.  If a prototype is    |                                      |
|     not provided., then the default  |                                      |
|     arguments must be placed in the  |                                      |
|     function heading.                |                                      |
| -   In the function argument list,   |                                      |
|     mandatory arguments must preceed |                                      |
|     default arguments.               |                                      |
| -   Default arguments may not be     |                                      |
|     specified in both the function   |                                      |
|     prototype and the heading of the |                                      |
|     function definition.             |                                      |
| -   All of a function's arguments    |                                      |
|     may have default values.         |                                      |
|                                      |                                      |
| \                                    |                                      |
|  This is an error\                   |                                      |
|  \                                   |                                      |
|  void funk(int arg1 = 7, int arg2);\ |                                      |
|  \                                   |                                      |
|  A function that is prototyped like  |                                      |
| this,\                               |                                      |
|  \                                   |                                      |
|  void funk(int x = 2, int y = 4, int |                                      |
| z = 6);\                             |                                      |
|  \                                   |                                      |
|  may be called in 4 different ways,\ |                                      |
|  \                                   |                                      |
| like this,\                          |                                      |
|  \                                   |                                      |
|  funk(1,2,3);     // first           |                                      |
| argument = 1, second argument = 2,   |                                      |
| third argument = 3\                  |                                      |
|  \                                   |                                      |
|  or this,\                           |                                      |
|  \                                   |                                      |
|  funk(1,2);     // first argument =  |                                      |
| 1, second argument = 2, third        |                                      |
| argument = 6\                        |                                      |
|  \                                   |                                      |
|  or this,\                           |                                      |
|  \                                   |                                      |
|  funk(1);     // first argument = 1, |                                      |
| second argument = 4, third argument  |                                      |
| = 6\                                 |                                      |
|  \                                   |                                      |
|  or this,\                           |                                      |
|  \                                   |                                      |
|  funk();     // first argument = 2,  |                                      |
| second argument = 4, third argument  |                                      |
| = 6\                                 |                                      |
| \                                    |                                      |
|  [Example](def_arg_example.html)\    |                                      |
|                                      |                                      |
| * * * * *                            |                                      |
|                                      |                                      |
| ### Pass By Reference                |                                      |
|                                      |                                      |
| A reference variable is an alias for |                                      |
| another variable, defined elsewhere  |                                      |
| in the program.  Reference variables |                                      |
| are commonly used for function       |                                      |
| arguments or return values.  The use |                                      |
| of reference variables as function   |                                      |
| argument avoids the requirement to   |                                      |
| pass a variable's address to a       |                                      |
| function and avoid the necessity to  |                                      |
| dereference variable addresses.\     |                                      |
| #### Reference to const              |                                      |
|                                      |                                      |
| A reference to a const is used as a  |                                      |
| function argument to disallow the    |                                      |
| function from changing the argument  |                                      |
| value.\                              |                                      |
| #### Example                         |                                      |
|                                      |                                      |
| +----------------------------------- |                                      |
| ------------------------------------ |                                      |
| ---+                                 |                                      |
| | ``` {style="background-color: rgb( |                                      |
| 255, 204, 102);"}                    |                                      |
|    |                                 |                                      |
| | #include <iostream>using namespace |                                      |
|  std;void update_salary(double& sal) |                                      |
| {  |                                 |                                      |
| | sal *= 1.1; return;}void display_s |                                      |
| alary(const double &sal){ cout << sa |                                      |
| l  |                                 |                                      |
| | << endl; return;}int main (void){  |                                      |
| double salary = 50000.; display_sala |                                      |
| ry |                                 |                                      |
| | (salary); update_salary(salary); d |                                      |
| isplay_salary(salary); return 0;}*** |                                      |
| ** |                                 |                                      |
| | * OUTPUT ******5000055000          |                                      |
|                                      |                                      |
|    |                                 |                                      |
| | ```                                |                                      |
|                                      |                                      |
|    |                                 |                                      |
| +----------------------------------- |                                      |
| ------------------------------------ |                                      |
| ---+                                 |                                      |
|                                      |                                      |
| #### The swap function               |                                      |
|                                      |                                      |
| int main()\                          |                                      |
|  {\                                  |                                      |
|     int x = 2, y = 3;\               |                                      |
|     swap(x,y);\                      |                                      |
|     cout \<\< x \<\< ' ' \<\< z \<\< |                                      |
| end;   // prints 3 2\                |                                      |
|     ...\                             |                                      |
|  }                                   |                                      |
|                                      |                                      |
| * * * * *                            |                                      |
|                                      |                                      |
| * * * * *                            |                                      |
|                                      |                                      |
| Videos\                              |                                      |
|  \                                   |                                      |
| [Functions](https://www.youtube.com/ |                                      |
| watch?v=bsWWHo4KDHE&index=9&list=PLA |                                      |
| E85DE8440AA6B83)\                    |                                      |
|  \                                   |                                      |
|  [Creating Functions That Use        |                                      |
| Parameters](https://www.youtube.com/ |                                      |
| watch?v=-87KQS-rZCA&index=10&list=PL |                                      |
| AE85DE8440AA6B83)\                   |                                      |
|  \                                   |                                      |
|  [Functions That Use Multiple        |                                      |
| Parameters](https://www.youtube.com/ |                                      |
| watch?v=fQ_CBGVfGbM&index=11&list=PL |                                      |
| AE85DE8440AA6B83)\                   |                                      |
| \                                    |                                      |
|  [Read Me](readme7.html)             |                                      |
+--------------------------------------+--------------------------------------+


