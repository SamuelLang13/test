#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#endif /* __PROGTEST__ */


typedef struct Domino
{
  char nameOfDomino[0];
  int sum1;
  int sum2;
}DOMINO;

int countCollectible ( const char * list )
{
  DOMINO*data=NULL;
  int maxOfData=100;
  int dataCnt=0;
  int side1_num1;
  int side1_num2;
  int side2_num1;
  int side2_num2;
  int maxOfArray=100;
  int arrayCnt=0;
  char *nameOfDomino;
  int tmpOfCnt=0;
  //Allocations of the array
  nameOfDomino=(int*)malloc(maxOfArray*sizeof(int));
  int stdinCnt=0;

  //while loop until the end of the stdin
  while (list[stdinCnt]!='\0')
  {
    if(list[stdinCnt]=='\'')
    {
      while (list[stdinCnt]=='\'')
      {
        if(arrayCnt>=maxOfArray)
        {
          maxOfArray=maxOfArray+100;
          nameOfDomino=(int*)realloc()
        }
        nameOfDomino[arrayCnt]=list[stdinCnt];
        stdinCnt++;
        arrayCnt++;
      }
      
    }
  }
  






  return 0; 
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
    "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n";
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

  assert ( countCollectible ( str1 ) == 0 );
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
