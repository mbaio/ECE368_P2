#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>



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

  
  void sort(int list[], int n)
{
  int type = 0;
  int count_sort = 0;
  int num = n;
  int ind;
  
    int neg = 0;
    //Check if sorted
    for (ind = 0; ind < num; ind ++)
    {
      if (ind != num - 1 && list[ind] > list[ind + 1] )
      {
	count_sort++;
      }
	  if (list[ind] < 0)
	    neg = 1;
    }
  
    
    if (count_sort < 100)
      type = 1;
   
   
    
    
  
  if (type == 1)
    insertion_sort(list,num);
  else if (!neg) {
      radix_sort(list,num);
    }
  else {
    qsort(list,num,sizeof(int),cmpfunc);}
    
}
  
 

int cmpfunc (const void * a, const void * b)
{
   if ( *(int *)a > *(int *)b)
     return 1;
   if ( *(int *)a == *(int *)b)
     return 0;
   return -1;
  
}
