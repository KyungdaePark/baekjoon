                                                                                          37,1          Bot
#include<stdio.h>
#include<string.h>
#include<unistd.h>
void main(){
   char *x[10];
   char buf[20];
   char buf2[100];
   int i=0;
   int j=0;
   int y=0;
   char *token;
   for(i=0; i<5; i++){
          y=fork();
          getcwd(buf2,100);

          if(y==0){
                 printf("[%s]$ ",buf2);
                 fgets(buf,99,stdin);
                 buf[strlen(buf)-1]=0;
                 token=strtok(buf, " ");

                 for(;;){
                         if(token==NULL)break;
                         x[j]=token;
                         token=strtok(NULL," ");
                         j++;
                 }
          }
          else{
                 wait(NULL);
          }
                 x[j]=0;
                 execve(x[0], x, 0);
   }
}