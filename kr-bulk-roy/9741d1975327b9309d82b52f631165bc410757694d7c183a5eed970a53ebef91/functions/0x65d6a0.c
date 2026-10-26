
void FUN_0065d6a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  int local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00920cfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  iVar1 = DAT_00f943ac;
  local_8 = 0xffffffff;
  local_14 = 0;
  FUN_0082ef00(&local_14);
  if (local_1c == *(int *)(iVar1 + 8)) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(local_1c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x170) = uVar4;
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xcc);
  if (iVar1 != 0) {
    FUN_00408920(iVar1,9);
  }
  local_14 = 0;
  piVar6 = (int *)(in_ECX + 0x100);
  do {
    FUN_0046b6f0(0xfa);
    FUN_0043c570(0xfb);
    FUN_0046b6f0(0xfc);
    iVar1 = *piVar6;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar1 + 0xa4) = 1;
    iVar1 = *piVar6;
    if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
       (iVar5 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
    local_14 = local_14 + 1;
    piVar6 = piVar6 + 1;
  } while (local_14 < 9);
  piVar6 = *(int **)(in_ECX + 0xf4);
  puVar2 = (undefined4 *)piVar6[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar1 = puVar3[2];
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
  }
  (**(code **)(*piVar6 + 0x128))();
  ExceptionList = local_10;
  return;
}

