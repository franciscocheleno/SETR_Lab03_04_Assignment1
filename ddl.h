/**
 * \file:   ddl.h
 * \author: Francisco Heleno <francisco.c.heleno@ua.pt> and Hugo Carola <hugocarola@ua.pt>
 *
 * \date 5, March, 2024
 * \brief 
 * 
 */

#ifndef FIFO_H
#define FIFO_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * @brief Initializes the temperature vector with zeros
 * @param temperatures Pointer to the temperature vector
 * @return 0
 */
void MyDLLInit();

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

#endif // FIFO_H