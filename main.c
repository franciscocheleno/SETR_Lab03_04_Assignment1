/**
 * \file:   ddl.c
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

    PrintDLL(&dll);
    return 0;
}