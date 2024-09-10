// See LICENSE for license details.
#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>

// 检查这些头文件是否只包含 C 代码，确保它们没有 C++ 模板等特性。
#include "softfloat.h" 
#include "internals.h" 
#include "specialize.h" 
#include "debug_defines.h" 

// 如果某些文件包含 C++ 特性（如模板），将这些头文件移到 extern "C" 外部。
#ifdef __cplusplus
}
#endif

// 如果有包含 C++ 模板或 C++ 特性的头文件，将它们放在 extern "C" 块外。
#include "decode_macros.h"  
#include "arith.h" 
#include "mmu.h" 
#include "tracer.h" 
#include "v_ext_macros.h" 