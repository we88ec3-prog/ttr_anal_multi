
void FUN_0043ab20(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  int *piVar8;
  undefined4 *local_38;
  int local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009201f6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0043c570(0x797c,local_14);
  FUN_0043c570(0x79e0);
  FUN_0043c570(0x7a44);
  FUN_0043c570(0x7aa8);
  FUN_0046b6f0(0x7b70);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  iVar7 = DAT_00f943ac;
  local_34 = 0x4b;
  FUN_0082ef00(&local_34);
  if (local_38 == (undefined4 *)*(int *)(iVar7 + 8)) {
    local_34 = 0;
  }
  else {
    local_34 = *(int *)((int)local_38 + 0x10);
  }
  local_38 = (undefined4 *)(in_ECX + 0x264);
  iVar7 = 0;
  do {
    puVar3 = (undefined4 *)FUN_004068f0();
    local_8 = 1;
    if (7 < (uint)puVar3[5]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    uVar4 = FUN_00763360(puVar3);
    local_8 = 0xffffffff;
    *local_38 = uVar4;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_38 = local_38 + 1;
    iVar7 = iVar7 + 1;
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
  } while (iVar7 < 10);
  local_34 = 0;
  piVar8 = (int *)(in_ECX + 0x25c);
  do {
    FUN_0046b6f0(local_34 + 0x7aa9);
    iVar7 = *piVar8;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar7 + 0xa4) = 1;
    iVar7 = *piVar8;
    if ((*(char *)(iVar7 + 0xa4) != '\0') && (*(int *)(iVar7 + 0x94) != 0)) {
      iVar5 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))();
      if (iVar5 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar7 + 0x94) + 0x4c) = 1;
      }
    }
    iVar7 = *piVar8;
    iVar5 = *(int *)(in_ECX + 0x264);
    if ((*(char *)(iVar7 + 0xa4) != '\0') && (*(int *)(iVar7 + 0x94) != 0)) {
      iVar6 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))();
      if (iVar6 == 0xbf6b) {
        iVar7 = *(int *)(iVar7 + 0x94);
        if (*(int *)(iVar7 + 0x10) != iVar5) {
          if (((iVar5 != 0) && (piVar2 = *(int **)(iVar5 + 8), piVar2 != (int *)0x0)) &&
             (piVar2[0x27] = piVar2[0x27] + 1, piVar2[0x27] == 1)) {
            (**(code **)(*piVar2 + 0x24))();
          }
          if ((*(int *)(iVar7 + 0x10) != 0) &&
             (piVar2 = *(int **)(*(int *)(iVar7 + 0x10) + 8), piVar2 != (int *)0x0)) {
            piVar1 = piVar2 + 0x27;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (**(code **)(*piVar2 + 0x28))();
            }
          }
          *(int *)(iVar7 + 0x10) = iVar5;
        }
      }
    }
    (**(code **)(*(int *)*piVar8 + 0x94))(0);
    local_34 = local_34 + 1;
    piVar8 = piVar8 + 1;
  } while (local_34 < 2);
  iVar7 = *(int *)(in_ECX + 600);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar7 + 0xa4) = 1;
  iVar7 = *(int *)(in_ECX + 600);
  if ((*(char *)(iVar7 + 0xa4) != '\0') && (*(int *)(iVar7 + 0x94) != 0)) {
    iVar5 = (**(code **)(**(int **)(iVar7 + 0x94) + 4))();
    if (iVar5 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar7 + 0x94) + 0x4c) = 1;
    }
  }
  local_34 = *(int *)(*(int *)(in_ECX + 0x25c) + 0x10) - *(int *)(*(int *)(in_ECX + 0x25c) + 8);
  uVar4 = FUN_008fed10();
  *(undefined4 *)(in_ECX + 0x290) = uVar4;
  *(undefined4 *)(in_ECX + 0x28c) = *(undefined4 *)(*(int *)(in_ECX + 0x254) + 8);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

