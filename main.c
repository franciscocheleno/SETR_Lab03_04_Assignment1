/**
 * \file:   main.c
 * \author: Francisco Heleno <francisco.c.heleno@ua.pt> and Hugo Carola <hugocarola@ua.pt>
 *
 * \date 5, March, 2024
 * \brief 
 * 
 */

#include "dll.h"

int main(){
    DLL dll;
    MyDLLInit(&dll, MAX_ELEMENTS);

    // Insert elements
    unsigned char data1[] = "data1";
    unsigned char data2[] = "123456789";
    unsigned char data3[] = "#### Hello World ###";
    MyDLLInsert(&dll, 1, data1);
    MyDLLInsert(&dll, 2, data2);
    MyDLLInsert(&dll, 3, data3);
    printf("After insert elements.\n");
    // Print elements
    PrintDLL(&dll);

    // Remove an element
    MyDLLRemove(&dll, 2);
    MyDLLRemove(&dll, 4);
    printf("After removing element with key 2:\n");
    PrintDLL(&dll);
    
    // Find and print specific elements
    printf("Data of element with key 2: %s\n", MyDLLFind(&dll, 2));
    printf("Data of element with key 3: %s\n", MyDLLFind(&dll, 3));

    return 0;
}