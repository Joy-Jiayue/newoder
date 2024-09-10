# Ubuntu 24.04 setup

```shell
sudo apt-get update && sudo apt-get install -y build-essential
```

# 运行过程

From scratch:
```
git clone https://github.com/Joy-Jiayue/newoder.git
cd newoder
make
```


导航到指令实现目录

```shell
make clean
```

更新所有相关文件后，使用以下命令重新构建 Spike 模拟器：
```shell
make
```

TODO: write an executable test

# README: 在 Spike 中添加新指令 mac.h
本指南解释了如何将新的 mac 指令添加到 Spike RISC-V 模拟器中。该指令执行乘法累加操作，并将集成到 RISC-V 指令集中。

添加 mac.h 指令的步骤：
1. 创建 mac.h 指令实现文件
第一步：导航到指令实现目录
cd ../riscv/insns
第二步：创建并编辑 mac.h 文件
使用文本编辑器（如 nano 或 vim）来创建和编辑 mac.h 文件：
nano mac.h
第三步：在 mac.h 文件中添加以下内容：
// mac.h
#include "decode.h"  // 用于访问各种宏和函数
#include "insn_template.h"

require_extension('M');  // 确保 M 扩展已启用
reg_t rs1 = RS1;  // 读取 rs1 寄存器的值
reg_t rs2 = RS2;  // 读取 rs2 寄存器的值
reg_t rd = RD;    // 读取 rd 寄存器的当前值

WRITE_RD(rd + rs1 * rs2);  // 将计算结果写回 rd 寄存器

trace_opcode(p, MATCH_MAC, insn);  // 跟踪指令执行
2. 更新 opcodes.h 文件
第一步：导航到 riscv 目录
cd ..
第二步：编辑 opcodes.h 文件
使用 nano 或其他文本编辑器来编辑 opcodes.h 文件：
nano opcodes.h
第三步：在适当的位置添加以下内容：
// 定义一个静态函数，用于生成自定义 MAC 指令的机器码
static uint32_t mac(unsigned int rd, unsigned int rs1, unsigned int rs2) __attribute__ ((unused));
static uint32_t mac(unsigned int rd, unsigned int rs1, unsigned int rs2) {
    return (rs2 << 20) | (rs1 << 15) | (rd << 7) | MATCH_MAC;
}

// MAC 指令的操作码和掩码
#define MATCH_MAC    0x02000033
#define MASK_MAC     0xfe00707f

DECLARE_INSN(mac, MATCH_MAC, MASK_MAC)
3. 在 encoding.h 文件中添加指令定义
打开 encoding.h 文件，并在其中添加以下内容：

#define MATCH_MAC 0x02000033  // 指令操作码
#define MASK_MAC  0xfe00707f  // 掩码

DECLARE_INSN(mac, MATCH_MAC, MASK_MAC)  // 定义 MAC 指令
4. 更新 riscv.mk
将 mac 指令添加到乘法和相关操作的扩展集中。在 riscv.mk 文件中，找到包含所有乘法相关指令的 riscv_insn_ext_m 列表，并添加 mac：

riscv_insn_ext_m = \
  div \
  divu \
  divuw \
  divw \
  mul \
  mulh \
  mulhsu \
  mulhu \
  mulw \
  rem \
  remu \
  remuw \
  remw \
  mac  # 将 mac 指令添加到扩展集

