
void FUN_0080cbe0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091eb0e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8 = 0;
      FUN_0080a3a0(uVar1);
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    local_8 = 0xffffffff;
    iVar2 = FUN_0080ba60(&DAT_00fab028,in_ECX);
    if ((iVar2 != 0) && (*(int **)(in_ECX + 8) != (int *)0x0)) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x20))(*(undefined4 *)(*(int *)(in_ECX + 4) + 8));
      uVar3 = FUN_0040b3f0();
      FUN_0080bd90(uVar3);
    }
  }
  InterlockedDecrement((LONG *)(in_ECX + 0x24));
  ExceptionList = local_10;
  return;
}

