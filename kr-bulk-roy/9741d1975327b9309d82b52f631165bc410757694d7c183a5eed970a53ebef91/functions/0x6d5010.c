
void FUN_006d5010(undefined4 param_1)

{
  uint uVar1;
  int unaff_ESI;
  int *piVar2;
  int local_38 [4];
  int local_28 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009267bc;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (unaff_ESI - 0x2711U < 9999) {
    FUN_0062d9b0(param_1);
    if ((DAT_00fdf3ec & 1) == 0) {
      DAT_00fdf3ec = DAT_00fdf3ec | 1;
      local_8 = 1;
      FUN_006d1da0(uVar1);
      _atexit((_func_4879 *)&LAB_00bce330);
    }
    piVar2 = local_28;
    local_8 = 2;
    FUN_006d43f0(&DAT_00fdf414);
    FUN_004738a0(piVar2);
  }
  else {
    FUN_0062d9b0(param_1);
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 4;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    local_8 = 5;
    FUN_004738a0(local_38);
    local_28[0] = local_38[0];
  }
  if (local_28[0] != 0) {
    FUN_0089120c(local_28[0]);
  }
  ExceptionList = local_10;
  return;
}

