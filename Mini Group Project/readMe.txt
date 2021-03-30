# OS_GroupA_Project_02
To Compile: 
1) gcc driver.c manager.c assistant.c historySearch.c -o driver
2) gcc server.c -o server -pthread

To Run (Linux):
1) Open three terminals
2) In the first terminal, type "tty" and make note of the number
3) In the second, type "./server" to start the server and establish the connection.
4) In the third, type "./driver" to run the client side. 
5) After the first query you will be prompted to enter a number, this will be the number returned by "tty" as mentioned earlier.
6) To view the results of each query, use the terminal you entered the "tty" command in.

Task Allocations:
Dillon - Server and Header, Client Connection to Server
Tyler - Manager and Driver
Nikul and Thomas - Client Side
