/**
 * \file:   dll.c
 * \author: Francisco Heleno <francisco.c.heleno@ua.pt> and Hugo Carola <hugocarola@ua.pt>
 *
 * \date 5, March, 2024
 * \brief Implementation of the Doubly Linked List (DLL) module.
 * 
 */

#include "dll.h"
    
/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 */
void MyDLLInit(DLL *dll, uint16_t max_elements)
{
    dll->head = NULL;
    dll->tail = NULL;
    dll->max_elem = max_elements;
    dll->count = 0;
}

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 */
int MyDLLInsert(DLL *dll, uint16_t key, unsigned char *data)
{
	if(dll->count == dll->max_elem){
        printf("DLL is full, cannot insert.\n");
        return -1;
    }

    Node *new_node = &dll->nodes[dll->count];
    new_node->key = key;
    for(int i = 0; i < MAX_ELEMENTS; ++i){
        new_node->data[i] = data[i];
    }

    if(dll->head == NULL){
        dll->head = new_node;
        dll->tail = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    }else{
        new_node->prev = dll->tail;
        dll->tail->next = new_node;
        new_node->next = NULL;
        dll->tail = new_node;
    }

    dll->count++;
    return 0;
}

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 */
int MyDLLRemove(DLL *dll, uint16_t key) 
{
    Node *current = dll->head;
    while(current != NULL){
        if(current->key == key){
            if(current == dll->head && current == dll->tail){
                dll->head = NULL;
                dll->tail = NULL;
            }else if(current == dll->head){
                dll->head = current->next;
                dll->head->prev = NULL;
            }else if(current == dll->tail){
                dll->tail = current->prev;
                dll->tail->next = NULL;
            }else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            dll->count--;
            printf("\nElement with key %d found and removed.\n", key);
            return 0;
        }
        current = current->next;
    }
    printf("Element with key %d not found.\n", key);
    return -1;
}

unsigned char *MyDLLFind(DLL *dll, uint16_t key){
    printf("Finding the element with the key %d...", key);
    Node *current = dll->head;
    while(current != NULL){
        if(current->key == key){
            printf("\nElement with key %d found.\n", key);
            return current->data;
        }
        current = current->next;
    }
    printf("\nElement with key %d not found.\n", key);
    return NULL;
}

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 */
unsigned char *MyDLLFindNext(DLL *dll, uint16_t key){
    printf("\nFinding the next element with the key %d...\n", key);
    Node *current = dll->head;
    while(current != NULL){
        if(current->key == key){
            if(current->next != NULL){
                return current->next->data;
            }else{
                printf("No next element found (current element is last).\n");
                return NULL;
            }
        }
        current = current->next;
    }
    printf("Element with key %d not found.\n", key+1);
    return NULL;
}

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 */
unsigned char *MyDLLFindPrevious(DLL *dll, uint16_t key){
    printf("\nFinding the previous element with the key %d...\n", key);
    Node *current = dll->head;
    while(current != NULL){
        if(current->key == key){
            if(current->prev != NULL){
                return current->prev->data;
            }else{
                printf("No previous element found (current element is first).\n");
                return NULL;
            }
        }
        current = current->next;
    }
    printf("Element with key %d not found.\n", key-1);
    return NULL;
}

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 */
void MyDLLSort(DLL *dll, bool order)
{
    printf("\nStarting sorting process...\n");
    int swapped;
    Node *current;

    if(dll->head == NULL){
        return;
    }
    do{
        swapped = 0;
        current = dll->head;
        while(current->next != NULL){
            if((order && current->key > current->next->key) || (!order && current->key < current->next->key)){
                uint16_t temp_key = current->key;
                current->key = current->next->key;
                current->next->key = temp_key;

                unsigned char temp_data[MAX_ELEM_SIZE];
                for(int i = 0; i < MAX_ELEM_SIZE; i++){
                    temp_data[i] = current->data[i];
                    current->data[i] = current->next->data[i];
                    current->next->data[i] = temp_data[i];
                }
                swapped = 1;
            }
            current = current->next;
        }
    }while(swapped);
}

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 */
void PrintDLL(DLL *dll){
    Node *current = dll->head;
    printf("DLL Elements:\n");
    while(current != NULL){
        printf("Key: %d, Data: %s\n", current->key, current->data);
        current = current->next;
    }
    printf("\n");
}