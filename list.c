#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
void list(char c,char *dn)
{
      DIR *dir;
      int cnt=0;
      struct dirent *entry;
      struct stat buff;
      if((dir=opendir(dn))==NULL)
      {
            printf("\nDirectory %s is not found.",dn);
            return;
      }
      switch(c)
      {
            case 'f':while((entry=readdir(dir))!=NULL)
                   {
                         stat(entry->d_name,&buff);
                         printf("\n%s\n",entry->d_name);
                   }
                   break;
            case 'n':while((entry=readdir(dir))!=NULL)
                         cnt++;
                   printf("\nTotal number of Entries::%d\n",cnt);
                   break;
            case 'i':while((entry=readdir(dir))!=NULL)
                   {
                         stat(entry->d_name,&buff);
                         printf("\n%s\t%d\n",entry->d_name,buff.st_ino);
                   }
                   break;
      }
}
void main()
{
      char com[80],t1[20],t2[20],t3[20],t4[20];
      int n;
      system("clear");
      while(1)
      {
            printf("myShell ");
            fflush(stdin);
            fgets(com,80,stdin);
            n=sscanf(com,"%s %s %s %s",t1,t2,t3,t4);
            if(strcmp(t1,"list")==0)
                  list(t2[0],t3);
            else
                  exit(0);
      }
}
