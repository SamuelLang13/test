#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#endif /* __PROGTEST__ */


int countCollectible ( const char * list )
{
  if(list==NULL)
  {
    return 0;
  }
  int endOfReading=0;
  int side1_num1;
  int side1_num2;
  int side1_sum=0;
  int side2_num1;
  int side2_num2;
  int side2_sum=0;
  int maxOfArray=100;
  int arrayCnt=0;
  char *nameOfDomino;
  int stdinCnt=0;
  int magicNumberCnt=0;
  char magicName[]="PA1 Basic";
  int isContaining=0;
  int cntUntilEnd=0;
  int read=0;

  //while loop until the end of the stdin
  while (list[stdinCnt]!='\0')
  {
    read=0;
    if(list[stdinCnt]==39 && read!=1)
    {
      isContaining=0;
      arrayCnt=0;
      maxOfArray=100;
      nameOfDomino=(char*)malloc(maxOfArray*sizeof(*nameOfDomino));
      stdinCnt++;
      while (list[stdinCnt]!=39)
      {
        if(arrayCnt>=maxOfArray)
        {
          maxOfArray=maxOfArray+100;
          nameOfDomino=(char*)realloc(nameOfDomino,maxOfArray*sizeof(*nameOfDomino));
        }
        nameOfDomino[arrayCnt]=list[stdinCnt];
        stdinCnt++;
        arrayCnt++;
      }
      endOfReading=stdinCnt;
      isContaining=strcmp(nameOfDomino,magicName);
      free(nameOfDomino);
      sscanf((list+endOfReading)," ; [ %d | %d ] ; [ %d | %d ] }",&side1_num1,&side1_num2,&side2_num1,&side2_num2);
      side1_sum=side1_num1+side1_num2;
      side2_sum=side2_num1+side2_num2;
      if((side1_sum==53 && side2_sum!=53) || (side1_sum!=53 && side2_sum==53))
      {
        if(isContaining==0)
        {
          magicNumberCnt++;
        }       
      }
      while (list[stdinCnt]=='}')
      {
        cntUntilEnd++;
      }
      read=1;
      
      stdinCnt=cntUntilEnd+stdinCnt;
    }
    if(read==0)
    {
      stdinCnt++;
    }

  }
  return magicNumberCnt; 
}




int countUnique  ( const char * list )
{
  return 0; /* TODO */
}

uint64_t countTowers ( const char * list )
{
  return 0; /* TODO */
}




#ifndef __PROGTEST__
int main ( void )
{
  const char * str1 =
    " { 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
    "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
    "{'PA1 Basic' ; [ 1 | 52 ] ; [ 1 | 4 ] }\n";
  const char * str2 =
    "{'Crash';  [1|2];[3|4]}\n"
    "{'MemLeak';[1|2];[3|4]}\n"
    "{'MemLeak';[2|3];[3|1]}\n"
    "{'MemLeak';[1|3];[3|2]}\n"
    "{'MemLeak';[1|4];[1|5]}\n"
    "{'MemLeak';[4|1];[1|5]}\n"
    "{'MemLeak';[4|1];[5|1]}\n"
    "{'MemLeak';[1|4];[5|1]}\n"
    "{'MemLeak';[1|5];[1|4]}\n"
    "{'MemLeak';[5|1];[1|4]}\n"
    "{'MemLeak';[5|1];[4|1]}\n"
    "{'MemLeak';[1|5];[4|1]}\n";
  const char * str3 =
    "{'-Wall -pedantic -Werror -Wno-long-long -O2';[2|2];[3|3]}\n"
    "{'-Wall -pedantic -Werror -Wno-long-long -O2';[4|4];[5|5]}\n"
    "{'-Wall -pedantic -Werror -Wno-long-long -O2';[3|4];[4|5]}\n";
  const char * str4 =
    "{'-fsanitize=address -g';[1|5];[5|7]}\n"
    "{'-fsanitize=address -g';[3|7];[1|9]}\n"
    "{'-fsanitize=address -g';[2|2];[4|7]}\n"
    "{'-fsanitize=address -g';[3|9];[2|6]}\n"
    "{'-fsanitize=address -g';[2|2];[2|2]}\n";

  assert ( countCollectible ( str1 ) == 1 );
  assert (countCollectible (NULL) == 0 );
  assert (countCollectible ("") == 0 );
  assert (countCollectible ("{' ") == 0 );

/*  assert ( countUnique ( str1 ) == 3 );
  assert ( countUnique ( str2 ) == 4 );
  assert ( countUnique ( str3 ) == 3 );
  assert ( countUnique ( str4 ) == 5 );
  assert ( countTowers ( str3 ) == 10 );
  assert ( countTowers ( str4 ) == 114 );
*/
  return 0;
}
#endif /* __PROGTEST__ */
