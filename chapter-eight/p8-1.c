/*
    Rewrite the program cat from Chapter 7 using read , write , open
     and close instead of their standard library equivalents.
*/
#include <stdio.h>          //standard function call definitions
#include <fcntl.h>          //system call function definitions

#define BUFSIZE     1024
#define PERMS       0666

void FileCopy(int ifd, int ofd)         //input and output descriptors
{
    int n = 0;
    char buf[BUFSIZE];

    while((n = read(ifd, buf, BUFSIZE)) > 0 )
        if(write(ofd, buf, n) != n)
            {printf("cat: can't write");exit(1);}
    return;
}

int main(int argc, char const *argv[])
{
    int f1 = 0, f2 = 0;
    void FileCopy(int ifd, int ofd);            //function declaration

    if(argc == 1)
        FileCopy(0, 1);                         //read from default stream and write to default stream(i.e keyboard->screen)
    else
    {
        while(--argc > 0)
        {
            if((f1 = open(argv[1], O_RDONLY, 0)) == -1)
                {printf("cat: can't open %s", argv[1]); exit(1);}
            if((f2 = creat(argv[2], PERMS)) == -1)
                {printf("cat: can't create %s with %3o permission", argv[1], PERMS); exit(1);}
            FileCopy(f1, f2);
            close(f1);
            close(f2);
        }
    }
    return 0;
}
