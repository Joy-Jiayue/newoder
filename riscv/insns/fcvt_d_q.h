require_extension('Q');
require_fp;
softfloat_roundingMode = RM;
// WRITE_FRD(f128M_to_f64(f128(FRS1)));
WRITE_FRD(f128M_to_f64(&f128(FRS1)));
set_fp_exceptions;
