    .section .text
    .globl _start

_start:
    # 初始化寄存器
    li x5, 3        # 将寄存器 x5 设为 3 (rs1)
    li x6, 4        # 将寄存器 x6 设为 4 (rs2)
    li x7, 5        # 将寄存器 x7 设为 5 (rd)

    # 执行 mac 指令
    mac x7, x5, x6  # 执行 rd = rd + (rs1 * rs2) -> x7 = 5 + (3 * 4) = 17

    # 停止执行
    li x10, 0       # 调用系统退出 (ECALL)
    ecall

