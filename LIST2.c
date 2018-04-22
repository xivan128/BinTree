/* 25.10.14, Nikonov Ivan, 10-2 */
#include "T32LIST.H"
#include <string.h>
void StrCopy(char *Dest, char *Src)
{
  while((*Dest++ = *Src++) !=0)
    ;
}


int FreeList(LIST **L)
{
  
  LIST *Old;
  if(*L==NULL)
    return 1;
  while((*L)->Prev!=NULL)
    L=&(*L)->Prev;
  while(*L!=NULL)
  {
    Old=*L;
    *L=(*L)->Next;
    free(Old);
  }
  return 1;
} 
void DisplayList(LIST *L)
{
  LIST *Ptr;
  if(L==NULL)
  {
    printf("Empty List\n");
     return;
  }
  Ptr = L;
  while(Ptr->Prev!=NULL)
    Ptr=Ptr->Prev;
   while(Ptr!=NULL)
  {
    printf("%s%s", Ptr->Str, Ptr==L ? "*" : " "); 
    printf((Ptr=Ptr->Next)==NULL ? "\n" : ";");
  }
}

int AddtoListBegin(LIST **L, char *NStr) 
{
  LIST *next=NULL;
  while (*L!=NULL)
  {
    next=*L;
    L=&(*L)->Prev;
  }
    *L=malloc(sizeof(LIST));
  if(*L==NULL)
    return 0;
     strncpy((*L)->Str, NStr, MAX_STR-1);
  // StrCpy((*L)->Str,NStr); /
  (*L)->Next = next;
  (*L)->Prev= NULL;
  return 1;
} 
int AddtoListEnd(LIST **L, char *NStr) 
{
  LIST *prev=NULL;
  while (*L!=NULL)
  {
    prev=*L;
    L=&(*L)->Next;
  }
  *L=malloc(sizeof(LIST));
  if(*L==NULL)
    return 0;
  StrCopy((*L)->Str,NStr);
  (*L)->Next = NULL;
  (*L)->Prev= prev;
  return 1;
}
void ShiftLeft(LIST **L)
{
  if(*L!=NULL&&(*L)->Prev!=NULL)
    *L=(*L)->Prev;
}

void ShiftRight(LIST **L)
{
  if(*L!=NULL&&(*L)->Next!=NULL)
    *L=(*L)->Next;
}



  void DeletefromEnd(LIST **L)
{
  LIST *Prl=NULL;
  if(*L!=NULL)
  {
    if((*L)->Next!=NULL || (*L)->Prev!=NULL)
    {
     if((*L)->Next!=NULL)
      while((*L)->Next!=NULL)
      {
        Prl=*L;
        L=&(*L)->Next;
      }
    else if((*L)->Next==NULL && (*L)->Prev!=NULL)
      Prl=(*L)->Prev;
  
    
  free(*L);
  *L=Prl;
  (*L)->Next=NULL;
    }
   else
   {  
     free(*L);
     *L=Prl;
    } 
  }
} 

void DeletefromBegin(LIST **L)
{
  LIST *Prl=NULL;
  if(*L!=NULL)
  {
    if((*L)->Prev!=NULL || (*L)->Next!=NULL)
    {
     if((*L)->Prev!=NULL)
      while((*L)->Prev!=NULL)
      {
        Prl=*L;
        L=&(*L)->Prev;
      }
    else if((*L)->Prev==NULL && (*L)->Next!=NULL)
      Prl=(*L)->Next;
  
    
  free(*L);
  *L=Prl;
  (*L)->Prev=NULL;
    }
   else
   {  
     free(*L);
     *L=Prl;
    } 
  }
}  

int AddCurrent(LIST **L, char *NS)
{
  LIST *ne, *prv, *nxt;
  if((ne=malloc(sizeof(LIST)))==NULL)
    return 0;
  strncpy(ne->Str,NS, MAX_STR-1);
  if(*L==NULL)
  {
   *L=ne;
   ne->Next=ne->Prev=NULL;
  }
  else
  {
    prv=*L;
    nxt=(*L)->Next;
    *L=ne;
    ne->Next=nxt;
    ne->Prev=prv;
    if(nxt!=NULL)
      nxt->Prev=ne;
    if(prv!=NULL)
      prv->Next=ne;

  }
  return 1;
}

/*int DeleteCurrent(LIST **L, char *OldStr) 
{
  LIST *OEl = *L;
  if(*L==NULL)
    return 0;
  if((*L)->Next!=NULL)
  {
   (*L)=(*L)->Next;
   (*L)->Prev=(*L)->Prev->Prev;
   if((*L)->Prev!=NULL)
     (*L)->Prev->Next;
  }
  else
  {
    *L=(*L)->Prev;
    if(*L!=NULL)
      (*L)->Next=NULL;
  }
   strncpy(OldStr, OEl->Str, MAX_STR-1);
   return 1;
}       */

int DeleteCurrent(LIST **L)
{
  LIST *OEl;
  if(*L==NULL)
    return 0;
  OEl=*L;
  if((*L)->Next!=NULL)
  {
    *L=(*L)->Next;
    (*L)->Prev=(*L)->Prev->Prev;
    if((*L)->Prev!=NULL)
      (*L)->Prev->Next=*L;
  }
  else
  {
    *L=(*L)->Prev;
    if(*L!=NULL)
      (*L)->Next=NULL;
  }
  free(OEl);
    return 1;
}


