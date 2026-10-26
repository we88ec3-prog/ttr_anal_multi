
int FUN_007c65d0(int *param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  char *_Str1;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  
  piVar1 = param_1;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar6 = param_1[0x37] - param_1[0x36] >> 2;
  param_1 = (int *)0x0;
  if (0 < iVar6) {
    do {
      if (param_1 < (uint)(piVar1[0x37] - piVar1[0x36] >> 2)) {
        piVar5 = *(int **)(piVar1[0x36] + (int)param_1 * 4);
      }
      else {
        piVar5 = (int *)0x0;
      }
      iVar2 = (**(code **)(*piVar5 + 4))();
      if (*(int *)(iVar2 + 4) == -0x5edf0000) {
        if (param_1 < (uint)(piVar1[0x37] - piVar1[0x36] >> 2)) {
          iVar2 = *(int *)(piVar1[0x36] + (int)param_1 * 4);
        }
        else {
          iVar2 = 0;
        }
        uVar7 = 0;
        if (*(int *)(iVar2 + 0x7c) - *(int *)(iVar2 + 0x78) >> 2 != 0) {
          do {
            iVar3 = *(int *)(*(int *)(iVar2 + 0x78) + uVar7 * 4);
            _Str1 = (char *)(iVar3 + 8);
            if (0xf < *(uint *)(iVar3 + 0x1c)) {
              _Str1 = *(char **)_Str1;
            }
            iVar3 = __stricmp(_Str1,param_2);
            if (iVar3 == 0) {
              return iVar2;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < (uint)(*(int *)(iVar2 + 0x7c) - *(int *)(iVar2 + 0x78) >> 2));
        }
      }
      param_1 = (int *)((int)param_1 + 1);
    } while ((int)param_1 < iVar6);
  }
  iVar6 = (**(code **)(*piVar1 + 0x34))();
  iVar2 = 0;
  if (0 < iVar6) {
    do {
      uVar4 = (**(code **)(*piVar1 + 0x30))(iVar2,param_2);
      iVar3 = FUN_007c65d0(uVar4);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar6);
  }
  return 0;
}

