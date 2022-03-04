#ifndef LS_DEMO_H
#define LS_DEMO_H

/* Libraries */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

/* Function Prototypes */
void list_files(const char* dir_name);
void explore_directory(int argc, char** argv);
void check_for_files(int argc, char** argv);
void check_for_sub_directories(int argc, char** argv);

#endif