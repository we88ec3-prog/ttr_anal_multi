
void FUN_007c5270(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = FUN_007c4af0(param_3);
  if ((iVar1 != 0) && (in_EAX < (uint)(*(int *)(iVar1 + 0x24) - *(int *)(iVar1 + 0x20) >> 2))) {
    if (*(int *)(*(int *)(*(int *)(iVar1 + 0x20) + in_EAX * 4) + 0x58) == 0) {
      FUN_007c5840(param_1,param_3);
    }
    iVar1 = *(int *)(*(int *)(iVar1 + 0x20) + in_EAX * 4);
    piVar4 = *(int **)(iVar1 + 0x44);
    if (piVar4 != *(int **)(iVar1 + 0x48)) {
      do {
        if ((int *)*piVar4 != (int *)0x0) {
          puVar2 = (undefined4 *)(**(code **)(*(int *)*piVar4 + 0xc))();
          iVar3 = FUN_007d3870(param_2,puVar2,param_4);
          if ((iVar3 == 0) && (puVar2 != (undefined4 *)0x0)) {
            (**(code **)*puVar2)(1);
          }
        }
        piVar4 = piVar4 + 1;
      } while (piVar4 != *(int **)(iVar1 + 0x48));
    }
  }
  return;
}

