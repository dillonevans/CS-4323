This program simulates Conway's Game of Life within the console. 
Functions preceded by the 'static' keyword have internal linkage, and are only visible within that source file. 
I have created two header files, one for definitions and one for declarations. This makes it easier to share methods and
definitions across files. 
To view the PDFs, see folder "Documentation".
The function call hierarchy looks like this:

main()
|
|__playerInfo()
   |__boardInitialization(...)
   |  |__displayGenerations(...)
   |     |--generations(...)
   |
   |__readPlayersInformation(...)
      |--displayGameInformationSummary(...)

So every function does stem from main, but main only has one function call
in its body. This way, there is a logical progression between functions. 

To Compile: gcc *.console
To Run: ./a.out