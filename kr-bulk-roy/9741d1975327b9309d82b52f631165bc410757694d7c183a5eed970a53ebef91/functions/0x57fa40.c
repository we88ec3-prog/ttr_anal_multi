
void FUN_0057fa40(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_1[0x1d] == 0) {
    if ((param_1[0x1e] != 0) || (param_1[0x1f] != 0)) {
      if (param_1[0x1f] != 0) {
        param_1[0x1f] = 0;
        (**(code **)(*(int *)(param_1[3] + 8) + 8))();
        (**(code **)(*(int *)(param_1[2] + 8) + 8))();
      }
      FUN_0057f750();
      return;
    }
  }
  else {
    (**(code **)(*(int *)*param_1 + 0xe8))((int *)*param_1,0x8b,param_1 + 0x20);
    (**(code **)(*(int *)param_1[0x15] + 0xc))(param_2);
    if (((int *)param_1[0x15] != (int *)0x0) &&
       (iVar1 = (**(code **)(*(int *)param_1[0x15] + 8))(), iVar1 != 0)) {
      switch(param_1[0x1b]) {
      case 0:
        param_1[0x1c] = 0;
        param_1[0x1b] = 1;
        iVar1 = FUN_005809a0();
        param_1[0x1a] = iVar1;
        if (iVar1 != 0) {
          if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)param_1[4])(1);
            param_1[4] = 0;
          }
          puVar2 = (undefined4 *)(param_1[0x1a] + 8);
          if (0xf < *(uint *)(param_1[0x1a] + 0x1c)) {
            puVar2 = (undefined4 *)*puVar2;
          }
          uVar3 = FUN_00734330(puVar2,0);
          param_1[4] = uVar3;
        }
        FUN_0057f930();
        return;
      case 1:
        iVar1 = FUN_005809a0();
        param_1[0x1b] = 3 - (uint)(iVar1 != 0);
        FUN_0057f930();
        return;
      case 2:
        param_1[0x1c] = param_1[0x1c] + 1;
        iVar1 = FUN_005809a0();
        param_1[0x1a] = iVar1;
        param_1[0x1b] = 1;
        if (iVar1 != 0) {
          if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)param_1[4])(1);
            param_1[4] = 0;
          }
          puVar2 = (undefined4 *)(param_1[0x1a] + 8);
          if (0xf < *(uint *)(param_1[0x1a] + 0x1c)) {
            puVar2 = (undefined4 *)*puVar2;
          }
          uVar3 = FUN_00734330(puVar2,0);
          param_1[4] = uVar3;
        }
        FUN_0057f930();
        return;
      case 3:
        param_1[0x1d] = 0;
      }
    }
  }
  return;
}

