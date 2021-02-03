/**
 * Author: Dillon Evans
 * Email: <dillon.e.evans@okstate.edu>
 * Date: January 21st, 2020
 * Program Description: This program simulates Conway's Game of Life, which is a
 * cellular automata, inside the console. The user is prompted for their name, 
 * today's date, and the number of generations they would like to see. Their data 
 * is then recorded in summary.txt and displayed to subsequent players.
 * If a player chooses to view more generations, the information in the struct 
 * will be updated accordingly.
 */
#include <stdio.h>
#include <stdlib.h>
#include "decl.h"

/*Program Entry Point*/
int main()
{
   playerInfo();
   return 0;
}