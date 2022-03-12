#ifndef LS_DEMO_H
#define LS_DEMO_H

/* Libraries */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

/* Struct */
#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    const char* val;
    struct s_listnode* next;
} listnode;
#endif

/* Function Prototypes */
void list_all_files(const char* dir_name);
void list_all_files_with_hidden(const char* dir_name);
int sort_lexicographically(const char* file_name);
listnode* add_to_end(listnode* pointer, const char* file_name);
void print_list_data(listnode* head_address);
listnode* merge_k_sorted_lists(listnode* result_head);
// void explore_directory(int argc, char** argv);
// void check_for_files(int argc, char** argv);
// void check_for_sub_directories(int argc, char** argv);

#endif