
void FUN_007f9660(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092bbfc;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  if (DAT_00fb798c != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    iVar5 = DAT_00fb7740;
    local_8 = 0xffffffff;
    iVar4 = (**(code **)(*in_ECX + 4))();
    iVar2 = *(int *)(iVar4 * 0x2004 + 0x2000 + iVar5);
    iVar5 = iVar4 * 0x2004 + iVar5;
    if (iVar2 < 0x800) {
      *(int **)(iVar5 + iVar2 * 4) = in_ECX;
      piVar1 = (int *)(iVar5 + 0x2000);
      *piVar1 = *piVar1 + 1;
    }
  }
  ExceptionList = local_10;
  return;
}

