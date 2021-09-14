#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define LEN 50

int     main()
{
    char    cmd[LEN];
    char    *argv[LEN];
    int     counter;
    int     flag;
    pid_t   p;
    int     s;

    scanf ("%[^\n]%*c", cmd);

    counter = 0;
    argv[counter] = strtok(cmd, " ");
    while (argv[counter++] != NULL)
        argv[counter] = strtok(NULL, " ");

    flag = !strcmp(argv[counter-2], "&");
    if (flag)
        argv[counter-2] = NULL;
    p = fork();
    if (!flag)
        execvp(argv[0], argv);
    else
    {
        if (p < 0)
        {
            printf("Unable to create child process.\n");
            return (1);
        }
        else if (p == 0)
            execvp(argv[0], argv);
        else
            wait(&s);
    }
    return (0);
}
