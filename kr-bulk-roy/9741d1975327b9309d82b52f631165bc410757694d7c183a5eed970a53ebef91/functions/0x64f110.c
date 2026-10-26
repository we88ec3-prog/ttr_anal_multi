
void FUN_0064f110(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d6fc;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar5 = &DAT_00f94540;
  piVar6 = (int *)(in_ECX + 0xdc);
  do {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 0;
      FUN_005c3de0(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    iVar2 = piVar5[-4];
    if (piVar6[-8] != iVar2) {
      if (((iVar2 != 0) && (piVar3 = *(int **)(iVar2 + 8), piVar3 != (int *)0x0)) &&
         (piVar3[0x27] = piVar3[0x27] + 1, piVar3[0x27] == 1)) {
        (**(code **)(*piVar3 + 0x24))();
      }
      if ((piVar6[-8] != 0) && (piVar3 = *(int **)(piVar6[-8] + 8), piVar3 != (int *)0x0)) {
        piVar1 = piVar3 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar3 + 0x28))();
        }
      }
      piVar6[-8] = iVar2;
    }
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 1;
      FUN_005c3de0(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    iVar2 = *piVar5;
    if (*piVar6 != iVar2) {
      if (((iVar2 != 0) && (piVar3 = *(int **)(iVar2 + 8), piVar3 != (int *)0x0)) &&
         (piVar3[0x27] = piVar3[0x27] + 1, piVar3[0x27] == 1)) {
        (**(code **)(*piVar3 + 0x24))();
      }
      if ((*piVar6 != 0) && (piVar3 = *(int **)(*piVar6 + 8), piVar3 != (int *)0x0)) {
        piVar1 = piVar3 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar3 + 0x28))();
        }
      }
      *piVar6 = iVar2;
    }
    piVar5 = piVar5 + 1;
    piVar6 = piVar6 + 2;
  } while ((int)piVar5 < 0xf94550);
  ExceptionList = local_10;
  return;
}

