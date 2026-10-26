
char * FUN_0071c660(double param_1)

{
  int iVar1;
  
  iVar1 = FUN_0089bfd1(param_1);
  if (iVar1 != 0) {
    if (param_1 == 0.0) {
      return "0";
    }
    return (char *)0x0;
  }
  iVar1 = __isnan(param_1);
  if (iVar1 != 0) {
    return "NaN";
  }
  if (0.0 < param_1) {
    return "Infinity";
  }
  return "-Infinity";
}

