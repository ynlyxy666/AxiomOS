#ifndef _AXIOM_H
#define _AXIOM_H

#include "../include/colors.h"

// NsTech Computing - Axiom OS 全局头文件

// 声明 put_char 函数
void put_char(char c, char color);

// 声明 printc 函数，类似 printf
void printc(const char* format, ...);

// 其他内核初始化函数
void init_memory();
void init_process();
void init_interrupts();

#endif /* _AXIOM_H */