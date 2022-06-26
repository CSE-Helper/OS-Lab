#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    int n;
    printf("Enter the number of processes to be created\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        if (fork()==0)
        {
            printf("\t[child] pid %d from[parents] pid %d\n",getpid(),getppid());
            exit(0);
        }
    }
    return 0;
}
