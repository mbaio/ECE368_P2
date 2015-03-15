  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  void radixSort(int *data, int n) {
        int bucket[10], dummy[n], max, i, index, lsd = 1;
        max = data[0];
        /* find the largest key */
        for (i = 0; i < n; i++) {
                if (data[i] > max)
                        max = data[i];
        }
        while (max / lsd > 0) {
                memset(bucket, 0, sizeof(int) * 10);
                memset(dummy, 0 , sizeof(int) * n);
                /*
                 * lsd - indicates the significant bit that we
                `* handle currently.  Update the counters for the
                 * elements that has same(current) significant
                 * bit into the bucket. Eg: if bucket[9] is 2
                 * and lsd is 1, then user input has two of the
                 * data with least significant value as 9(199, 299)
                 */
                for (i = 0; i < n; i++) {
                        index = (data[i] / lsd) % 10;
                        bucket[index]++;
                }

                /*
                 * update all the buckets. If bucket[8] has 2,
                 * then there are 2 elements present till bucket 8
                 * Basically, its is the cumulative sum of count in 
                 * current bucket & previous buckets(0 to 7).
                 */
                for (i = 1; i < 10; i++)
                        bucket[i] = bucket[i] + bucket[i-1];


                /* sort the elements based on current significant digit */
                for (i = n-1; i >= 0; i--) {
                        index = (data[i] / lsd) % 10;
                        index = --bucket[index];
                        dummy[index] = data[i];
                }

                /* update original with dummy */
                for (i = 0; i < n; i++)
                        data[i] = dummy[i];
                lsd = lsd * 10;
        }
  }

  int main() {
        int *data, i, n;
        printf("Enter the no of entries:");
        scanf("%d", &n);
        data = (int *)malloc(sizeof (int) * n);
        printf("Enter your inputs:\n");
        for (i = 0; i < n; i++) {
                scanf("%d", &data[i]);
        }
        radixSort(data, n);
        printf("Data After Sorting:\n");
        for (i = 0; i < n; i++)
                printf("%-5d ", data[i]);
        printf("\n");
        return 0;
  }