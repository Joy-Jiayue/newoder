#include <stdio.h>

int main() {
    int a = 2;
    int b = 3;
    int c;

    // 假设你的 mac 指令形式是 rd = rs1 + rs1 * rs2
    asm volatile ("mac %0, %1, %2" : "=r" (c) : "r" (a), "r" (b));

    printf("Result of MAC operation: %d\n", c);
    return 0;
}

