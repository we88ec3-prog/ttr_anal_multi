
void FUN_007bed00(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b79e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar4 = DAT_00fb7740;
  local_8 = 0xffffffff;
  iVar3 = (**(code **)(*in_ECX + 4))();
  iVar2 = *(int *)(iVar3 * 0x2004 + 0x2000 + iVar4);
  iVar4 = iVar3 * 0x2004 + iVar4;
  if (iVar2 < 0x800) {
    *(int **)(iVar4 + iVar2 * 4) = in_ECX;
    piVar1 = (int *)(iVar4 + 0x2000);
    *piVar1 = *piVar1 + 1;
  }
  ExceptionList = local_10;
  return;
}

