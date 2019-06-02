/*

    Write a program that reads a C program and prints in alphabetical order each group of variable names
    that are identical in the first 6 characters but different somewhere thereafter.
    Don't count words within strings and comments.
    Make 6 a parameter that can be set from the command line.

    Note :
    Not the exact program that was mentioned in the exercise.
    This program does not consider variable names and rather classify
    all given input words and categorize them
*/
#include <stdio.h>      //standard input and output functions
#include <stdlib.h>     //memory allocation functions
#include <string.h>     //string len functions

//variable len can have upto 20 characters
#define MAXLEN          20
//max group members an array of pointers can hold
#define MAXWORDS        100

struct node
{
    /*
        *w = group leader who has different upto n characters
        *sw[MAXWORDS] = group members who have similar name upto n characters, MAXWORDS refer to how many group members it can point to. (array of pointers)
        idx = to maintain a count of number of group members
        *left; = *right = to point to the left of the tree(binary tree)
    */
    char *w;
    char *sw[MAXWORDS];
    int idx;
    struct node *left;
    struct node *right;
};

int getWordVariableNameString(char *s, int n)
{
    /*
        Read each line and strstr for basic data types in string s.
        If found any, obtain the pointer of the data type and traverse till the
        variable name and save it in a string and return.
        perform for every data type, extract and return
    */
}

int getWordNormalString(char *s, int n)
{
    int i = 0, c = 0;
    while(i < n && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

struct node *talloc(void)
{
    return (struct node*)malloc(sizeof(struct node) * 1);
}

char *strdupM(char *s)
{
    char *p;
    p = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    if(p != NULL)
        strcpy(p, s);
    return p;
}

struct node *AddNodeToTree(struct node *t, char *s, int n)
{
    if(t == NULL)                       //found new node
    {
        t = talloc();                   //allocate memory for node
        t->w = strdupM(s);              //point to the memory of the group leader
        t->left = t->right = NULL;      //child nodes are empty
    }
    else
    {
        int temp = strncmp(t->w, s, n);     //to find group members
        if(temp == 0)                                                      //if found
        {
            if(strcmp(t->w, s) != 0)                                       //check if he was not the group leader
            {
                char *w = (char*)malloc(sizeof(char) * (strlen(s) + 1)); //allocate memory for group member
                strcpy(w, s);
                t->sw[t->idx] = w;                                      //point the group member arr ptr to that word
                t->idx++;
            }
        }
        else if(temp > 0)
            t->left = AddNodeToTree(t->left, s, n);                 //traverse upto leaf node to insert as the value is lexicographically less
        else
            t->right = AddNodeToTree(t->right, s, n);               //traverse upto leaf node to insert as the value is lexicographically more
    }
    return t;
}

void PrintTree(struct node *t)
{
    if(t != NULL)
    {
        PrintTree(t->left);
        printf("group leader = %s, %i group members\n", t->w, t->idx);
        for(int i = 0; i < t->idx; i++)
            printf("\t%s", t->sw[i]);
        printf("\n");
        PrintTree(t->right);
    }
    return;
}

int main(int argc, char const *argv[])
{
    //read variable_len_check value from cmd to differentiate n characters for variable names
    if(argc == 2)
    {
        int variable_len_check = atoi(argv[1]);     //read this from argv
        struct node *root = NULL;                   //root of the tree
        char word[MAXLEN];                          //to store each word read from input

        while((getWordNormalString(word, MAXLEN)) > 0)          //to read input from user
        {
            root = AddNodeToTree(root, word, variable_len_check); //insert node in tree
        }
        PrintTree(root); //print tree and its members
    }

    return 0;
}
