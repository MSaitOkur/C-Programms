// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <errno.h>

// // combine <filename> <partsize>
// // part files: part%03d.par
// // combine <newfilename>

// #define MAX_LEN 100

// int main(int argc, char **argv)
// {
//     char new_file_name[MAX_LEN];
//     if (argc != 2)
//     {
//         fprintf(stdout, "Enter the new file name: ");
//         scanf("%s", new_file_name);
//     }
//     else
//         strcpy(new_file_name, argv[1]);

//     FILE *dest_file;
//     if ((dest_file = fopen(new_file_name, "wb")) == NULL)
//     {
//         fprintf(stdout, "%s couldn't created!\n", new_file_name);
//         exit(EXIT_FAILURE);
//     }

//     size_t part_file_count = 0;
//     size_t total_byte_count = 0;
//     char part_file_name[MAX_LEN];
//     while (1)
//     {
//         sprintf(part_file_name, "part%03zu.par", part_file_count + 1);
//         FILE *file_part;
//         if ((file_part = fopen(part_file_name, "rb")) == NULL)
//             break;
//         ++part_file_count;

//         int c;
//         while ((c = fgetc(file_part)) != EOF)
//         {
//             fputc(c, dest_file);
//             ++total_byte_count;
//         }

//         fclose(file_part);
//     }

//     fprintf(stdout, "Totally %zu byte and %zu part files combined to create %s file.\n",
//             total_byte_count, part_file_count, new_file_name);

//     for (size_t i = 1; i <= part_file_count; ++i)
//     {
//         sprintf(part_file_name, "part%03zu.par", i);

//         if (remove(part_file_name))
//         {
//             fprintf(stderr, "File couldn't delete!...: \n");
//             puts(strerror(errno));
//             exit(EXIT_FAILURE);
//         }
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// parsefile <filename> <partsize>
// file 2356byte
// parsefile file 1000
// part001.par --> 1000byte
// part002.par --> 1000byte
// part003.par -->  356byte

#define MAX_LEN 100

int main(int argc, char **argv)
{
    char source_file_name[MAX_LEN + 1];
    size_t partsize;

    if (argc != 3)
    {
        fprintf(stdout, "Enter source file name: ");
        scanf("%s", source_file_name);

        fprintf(stdout, "Enter the part files' size: ");
        scanf("%zu", &partsize);
    }
    else
    {
        strcpy(source_file_name, argv[1]);
        partsize = atoi(argv[2]);
    }

    FILE *fsource;
    if ((fsource = fopen(source_file_name, "r")) == NULL)
    {
        fprintf(stderr, "%s couldn't opened!...\n", source_file_name);
        exit(EXIT_FAILURE);
    }

    int c;
    size_t byte_count = 0;

    char part_file_name[MAX_LEN + 1];
    size_t part_count = 0;
    FILE *fpart = NULL;

    while ((c = fgetc(fsource)) != EOF)
    {
        if (fpart == NULL)
        {
            sprintf(part_file_name, "part%03zu.par", part_count + 1);
            if ((fpart = fopen(part_file_name, "w")) == NULL)
            {
                fprintf(stderr, "%s couldn't opened!...\n", part_file_name);
                fclose(fsource);
                exit(EXIT_FAILURE);
            }
            ++part_count;
        }
        fputc(c, fpart);
        ++byte_count;

        if (byte_count % partsize == 0)
        {
            fclose(fpart);
            fpart = NULL;
        }
    }

    if (fpart)
        fclose(fpart);
    fclose(fsource);

    fprintf(stdout, "%s(%zu Byte) was parsed by %zu files\n", source_file_name, byte_count, part_count);
}