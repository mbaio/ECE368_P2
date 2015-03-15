#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#define SIZE 1000000


/*
  0 - Random
  1 - 90% Sorted
  2 - 90 % Reverse Sorted
  3 - non-negative
*/


int cmpfunc (const void * a, const void * b);
void insertion_sort(int *, int);
void radix_sort(int *, int);

int findLargestNum(int * array, int size);

// Radix Sort
void radix_sort(int * array, int size){
  

  // Base 10 is used
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);
  
  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0){
    
    
    int bucket[10] = { 0 };
    
    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;
    
    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    
    // Use the bucket to fill a "semiSorted" array
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];
    
    
    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];
    
    // Move to next significant digit
    significantDigit *= 10;
    
  }
}

int findLargestNum(int * array, int size){
  
  int i;
  int largestNum = -1;
  
  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }
  
  return largestNum;
}


 void insertion_sort(int * arr, int num)
 {
    int temp;
    int i;
    int j;
    for (i = 1; i < num; i++) {
   
      temp = arr[i];
      j = i - 1;
      while ((temp < arr[j]) && (j >= 0)) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = temp;
   }
  
 }

// int main(int argc, char ** argv)
// {
//   int arr[SIZE];
//   int arr2[SIZE];
//   int ind;
//   int num = SIZE;
//   int rando = 1;
//   for (ind = 0; ind < SIZE; ind++)
//   {
//     arr[ind] = rando * rand() % 2147483647; // random
//    // rando *= -1;
//     //arr2[ind] = rand() % 10000; // random
//    
//   // arr[ind] = ind; // sorted 
//     //printf("%d \n",arr[ind]);
//     //arr2[ind] = ind; // sorted
//   //arr[ind] = SIZE - ind; //reverse sorted
//   // arr2[ind] = SIZE - ind;
//     
// 
//   }
//   for(ind = 90000; ind < 90150; ind++){
//     arr[ind] = rand() % 400;
// }
  
  
  int type = 0;
  int test = 1;
  int count_sort = 0;
  
//double start = clock();
    int neg = 0;
    //Check if sorted
    for (ind = 0; ind < num; ind ++)
    {
      if (ind != num - 1 && arr[ind] > arr[ind + 1] )
      {
	count_sort++;
      }
	  if (arr[ind] < 0)
	    neg = 1;
    }
   // printf("num sorted = %d\n",count_sort);
    
    if (count_sort < 100)
      type = 1;
   
   
    
    
  
  if (type == 1)
    insertion_sort(arr,num);
  else if (!neg) {
   // printf("in neg\n\nintital list:\n");

	

//     int * arr_neg = malloc(sizeof(int) * num);
//     int * arr_pos = malloc(sizeof(int) * num);
// 	int ind_neg = 0;
// 	int ind_pos = 0;
// 	for (ind = 0; ind < num; ind++)
// 	{
// 	  if (arr[ind] < 0){
// 	    arr_neg[ind_neg] = -1 * arr[ind];
//         ind_neg++;
// 		}
//       else {
// 	    arr_pos[ind_pos] = arr[ind];
// 		ind_pos++;
// 		}
//     }
//    // printf("neg array:\n");
//     for (ind = 0; ind  < ind_neg; ind++)
//     {
//     //  printf("%d, ",arr_neg[ind]); 
//     }
// 	printf("\npos array\n");
//     for (ind = 0; ind  < ind_pos; ind++)
//     {
//      // printf("%d, ",arr_pos[ind]); 
//     }
// 	
// 	int * arr_neg2 = malloc(sizeof(int) * ind_neg);
// 	int * arr_pos2 = malloc(sizeof(int) * ind_pos);
// 	memcpy(arr_neg2,arr_neg,ind_neg * sizeof(int));
// 	memcpy(arr_pos2,arr_pos,ind_pos * sizeof(int));
//     radix_sort(arr_neg2,ind_neg);
// 	radix_sort(arr_pos2,ind_pos);
// 
// 	//printf("\nSorted neg:\n");
// 	
//     for (ind = 0; ind  < ind_neg; ind++)
//     {
//      // printf("index: %d = %d,   ",ind,arr_neg2[ind]); 
//     }
// 	//printf("\nsorted pos:\n");
// 
//     for (ind = 0; ind  < ind_neg; ind++)
//     {
//     // printf("index: %d = %d,   ",ind, arr_pos2[ind]); 
//     }
//    // printf("\nind_neg = %d arrayneg_final\n",ind_neg);
// 	int * arr_neg_final = malloc(sizeof(int) * num);
// 	for (ind = 0; ind < num; ind++)
// 	{
// 	  if (ind < ind_neg)
// 	  	arr_neg_final[ind] = -1 * arr_neg2[ind_neg - ind - 1];
// 	 // printf("index: %d =  %d,  ",ind,arr_neg_final[ind]);
// 	  
// 	 
//     }
// 	memcpy(arr_neg_final + ind_neg,arr_pos2,ind_pos * sizeof(int));
// 	printf("\nfinal array:\n\n");
// 	for (ind = 0; ind < num; ind++)
// 	{
// 	  arr[ind] = arr_neg_final[ind];
// 	  //printf("%d\n",arr[ind]);
// 	}
      radix_sort(arr,num);
}

  else {
    //printf("qsort\n");
    qsort(arr,num,sizeof(int),cmpfunc);}
  
 
  
  //double end = clock();
 // printf("List type: %d\n",type);
 // printf("Time took to measure: %f\n",(double) (end - start) / CLOCKS_PER_SEC); 
//   for(ind = 0; ind < SIZE; ind++)
//   {
//     if (ind != SIZE - 1 && arr[ind] > arr[ind + 1]){
//       printf("not sorted\n");
//       break;}
//   }
//   printf("\n\n");
//   return 0;
// }

int cmpfunc (const void * a, const void * b)
{
   if ( *(int *)a > *(int *)b)
     return 1;
   if ( *(int *)a == *(int *)b)
     return 0;
   return -1;
  // return ( *(int*)a - *(int*)b );
}
