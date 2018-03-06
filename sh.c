#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parse.h"

void sighandler(int);

int main()
{
    int newpid;
    int childStatus;
    char *arglist[2048];
    char input[2048];

    signal(SIGINT, sighandler);

    printf("$ ");
    fgets(input, sizeof(input), stdin);
    parse(input, arglist);

    while(strcmp(arglist[0],"exit"))
    {
        if(!strcmp(arglist[0],"cd"))
        {
            chdir(arglist[1]);
        }
        else if((newpid = fork()) == -1)
        {
            perror("fork");
        }
        else if(newpid != 0)    // I am parent
        {
            wait(&childStatus);
        }
        else    // I am child
        {
            execvp(arglist[0], arglist);
        }
        printf("$ ");
        fgets(input, sizeof(input), stdin);
        parse(input, arglist);
    }
    return 0;
}

void sighandler(int signum)
{

}
