#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int checking(const char * list,int comparing,int endIndex)
{
    int side1_num1=0;
    int side1_num2=0;
    int side2_num1=0;
    int side2_num2=0;
    int sum1=0;
    int sum2=0;
    int isEdition=0;
    if(comparing!=0)
    {
        return 0;
    }
    sscanf((list+endIndex+1)," ; [ %d | %d ] ; [ %d | %d ] }",&side1_num1,&side1_num2,&side2_num1,&side2_num2);
    sum1=side1_num1+side1_num2;
    sum2=side2_num1+side2_num2;

    if((sum1==53 && sum2!=53) || (sum1!=53 && sum2==53) )
    {
        isEdition=1;
    }


    return isEdition;
}


int comparing(const char * list,int startIndex, int endIndex)
{
    char *nameOfDomino;
    int max=100;
    int arrCnt=0;
    int isEdition=0;
    int comparing=0;
    char edition[]="PA1 Basic";
    nameOfDomino=(char *)malloc(max*sizeof(*nameOfDomino));
    for (int i = startIndex+1; i <endIndex ; i++)
    {
        if(arrCnt>=max)
        {
            max=max+100;
            nameOfDomino=(char *)realloc(nameOfDomino,max*sizeof(*nameOfDomino));
        }
        nameOfDomino[arrCnt]=list[i];
        arrCnt++;
    }
    comparing=strcmp(nameOfDomino,edition);
    free(nameOfDomino);
    isEdition=checking(list,comparing,endIndex);
    return isEdition;
}

int loopThrough(const char * list)
{
    int read=0;
    int result=0;
    int isEdition=0;
    int startIndex=0;
    int endIndex=0;
    int start=0;
    int end=0;
    int listCnt=0;
    int fromEdition=0;
    int total=0;
    while (list[listCnt]!='\0')
    {
        if (list[listCnt]==39)
        {
            if(start==0)
            {
                startIndex=listCnt;
                start=1;
            }
            else
            {
                endIndex=listCnt;
                end=1;
            }
            if(end==1 && start==1)
            {
                isEdition=comparing(list,startIndex,endIndex);
                total=total+isEdition;
                read=1;
            }
        }
        listCnt++;
        if(read==1)
        {
            startIndex=0;
            start=0;
            endIndex=0;
            end=0;
            read=0;
        }
    }
    return total;
}

int countCollectible ( const char * list )
{
    if(list==NULL)
    {
        return 0;
    }
    int fromEdition=0;
    fromEdition=loopThrough(list);
    return fromEdition;
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
            "{'PA1 Basic' ; [ 1 | 52 ] ; [ 1 | 4 ] }\n"
            " { 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
            "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
            "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n"
            "{'PA1 Basic' ; [ 1 | 52 ] ; [ 1 | 4 ] }\n";
    /*
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
    */
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
