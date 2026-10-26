
void FUN_005ad6a0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093605e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_0059b1f0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  if ((*(uint *)(*(int *)(in_ECX + 0x21c) + 0x28) >> 8 & 1) != 0) {
    FUN_0064e430(*(int *)(in_ECX + 0x21c));
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x220) + 0x28) >> 8 & 1) != 0) {
    FUN_0065d360();
  }
  if (*(int *)(in_ECX + 0x224) != 0) {
    FUN_00659bc0(*(int *)(in_ECX + 0x224));
  }
  if (*(int *)(in_ECX + 0x228) != 0) {
    FUN_006528c0(*(int *)(in_ECX + 0x228));
    FUN_00652ac0();
  }
  if (((uint)(*(int **)(in_ECX + 0x22c))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x22c) + 0x16c))();
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x238) + 0x28) >> 8 & 1) != 0) {
    FUN_006520e0(*(int *)(in_ECX + 0x238));
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x234) + 0x28) >> 8 & 1) != 0) {
    FUN_00651880(*(int *)(in_ECX + 0x234));
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if ((iVar3 == 0) || ((*(uint *)(*(int *)(in_ECX + 0x238) + 0x28) >> 8 & 1) != 0)) {
    if (((uint)(*(int **)(in_ECX + 0x234))[10] >> 8 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x234) + 0xd4))();
    }
  }
  else if ((*(int *)(iVar3 + 0x158) == 0) || (*(int *)(*(int *)(iVar3 + 0x158) + 0x34) != 0)) {
    if ((((uint)(*(int **)(in_ECX + 0x234))[10] >> 8 & 1) == 0) &&
       (*(char *)(in_ECX + 0x230) == '\0')) {
      if (*(char *)(in_ECX + 0x244) == '\0') {
        (**(code **)(**(int **)(in_ECX + 0x234) + 0xd0))();
      }
      *(undefined1 *)(in_ECX + 0x230) = 1;
    }
  }
  else {
    if (((uint)(*(int **)(in_ECX + 0x234))[10] >> 8 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x234) + 0xd4))();
    }
    *(undefined1 *)(in_ECX + 0x230) = 0;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x24c);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((*(uint *)(puVar2[2] + 0x28) >> 8 & 1) != 0) {
      FUN_006c96a0();
    }
  }
  ExceptionList = local_14;
  return;
}

