
void FUN_00649b40(void)

{
  int iVar1;
  int in_ECX;
  void *unaff_EBX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094639c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00649bad;
    iVar1 = FUN_00745c20();
  }
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) &&
      ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)) {
    FUN_0074a010(iVar1);
  }
LAB_00649bad:
  (**(code **)(**(int **)(in_ECX + 0xf8) + 0x94))(0);
  *(int **)(in_ECX + 0xf4) = *(int **)(in_ECX + 0xf8);
  (**(code **)(**(int **)(in_ECX + 0xf8) + 0x94))(1);
  FUN_0064ae00(in_ECX);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_14 = (void *)0x0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_14 = (void *)0xffffffff;
  }
  iVar1 = FUN_004d43d0();
  (**(code **)(**(int **)(in_ECX + 0x104) + 0x94))(iVar1 < 0x50);
  FUN_00649cc0();
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  FUN_0064a790();
  FUN_0064a8e0(in_ECX);
  FUN_00749920(*(undefined4 *)(in_ECX + 0x10c));
  (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
  FUN_0064ac50(in_ECX);
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  FUN_00501650(1);
  ExceptionList = unaff_EBX;
  return;
}

