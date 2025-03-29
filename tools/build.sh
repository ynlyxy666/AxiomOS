#!/bin/bash

# NsTech Computing - Axiom OS 构建脚本

# 项目根目录
PROJECT_ROOT=$(cd "$(dirname "$0")/.." && pwd)

# 打印当前工作目录
echo "当前工作目录: $(pwd)"

# 确保工具路径正确
export PATH=$PATH:/c/msys64/mingw64/bin

# 构建引导程序
cd "${PROJECT_ROOT}/bootloader" || exit
echo "进入引导程序目录: $(pwd)"
make

# 构建内核
cd "${PROJECT_ROOT}/kernel" || exit
echo "进入内核目录: $(pwd)"
make

# 合并引导程序和内核到一个镜像文件
cd "${PROJECT_ROOT}" || exit
echo "进入项目根目录: $(pwd)"
cat bootloader/bootloader.bin kernel/kernel.bin > os.img

# 清理临时文件
cd "${PROJECT_ROOT}/bootloader" || exit
echo "进入引导程序目录: $(pwd)"
make clean

cd "${PROJECT_ROOT}/kernel" || exit
echo "进入内核目录: $(pwd)"
make clean

echo "构建完成: os.img"
