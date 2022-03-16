#include "ls_demo.h"

int explore_directory(int argc, char* argv[])
{
    if (argc == 1)
    {
        list_files(".");
    }

    int index = 1;
    while (index < argc)
    {
        printf("%s\n", argv[index]);
    }

    return 0;
}

void list_files(const char* dir_name)
{
    DIR *folder;

    folder = opendir(dir_name);

    if (folder == NULL)
    {
        perror("Unable to read directory");
        return;
    }

    struct dirent *entry = readdir(folder);
    listnode* head = malloc(sizeof(listnode));
    listnode* pointer = head;

    while (entry != NULL)
    {
        if (pointer->val == NULL)
        {
            pointer->val = entry->d_name;
            pointer->next = NULL;
        }
        else
        {
            pointer = create_linked_list(pointer, entry->d_name);
        }

        entry = readdir(folder);
    }

    print_list_data(head);

    free(head);
    head = NULL;

    closedir(folder);
}


// void list_all_files(const char* dir_name)
// {
//     DIR *folder;
//     struct dirent *entry;
//     struct stat filestat;
//     listnode* head = malloc(sizeof(listnode));
//     listnode* pointer;

//     folder = opendir(dir_name);

//     if (folder == NULL)
//     {
//         perror("Unable to read directory");
//         return;
//     }
    
//    /* Read directory entries */
//     while( (entry = readdir(folder)) )
//     {
        
//         /* Extract Filename */
//         stat(entry->d_name,&filestat);
        
//         if (strncmp(entry->d_name, ".", 1) != 0)
//         {
//             // printf("%-24s",entry->d_name);

//             // /* Extract Type */
//             // if( S_ISDIR(filestat.st_mode) )
//             //     printf("%-8s  ", "Directory");
//             // else
//             // {
//             //     printf("%-9s  ", "File");
//             // }

//             // /* Extract create date and time */
//             // printf("%s",ctime(&filestat.st_mtime));
//             if (head->val == NULL)
//             {
//                 head->val = entry->d_name;
//                 head->next = NULL;
//                 pointer = head;
//             }
//             else
//             {
//                 pointer = add_to_end(pointer, entry->d_name);
//             }
//         }
//     }

//     print_list_data(head);
//     printf("\n");

//     closedir(folder);
// }

// void explore_directory(int argc, char** argv)
// {   
//     check_for_files(argc, argv);
//     check_for_sub_directories(argc, argv);    
// }

// // If one argument and is a folder -> display name
// void check_for_files(int argc, char** argv)
// {
//     DIR *folder;
//     struct dirent *entry;

//     folder = opendir(".");
//     entry = readdir(folder);

//     while (entry != NULL)
//     {   
//         int index = 1;
//         while (index < argc)
//         {
//             if (entry->d_type == DT_REG && strcmp(entry->d_name, argv[index]) == 0 )
//             {
//             printf("File name: %s\n", entry->d_name);
//             break;
//             }
//             index++;
//         }
//         entry = readdir(folder); 
//     }
//     printf("\n");

//     closedir(folder);
// }

// // If one argument is a directory -> display items inside
// void check_for_sub_directories(int argc, char** argv)
// {
//     DIR *folder;
//     struct dirent *entry;

//     folder = opendir(".");
//     entry = readdir(folder);

//     while ((entry = readdir(folder)) != NULL)
//     {
//         int index = 1;
        
//         while (index < argc)
//         {
//             if (entry->d_type == DT_DIR && strcmp(entry->d_name, argv[index]) == 0)
//             {
//                 printf("Sub-directory name: %s\n", entry->d_name);
//                 list_all_files(entry->d_name);
//                 printf("\n");
//                 break;
//             }
//             index++;
//         }
//     }

//     closedir(folder);
// }