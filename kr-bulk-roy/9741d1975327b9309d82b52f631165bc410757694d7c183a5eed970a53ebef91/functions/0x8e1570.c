
uint FUN_008e1570(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int *in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = (*param_4 - *param_3) + 0x10 >> 5;
  iVar5 = (param_4[1] - param_3[1]) + 0x10 >> 5;
  lVar1 = (longlong)((*param_2 - *in_ECX) + 0x10 >> 5) * (longlong)iVar5;
  lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
  lVar2 = (longlong)((param_2[1] - in_ECX[1]) + 0x10 >> 5) * (longlong)iVar4;
  lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
  uVar3 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
  iVar6 = (((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000) - uVar3;
  if (iVar6 != 0) {
    lVar1 = (longlong)((*param_3 - *in_ECX) + 0x10 >> 5) * (longlong)iVar5;
    lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
    lVar2 = (longlong)((param_3[1] - in_ECX[1]) + 0x10 >> 5) * (longlong)iVar4;
    lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
    iVar4 = FUN_008b7f40((((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000) -
                         (((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000),iVar6);
    lVar1 = (longlong)iVar4 * (longlong)(*param_2 - *in_ECX);
    lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
    *param_5 = *in_ECX + ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
    lVar1 = (longlong)iVar4 * (longlong)(param_2[1] - in_ECX[1]);
    lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
    param_5[1] = in_ECX[1] + ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
    iVar4 = *in_ECX;
    if (iVar4 == *param_2) {
      iVar5 = *param_5 - iVar4;
      if (iVar5 < 0) {
        iVar5 = iVar4 - *param_5;
      }
      if (iVar5 < *(int *)(param_1 + 0x2db4)) {
        *param_5 = iVar4;
      }
    }
    iVar4 = in_ECX[1];
    if (iVar4 == param_2[1]) {
      iVar5 = param_5[1] - iVar4;
      if (iVar5 < 0) {
        iVar5 = iVar4 - param_5[1];
      }
      if (iVar5 < *(int *)(param_1 + 0x2db4)) {
        param_5[1] = iVar4;
      }
    }
    iVar4 = *param_3;
    if (iVar4 == *param_4) {
      iVar5 = *param_5 - iVar4;
      if (iVar5 < 0) {
        iVar5 = iVar4 - *param_5;
      }
      if (iVar5 < *(int *)(param_1 + 0x2db4)) {
        *param_5 = iVar4;
      }
    }
    iVar4 = param_3[1];
    if (iVar4 == param_4[1]) {
      iVar5 = param_5[1] - iVar4;
      if (iVar5 < 0) {
        iVar5 = iVar4 - param_5[1];
      }
      if (iVar5 < *(int *)(param_1 + 0x2db4)) {
        param_5[1] = iVar4;
      }
    }
    iVar4 = (*param_2 + *param_3) / 2;
    uVar3 = *param_5 - iVar4;
    if ((int)uVar3 < 0) {
      uVar3 = iVar4 - *param_5;
    }
    if ((int)uVar3 <= *(int *)(param_1 + 0x2db0)) {
      iVar4 = (param_3[1] + param_2[1]) / 2;
      uVar3 = param_5[1] - iVar4;
      if ((int)uVar3 < 0) {
        uVar3 = iVar4 - param_5[1];
      }
      if ((int)uVar3 <= *(int *)(param_1 + 0x2db0)) {
        return CONCAT31((int3)(uVar3 >> 8),1);
      }
    }
  }
  return uVar3 & 0xffffff00;
}

