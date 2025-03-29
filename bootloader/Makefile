# NsTech Computing - Axiom OS 引导程序 Makefile

# 汇编器
AS := nasm

# 汇编器标志
ASFLAGS := -f bin

# 目标文件
BOOTLOADER := bootloader.bin

# 源文件
BOOTLOADER_SRC := bootloader.asm

# 默认目标
all: $(BOOTLOADER)

# 编译汇编文件
$(BOOTLOADER): $(BOOTLOADER_SRC)
	$(AS) $(ASFLAGS) $(BOOTLOADER_SRC) -o $(BOOTLOADER)

# 清理生成的文件
clean:
	rm -f $(BOOTLOADER)
