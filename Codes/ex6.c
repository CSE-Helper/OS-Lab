#include<stdio.h>
#include<unistd.h>
int main(){
    pid_t pid;
    char*const paramList[]={"/bin/date",NULL};
    pid=fork();
    printf("%d\n",pid);
    if(pid==-1){
        printf("Error is creating child process\n");
    }
    else if(pid==0){
        execv("/bin/date",paramList);
    }
    else{
        printf("Child process pid is %d\n",getpid());
    }
    return 0;
}
