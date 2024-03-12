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
    printf("Inserting elements in the DLL...\n");
    unsigned char data1[] = "data1";
    unsigned char data2[] = "123456789";
    unsigned char data3[] = "#### Hello World ###";
    unsigned char data4[] = "Mario, Coimbra, 15-02-1956";
    unsigned char data5[] = "15-02-2024";
    unsigned char data6[] = "# Alice, Lisboa, 01-06-2003 #";
    MyDLLInsert(&dll, 1, data1);
    MyDLLInsert(&dll, 2, data2);
    MyDLLInsert(&dll, 3, data3);
    MyDLLInsert(&dll, 4, data4);
    MyDLLInsert(&dll, 5, data5);
    MyDLLInsert(&dll, 6, data6);
    printf("After insert elements.\n");
    // Print elements
    PrintDLL(&dll);

    // Remove an element
    MyDLLRemove(&dll, 2);
    MyDLLRemove(&dll, 7);
    printf("After removing element with key 2:\n");
    PrintDLL(&dll);
    
    // Find and print specific elements
    printf("Data of element with key 2: %s\n", MyDLLFind(&dll, 2));
    printf("Data of element with key 3: %s\n", MyDLLFind(&dll, 3));
    printf("Next element after key 3: %s", MyDLLFindNext(&dll, 3));
    printf("Next element after key 7: %s\n", MyDLLFindNext(&dll, 7));
    printf("Previous element before key 3: %s", MyDLLFindPrevious(&dll, 3));
    printf("Previous element before key 1: %s\n", MyDLLFindPrevious(&dll, 1));

    return 0;
}