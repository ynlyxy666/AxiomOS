#ifndef _STDDEF_H
#define _STDDEF_H

// NsTech Computing - Axiom OS 自定义 stddef.h
typedef unsigned int size_t;  // 无符号整数类型，用于表示大小
typedef signed int ssize_t;   // 有符号整数类型，用于表示带符号的大小
typedef long ptrdiff_t;       // 有符号整数类型，用于表示指针差值

#define NULL ((void*)0)       // 空指针常量

#endif /* _STDDEF_H */