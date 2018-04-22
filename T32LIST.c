  /* 25.10.14, Nikonov Ivan, 10-2 */
#include "T32LIST.H"
void PrintMenu()
{
  printf("0-exit\n"
        "1-Add to Begin\n"
        "2-Add to End\n"
        "3-Delete from Begin\n"        
        "4-Delete from End\n"
        "5-Add current\n"
        "6-Delete current\n"
        "7-Shift Left\n"
        "8-Shift Right\n");
}

void main(void)
{
  LIST *Start = NULL;
  char OldStr[MAX_STR], NewStr[MAX_STR];
  int flag=1;
  while(flag)
  {
    PrintMenu();
    DisplayList(Start);
    switch(_getch())  
    {
      case '0':
      flag=0;
      break;
      
      case '1':
        printf(":Str\n");
        gets(NewStr);
        AddtoListBegin(&Start, NewStr);
      break;
        
      case '2':
        printf(":Str\n");
        gets(NewStr);
        AddtoListEnd(&Start, NewStr);
      break;
       
      case '3':
        DeletefromBegin(&Start);
        printf("The String  has been succesfully deleted\n");
       break;
       
      case '4':
        DeletefromEnd(&Start); 
        printf("The String  has been succesfully deleted\n");
       break;
       case '5':
         printf("Str:");
         gets(NewStr);
         AddCurrent(&Start, NewStr);
        printf("The String  %s\n has been succesfully Aded\n", NewStr);
       break;

       case '6':
        if(DeleteCurrent(&Start)); 
        printf("The String has been succesfully deleted\n");
       break;
      
      
       case  '7':
        DisplayList(Start);
        ShiftLeft(&Start);
       break;

       case  '8':
        DisplayList(Start);
        ShiftRight(&Start);
       break;
    }  
  }
}