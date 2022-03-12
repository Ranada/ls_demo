#include "ls_demo.h"

int main(int argc, char** argv)
{
        //If option "-a" is given -> list directories whose name begins with "."
        //If option "-t" is given -> sort by time modified (most recently modified first) before sorting the operands by lexicographical order

    // If no operands are given -> list all contents of current directory
    if (argc == 1)
    {
        printf("\nPrinting all files and directories in %s\n", argv[0]);
        list_all_files(".");
        return 0;
    }

    if (argc == 2 && strcmp(argv[1], "-a") == 0)
    {
        printf("\nPrinting all files and directories (including hidden) in %s\n", argv[0]);
        list_all_files_with_hidden(".");
        return 0;
    }

    // if (argc == 2 && strcmp(argv[1], "-t") == 0)
    // {
    //     printf("\nSort all files and directories by most recently modified in %s\n", argv[0]);
    //     list_files(".", "-t");
    // }

    // if (argc > 1)
    // {
    //     explore_directory(argc, argv);
    // }

    return 0;
}