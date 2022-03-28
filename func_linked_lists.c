#include "ls_demo.h"

listnode* insert_node(listnode *head, struct dirent *entry)
{
    // printf("%s\n", entry->d_name);

    listnode *temp_pointer = head;
    listnode *new_node = malloc(sizeof(listnode));
    
    new_node->file_name = entry->d_name;
    new_node->next = NULL;

    if (head->file_name == NULL)
    {
        head = new_node;
        return head;
    }

    if (strcmp(new_node->file_name, head->file_name) < 0) 
    {
        new_node->next = temp_pointer;
        temp_pointer->next = NULL;
        head = new_node;
        return head;
    }
   
    while (temp_pointer->next != NULL)
    {
        // printf("Inside while loop: %s\n", entry->d_name);

        temp_pointer = temp_pointer->next;

        // if ((strcmp(new_node->file_name, temp_pointer->file_name) > 0) &&
        //     (strcmp(new_node->file_name, temp_pointer->next->file_name) < 0))
        // {
        //     printf("Insert me here!\n");
        // }
        // else
        // {
        //     temp_pointer->next = new_node;
        // }
    }

    temp_pointer->next = new_node;

    temp_pointer = head;

    return temp_pointer;
}

// listnode *create_linked_list(listnode *pointer, const char *file_name)
// {
//     listnode* temp_pointer = malloc(sizeof(listnode));
//     temp_pointer->val = file_name;
//     temp_pointer->next = NULL;

//     pointer->next = temp_pointer;

//     return temp_pointer;
// }

void print_list_data(listnode* head_address)
{
    listnode* head = head_address;

    listnode* temp_pointer = head;

    while (temp_pointer != NULL)
    {
        printf("%14p %-24s %14p\n", temp_pointer, temp_pointer->file_name, temp_pointer->next);
        
        temp_pointer = temp_pointer->next;
    }

    printf("\n");
}