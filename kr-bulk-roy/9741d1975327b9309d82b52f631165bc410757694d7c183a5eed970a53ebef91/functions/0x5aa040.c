
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005aa040(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  FUN_005a3980();
  if ((_DAT_00f8d8a8 & 1) == 0) {
    _DAT_00f8d8a8 = _DAT_00f8d8a8 | 1;
    FUN_005e93a0();
    _atexit((_func_4879 *)&DAT_00bccc40);
  }
  FUN_005e9720();
  FUN_005a55e0(2);
  if (*(int *)(in_ECX + 0x158) == 1) {
    iVar2 = *(int *)(in_ECX + 0x140);
  }
  else {
    if (*(int *)(in_ECX + 0x158) != 2) goto LAB_005aa0bd;
    iVar2 = *(int *)(in_ECX + 0x148);
  }
  iVar1 = (*(int *)(in_ECX + 0x10) + -0x13b) - *(int *)(iVar2 + 8);
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + iVar1;
  *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + iVar1;
  iVar1 = 5 - *(int *)(iVar2 + 0xc);
  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + iVar1;
  *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + iVar1;
  FUN_00746f70();
LAB_005aa0bd:
  if (*(int *)(in_ECX + 0x158) == 1) {
    (**(code **)(**(int **)(in_ECX + 0x140) + 0xb4))(0x66);
  }
  else if (*(int *)(in_ECX + 0x158) == 2) {
    (**(code **)(**(int **)(in_ECX + 0x148) + 0xb4))(0x66);
    return;
  }
  return;
}

