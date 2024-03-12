/**
 * \file:   dll.h
 * \author: Francisco Heleno <francisco.c.heleno@ua.pt> and Hugo Carola <hugocarola@ua.pt>
 *
 * \date 5, March, 2024
 * \brief 
 * 
 */

#ifndef DLL_H
#define DLL_H
#define MAX_ELEM_SIZE 256
#define MAX_ELEMENTS 64

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * @brief Struct for a DLL node
 * @details temperatures Pointer to the temperature vector
 */
typedef struct Node{
    uint16_t key;
    unsigned char data[MAX_ELEM_SIZE];
    struct Node *prev;
    struct Node *next;
}Node;

/**
 * @brief Struct for a DLL
 * @details temperatures Pointer to the temperature vector
 */
typedef struct{
    Node nodes[MAX_ELEMENTS];
    Node *head;
    Node *tail;
    uint16_t max_elem;
    uint16_t count;
}DLL;

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
void MyDLLInit(DLL *dll, uint16_t max_elements);

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
int MyDLLInsert(DLL *dll, uint16_t key, unsigned char *data);

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
int MyDLLRemove(DLL *dll, uint16_t key);

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
unsigned char *MyDLLFind(DLL *dll, uint16_t key);

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
void MyDLLFind_Next_Previous();

void PrintDLL(DLL *dll);

#endif // DLL_H