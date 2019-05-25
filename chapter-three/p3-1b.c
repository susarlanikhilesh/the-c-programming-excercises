/*
Execute with custom flags, as compiler does optimation, to avoid that and find the time difference
gcc -O0 -S file.c
gcc -c file.s -o file.o
gcc file.o -o executable
./executable
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

int BinarySearch2(int *arr, int x)
{
    int low = 0, high = MAX_LEN - 1;
    int mid = 0;
    while(low <= high && x != arr[mid])
    {
        mid = (low + high) / 2;
        if(x < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    if(x == arr[mid]) return 1;
    return 0;
}

int main(void)
{
    int arr[MAX_LEN];
    Fill(arr);

    clock_t t2;

    t2 = clock();
    for(int i = 0; i < MAX_LEN; i++)
    {
        BinarySearch2(arr, i);
    }
    t2 = clock() - t2;

    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds

    printf("t2 = %f\n", time_taken2);
    return 0;
}
