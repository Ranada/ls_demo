#include "ls_demo.h"

void list_files(const char* dir_name)
{
    DIR *folder;
    struct dirent *entry;
    struct stat filestat;
    char cwdpath[256];
    int count = 0;
    long long total = 0;

    folder = opendir(dir_name);
    // entry = readdir(folder);

    if (folder == NULL)
    {
        perror("Unable to read directory");
        return;
    }

    /* State directory name */
    getcwd(cwdpath,256);
    printf(" Directory of %s\n\n",cwdpath);
    
   /* Read directory entries */
    while( (entry=readdir(folder)) )
    {
        count++;
        
        /* Extract Filename */
        stat(entry->d_name,&filestat);
        printf("%-16s",entry->d_name);

        /* Extract Size */
        if( S_ISDIR(filestat.st_mode) )
            printf("%-8s  ","<DIR>");
        else
        {
            printf("%8lld  ",filestat.st_size);
            total+=filestat.st_size;
        }

        /* Extract create date and time */
        printf("%s",ctime(&filestat.st_mtime));
    }

    closedir(folder);

      printf("\n        %d File(s) for %lld bytes\n",
            count,
            total
          );
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
        int index = 1;
        
        while (index < argc)
        {
            if (entry->d_type == DT_DIR && strcmp(entry->d_name, argv[index]) == 0)
            {
                printf("Sub-directory name: %s\n", entry->d_name);
                list_files(entry->d_name);
                printf("\n");
                break;
            }
            index++;
        }
    }

    closedir(folder);
}