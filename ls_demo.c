#include "ls_demo.h"

int main(int argc, char** argv)
{
        //If option "-a" is given -> list directories whose name begins with "."
        //If option "-t" is given -> sort by time modified (most recently modified first) before sorting the operands by lexicographical order

    // If no operands are given -> list all contents of current directory
    if (argc == 1)
    {
        printf("Parent directory: %s\n", argv[0]);
        list_files(".");
    }

    if (argc > 1)
    {
        explore_directory(argc, argv);
    }

    return(0);
}