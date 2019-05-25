/*
    Function expand, that expands shorthand notation like
    a-z, in s1 into equvilaent list abc...xyz in s2.
    Handle same A-Z, 0-9. Arrange the leading or trailing - is taken literally
*/
#include<stdio.h>

char s1[10];
char s2[64];

//To handle the trailing or leading hypen
int hypen_flag = 0;

//Read short hand notation
void ReadInput(void)
{
    scanf("%[^\t]s", s1);
    return;
}

void Convert(int *arr, int *num)
{
    //to mark which alpha is starting and ending in lowercase letters
    int small_aplha_start = -1;
    int small_aplha_end = -1;

    //iterating and marking those values
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] != 0)
        {
            if(small_aplha_start == -1) small_aplha_start = i;
            else    small_aplha_end = i;
        }
    }

    //to mark which alpha is starting and ending in uppercase letters
    int big_alpha_start = -1;
    int big_alpha_end = -1;

    //iterating and marking those values
    for(int i = 26; i < 52; i++)
    {
        if(arr[i] != 0)
        {
            if(big_alpha_start == -1) big_alpha_start = i - 26;
            else    big_alpha_end = i - 26;
        }
    }

    //to mark which number is starting and ending
    int num_start = -1;
    int num_end = -1;

    //iterating and marking those values
    for(int i = 0; i < 10; i++)
    {
        if(num[i] != 0)
        {
            if(num_start == -1) num_start = i;
            else num_end = i;
        }
    }

    int i = 0;
    if(hypen_flag == 1) s2[i++] = '-'; //if hypen exits as leading or trailing

    //iterating and copying the char into s2
    for(;small_aplha_start != -1 && small_aplha_start <= small_aplha_end; small_aplha_start++)
        s2[i++] = small_aplha_start + 'a';
    for(;big_alpha_start != -1 && big_alpha_start <= big_alpha_end; big_alpha_start++)
        s2[i++] = big_alpha_start + 'A';
    for(;num_start != -1 && num_start <= num_end; num_start++)
        s2[i++] = num_start + '0';

    s2[i] = '\0';
    return;
}

//fill an array with 0
void Fill(int *a, int n)
{
    for(int i = 0; i < n; i++)
        a[i] = 0;
    return;
}

void Expand(void)
{
    //to mark which notation to expand
    //0-25 == a-z
    //26-52 == A-Z
    int arr[52];
    //0-9 == 0-9
    int num[10];

    //fill initial values as zeroes
    Fill(arr, 52);
    Fill(num, 10);

    int i = 0;

    //checking for a leading hypen
    if(s1[0] == '-') hypen_flag = 1;

    for(; s1[i] != '\0'; i++)
    {
        //check if it is non hypen and update the array index accordingly
        if(s1[i] >= 'A' && s1[i] <= 'Z') arr[(s1[i] - 'A') + 26]++;
        else if(s1[i] >= 'a' && s1[i] <= 'z') arr[s1[i] - 'a']++;
        else if(s1[i] >= '0' && s1[i] <= '9') num[s1[i] - '0']++;
    }

    //checking trailing hypen
    if(s1[i - 2] == '-') hypen_flag = 1;

    //convert the short notation to expand in s2
    Convert(arr, num);
    return;
}

int main(void)
{
    ReadInput();
    Expand();
    printf("%s\n", s2);
    return 0;
}
