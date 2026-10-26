
void FUN_007cc5a0(char *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *_Str;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  
  piVar1 = param_3;
  _Str = param_3 + 2;
  if (0xf < (uint)param_3[7]) {
    _Str = (int *)*_Str;
  }
  pcVar2 = _strstr((char *)_Str,param_1);
  uVar5 = param_4;
  if (pcVar2 != (char *)0x0) {
    uVar3 = FUN_006bde40(&param_3);
    FUN_0044bbd0(uVar5,uVar3);
  }
  iVar4 = (**(code **)(*piVar1 + 4))();
  if (*(int *)(iVar4 + 4) == -0x5eed0000) {
    uVar7 = 0;
    if (0 < (int)(piVar1[0x37] - piVar1[0x36] & 0xfffffffcU)) {
      do {
        if (uVar7 < (uint)(piVar1[0x37] - piVar1[0x36] >> 2)) {
          uVar5 = *(undefined4 *)(piVar1[0x36] + uVar7 * 4);
        }
        else {
          uVar5 = 0;
        }
        FUN_007cc5a0(param_1,param_2,uVar5,param_4);
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < piVar1[0x37] - piVar1[0x36] >> 2);
    }
    uVar7 = 0;
    iVar4 = (**(code **)(*piVar1 + 0x34))();
    if (iVar4 != 0) {
      do {
        uVar5 = (**(code **)(*piVar1 + 0x30))(uVar7,param_4);
        FUN_007cc5a0(param_1,param_2,uVar5);
        uVar7 = uVar7 + 1;
        uVar6 = (**(code **)(*piVar1 + 0x34))();
      } while (uVar7 < uVar6);
    }
  }
  else if ((*(int *)(iVar4 + 4) == -0x5edf0000) &&
          (uVar7 = 0, piVar1[0x1f] - piVar1[0x1e] >> 2 != 0)) {
    do {
      FUN_007cc5a0(param_1,param_2,*(undefined4 *)(piVar1[0x1e] + uVar7 * 4),param_4);
      uVar7 = uVar7 + 1;
    } while (uVar7 < (uint)(piVar1[0x1f] - piVar1[0x1e] >> 2));
    return;
  }
  return;
}

