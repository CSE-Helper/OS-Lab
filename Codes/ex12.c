#include<stdio.h>
#include<dirent.h>
#include <stdlib.h>
int main()
{
    struct dirent *d;
    char filename[100], c;
    DIR *dr;
    FILE *fptr;
    dr = opendir(".");
    if(dr!=NULL)
    {
        printf("***Listing the Files & Folders of the Current Directory***\n\n");
        for(d=readdir(dr); d!=NULL; d=readdir(dr))
        {
            printf("%s\n", d->d_name);
        }
        closedir(dr);
    }
    else
        printf("\nError occurred while opening the current directory!\n");

    printf("\nEnter the filename to open:\n");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("\nFile not Available or Cannot open file \n");
        exit(0);
    }
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    return 0;
}
