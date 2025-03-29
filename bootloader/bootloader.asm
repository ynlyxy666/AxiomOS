; NsTech Computing - Axiom OS Bootloader

org 0x7c00

mov ah, 0x00
mov al, 0x03
int 0x10

; 加载内核到内存
mov bx, 0x1000  ; 内核加载地址
mov ah, 0x02    ; 读扇区功能号
mov al, 1       ; 读取1个扇区
mov ch, 0       ; 柱面号
mov cl, 2       ; 扇区号，从第二个扇区开始读取内核
mov dh, 0       ; 磁头号
int 0x13        ; 调用BIOS磁盘中断

; 跳转到内核入口点
jmp 0x1000:0x0000

times 510-($-$$) db 0
dw 0xaa55