#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main()
{
    int myPipe[2];
    char c = 'a';
    int i=0, writing=1;

    fprintf(stdout, "Pipe Creation\n");
    
    if( pipe(myPipe) != 0)
    {
        fprintf (stderr, "pipe\n");
        exit(1);
    }
    fprintf(stdout, "Writing in pipe\n");
    while( writing )
    {
        fprintf(stdout, "%d ", i+1);
        if( 1 != write(myPipe[1], &c, 1) )
        {
            fprintf(stdout, "intra");
            writing = 0;
            //fprintf(stdout, "%d ", i+1);
            //fprintf (stderr, "write\n");
            //exit(1);
        }
        i++;
    }
    return 0;
}