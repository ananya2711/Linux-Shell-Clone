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
  if(strstr(cmd,"cat -n ")!=NULL)
  	{  int num=1;
  		FILE *fptr; 
       fptr = fopen(cmd+7,"r"); 
   
     if (fptr == NULL) 
    { 
        perror("Error:");
        return 0;
    } 
 
    char c= fgetc(fptr);
    char prev=NULL;
    printf("  %d  ",num);
    num++;
    while (c != EOF) 
    { if(prev!=NULL && prev=='\n')
    	{
    		printf("  %d  ",num);
    		num++;
    	}
    	
        printf ("%c", c); 
        prev=c;
        c = fgetc(fptr); 
        
    } 
  
    fclose(fptr);
      
      
  	}
  	else if(strstr(cmd,"cat -E ")!=NULL)
  	{
      
  		FILE *fptr; 
       fptr = fopen(cmd+7,"r"); 
   
     if (fptr == NULL) 
    { 
        perror("Error:");
        return 0;
    } 
 
    char c= fgetc(fptr);
    char prev=NULL;
    while (c != EOF) 
    { 
    	printf ("%c", c); 
        c = fgetc(fptr); 
        if(c=='\n')
        	printf("$");

        
    } 
  
    fclose(fptr);
      
      
       
  	}
  	else if(strstr(cmd,"cat -")!=NULL)
  	{
          printf("Invalid cat Command");
  	}
  	else{
  		FILE *fptr; 
       fptr = fopen(cmd+4,"r"); 
   
     if (fptr == NULL) 
    { 
        perror("Error:");
        return 0;
    } 
 
    char c= fgetc(fptr);
   
    while (c != EOF) 
    { 
    	printf ("%c", c); 
        c = fgetc(fptr); 
        
    } 
  
    fclose(fptr);
  }
  printf("\n");
  return 0;
}