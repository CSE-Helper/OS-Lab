#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(void){
DIR *d;//Stores all sub directory and file information
struct dirent *dir;//dir stores individual file / directory details
char *filename;//to store the filename
char *command ="/bin/wc";
char *arg1 = "-w";
int i=0;
d=opendir(".");
if(d){
while((dir=readdir(d))!=NULL){
if(dir->d_type==DT_REG){
//Retrive the file name and pass it as third option
filename = (char *) malloc(sizeof(char)*strlen(dir->d_name));
strncat(filename,dir->d_name,strlen(dir->d_name));
//create a new child process and execute execl call
if(fork()==0){
execl(command,command,arg1,filename,NULL);
}
i++;
}
}
closedir(d);
}
return 0;
}
