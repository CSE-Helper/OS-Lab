#include<stdio.h>
void display(int a[], int size);
int main(){
   int size, i, a[10], odd[20];
   int Ecount = 0, Ocount = 0;
   printf("enter size of array :\n");
   scanf("%d", &size);
   printf("enter array elements:\n");
   for(i = 0; i < size; i++){
      scanf("%d", &a[i]);
   }
   for(i = 0; i < size; i ++){
      if(a[i] % 2 == 0){
         even[Ecount] = a[i];
         Ecount++;
      }
      else{
         odd[Ocount] = a[i];
         Ocount++;
      }
   }
   printf("no: of elements comes under odd are = %d \n", Ocount);
   printf("The elements that are present in an odd array is : ");
   display(odd, Ocount);
   return 0;
}
void display(int a[], int size){
   int i;
   for(i = 0; i < size; i++){
      printf("%d \t ", a[i]);
   }
   printf("\n");
}
