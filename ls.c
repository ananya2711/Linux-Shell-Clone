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
  
  if(strcmp(cmd,"ls")==0)
         {struct dirent *de;
          
          DIR *dr = opendir("."); 
           if (dr == NULL) 
             { 
               perror("Error:");
               return 0; 
            } 

           while ((de = readdir(dr)) != NULL)
          {if(strncmp(de->d_name,".",1)==0)
                     continue;
             printf("%s ", de->d_name); 
            }
      
         closedir(dr);  
          }
    else if(strcmp(cmd,"ls -i")==0)
    {
        struct dirent *de; 
          DIR *dr = opendir("."); 
           
           if (dr == NULL) 
             { 
              
              perror("Error:");
           
           return 0; 
            } 
           int num=1;
           while ((de = readdir(dr)) != NULL)
          {if(strncmp(de->d_name,".",1)==0)
                     continue;
             printf("%d->%s ",num,de->d_name); 
             num++;
    }
    
     closedir(dr);  
    }
    else if(strcmp(cmd,"ls -a")==0)
    {
        struct dirent *de; 
          DIR *dr = opendir("."); 
  
           if (dr == NULL) 
             { 
           perror("Error:");
           return 0; 
            } 
           
           while ((de = readdir(dr)) != NULL)
          {
             printf(" %s ", de->d_name); 
            
    }
  
    closedir(dr); 

    }
    else
      printf("Invalid ls command");
    printf("\n");
 
  return 0;
}