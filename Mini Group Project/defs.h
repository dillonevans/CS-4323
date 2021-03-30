#ifndef DEFS_H
#define DEFS_H

typedef int bool;
#define TRUE 1
#define FALSE 0
#define INVALID_QUERY "INVALID"
bool historySearch(char *query);
void termPrinter(char *results);
void assistant();
void manager();
#endif
