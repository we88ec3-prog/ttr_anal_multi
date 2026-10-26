
void FUN_005aec90(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941c7c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_0059b1f0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  if ((*(uint *)(*(int *)(in_ECX + 0x21c) + 0x28) >> 8 & 1) != 0) {
    FUN_0064e430(*(int *)(in_ECX + 0x21c));
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x220) + 0x28) >> 8 & 1) != 0) {
    FUN_0065d360();
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (*(char *)(in_ECX + 0x230) == '\0') {
    FUN_006b8df0(*(undefined4 *)(in_ECX + 0x234));
    *(undefined1 *)(*(int *)(in_ECX + 0x164) + 0x37d) = 1;
  }
  else {
    iVar2 = FUN_008fed10();
    iVar3 = FUN_008fed10();
    iVar4 = FUN_008fed10();
    FUN_006b8a80(*(undefined4 *)(in_ECX + 0x234),iVar2 % 100,iVar3 % 0x3c,iVar4 % 100);
    *(undefined1 *)(*(int *)(in_ECX + 0x164) + 0x37d) = 0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar2 = *(int *)(in_ECX + 0x234);
  piVar1 = *(int **)(iVar2 + 0x9c);
  if (DAT_00f9392c == 6) {
    if (((uint)piVar1[10] >> 8 & 1) != 0) {
      (**(code **)(*piVar1 + 0x94))(0);
      (**(code **)(**(int **)(iVar2 + 0x9c) + 200))();
    }
    iVar2 = *(int *)(in_ECX + 0x224);
    if ((*(uint *)(iVar2 + 0x28) >> 8 & 1) != 0) {
      FUN_00427fb0(iVar2);
      FUN_00428100(iVar2);
    }
  }
  else {
    if (((uint)piVar1[10] >> 8 & 1) != 0) {
      (**(code **)(*piVar1 + 0x16c))();
    }
    if (((uint)(*(int **)(iVar2 + 0xa0))[10] >> 8 & 1) != 0) {
      (**(code **)(**(int **)(iVar2 + 0xa0) + 0x16c))();
    }
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x238) + 0x28) >> 8 & 1) != 0) {
    FUN_006b0550();
  }
  ExceptionList = local_14;
  return;
}

