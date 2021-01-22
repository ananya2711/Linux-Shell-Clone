#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include<errno.h> 
#include<sys/wait.h> 
#include <unistd.h> 
#include<stdio.h> 
#include <string.h> 
#include <dirent.h> 
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include<sys/types.h>


int main(int argc,char **argv[])
{ 
  char *cmd=argv[1];
  if(strcmp(cmd,"date")==0)
  	{
   struct tm *local;
    time_t t;
    t = time(NULL);
    local = localtime(&t);
    char *ltime=asctime(local);
    char start[20];
    memcpy(start,&ltime[0],19);
    start[19]='\0';
    char end[5];
    memcpy(end,&ltime[20],4);
    end[4]='\0';
    printf("%s PDT %s", start,end);
    
  	}
  	else if(strcmp(cmd,"date -u")==0)
  	{
  		struct tm *local;
    time_t t;
    t = time(NULL);
    local = gmtime(&t);
    char *ltime=asctime(local);
    char start[20];
    memcpy(start,&ltime[0],19);
    start[19]='\0';
    char end[5];
    memcpy(end,&ltime[20],4);
    end[4]='\0';
    printf("%s UTC %s", start,end);
     
  	}
  	else if(strcmp(cmd,"date -R")==0)
  	{

  	struct tm *local;
    time_t t;
    t = time(NULL);
    local = localtime(&t);
    char *ltime=asctime(local);

    char start[3];
    memcpy(start,&ltime[0],3);
    start[3]='\0';
    printf("%s ,",start);
    char mid1[2];
    memcpy(mid1,&ltime[8],2);
    mid1[2]='\0';
     printf(" %s",mid1);
    char mid2[3];
    memcpy(mid2,&ltime[4],3);
    mid2[3]='\0';
    printf(" %s",mid2);
    char mid3[4];
    memcpy(mid3,&ltime[20],4);
    mid3[4]='\0';
 printf(" %s",mid3);
    char end[8];
    memcpy(end,&ltime[11],8);
    end[8]='\0';
     printf(" %s -0700",end);


  	}
  	else
  		printf("Invalid date command");
  printf("\n");
  return 0;
 }