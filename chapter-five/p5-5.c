#include <stdio.h>      //standard input output
#include <stddef.h>     //the difference of pointer data type ptrdiff_t
#include <limits.h>     //INT_MIN limits

#define MAXLEN 100

#define HELP "Options:\n"\
             "1.Copy\n"\
             "2.Concatenate\n"\
             "3.Compare\n"\

//length of a string
int FindStrLen(char *s)
{
    int count = 0;
    for(; *s != '\0' ; s++)
        count++;
     return count;
}

//Check if the n is within the len of t, Can't copy/cmp/Concatenate more than the string t
int CheckN(char *t, int n)
{
    if(n > FindStrLen(t))
        return 0;
    return 1;
}

//copying n characters from s to t
void ncpy(char *s, char *t, int n)
{
    for(int i = 0; i < n; i++)
        *s++ = *t++;
    return;
}

//copy n characters from s to t main func
void strncpyM(char *s, char *t, int n)
{
    if(!CheckN(t, n)) return;
    ncpy(s, t, n);
    return;
}

//Concatenate n characters in t to s at the end of the string
void strncatM(char *s, char *t, int n)
{
    if(!CheckN(t, n)) return;

    for(; *s != '\0'; s++);
    ncpy(s, t, n);
    return;
}

//Compare n characters from beginning in s and t
int strncmpM(char *s, char *t, int n)
{
    if(!CheckN(t, n)) return INT_MIN;
    if(!CheckN(s, n)) return INT_MIN;
    int i = 0;

    for(i = 0; i < n; i++)
    {
        ptrdiff_t diff = *s - *t;
        if(diff != 0) return diff;
        s++;
        t++;
    }
    return 0;
}

int main(void)
{
    char s[MAXLEN];
    char t[MAXLEN];

    scanf("%s", s);
    scanf("%s", t);

    int n = 0, select = 0, res = INT_MIN;

    scanf("%i", &n);

    printf(HELP);

    if(n > 0)
    {
        scanf("%i", &select);
        switch (select)
        {
            case 1:
            strncpyM(s, t, n);
                break;
            case 2:
            strncatM(s, t, n);
                break;
            case 3:
            res = strncmpM(s, t, n);
                break;
            default : printf("wrong key\n");
        }
    }
    if(select == 3)
        printf("%i\n", res);
    else
        printf("%s\n", s);

    return 0;
}
