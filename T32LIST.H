/* 25.10.14, Nikonov Ivan, 10-2 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_STR 1000

typedef struct tagLIST LIST;
struct tagLIST
{
  char Str[MAX_STR];
  LIST *Prev, *Next;
};
void DisplayList(LIST *L);
int FreeList(LIST **L);
int AddtoListBegin(LIST **L, char *NStr);
int AddtoListEnd(LIST **L, char *NStr);
int AddCurrent(LIST **L, char *NStr);
int DeleteCurrent(LIST **L);
void ShiftLeft(LIST **L);
void ShiftRight(LIST **L);
void DeletefromBegin(LIST **L);
void DeletefromEnd(LIST **L); 