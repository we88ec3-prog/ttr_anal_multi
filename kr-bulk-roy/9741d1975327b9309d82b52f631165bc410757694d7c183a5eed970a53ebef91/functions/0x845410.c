
undefined4 * FUN_00845410(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  bool bVar3;
  int in_EAX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(in_EAX + 4);
  bVar3 = true;
  if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      bVar3 = *(int *)(param_2 + 0xc) < (int)puVar5[3];
      if (bVar3) {
        puVar4 = (undefined4 *)*puVar5;
      }
      else {
        puVar4 = (undefined4 *)puVar5[2];
      }
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  }
  if (bVar3) {
    if (puVar5 == (undefined4 *)**(int **)(in_EAX + 4)) {
      puVar5 = (undefined4 *)FUN_008454f0(&param_2,1,param_2);
      *param_1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      return param_1;
    }
    FUN_0053f8a0();
  }
  if ((int)puVar5[3] < *(int *)(param_2 + 0xc)) {
    puVar5 = (undefined4 *)FUN_008454f0(&param_2,bVar3,param_2);
    uVar2 = *puVar5;
    *(undefined1 *)(param_1 + 1) = 1;
    *param_1 = uVar2;
    return param_1;
  }
  puVar4 = *(undefined4 **)(param_2 + 0x10);
  if (puVar4 != (undefined4 *)0x0) {
    piVar1 = puVar4 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*puVar4)(1);
    }
  }
  FUN_0089120c(param_2);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = puVar5;
  return param_1;
}

