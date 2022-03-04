#include "ls_demo.h"

void list_files(const char* dir_name)
{
    DIR *folder;
    struct dirent *entry;

    folder = opendir(dir_name);
    entry = readdir(folder);

    if (folder == NULL)
    {
        perror("Unable to read directory");
        return;
    }
    
    int file = 0;
    while (entry != NULL)
    {
        if (entry->d_name[0] != '.')
        {
            file++;
            printf("\tFile %d \t%hhu  %s \t%c\n", file, entry->d_type, entry->d_name, entry->d_name[0]);
        }

        entry = readdir(folder);
    }

    closedir(folder);
}

void explore_directory(int argc, char** argv)
{   
    check_for_files(argc, argv);
    check_for_sub_directories(argc, argv);    
}

// If one argument and is a folder -> display name
void check_for_files(int argc, char** argv)
{
    DIR *folder;
    struct dirent *entry;

    folder = opendir(".");
    entry = readdir(folder);

    while (entry != NULL)
    {   
        int index = 1;
        while (index < argc)
        {
            if (entry->d_type == DT_REG && strcmp(entry->d_name, argv[index]) == 0 )
            {
            printf("File name: %s\n", entry->d_name);
            break;
            }
            index++;
        }
        entry = readdir(folder); 
    }
    printf("\n");

    closedir(folder);
}

// If one argument is a directory -> display items inside
void check_for_sub_directories(int argc, char** argv)
{
    DIR *folder;
    struct dirent *entry;

    folder = opendir(".");
    entry = readdir(folder);

    while ((entry = readdir(folder)) != NULL)
    {
        int j = 1;
        
        while (j < argc)
        {
            if (entry->d_type == DT_DIR && strcmp(entry->d_name, argv[j]) == 0)
            {
                printf("Sub-directory name: %s\n", entry->d_name);
                list_files(entry->d_name);
                printf("\n");
                break;
            }
            j++;
        }
    }

    closedir(folder);
}