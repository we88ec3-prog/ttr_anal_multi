
void FUN_008ce340(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  piVar3 = param_1;
  iVar4 = param_3 * 0xcc;
  local_c = *(int *)(iVar4 + 200 + param_2);
  local_14 = iVar4 + 4 + param_2;
  if ((*(byte *)(param_1 + 4) & 8) != 0) {
    return;
  }
  lVar2 = (longlong)*param_1 * (longlong)local_c +
          (ulonglong)((int)((longlong)*param_1 * (longlong)local_c >> 0x3f) + 0x8000);
  uVar9 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 +
          *(int *)(iVar4 + 0xcc + param_2);
  lVar2 = (longlong)param_1[1] * (longlong)local_c +
          (ulonglong)((int)((longlong)param_1[1] * (longlong)local_c >> 0x3f) + 0x8000);
  iVar4 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
  if (param_3 == 0) {
    if (*(char *)(param_4 + 0x78) == '\0') {
LAB_008ce4ef:
      param_1[4] = param_1[4] | 8;
      param_1[2] = uVar9;
      param_1[3] = iVar4;
      return;
    }
    if (*(char *)(param_4 + 0x7a) == '\0') goto LAB_008ce3f8;
LAB_008ce509:
    local_10 = 1;
  }
  else {
    if (param_3 == 1) {
      if (*(char *)(param_4 + 0x79) == '\0') goto LAB_008ce4ef;
      if (*(char *)(param_4 + 0x7b) != '\0') goto LAB_008ce509;
    }
LAB_008ce3f8:
    local_10 = 0;
  }
  param_1[3] = iVar4;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  piVar10 = (int *)iVar4;
  if (param_3 == 1) {
    local_8 = (int *)iVar4;
    FUN_008cdc10(param_1[1] + *param_1,*param_1,&local_20);
    piVar10 = local_8;
  }
  if (local_20 == 1) {
    local_18 = local_1c - (int)piVar10;
LAB_008ce589:
    param_1[2] = local_18;
  }
  else {
    if (local_20 == 2) goto LAB_008ce589;
    if (local_20 == 3) {
      param_1[3] = local_1c - local_18;
      goto LAB_008ce589;
    }
    local_8 = (int *)param_1[5];
    if (local_8 != (int *)0x0) {
      if ((*(byte *)(local_8 + 4) & 8) == 0) {
        FUN_008ce340(local_8,param_2,param_3,param_4);
      }
      iVar7 = local_8[3];
      iVar1 = local_8[2];
      iVar5 = FUN_008b7f10(((param_1[1] >> 1) + *param_1) - ((local_8[1] >> 1) + *local_8),local_c);
      uVar9 = iVar5 + (((iVar7 >> 1) + iVar1) - ((int)piVar10 >> 1));
    }
    param_1[2] = uVar9;
    param_1[3] = (int)piVar10;
    uVar6 = uVar9;
    param_1 = (int *)iVar4;
    if (*(char *)(param_4 + 0x7c) != '\0') {
      if ((int)piVar10 < 0x41) {
        if ((int)piVar10 < 0x20) {
          if ((int)piVar10 < 1) {
            uVar6 = uVar9 + 0x20 & 0xffffffc0;
          }
          else {
            uVar6 = (int)piVar10 + 0x20 + uVar9 & 0xffffffc0;
            uVar8 = uVar9 + 0x20 & 0xffffffc0;
            iVar4 = (uVar6 - (int)piVar10) - uVar9;
            iVar7 = uVar8 - uVar9;
            if (iVar7 < 0) {
              iVar7 = -iVar7;
            }
            if (iVar4 < 0) {
              iVar4 = -iVar4;
            }
            if (iVar7 <= iVar4) {
              uVar6 = uVar8;
            }
          }
        }
        else {
          param_1 = (int *)0x40;
          uVar6 = uVar9 + ((int)piVar10 >> 1) & 0xffffffc0;
        }
      }
      else {
        param_1 = (int *)FUN_008ce2a0(0);
      }
    }
    iVar4 = FUN_008ce310();
    piVar3[3] = (int)param_1;
    piVar3[2] = iVar4 + uVar6;
  }
  if (local_10 != 0) {
    if (piVar3[3] < 0x40) {
      uVar9 = 0x40;
    }
    else {
      uVar9 = piVar3[3] + 0x20U & 0xffffffc0;
    }
    if (local_20 == 1) {
      piVar3[2] = local_1c - uVar9;
    }
    else if (local_20 != 2) {
      if (local_20 != 3) {
        iVar4 = (int)uVar9 >> 1;
        piVar3[3] = uVar9;
        if ((uVar9 & 0x40) != 0) {
          piVar3[4] = piVar3[4] | 8;
          piVar3[2] = ((iVar4 + piVar3[2] & 0xffffffc0U) + 0x20) - iVar4;
          piVar3[3] = uVar9;
          return;
        }
        piVar3[4] = piVar3[4] | 8;
        piVar3[2] = (iVar4 + 0x20 + piVar3[2] & 0xffffffc0U) - iVar4;
        piVar3[3] = uVar9;
        return;
      }
      goto LAB_008ce600;
    }
    piVar3[3] = uVar9;
  }
LAB_008ce600:
  piVar3[4] = piVar3[4] | 8;
  return;
}

