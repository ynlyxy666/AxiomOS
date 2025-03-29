# NsTech Computing - Axiom OS 内核 Makefile

# 编译器
CC := x86_64-w64-mingw32-gcc
# 链接器
LD := x86_64-w64-mingw32-ld

# 编译器标志
CFLAGS := -ffreestanding -Wall -Wextra -Iinclude
# 链接器标志
LDFLAGS := -Ttext 0x1000 --oformat binary

# 目标文件
KERNEL := kernel.bin

# 源文件
OBJ := src/main.o src/put_char.o

# 默认目标
all: $(KERNEL)

# 编译C文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 链接目标
$(KERNEL): $(OBJ)
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJ)

# 清理生成的文件
clean:
	rm -f $(OBJ) $(KERNEL)
