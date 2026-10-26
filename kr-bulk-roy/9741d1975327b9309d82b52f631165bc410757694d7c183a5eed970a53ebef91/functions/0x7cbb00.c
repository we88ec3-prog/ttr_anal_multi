
void FUN_007cbb00(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (*(int *)(iVar1 + 4) == -0x5eed0000) {
    uVar4 = 0;
    if (0 < (int)(param_1[0x37] - param_1[0x36] & 0xfffffffcU)) {
      do {
        if (uVar4 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uVar2 = *(undefined4 *)(param_1[0x36] + uVar4 * 4);
        }
        else {
          uVar2 = 0;
        }
        FUN_007cbb00(uVar2,param_2);
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < param_1[0x37] - param_1[0x36] >> 2);
    }
    iVar1 = (**(code **)(*param_1 + 0x34))();
    if (iVar1 != 0) {
      uVar4 = 0;
      do {
        uVar2 = (**(code **)(*param_1 + 0x30))(uVar4,param_2);
        FUN_007cbb00(uVar2);
        uVar4 = uVar4 + 1;
        uVar3 = (**(code **)(*param_1 + 0x34))();
      } while (uVar4 < uVar3);
    }
  }
  else if (*(int *)(iVar1 + 4) == -0x5ed70000) {
    FUN_007bb350();
    return;
  }
  return;
}

