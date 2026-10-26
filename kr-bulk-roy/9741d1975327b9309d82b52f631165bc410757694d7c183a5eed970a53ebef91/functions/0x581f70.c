
void FUN_00581f70(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e38e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x30) != 0) {
    if ((DAT_00fb72a4 & 1) == 0) {
      DAT_00fb72a4 = DAT_00fb72a4 | 1;
      local_8 = 0;
      FUN_0049f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccfe0);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb72ac == 0) {
      iVar2 = FUN_00582400(in_ECX);
      if (iVar2 == 0) {
        FUN_00582670();
      }
    }
    iVar2 = *(int *)(in_ECX + 4);
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x28) != 0)) &&
       (iVar1 = *(int *)(iVar2 + 0x3c), *(int *)(iVar2 + 0x3c) = iVar1 + -1, iVar1 < 1)) {
      *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar2 + 0x38);
      if (*(int *)(iVar2 + 0x10) <= *(int *)(iVar2 + 0x34)) {
        *(int *)(iVar2 + 0x34) = *(int *)(iVar2 + 0x10);
        ExceptionList = local_10;
        return;
      }
      *(int *)(iVar2 + 0x34) = *(int *)(iVar2 + 0x34) + 1;
    }
  }
  ExceptionList = local_10;
  return;
}

