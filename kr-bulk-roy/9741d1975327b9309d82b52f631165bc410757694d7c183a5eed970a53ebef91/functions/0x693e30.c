
void FUN_00693e30(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941c7c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  iVar3 = *(int *)(in_ECX + 0x84);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar3 + 0xa4) = 1;
  iVar3 = *(int *)(in_ECX + 0x84);
  if ((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(uVar1);
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar3 + 0x94) + 0x4c) = 1;
    }
  }
  *(undefined1 *)(in_ECX + 0xf4) = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (DAT_00f9392c != 4) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if (DAT_00f9392c != 6) {
      iVar3 = FUN_00404ba0();
      if (*(int *)(iVar3 + 0x5f4c) != 9) goto LAB_00693f77;
    }
  }
  iVar3 = *(int *)(in_ECX + 0x80);
  if ((*(int *)(iVar3 + 0x3c) != 0) && ((*(uint *)(iVar3 + 0x28) & 0x40000) == 0)) {
    FUN_00746c10();
    FUN_00746b80();
    if (*(int **)(iVar3 + 0x3c) != (int *)0x0) {
      (**(code **)(**(int **)(iVar3 + 0x3c) + 0x1c))(1);
    }
    *(undefined4 *)(iVar3 + 0x3c) = 0;
  }
  *(undefined1 *)(in_ECX + 0xf4) = 1;
LAB_00693f77:
  *(undefined4 *)(in_ECX + 0xd4) = 0xffffffff;
  ExceptionList = local_14;
  return;
}

