/**
 * \file:   ddl.h
 * \author: Francisco Heleno <francisco.c.heleno@ua.pt> and Hugo Carola <hugocarola@ua.pt>
 *
 * \date 5, March, 2024
 * \brief 
 * 
 */

#ifndef DDL_H
#define DDL_H
#define MAX_ELEM_SIZE 150
#define MAX_ELEMENTS 16

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * @brief Initializes the temperature vector with zeros
 * @details temperatures Pointer to the temperature vector
 */
typedef struct Node
{
    uint16_t key;
    char data[MAX_ELEM_SIZE];
    struct Node *next;
	struct Node *previous;
    struct Node *head;
	struct Node *tail;
} Node[MAX_ELEMENTS];

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
void MyDLLInit(List *l, uint16_t max_size);

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
void MyDLLInsert();

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
void MyDLLRemove();

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
void MyDLLFind_Next_Previous();

#endif // DDL_H