
void FUN_007c73a0(int *param_1,float *param_2,float *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  float *pfVar6;
  uint uVar7;
  undefined1 local_c [4];
  int local_8;
  
  piVar1 = param_1;
  iVar3 = (**(code **)(*param_1 + 4))();
  piVar2 = param_4;
  iVar3 = *(int *)(iVar3 + 4);
  if (iVar3 == -0x5eed0000) {
    uVar7 = 0;
    if (piVar1[0x37] - piVar1[0x36] >> 2 != 0) {
      do {
        if (uVar7 < (uint)(piVar1[0x37] - piVar1[0x36] >> 2)) {
          uVar4 = *(undefined4 *)(piVar1[0x36] + uVar7 * 4);
        }
        else {
          uVar4 = 0;
        }
        FUN_007c73a0(uVar4,param_2,param_3,piVar2);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(piVar1[0x37] - piVar1[0x36] >> 2));
    }
    uVar7 = 0;
    iVar3 = (**(code **)(*piVar1 + 0x34))();
    if (iVar3 != 0) {
      do {
        uVar4 = (**(code **)(*piVar1 + 0x30))(uVar7,param_2,param_3,piVar2);
        FUN_007c73a0(uVar4);
        uVar7 = uVar7 + 1;
        uVar5 = (**(code **)(*piVar1 + 0x34))();
      } while (uVar7 < uVar5);
    }
  }
  else if (iVar3 == -0x5edf0000) {
    if (piVar1[0x1f] - piVar1[0x1e] >> 2 != 0) {
      uVar7 = 0;
      do {
        FUN_007c73a0(*(undefined4 *)(piVar1[0x1e] + uVar7 * 4),param_2,param_3,piVar2);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(piVar1[0x1f] - piVar1[0x1e] >> 2));
      return;
    }
  }
  else if (((iVar3 == -0x5edc0000) && (*(int *)(piVar1[0x1e] + 0x40) != 0)) &&
          (FUN_008570d0(local_c,&param_1,&local_8), param_1 != (int *)0x0)) {
    pfVar6 = (float *)(local_8 + 8);
    do {
      if (*param_4 == 0) {
        if (pfVar6[-2] < *param_2) {
          *param_2 = pfVar6[-2];
        }
        if (pfVar6[-1] < param_2[1]) {
          param_2[1] = pfVar6[-1];
        }
        if (*pfVar6 < param_2[2]) {
          param_2[2] = *pfVar6;
        }
        if (*param_3 < pfVar6[-2]) {
          *param_3 = pfVar6[-2];
        }
        if (param_3[1] < pfVar6[-1]) {
          param_3[1] = pfVar6[-1];
        }
        if (param_3[2] < *pfVar6) {
          param_3[2] = *pfVar6;
        }
      }
      else {
        *param_3 = pfVar6[-2];
        param_3[1] = pfVar6[-1];
        param_3[2] = *pfVar6;
        *param_2 = *param_3;
        param_2[1] = param_3[1];
        param_2[2] = param_3[2];
        *param_4 = 0;
      }
      pfVar6 = pfVar6 + 3;
      param_1 = (int *)((int)param_1 + -1);
    } while (param_1 != (int *)0x0);
    return;
  }
  return;
}

