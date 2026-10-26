
void FUN_0079a7a0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *unaff_EDI;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bbbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = *(int *)(param_1 + 0x40);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  FUN_007c9190(&local_28,param_3,param_4,*(undefined4 *)(iVar1 + 0xb4),*(undefined4 *)(iVar1 + 0xb8)
              );
  *param_2 = local_28;
  param_2[1] = local_24;
  param_2[2] = local_20;
  *unaff_EDI = local_1c;
  unaff_EDI[1] = local_18;
  unaff_EDI[2] = local_14;
  ExceptionList = local_10;
  return;
}

