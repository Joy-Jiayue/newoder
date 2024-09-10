mac.h

#include "decode.h"  // 用于访问各种宏和函数
#include "insn_template.h"

require_extension('M');  // 确保 M 扩展已经启用

// 读取寄存器 rs1, rs2 和 rd 的值
reg_t rs1 = RS1;
reg_t rs2 = RS2;
reg_t rd = RD;

// 将 rd 与 rs1 * rs2 的乘积相加，并写回 rd 寄存器
WRITE_RD(rd + rs1 * rs2);

// 跟踪指令的执行
trace_opcode(p, MATCH_MAC, insn);


