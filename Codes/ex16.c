#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(void){
DIR *d,*td;//Stores all sub directory and file information
struct dirent *dir,*tempdir;//dir stores individual file / directory details
char *filename="sona";//to store the filename
char *fname="sona.txt";
char *command ="/bin/cat";
char *command2="/bin/rm";
//char *arg1 = "-w";
int tf=0;
int i=0;
d=opendir(".");
if(d){
while((dir=readdir(d))!=NULL) {
if(dir->d_type==DT_REG && strcmp(fname,dir->d_name)==0) {
if(tf!=1){
system("cat sona.txt");
tf=1;
break;
}
}
}
closedir(d);
}
l1:
printf("Start\n\n");
d=opendir(".");
if(d){
while((dir=readdir(d))!=NULL){
if(dir->d_type==DT_DIR && strcmp(".",dir->d_name)!=0 && strcmp("..",dir->d_name)!=0 ){
td = opendir(dir->d_name);
while((tempdir=readdir(td))!=NULL){
if(tempdir->d_type==DT_REG && strcmp(fname,tempdir->d_name)==0) {
if(tf!=1){
chdir(dir->d_name);
system("cat sona.txt");
chdir("..");
tf=1;
break;
}else{
chdir(dir->d_name);
printf("\nDeteting file from %s\n",dir->d_name);
system("rm sona.txt");
chdir("..");
tf=1;
break;
}
}
}
closedir(td);
}
}
closedir(d);
}
return 0;
}
