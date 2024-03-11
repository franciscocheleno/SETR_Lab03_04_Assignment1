/**
 * \file:   ddl.c
 * \author: Francisco Heleno <francisco.c.heleno@ua.pt> and Hugo Carola <hugocarola@ua.pt>
 *
 * \date 5, March, 2024
 * \brief 
 * 
 */

#include "dll.h"
    
/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 */
void MyDLLInit(DLL *dll, uint16_t max_elements) {
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
	if (dll->count == dll->max_elem) {
        fprintf(stderr, "DLL is full, cannot insert.\n");
        return -1;
    }

    Node *new_node = &dll->nodes[dll->count];
    new_node->key = key;
    for (int i = 0; i < MAX_ELEMENTS; ++i) {
        new_node->data[i] = data[i];
    }

    if (dll->head == NULL) {
        dll->head = new_node;
        dll->tail = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    } else {
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
void MyDLLRemove() 
{
	return;
}

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 */
void MyDLLFind_Next_Previous() 
{
	return;
}


void PrintDLL(DLL *dll) {
    Node *current = dll->head;
    printf("DLL Elements:\n");
    while (current != NULL) {
        printf("Key: %d, Data: %s\n", current->key, current->data);
        current = current->next;
    }
}