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
  if(strstr(cmd,"rm -i")!=NULL)
					{  
						  		FILE *fptr; 
						       fptr = fopen(cmd+6,"r"); 
						   
						     if (fptr == NULL) 
						    { 
						       perror("Error:");
						        return 0;
						    } 

						    fclose(fptr);
						 
						       char c[2];
						       printf("Are you sure you wish to delete %s (Y/N)",cmd+6);
						       gets(c);
						 
						       if(strstr(c,"Y"))
						       {
						       
						       printf(" %s Removed \n",cmd+6);
						       	remove(cmd+6); 
						       	       
				                }
				    }
				    else if(strstr(cmd,"rm -f ")!=NULL)
				  	{
				    
						  		FILE *fptr; 
						       fptr = fopen(cmd+6,"r"); 
						   
						     if (fptr == NULL) 
							    { 
							    	return 0;
							    } 
						     fclose(fptr);
						     remove(cmd+6);   
				  
				    
				  	}
				  	else if(strstr(cmd,"rm -")!=NULL)
				  	{
				          printf("Invalid rm Command\n");
				  	}
				  	else
				  	{
				  	
						  		FILE *fptr; 
						       fptr = fopen(cmd+3,"r"); 
						   
						     if (fptr == NULL) 
						    { 
						    	perror("Error:");
						       return 0;
						    } 
						     fclose(fptr);
						     remove(cmd+3);   
						  
						    
				  }

  return 0;
}