
undefined4 * FUN_00784330(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_EAX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  
  puVar4 = *(undefined4 **)(in_EAX + 4);
  bVar5 = true;
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      bVar5 = *(uint *)(param_2 + 0xc) < (uint)puVar4[3];
      if (bVar5) {
        puVar3 = (undefined4 *)*puVar4;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
      }
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_EAX + 4)) {
      puVar4 = (undefined4 *)FUN_008454f0(&param_2,1,param_2);
      *param_1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      return param_1;
    }
    FUN_0053f8a0();
  }
  if ((uint)puVar4[3] < *(uint *)(param_2 + 0xc)) {
    puVar4 = (undefined4 *)FUN_008454f0(&param_2,bVar5,param_2);
    uVar2 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    *param_1 = uVar2;
    return param_1;
  }
  puVar3 = *(undefined4 **)(param_2 + 0x10);
  if (puVar3 != (undefined4 *)0x0) {
    piVar1 = puVar3 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*puVar3)(1);
    }
  }
  FUN_0089120c(param_2);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = puVar4;
  return param_1;
}

