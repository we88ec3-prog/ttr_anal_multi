
void FUN_0046cbe0(void)

{
  int iVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0046cc46;
    iVar1 = FUN_00745c20();
  }
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) &&
      ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)) {
    FUN_0074a010(iVar1);
  }
LAB_0046cc46:
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (DAT_00f942a8 == 1) {
    *(undefined1 *)(*(int *)(in_ECX + 0x1d4) + 0x141) = 0;
    FUN_007612c0();
    (**(code **)(**(int **)(in_ECX + 0x1d4) + 200))();
  }
  else if (DAT_00f942a8 == 2) {
    *(undefined1 *)(*(int *)(in_ECX + 0x1d4) + 0x141) = 1;
    FUN_007612c0();
    (**(code **)(**(int **)(in_ECX + 0x1d4) + 200))();
    ExceptionList = local_14;
    return;
  }
  ExceptionList = local_14;
  return;
}

