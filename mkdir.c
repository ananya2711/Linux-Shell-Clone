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
  if(strstr(cmd,"mkdir -v")!=NULL)
					{  
						  

						      
						       int r= mkdir(cmd+9,0777);
	                           if(r==-1)
	                           	perror("Error:");
	                        else
				               printf(" New Directory created\n");
				    }
				    else if(strstr(cmd,"mkdir -p ")!=NULL)
				  	{

						       int r=mkdir(cmd+9,0777);

				  	}
				  	else if(strstr(cmd,"mkdir -")!=NULL)
				  	{
				          printf("Invalid mkdir Command\n");
				  	}
				  	else
				  	{
				  	
						  		
						       int r= mkdir(cmd+6,0777);
	                           if(r==-1)
	                           perror("Error:");
				                  
						  
						    
				  }
  return 0;
}