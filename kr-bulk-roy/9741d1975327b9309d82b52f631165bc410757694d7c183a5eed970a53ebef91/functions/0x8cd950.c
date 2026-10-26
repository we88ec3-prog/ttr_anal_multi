
void FUN_008cd950(int *param_1,int param_2)

{
  longlong lVar1;
  int in_EAX;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_14;
  uint local_8;
  
  if (param_2 < 0x20c49ba) {
    *(bool *)(param_1 + 0x208) = param_2 * 0x7d < param_1[0x204] * 8;
  }
  else {
    *(bool *)(param_1 + 0x208) = param_2 < (param_1[0x204] * 8) / 0x7d;
  }
  iVar5 = param_1[0x205];
  while ((0 < iVar5 &&
         (lVar1 = (longlong)iVar5 * (longlong)param_2 +
                  (ulonglong)((int)((longlong)iVar5 * (longlong)param_2 >> 0x3f) + 0x8000),
         0x20 < (int)(((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000)))) {
    iVar5 = iVar5 + -1;
  }
  param_1[0x206] = iVar5;
  local_8 = 0;
  do {
    piVar2 = param_1;
    if (local_8 != 0) {
      if (local_8 == 1) {
        piVar2 = param_1 + 0x81;
      }
      else if (local_8 == 2) {
        piVar2 = param_1 + 0x102;
      }
      else {
        piVar2 = param_1 + 0x183;
      }
    }
    piVar3 = piVar2 + 1;
    for (iVar5 = *piVar2; iVar5 != 0; iVar5 = iVar5 + -1) {
      lVar1 = (longlong)piVar3[2] * (longlong)param_2 +
              (ulonglong)((int)((longlong)piVar3[2] * (longlong)param_2 >> 0x3f) + 0x8000);
      piVar3[7] = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000 + in_EAX;
      lVar1 = (longlong)piVar3[3] * (longlong)param_2 +
              (ulonglong)((int)((longlong)piVar3[3] * (longlong)param_2 >> 0x3f) + 0x8000);
      piVar3[6] = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000 + in_EAX;
      lVar1 = (longlong)*piVar3 * (longlong)param_2 +
              (ulonglong)((int)((longlong)*piVar3 * (longlong)param_2 >> 0x3f) + 0x8000);
      piVar3[4] = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000 + in_EAX;
      lVar1 = (longlong)piVar3[1] * (longlong)param_2 +
              (ulonglong)((int)((longlong)piVar3[1] * (longlong)param_2 >> 0x3f) + 0x8000);
      piVar3[5] = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
      piVar3[4] = piVar3[4] + 0x20U & 0xffffffc0;
      piVar3 = piVar3 + 8;
    }
    local_8 = local_8 + 1;
  } while (local_8 < 4);
  local_8 = 0;
  do {
    if (local_8 == 0) {
      piVar2 = param_1 + 0x102;
      piVar3 = param_1;
    }
    else {
      piVar2 = param_1 + 0x183;
      piVar3 = param_1 + 0x81;
    }
    piVar4 = piVar3 + 1;
    for (iVar5 = *piVar3; iVar5 != 0; iVar5 = iVar5 + -1) {
      piVar3 = piVar2 + 1;
      for (iVar6 = *piVar2; iVar6 != 0; iVar6 = iVar6 + -1) {
        local_14 = *piVar4 - *piVar3;
        if (local_14 < 0) {
          local_14 = -local_14;
        }
        lVar1 = (longlong)local_14 * (longlong)param_2 +
                (ulonglong)((int)((longlong)local_14 * (longlong)param_2 >> 0x3f) + 0x8000);
        if ((int)(((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000) < 0x40) {
          piVar4[7] = piVar3[7];
          piVar4[6] = piVar3[6];
          piVar4[4] = piVar3[4];
          piVar4[5] = piVar3[5];
          break;
        }
        piVar3 = piVar3 + 8;
      }
      piVar4 = piVar4 + 8;
    }
    local_8 = local_8 + 1;
    if (1 < local_8) {
      return;
    }
  } while( true );
}

