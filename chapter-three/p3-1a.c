/*
    To find the time diff between writing conditions within the loop and
    on the loop(while conditions)
*/

#include<stdio.h>
#include<time.h>

#define MAX_LEN 1000000

void Fill(int *arr)
{
    for(int i = 0; i < MAX_LEN; i++)
        arr[i] = i;
    return;
}

int BinarySearch1(int *arr, int x)
{
    int low = 0, high = MAX_LEN - 1;
    int mid = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(x < arr[mid]) high = mid - 1;
        else if(x > arr[mid]) low = mid + 1;
        else return 1;
    }
    return 0;
}

int main(void)
{
    int arr[MAX_LEN];
    Fill(arr);

    clock_t t1;
    t1 = clock();
    for(int i = 0; i < MAX_LEN; i++)
    {
        BinarySearch1(arr, i);
    }
    t1 = clock() - t1;

    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

    printf("t1 = %f \n", time_taken1);
    return 0;
}
