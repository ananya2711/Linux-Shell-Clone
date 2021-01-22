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

int main(){ 
  //welcome();
  //commands();
  char cmd[100];
  char history[100][100];
  int ptr=0;
  int ctr=0;
  printf("Please Provide Valid Commands\n");
  do{
   printf(">>>");
   gets(cmd); 
   strcpy(history[ctr],cmd);
   ctr++;
   if(ctr==100)
   {
   	printf("History has been cleared");
   	ctr=0;
   	ptr=0;
   }
  	if(strncmp(cmd,"ls",2)==0)
  	{  
  		  pid_t pid;
       pid=fork();
       if(pid<0)
     {
       perror("Error:");
       return 1;
     }
   else if(pid==0)
   {
    char field[100];
    char *path=strcat(strcpy(field,getenv("PWD")),"/ls");
    execlp(path,"./ls",cmd,NULL);
    perror("exec error:");
    exit(0);

  }
  else
  {
    wait(NULL);
  }

  	}
  else if(strncmp(cmd,"cat",3)==0)
  {
  	
      pid_t pid;
       pid=fork();
       if(pid<0)
     {
       perror("Error:");
       return 1;
     }
   else if(pid==0)
   {
    char field[100];
    char *path=strcat(strcpy(field,getenv("PWD")),"/cat");
    execlp(path,"./cat",cmd,NULL);
    perror("exec error:");
    exit(0);

  }
  else
  {
    wait(NULL);
  }
  }
  else if(strncmp(cmd,"date",4)==0)
  {
  	    pid_t pid;
       pid=fork();
       if(pid<0)
     {
       perror("Error:");
       return 1;
     }
   else if(pid==0)
   {
    
    char field[100];
    char *path=strcat(strcpy(field,getenv("PWD")),"/date");
    execlp(path,"./date",cmd,NULL);
    perror("exec error:");
    exit(0);

  }
  else
  {
    wait(NULL);
  }
  }
  else if(strncmp(cmd,"rm",2)==0)
		{   
      pid_t pid;
       pid=fork();
       if(pid<0)
     {
       perror("Error:");
       return 1;
     }
   else if(pid==0)
   {
    char field[100];
    char *path=strcat(strcpy(field,getenv("PWD")),"/rm");
    execlp(path,"./rm",cmd,NULL);
    perror("exec error:");
    exit(0);

  }
  else
  {
    wait(NULL);
  }
				     
       
  		}
  		else if(strncmp(cmd,"mkdir",5)==0)
  		{  

  			pid_t pid;
       pid=fork();
       if(pid<0)
     {
       perror("Error:");
       return 1;
     }
   else if(pid==0)
   {
    
    char field[100];
    char *path=strcat(strcpy(field,getenv("PWD")),"/mkdir");
    execlp(path,"./mkdir",cmd,NULL);
    perror("exec error:");
    exit(0);

  }
  else
  {
    wait(NULL);
  }
       
  		}
  	else if(strncmp(cmd,"cd",2)==0)
  	{
  		if(strcmp(cmd,"cd")==0)
  		{
             int a=chdir(getenv("HOME")); 
             if(a==-1)
             	perror("Error:");
  		}
      else if(strcmp(cmd,"cd ~")==0)
      {
             int a=chdir(getenv("HOME")); 
             if(a==-1)
              perror("Error:");
      }
  		else if(strcmp(cmd,"cd ..")==0)
  		{
               int a=chdir(".."); 
             if(a==-1)
             	perror("Error:");
  		}
  		else if(strstr(cmd,"cd -P ")!=NULL)
  		{
             
              int a=chdir(cmd+6);
             if(a==-1)
             	perror("Error:");
  		}
  		else 
  		{
            
              int a=chdir(cmd+3);
             if(a==-1)
             	perror("Error:");
  		}
      
  	}
    else if(strncmp(cmd,"echo",4)==0)
    {
    	if(strstr(cmd,"echo -n ")!=NULL)
    	{
    	  char* c= cmd+8;
   
    while (*c != '\0') 
    { 
      if(*c=='\\')
      {
        c++;
        
        continue;
      }
      printf ("%c",*c); 
          c++;
        
    } 
    continue;
    	}
    	else if(strstr(cmd,"echo -E ")!=NULL)
    	{
    		char* c= cmd+7;
   
    while (*c != '\0') 
    { 
    	printf ("%c",*c); 
          c++;
        
    } 
    	}
    else if(strstr(cmd,"echo -")!=NULL)
    {
    	printf("please enter a valid command");
    }
    else
    {
    	
    	char* c= cmd+5;
   
    while (*c != '\0') 
    { 
    	if(*c=='\\')
    	{
    		c++;
    		
    		continue;
    	}
    	printf ("%c",*c); 
          c++;
        
    } 

    }
    printf("\n");
    }

  else if(strncmp(cmd,"pwd",3)==0)
     {if(strcmp("pwd",cmd)==0 || strcmp("pwd -L",cmd)==0)
        {
    	char cwd[1000];
         getcwd(cwd, sizeof(cwd));
        setenv("OLDPWD",getenv("PWD"),1);
        setenv("PWD",cwd,1);
        printf("%s",getenv("PWD"));
        }
    else if(strcmp("pwd -P",cmd)==0)
       {
    	char s[100]; 
         printf("%s", getcwd(s, 100));
       }
    else
    	printf("Invalid pwd command");
    printf("\n");
    }
   else if(strncmp(cmd,"history",7)==0)
    {  
    	if(strcmp(cmd,"history")==0)
    	{  int i=0;
    		while(i!=ctr)
    		{ 
    			printf("\n%d %s ",i+1,history[i]);
    			i++;
    		}
    	 ptr=ctr;
    	}
    	else if(strcmp(cmd,"history -c")==0)
    	{   
    		int i=0;
    		while(i!=ctr)
    		{  history[i][0]='\0';
    			i++;
    		}
    		ctr=0;
    		ptr=0;
    	}
    	else if(strcmp(cmd,"history -n")==0)
    	{
             if(ptr==ctr)continue;
            int i=ptr;
    		while(i!=ctr)
    		{  
    			printf("\n%d %s ",i+1,history[i]);
    			i++;
    		}
    	ptr=i;

    	}
    	else 
    		printf("Invalid history command");
     printf("\n");
    }
    else if(strcmp(cmd,"exit")!=0)
      printf("Command not recognised\n");

  }while(strstr(cmd,"exit")==NULL);

	return 0;
}  	
  
