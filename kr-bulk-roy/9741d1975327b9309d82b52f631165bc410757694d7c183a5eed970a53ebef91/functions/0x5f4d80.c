
void FUN_005f4d80(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int *piVar7;
  int local_24;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ef1c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_20 = in_ECX;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_c = 0;
    FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  iVar4 = DAT_00f943ac;
  local_c = 0xffffffff;
  local_24 = 0;
  FUN_0082ef00(&local_24);
  if (local_1c == *(int *)(iVar4 + 8)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(local_1c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0xc4) = uVar3;
  iVar4 = *(int *)(*(int *)(in_ECX + 0x84) + 0xcc);
  if (iVar4 != 0) {
    FUN_00408920(iVar4,9);
  }
  uVar6 = 0;
  local_1c = -0x88 - in_ECX;
  local_24 = 0x210;
  piVar7 = (int *)(in_ECX + 0x88);
  do {
    FUN_0046b6f0(0x834);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    uVar6 = uVar6 + 1;
    if (((uVar6 < 10) && (iVar4 = local_24 + DAT_00f94304, *(int *)(iVar4 + 0x5c) != 0)) &&
       (iVar4 != 0)) {
      iVar4 = *(int *)(iVar4 + 0x5c);
    }
    else {
      iVar4 = 0;
    }
    (**(code **)(*(int *)*piVar7 + 0x90))(iVar4 != 0);
    iVar4 = *piVar7;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar4 + 0xa4) = 1;
    iVar4 = *piVar7;
    if (((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) &&
       (iVar5 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar4 + 0x94) + 0x4c) = 1;
    }
    local_24 = local_24 + 0x210;
    piVar7 = piVar7 + 1;
  } while (local_24 < 0x14a0);
  piVar7 = *(int **)(local_20 + 0x84);
  puVar1 = (undefined4 *)piVar7[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar4 = puVar2[2];
    if ((*(int *)(iVar4 + 0x60) != 0) && ((*(int **)(iVar4 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x30))(iVar4);
    }
  }
  (**(code **)(*piVar7 + 0x128))();
  ExceptionList = local_14;
  return;
}

