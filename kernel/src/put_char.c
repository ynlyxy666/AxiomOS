#include "..\include\axiom.h"

// 视频内存地址（彩色显示）
#define VIDEO_MEMORY 0xb8000
// 屏幕宽度（80列）
#define SCREEN_WIDTH 80
// 屏幕高度（25行）
#define SCREEN_HEIGHT 25

// 光标位置
static unsigned int cursor_x = 0;
static unsigned int cursor_y = 0;

// 将字符输出到屏幕
void put_char(char c, char color) {
    char* video_memory = (char*) VIDEO_MEMORY;
    unsigned int index = cursor_y * SCREEN_WIDTH + cursor_x;

    // 处理换行符
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
        if (cursor_y >= SCREEN_HEIGHT) {
            cursor_y = SCREEN_HEIGHT - 1;
        }
        return;
    }

    // 输出字符
    video_memory[index * 2] = c;          // 字符
    video_memory[index * 2 + 1] = color;  // 颜色

    // 更新光标位置
    cursor_x++;
    if (cursor_x >= SCREEN_WIDTH) {
        cursor_x = 0;
        cursor_y++;
        if (cursor_y >= SCREEN_HEIGHT) {
            cursor_y = SCREEN_HEIGHT - 1;
        }
    }
}
