require_extension('Q');
require_fp;
softfloat_roundingMode = RM;

float128_t temp_f128 = f128(FRS1); 
WRITE_FRD(f128M_to_f64(&temp_f128));  

set_fp_exceptions;
