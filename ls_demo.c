#include <stdio.h>
#include <dirent.h>
#include <string.h>

void list_all_files(DIR *folder, struct dirent *entry);
void explore_directory(DIR *folder, struct dirent *entry, int argv, char** argc);
void check_arguments(char** argc, struct dirent *entry);

int main(int argv, char** argc)
{
    
    // If one argument and is a directory -> display items inside
    // If one argument and is a folder -> display name
        //If option "-a" is given -> list directories whose name begins with "."
        //If option "-t" is given -> sort by time modified (most recently modified first) before sorting the operands by lexicographical order
   
    DIR *folder;
    struct dirent *entry;

    folder = opendir(".");
    entry = readdir(folder);

    if (folder == NULL)
    {
        perror("Unable to read directory");
        return(1);
    }

    // If no operands are given -> list all contents of current directory
    if (argv == 1)
    {
        list_all_files(folder, entry);
    }

    if (argv > 1)
    {
        explore_directory(folder, entry, argv, argc);
    }

    // closedir(folder);

    return(0);
}

void list_all_files(DIR *folder, struct dirent *entry)
{
    int file = 0;

    while (entry != NULL)
    {
        file++;
        printf("File %d \t%hhu  %s\n", file, entry->d_type, entry->d_name);
        entry = readdir(folder);
    }

    closedir(folder);
}

void explore_directory(DIR *folder, struct dirent *entry, int argv, char** argc)
{
    int file = 0;

    while ((entry = readdir(folder)) != NULL)
    {
        file++;
        //printf("File %d \t%hhu  %s\n", file, entry->d_type, entry->d_name);
       
        int index = 1;
        while (index < argv)
        {
            if (strcmp(entry->d_name, argc[index]) == 0 && entry->d_type == 8)
            {
                //printf("ARGC: %s\n", argc[index]);
                printf("File name: %s\n\n", entry->d_name);
            }
            else if (strcmp(entry->d_name, argc[index]) == 0 && entry->d_type == 4)
            {
                printf("-------------------------------------\n");
                printf("Directory name: %s\n", entry->d_name);

                DIR *folder = opendir(entry->d_name);
                struct dirent *entry = readdir(folder);

                list_all_files(folder, entry);
                printf("-------------------------------------\n");
            }
            
            index++;
        }
    }
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
