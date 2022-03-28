#ifndef LS_DEMO_H
#define LS_DEMO_H

/* Libraries */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

/* Struct */
#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
struct s_listnode
{
    const char* file_name;
    struct s_listnode* next;
};

typedef struct s_listnode listnode;
#endif

/* Function Prototypes */
int explore_directory(int argc, char* argv[]);
void list_files(const char* dir_name);
listnode* create_linked_list(listnode* pointer, const char* file_name);
listnode* insert_node(listnode* head, struct dirent *entry);
void print_list_data(listnode *head_address);
// void check_for_files(int argc, char** argv);
// void check_for_sub_directories(int argc, char** argv);

#endif