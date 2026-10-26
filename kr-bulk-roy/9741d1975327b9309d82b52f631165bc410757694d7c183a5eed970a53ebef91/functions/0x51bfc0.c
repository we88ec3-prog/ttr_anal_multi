
undefined4 FUN_0051bfc0(void)

{
  int unaff_ESI;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910303;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 0;
    FUN_00523540(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
  }
  local_14 = *(undefined4 *)(unaff_ESI + 0x20);
  FUN_008438c0(&local_14);
  if ((((local_18 != DAT_00f8d9b0) && (*(int *)(local_18 + 0x10) != 0)) &&
      (*(int *)(unaff_ESI + 0x38) != 2)) && ((*(byte *)(*(int *)(local_18 + 0x10) + 0xec) & 2) == 0)
     ) {
    ExceptionList = local_10;
    return 0;
  }
  ExceptionList = local_10;
  return 1;
}

