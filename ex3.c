#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CMD_LEN 20

int     main()
{
    char    cmd[CMD_LEN];

    scanf("%s", cmd);
    system(cmd);
    return (0);
}
