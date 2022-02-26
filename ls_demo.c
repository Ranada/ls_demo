#include <stdio.h>
#include <dirent.h>
#include <string.h>

void check_arguments(char** argc, struct dirent *entry);

int main(int argv, char** argc)
{
   
    DIR *folder;
    struct dirent *entry;
    int files = 0;

    folder = opendir(".");
    if(folder == NULL)
    {
        perror("Unable to read directory");
        return(1);
    }

    while( (entry = readdir(folder)) )
    {
        files++;

        if (argv == 1)
        {
            printf("File %3d: %s\n",
                files,
                entry->d_name
              );
        }
        else
        {
            check_arguments(argc, entry);
        }
    }

    closedir(folder);

    return(0);
}

void check_arguments(char** argc, struct dirent *entry)
{
    // printf("Argc[1]: %s\n", argc[1]);         
    // printf("File name: %s\n", entry->d_name);

    if (strcmp(argc[1], entry->d_name) == 0)
    {
        printf("%s\n", entry->d_name);
    }
}
