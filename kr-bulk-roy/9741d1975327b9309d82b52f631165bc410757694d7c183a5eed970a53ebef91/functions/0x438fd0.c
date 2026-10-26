
void FUN_00438fd0(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 **ppuVar9;
  undefined4 *puVar10;
  int in_ECX;
  int *piVar11;
  undefined4 *local_58;
  undefined4 *local_54;
  undefined4 *local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920270;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_50 = (undefined4 *)0xb;
  local_14 = uVar4;
  FUN_0082ef00(&local_50);
  if (local_54 == (undefined4 *)*(int *)(in_ECX + 0x50)) {
    uVar8 = 0;
  }
  else {
    uVar8 = *(undefined4 *)((int)local_54 + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar8;
  FUN_0043dd20(uVar4);
  FUN_0043c570(51000);
  FUN_0043c570(52000);
  FUN_0043c570(53000);
  FUN_0043c570(61000);
  FUN_0046b6f0(10000);
  FUN_0046b6f0(58000);
  iVar7 = *(int *)(in_ECX + 0x104);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar7 + 0xa4) = 1;
  iVar7 = *(int *)(in_ECX + 0x104);
  if (((*(char *)(iVar7 + 0xa4) != '\0') && (*(int *)(iVar7 + 0x94) != 0)) &&
     (iVar5 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar7 + 0x94) + 0x4c) = 1;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  iVar7 = DAT_00f943ac;
  local_50 = (undefined4 *)0x5d;
  FUN_0082ef00(&local_50);
  if ((local_54 != (undefined4 *)*(int *)(iVar7 + 8)) && (*(int *)((int)local_54 + 0x10) != 0)) {
    iVar7 = *(int *)(in_ECX + 0x100);
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar7 + 0xa4) = 1;
    iVar7 = *(int *)(in_ECX + 0x100);
    if ((*(char *)(iVar7 + 0xa4) != '\0') &&
       ((*(int *)(iVar7 + 0x94) != 0 &&
        (iVar5 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), iVar5 == 0xbf6b)))) {
      *(undefined1 *)(*(int *)(iVar7 + 0x94) + 0x4c) = 1;
    }
    if ((DAT_00fb7a08 & 1) == 0) {
      DAT_00fb7a08 = DAT_00fb7a08 | 1;
      local_8 = 1;
      FUN_0081ee80();
      _atexit(FUN_00bcd310);
      local_8 = 0xffffffff;
    }
    puVar6 = (undefined4 *)FUN_00426ec0();
    local_8 = 2;
    if (7 < (uint)puVar6[5]) {
      puVar6 = (undefined4 *)*puVar6;
    }
    FUN_00763360(puVar6);
    iVar7 = *(int *)(in_ECX + 0x100);
    if (((*(char *)(iVar7 + 0xa4) != '\0') && (*(int *)(iVar7 + 0x94) != 0)) &&
       (iVar7 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), iVar7 == 0xbf6b)) {
      FUN_0077b200();
    }
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
    iVar7 = DAT_00f943ac;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 3;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
    iVar7 = DAT_00f943ac;
  }
  local_50 = (undefined4 *)0x4b;
  FUN_0082ef00(&local_50);
  if (local_54 == (undefined4 *)*(int *)(iVar7 + 8)) {
    local_50 = (undefined4 *)0x0;
  }
  else {
    local_50 = *(undefined4 **)((int)local_54 + 0x10);
  }
  local_54 = (undefined4 *)(in_ECX + 0x110);
  iVar7 = 0;
  do {
    puVar6 = (undefined4 *)FUN_004068f0();
    local_8 = 4;
    if (7 < (uint)puVar6[5]) {
      puVar6 = (undefined4 *)*puVar6;
    }
    uVar8 = FUN_00763360(puVar6);
    local_8 = 0xffffffff;
    *local_54 = uVar8;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_54 = local_54 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 10);
  local_54 = (undefined4 *)0x0;
  piVar11 = (int *)(in_ECX + 0x108);
  do {
    FUN_0046b6f0((int)local_54 + 0xcb21);
    iVar7 = *piVar11;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar7 + 0xa4) = 1;
    iVar7 = *piVar11;
    if (((*(char *)(iVar7 + 0xa4) != '\0') && (*(int *)(iVar7 + 0x94) != 0)) &&
       (iVar5 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar7 + 0x94) + 0x4c) = 1;
    }
    iVar7 = *piVar11;
    local_58 = *(undefined4 **)(in_ECX + 0x110);
    if (((*(char *)(iVar7 + 0xa4) != '\0') && (*(int *)(iVar7 + 0x94) != 0)) &&
       ((iVar5 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))(), puVar6 = local_58, iVar5 == 0xbf6b
        && (local_50 = *(undefined4 **)(iVar7 + 0x94), (undefined4 *)local_50[4] != local_58)))) {
      if (((local_58 != (undefined4 *)0x0) && (piVar3 = (int *)local_58[2], piVar3 != (int *)0x0))
         && (piVar3[0x27] = piVar3[0x27] + 1, piVar3[0x27] == 1)) {
        (**(code **)(*piVar3 + 0x24))();
      }
      if ((local_50[4] != 0) && (piVar3 = *(int **)(local_50[4] + 8), piVar3 != (int *)0x0)) {
        piVar1 = piVar3 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar3 + 0x28))();
        }
      }
      local_50[4] = puVar6;
    }
    (**(code **)(*(int *)*piVar11 + 0x94))(0);
    local_54 = (undefined4 *)((int)local_54 + 1);
    piVar11 = piVar11 + 1;
  } while ((int)local_54 < 2);
  local_58 = (undefined4 *)
             (*(int *)(*(int *)(in_ECX + 0x108) + 0x10) - *(int *)(*(int *)(in_ECX + 0x108) + 8));
  uVar8 = FUN_008fed10();
  uVar4 = DAT_00f94394 & 1;
  *(undefined4 *)(in_ECX + 0x160) = uVar8;
  *(undefined4 *)(in_ECX + 0x15c) = *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 8);
  if (uVar4 == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 5;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  puVar6 = (undefined4 *)(*(undefined4 **)(DAT_00f943ac + 8))[1];
  cVar2 = *(char *)((int)puVar6 + 0x15);
  local_58 = *(undefined4 **)(DAT_00f943ac + 8);
  while (cVar2 == '\0') {
    if ((uint)puVar6[3] < 0x10) {
      puVar10 = (undefined4 *)puVar6[2];
      puVar6 = local_58;
    }
    else {
      puVar10 = (undefined4 *)*puVar6;
    }
    local_58 = puVar6;
    puVar6 = puVar10;
    cVar2 = *(char *)((int)puVar10 + 0x15);
  }
  if ((local_58 == *(undefined4 **)(DAT_00f943ac + 8)) || (0x10 < (uint)local_58[3])) {
    local_50 = *(undefined4 **)(DAT_00f943ac + 8);
    ppuVar9 = &local_50;
  }
  else {
    ppuVar9 = &local_58;
  }
  if ((*ppuVar9 != *(undefined4 **)(DAT_00f943ac + 8)) &&
     (local_58 = (undefined4 *)(*ppuVar9)[4], local_58 != (undefined4 *)0x0)) {
    iVar7 = 0;
    puVar6 = (undefined4 *)(in_ECX + 0x138);
    do {
      iVar7 = iVar7 + 1;
      puVar10 = (undefined4 *)FUN_004068f0();
      local_8 = 6;
      if (7 < (uint)puVar10[5]) {
        puVar10 = (undefined4 *)*puVar10;
      }
      uVar8 = FUN_00763360(puVar10);
      local_8 = 0xffffffff;
      *puVar6 = uVar8;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
      puVar6 = puVar6 + 1;
    } while (iVar7 < 3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

