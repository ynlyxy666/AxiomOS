#include "..\include\axiom.h"
#include "..\include\stdarg.h"

// 实现 printc 函数，类似 printf
void printc(const char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    put_char(va_arg(args, int), 0x07);  // 默认颜色
                    break;
                case 's':
                    {
                        char* str = va_arg(args, char*);
                        while (*str) {
                            put_char(*str++, 0x07);  // 默认颜色
                        }
                    }
                    break;
                case 'd':
                    {
                        int num = va_arg(args, int);
                        char buffer[12]; // 足够大，可以存储 -2147483648
                        int i = 11;
                        buffer[11] = '\0';
                        if (num == 0) {
                            buffer[10] = '0';
                            i = 10;
                        } else {
                            int is_negative = 0;
                            if (num < 0) {
                                is_negative = 1;
                                num = -num;
                            }
                            while (num > 0) {
                                buffer[i--] = (num % 10) + '0';
                                num /= 10;
                            }
                            if (is_negative) {
                                buffer[i--] = '-';
                            }
                        }
                        while (buffer[++i]) {
                            put_char(buffer[i], 0x07);  // 默认颜色
                        }
                    }
                    break;
                default:
                    put_char('%', 0x07);  // 默认颜色
                    put_char(*format, 0x07);  // 默认颜色
                    break;
            }
        } else {
            put_char(*format, 0x07);  // 默认颜色
        }
        format++;
    }

    va_end(args);
}
