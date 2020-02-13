#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
    int pid, p1[2], p2[2];
    int number;
    char info;
    if (-1 == pipe(p1))
    {
        perror("Error creating the pipe");
        exit(1);
    }

    if (-1 == pipe(p2))
    {
        perror("Error creating the pipe");
        exit(1);
    }

    if (-1 == (pid = fork()))
    {
        perror("Error creating the child process");
        exit(2);
    }

    if (pid) //parent process
    {

        number = 123;
        if (write(p1[1], &number, 1) == -1) //write a random number in the pipe
        {
            perror("Error writing in the pipe");
        }

        //close writing end so the child can read from the pipe
        close(p1[1]);

        //wait for the child to finish
        wait(NULL);

        if (read(p2[0], &info, 1) != 0)
        {
            if (info == 'y')
            {
                printf("%d is even \n", number);
            }
            else
            {
                printf("%d is odd \n", number);
            }
        }
    }
    else //child process
    {
        int nr;
        char ch;

        if (read(p1[0], &nr, sizeof(int)) != 0) //read the number from the pipe
        {    
        if (nr % 2 == 0)
            {
                ch = 'y';
                write(p2[1], &ch, 1);
            }
            else
            {
                ch = 'n';
                write(p2[1], &ch, 1);
            }
        }
        close(p2[1]); //close the writing end so the parent can read from the pipe
        exit(3);
        
    }
    return 0;
}
