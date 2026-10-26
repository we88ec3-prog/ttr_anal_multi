
void FUN_007cbbd0(char *param_1,size_t param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *_Str1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  piVar1 = param_3;
  _Str1 = param_3 + 2;
  if (0xf < (uint)param_3[7]) {
    _Str1 = (int *)*_Str1;
  }
  iVar2 = __strnicmp((char *)_Str1,param_1,param_2);
  uVar4 = param_4;
  if (iVar2 == 0) {
    uVar3 = FUN_006bde40(&param_3);
    FUN_0044bbd0(uVar4,uVar3);
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (*(int *)(iVar2 + 4) == -0x5eed0000) {
    uVar6 = 0;
    if (0 < (int)(piVar1[0x37] - piVar1[0x36] & 0xfffffffcU)) {
      do {
        if (uVar6 < (uint)(piVar1[0x37] - piVar1[0x36] >> 2)) {
          uVar4 = *(undefined4 *)(piVar1[0x36] + uVar6 * 4);
        }
        else {
          uVar4 = 0;
        }
        FUN_007cbbd0(param_1,param_2,uVar4,param_4);
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < piVar1[0x37] - piVar1[0x36] >> 2);
    }
    uVar6 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x34))();
    if (iVar2 != 0) {
      do {
        uVar4 = (**(code **)(*piVar1 + 0x30))(uVar6,param_4);
        FUN_007cbbd0(param_1,param_2,uVar4);
        uVar6 = uVar6 + 1;
        uVar5 = (**(code **)(*piVar1 + 0x34))();
      } while (uVar6 < uVar5);
    }
  }
  else if ((*(int *)(iVar2 + 4) == -0x5edf0000) &&
          (uVar6 = 0, piVar1[0x1f] - piVar1[0x1e] >> 2 != 0)) {
    do {
      FUN_007cbbd0(param_1,param_2,*(undefined4 *)(piVar1[0x1e] + uVar6 * 4),param_4);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)(piVar1[0x1f] - piVar1[0x1e] >> 2));
    return;
  }
  return;
}

