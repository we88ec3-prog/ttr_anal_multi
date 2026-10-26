
void FUN_0068cd00(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094787e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0068cd67;
    iVar2 = FUN_00745c20();
  }
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) &&
      ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar2 + 0x60) != 0)) {
    FUN_0074a010(iVar2);
  }
LAB_0068cd67:
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_8 = 0xffffffff;
  }
  iVar2 = DAT_00fb7258;
  if (DAT_00fb7258 != 0) {
    iVar1 = *(int *)(in_ECX + 0xf4);
    if (*(char *)(iVar1 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10("Not supported operation");
    }
    *(undefined4 *)(iVar1 + 0x168) = 0;
    *(undefined4 *)(iVar1 + 0x160) = 0;
    *(undefined4 *)(iVar1 + 0x164) = 0;
    *(undefined4 *)(iVar1 + 0x14c) = 0;
    (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
    FUN_0075cd30(*(undefined4 *)(in_ECX + 0xf8));
    (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
    FUN_0068c340(0 < *(int *)(iVar2 + 0x24));
    ExceptionList = local_10;
    return;
  }
  iVar2 = *(int *)(in_ECX + 0xf4);
  if (*(char *)(iVar2 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar2 + 0x168) = 0;
  *(undefined4 *)(iVar2 + 0x160) = 0;
  *(undefined4 *)(iVar2 + 0x164) = 0;
  *(undefined4 *)(iVar2 + 0x14c) = 0;
  (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  FUN_0075cd30(*(undefined4 *)(in_ECX + 0xf8));
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  (**(code **)(**(int **)(in_ECX + 0xfc) + 0xa0))(0);
  (**(code **)(**(int **)(in_ECX + 0x100) + 0xa0))(1);
  ExceptionList = local_10;
  return;
}

