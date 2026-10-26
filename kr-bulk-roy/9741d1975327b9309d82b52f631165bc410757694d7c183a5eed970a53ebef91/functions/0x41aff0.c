
void FUN_0041aff0(void)

{
  int iVar1;
  int in_ECX;
  void *unaff_EDI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0041b056;
    iVar1 = FUN_00745c20();
  }
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) &&
      ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)) {
    FUN_0074a010(iVar1);
  }
LAB_0041b056:
  (**(code **)(**(int **)(in_ECX + 0xf8) + 0x94))(0);
  *(int **)(in_ECX + 0xfc) = *(int **)(in_ECX + 0xf8);
  (**(code **)(**(int **)(in_ECX + 0xf8) + 0x94))(1);
  FUN_0041b370(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_14 = (void *)0x0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_14 = (void *)0xffffffff;
  }
  iVar1 = FUN_004d43d0();
  (**(code **)(**(int **)(in_ECX + 0x10c) + 0x94))(iVar1 < 0x50);
  FUN_0041b470();
  FUN_0041b5a0(in_ECX);
  FUN_00749920(*(undefined4 *)(in_ECX + 0x100));
  (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
  FUN_0041b1b0(in_ECX);
  ExceptionList = unaff_EDI;
  return;
}

