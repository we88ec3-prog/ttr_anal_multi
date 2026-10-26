
void FUN_00563970(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ebfa;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar1 = DAT_00fb76e8;
  *(undefined4 *)(DAT_00fb76e8 + 0x20) = param_1;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar1 = DAT_00fb76e8;
  *(undefined4 *)(DAT_00fb76e8 + 0x18) = param_2;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar1 = DAT_00fb76e8;
  *(undefined4 *)(DAT_00fb76e8 + 0x24) = param_3;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  ExceptionList = local_10;
  return;
}

