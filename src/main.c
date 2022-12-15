#include <stdio.h>
#include <stdlib.h>
#include "csd_grp.h"
#include <errno.h>
#include <grp.h>

int main(int argc, char **argv)
{
    struct group *grp;

    csd_setgrent();
    while ((errno = 0, grp = csd_getgrent()) != NULL)
    {
        puts("\n=====================================================");
        fprintf(stdout, "Group name     : %s\n", grp->gr_name);
        fprintf(stdout, "Group password : %s\n", grp->gr_passwd);
        fprintf(stdout, "Group ID       : %llu\n", (unsigned long long)grp->gr_gid);

        fprintf(stdout, "Supplementary group members : ");
        for (size_t i = 0; grp->gr_mem[i] != NULL; ++i)
            fprintf(stdout, "%s, ", grp->gr_mem[i]);

    }

    if (errno)
        perror("csd_getgrnam");

    csd_endgrent();
}