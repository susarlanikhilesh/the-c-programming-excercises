/*
    Finding key words and their count.

    Note:
    Does not solve the exercise problem.
*/
#include <stdio.h>
#include <string.h>

#define FAST        1
#define MAXLEN      100

struct keyword
{
    char word[MAXLEN];
    int count;
};

int getWord(char *s, int n)
{
    int i = 0, c = 0;
    while(i < n && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void Push(struct keyword *k, int i)
{
    k[i].count++;
    return;
}

int LinearSearch(struct keyword *k, char *s, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(strcmp(k[i].word, s) == 0)
            return i;
    }
    return -1;
}

int BinarySearch(struct keyword *k, char *s, int n)
{
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int temp = strcmp(k[mid].word, s);
        if(temp < 0)
            low = mid + 1;
        else if(temp > 0)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

void Search(struct keyword *k, char *s, int n)
{
    int idx = FAST == 1 ? BinarySearch(k, s, n) : LinearSearch(k, s, n);
    if(idx > -1) Push(k, idx);
    return;
}

void CountCKeywords(struct keyword *k, int n)
{
    char w[MAXLEN];
    while(getWord(w, MAXLEN) > 0)
    {
        if(!isalpha(w[0]))
            continue;
        Search(k, w, n);
    }
    return;
}

int main(void)
{
    struct keyword k[] = {
                {"auto", 0},
                {"break", 0},
                {"case", 0},
                {"char", 0},
                {"const", 0},
                {"continue", 0},
                {"default", 0},
                {"unsigned", 0},
                {"void", 0},
                {"volatile", 0},
                {"while", 0}
    };

    CountCKeywords(k, (sizeof(k) / sizeof(k[0])));

    for(int i = 0; i < (sizeof(k)/ sizeof(k[0])); i++)
    {
        printf("%i %s\n", k[i].count, k[i].word);
    }
}
