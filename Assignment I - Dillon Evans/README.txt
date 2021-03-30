To compile: gcc *.c -lrt
To run:     ./a.out

The number of processes (customers) has to be between 1 and 26 inclusive in order to 
use ABC...Z for ordering. 

When entering the order, the number of characters cannot exceed the number of customers. 
For instance, if there are 3 processes, there are 6 valid orderings such as ABC, CBA, ACB.
Furthermore, each character correpsonds to the index of a process. For instance, if there are two processes the 
only letters that can be used are A and B because A is mapped to 1 and B is mapped to 2.

The number of items is limited to values between 1 and 100 inclusive so as to minimize the size of the messages.

Each receipt file is created dynamically during runtime. 