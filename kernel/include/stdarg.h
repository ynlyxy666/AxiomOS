#ifndef _STDARG_H
#define _STDARG_H

// NsTech Computing - Axiom OS 自定义 stdarg.h
typedef char* va_list;  // 可变参数列表的类型

#define va_start(ap, last) (ap = (va_list)&(last) + sizeof(last))
#define va_arg(ap, type) (*(type*)((ap += sizeof(type)) - sizeof(type)))
#define va_end(ap) (ap = (va_list)0)

#endif /* _STDARG_H */