
void FUN_007c6c20(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (*(int *)(iVar1 + 4) == -0x5eed0000) {
    iVar1 = param_1[0x37] - param_1[0x36] >> 2;
    uVar3 = 0;
    if (0 < iVar1) {
      do {
        if (uVar3 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uVar2 = *(undefined4 *)(param_1[0x36] + uVar3 * 4);
        }
        else {
          uVar2 = 0;
        }
        FUN_007c6c20(uVar2,param_2);
        uVar3 = uVar3 + 1;
      } while ((int)uVar3 < iVar1);
    }
    uVar3 = (**(code **)(*param_1 + 0x34))();
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        uVar2 = (**(code **)(*param_1 + 0x30))(uVar4,param_2);
        FUN_007c6c20(uVar2);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
  }
  else if (*(int *)(iVar1 + 4) == -0x5edf0000) {
    FUN_007bb350();
    return;
  }
  return;
}

