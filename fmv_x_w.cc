// See LICENSE for license details.

#include "insn_template.h"
#include "insn_macros.h"

#define DECODE_MACRO_USAGE_LOGGED 0

#define PROLOGUE \
  reg_t npc = sext_xlen(pc + insn_length( MATCH_FMV_X_W))

#define EPILOGUE \
  trace_opcode(p,  MATCH_FMV_X_W, insn); \
  return npc

reg_t fast_rv32i_fmv_x_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  PROLOGUE;
  #include "insns/fmv_x_w.h"
  EPILOGUE;
  #undef xlen
}

reg_t fast_rv64i_fmv_x_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  PROLOGUE;
  #include "insns/fmv_x_w.h"
  EPILOGUE;
  #undef xlen
}

#undef DECODE_MACRO_USAGE_LOGGED
#define DECODE_MACRO_USAGE_LOGGED 1

reg_t logged_rv32i_fmv_x_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  PROLOGUE;
  #include "insns/fmv_x_w.h"
  EPILOGUE;
  #undef xlen
}

reg_t logged_rv64i_fmv_x_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  PROLOGUE;
  #include "insns/fmv_x_w.h"
  EPILOGUE;
  #undef xlen
}

#undef CHECK_REG
#define CHECK_REG(reg) require((reg) < 16)

#undef DECODE_MACRO_USAGE_LOGGED
#define DECODE_MACRO_USAGE_LOGGED 0

reg_t fast_rv32e_fmv_x_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  PROLOGUE;
  #include "insns/fmv_x_w.h"
  EPILOGUE;
  #undef xlen
}

reg_t fast_rv64e_fmv_x_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  PROLOGUE;
  #include "insns/fmv_x_w.h"
  EPILOGUE;
  #undef xlen
}

#undef DECODE_MACRO_USAGE_LOGGED
#define DECODE_MACRO_USAGE_LOGGED 1

reg_t logged_rv32e_fmv_x_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 32
  PROLOGUE;
  #include "insns/fmv_x_w.h"
  EPILOGUE;
  #undef xlen
}

reg_t logged_rv64e_fmv_x_w(processor_t* p, insn_t insn, reg_t pc)
{
  #define xlen 64
  PROLOGUE;
  #include "insns/fmv_x_w.h"
  EPILOGUE;
  #undef xlen
}
