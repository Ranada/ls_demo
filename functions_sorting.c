#include "ls_demo.h"



listnode* add_to_end(listnode* pointer, const char* file_name)
{
    listnode* temp_pointer = malloc(sizeof(listnode));
    temp_pointer->val = file_name;
    temp_pointer->next = NULL;

    pointer->next = temp_pointer;

    return temp_pointer;
}

void print_list_data(listnode* head_address)
{
    listnode* head = head_address;

    listnode* temp_pointer = head;

    while (temp_pointer != NULL)
    {
        printf("%14p %-24s %14p\n", temp_pointer, temp_pointer->val, temp_pointer->next);
        
        temp_pointer = temp_pointer->next;
    }

    printf("\n");
}


// listnode* merge_k_sorted_lists(listnode* result_head)
// { 
//     listnode* result_pointer = result_head;

//     listnode* temp_head = result_head;
//     listnode* current_pointer = temp_head;
//     listnode* previous_pointer = temp_head;

//     while (result_pointer != NULL && current_pointer != NULL)
//     {
//         // printf("ARRAY[%i] %p %i\n", head_index, result_pointer, result_pointer->val);
//         // printf("ARRAY[%i] %p %i\n", temp_index, previous_pointer, previous_pointer->val);
//         // printf("ARRAY[%i] %p %i\n\n", temp_index, current_pointer, current_pointer->val);

//         if ((current_pointer->val < result_pointer->val))
//         {
//             current_pointer = current_pointer->next;
//             previous_pointer->next = result_head;
//             result_head = previous_pointer;
//             previous_pointer = current_pointer;
//             result_pointer = result_head;
//         }
//         else if ((current_pointer->val >= result_pointer->val) && ((result_pointer->next == NULL) || (current_pointer->val < result_pointer->next->val)))
//         {
//             current_pointer = current_pointer->next;
//             previous_pointer->next = result_pointer->next;
//             result_pointer->next = previous_pointer;
//             result_pointer = result_pointer->next;
//             previous_pointer = current_pointer;
//         }
//         else
//         {
//             result_pointer = result_pointer->next;
//         }
//     }

//     result_pointer = result_head;
    
//     return result_head;
// }

// int sort_lexicographically(const char* file_name)
// {
//     /* LINKED LIST 1 */
//     printf("LINKED LIST ROUND\n");

//     listnode* head = malloc(sizeof(listnode));

//     if (head == NULL)
//     {
//         head->val = file_name;
//         head->next = NULL;
//     }

//     listnode* pointer;

//     pointer = head;

//     pointer = add_to_end(pointer, file_name);

//     // print_list_data(head);
//     // printf("\n");

//     // listnode* result_head = malloc(sizeof(listnode));

//     // result_head = merge_k_sorted_lists(input_array);

//     // printf("\nPRINT LINKED LIST RESULT\n");
//     // print_list_data(result_head);

//     free(head);
//     head = NULL;

//     return 0;
// }