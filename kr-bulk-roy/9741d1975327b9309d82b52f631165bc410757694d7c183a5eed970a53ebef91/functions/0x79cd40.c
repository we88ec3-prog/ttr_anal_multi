
void FUN_0079cd40(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_ECX;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b79e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX - 0x34) != 0) {
    piVar4 = (int *)(-(uint)(in_ECX != 0x38) & in_ECX);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    iVar3 = DAT_00fb7740;
    local_8 = 0xffffffff;
    iVar2 = (**(code **)(*piVar4 + 4))();
    iVar1 = *(int *)(iVar2 * 0x2004 + 0x2000 + iVar3);
    iVar3 = iVar2 * 0x2004 + iVar3;
    if (iVar1 < 0x800) {
      *(int **)(iVar3 + iVar1 * 4) = piVar4;
      piVar4 = (int *)(iVar3 + 0x2000);
      *piVar4 = *piVar4 + 1;
    }
  }
  ExceptionList = local_10;
  return;
}

