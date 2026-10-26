
void FUN_007e15e0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00934c3c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  iVar2 = *(int *)(*(int *)(in_ECX + 0xc + *(int *)(in_ECX + 8) * 4) + 0xc);
  iVar3 = *(int *)(*(int *)(in_ECX + 0xc + *(int *)(in_ECX + 4) * 4) + 0xc);
  if (iVar2 == 0) {
    iVar2 = *(int *)(*(int *)(in_ECX + 0xc) + 0xc);
  }
  if (iVar3 == 0) {
    iVar3 = *(int *)(*(int *)(in_ECX + 0xc) + 0xc);
  }
  if ((iVar2 != 0) && (iVar3 != 0)) {
    FUN_007e06e0(iVar3,*(undefined4 *)(in_ECX + 0x30));
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    FUN_0079a5f0(&DAT_00fb76a8);
    FUN_007d7260();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    DAT_00fb79a4 = local_20;
  }
  ExceptionList = local_14;
  return;
}

