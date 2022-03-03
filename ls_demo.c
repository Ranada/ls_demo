#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

void list_all_files(const char* dir_name);
void explore_directory(int argc, char** argv);

int main(int argc, char** argv)
{
    
    // If one argument and is a directory -> display items inside
    // If one argument and is a folder -> display name
        //If option "-a" is given -> list directories whose name begins with "."
        //If option "-t" is given -> sort by time modified (most recently modified first) before sorting the operands by lexicographical order

    // If no operands are given -> list all contents of current directory
    if (argc == 1)
    {
        printf("Parent directory: %s\n", argv[0]);
        list_all_files(".");
    }

    if (argc > 1)
    {
        explore_directory(argc, argv);
    }

    return(0);
}

void list_all_files(const char* dir_name)
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
        file++;
        printf("\tFile %d \t%hhu  %s\n", file, entry->d_type, entry->d_name);
        entry = readdir(folder);
    }

    closedir(folder);
}

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
                list_all_files(entry->d_name);
                printf("\n");
                break;
            }
            j++;
        }
    }

    closedir(folder);
}

void explore_directory(int argc, char** argv)
{   
    check_for_files(argc, argv);
    check_for_sub_directories(argc, argv);    
}
