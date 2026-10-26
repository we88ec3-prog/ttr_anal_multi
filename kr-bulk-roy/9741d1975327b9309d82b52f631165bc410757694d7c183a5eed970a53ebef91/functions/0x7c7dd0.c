
void FUN_007c7dd0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  piVar1 = param_1;
  iVar2 = (**(code **)(*param_1 + 4))();
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == -0x5eed0000) {
    uVar4 = 0;
    iVar2 = param_1[0x37] - param_1[0x36] >> 2;
    if (0 < iVar2) {
      do {
        if (uVar4 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uVar3 = *(undefined4 *)(param_1[0x36] + uVar4 * 4);
        }
        else {
          uVar3 = 0;
        }
        FUN_007c7dd0(uVar3,param_2);
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < iVar2);
    }
    uVar4 = (**(code **)(*param_1 + 0x34))();
    uVar5 = 0;
    if (uVar4 != 0) {
      do {
        uVar3 = (**(code **)(*param_1 + 0x30))(uVar5,param_2);
        FUN_007c7dd0(uVar3);
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar4);
    }
  }
  else if (iVar2 == -0x5edf0000) {
    uVar4 = 0;
    uVar5 = param_1[0x1f] - param_1[0x1e] >> 2;
    if (uVar5 != 0) {
      do {
        FUN_007c7dd0(*(undefined4 *)(param_1[0x1e] + uVar4 * 4),param_2);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar5);
    }
    uVar5 = 0;
    uVar4 = param_1[0x23] - param_1[0x22] >> 2;
    if (uVar4 != 0) {
      do {
        if ((uint)(param_1[0x23] - param_1[0x22] >> 2) <= uVar5) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        FUN_007c7dd0(*(undefined4 *)(param_1[0x22] + uVar5 * 4),param_2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar4);
      return;
    }
  }
  else if (iVar2 == -0x5edc0000) {
    uVar4 = 0;
    if ((int *)param_1[0x1d] == (int *)0x0) {
      param_1 = (int *)0x0;
    }
    else {
      param_1 = (int *)(**(code **)(*(int *)param_1[0x1d] + 0x38))();
      if (param_1 == (int *)0x0) {
        param_1 = (int *)0x1;
      }
    }
    if (param_1 != (int *)0x0) {
      do {
        if ((((int *)piVar1[0x1d] != (int *)0x0) &&
            (iVar2 = (**(code **)(*(int *)piVar1[0x1d] + 0x24))(), iVar2 != 0)) &&
           (iVar2 = (**(code **)(*(int *)piVar1[0x1d] + 0x38))(), (int)uVar4 < iVar2)) {
          (**(code **)(*(int *)piVar1[0x1d] + 0x28))(uVar4);
        }
        FUN_007bb350();
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_1);
      return;
    }
  }
  return;
}

