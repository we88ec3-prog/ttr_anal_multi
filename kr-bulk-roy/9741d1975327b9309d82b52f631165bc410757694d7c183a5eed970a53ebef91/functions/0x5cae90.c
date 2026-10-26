
undefined4 FUN_005cae90(int param_1,uint param_2,undefined4 *param_3)

{
  char cVar1;
  code *pcVar2;
  char cVar3;
  
  cVar1 = '\x01';
  cVar3 = '\x01';
  if (param_2 < 0x10f) {
    if (param_2 == 0x10e) {
      if (*(int *)(param_1 + 0x24) == 0) goto LAB_005caf93;
      pcVar2 = *(code **)(**(int **)(param_1 + 0x24) + 0x1c);
LAB_005caf78:
      cVar1 = (*pcVar2)();
    }
    else if (param_2 == 0x51) {
      cVar1 = FUN_005cafc0();
    }
    else if (param_2 == 0x102) {
      if (*(int *)(param_1 + 0x24) == 0) goto LAB_005caf93;
      if (*(int *)(param_1 + 0x14) != 0) {
        cVar1 = (**(code **)(**(int **)(param_1 + 0x24) + 0x28))();
      }
    }
    else if (param_2 == 0x10d) {
      if (*(int *)(param_1 + 0x24) == 0) goto LAB_005caf93;
      if (*(int *)(param_1 + 0x14) != 0) {
        pcVar2 = *(code **)(**(int **)(param_1 + 0x24) + 0x18);
        goto LAB_005caf78;
      }
    }
  }
  else if (param_2 == 0x10f) {
    if (*(int *)(param_1 + 0x24) == 0) goto LAB_005caf93;
    if (*(int *)(param_1 + 0x14) != 0) {
      pcVar2 = *(code **)(**(int **)(param_1 + 0x24) + 0x20);
      goto LAB_005caf78;
    }
  }
  else if (param_2 == 0x282) {
    if (*(int *)(param_1 + 0x24) == 0) goto LAB_005caf93;
    if (*(int *)(param_1 + 0x14) != 0) {
      cVar1 = (**(code **)(**(int **)(param_1 + 0x24) + 0x24))();
    }
  }
  cVar3 = cVar1;
  if ((*(int *)(param_1 + 0x24) != 0) && (*(int *)(param_1 + 0x14) == 0)) {
    (**(code **)(**(int **)(param_1 + 0x24) + 0x30))();
  }
LAB_005caf93:
  if (cVar3 != '\0') {
    return 1;
  }
  *param_3 = 1;
  return 0;
}

