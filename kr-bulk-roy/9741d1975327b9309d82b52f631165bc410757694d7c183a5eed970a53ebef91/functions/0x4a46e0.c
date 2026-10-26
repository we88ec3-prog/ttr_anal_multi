
void FUN_004a46e0(void)

{
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e4ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fd94d8 & 1) == 0) {
    DAT_00fd94d8 = DAT_00fd94d8 | 1;
    local_8 = 0;
    FUN_007b5430(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce660);
  }
  local_8 = 0xffffffff;
  if (DAT_00fd94b8 == 0) {
    if (*in_ECX < 1) {
      ExceptionList = local_10;
      return;
    }
  }
  else {
    *in_ECX = 10;
    in_ECX[1] = 1;
  }
  FUN_00739180(0x42000000,0x42000000,0,0,(int)(float)in_ECX[3],0x3f800000,0x3f800000,0x3f800000,
               0x3f800000);
  ExceptionList = local_10;
  return;
}

