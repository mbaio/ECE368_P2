#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000000

int main()
{
  {
  int arr[SIZE];
  int ind;
  int n = SIZE;
  int rando = 1;
  for (ind = 0; ind < SIZE; ind++)
  {
    list[ind] = rando * rand() % 2147483647; // random
   // rando *= -1;
   
  // list[ind] = ind; // sorted 
    
  //list[ind] = SIZE - ind; //reverse sorted
    

  }
  for(ind = 90000; ind < 90150; ind++){
    list[ind] = rand() % 400;
}


double start = clock();
void sort(list, n);
double end = clock();

for (ind = 0; ind < n; ind++)
{
  if (list[ind] > list[ind + 1]){
    printf("NOT SORTED\n");
    break;}
}

printf("\nTime taken: %f\n",(double) (end - start) / CLOCKS_PER_SEC);