
void FUN_008e0770(int param_1,int param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  int *in_EAX;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char in_DL;
  int iVar11;
  
  *param_4 = 0;
  if ((param_5 == 0) && (in_DL == '\0')) {
    return;
  }
  if (param_1 < 0x28f) {
    return;
  }
  if (in_DL == '\0') goto LAB_008e09b1;
  iVar9 = in_EAX[1];
  iVar10 = in_EAX[2];
  iVar1 = in_EAX[5];
  iVar2 = in_EAX[4];
  iVar3 = in_EAX[3];
  iVar4 = in_EAX[6];
  iVar5 = in_EAX[7];
  lVar6 = (longlong)(param_3 + param_5) * (longlong)param_1;
  lVar6 = lVar6 + (ulonglong)((int)(lVar6 >> 0x3f) + 0x8000);
  iVar7 = ((uint)lVar6 >> 0x10) + (int)((ulonglong)lVar6 >> 0x20) * 0x10000;
  if ((param_1 < 0x10001) || (param_3 + param_5 < iVar7)) {
    lVar6 = (longlong)iVar7 * (longlong)param_2 +
            (ulonglong)((int)((longlong)iVar7 * (longlong)param_2 >> 0x3f) + 0x8000);
    iVar8 = ((uint)lVar6 >> 0x10) + (int)((ulonglong)lVar6 >> 0x20) * 0x10000;
    if ((0x10000 < param_2) && (iVar8 <= iVar7)) goto LAB_008e084e;
  }
  else {
    iVar7 = 0;
LAB_008e084e:
    iVar8 = iVar4 << 0x10;
  }
  iVar11 = *in_EAX * 0x10000;
  if (iVar8 < iVar11) {
    iVar9 = FUN_008b7f40(iVar9 << 0x10,param_2);
    *param_4 = iVar9;
  }
  else if (iVar8 < iVar10 * 0x10000) {
    iVar8 = iVar10 - *in_EAX;
    iVar11 = FUN_008b7f40(iVar11,param_2);
    if (iVar8 == 0) {
LAB_008e08ef:
      iVar9 = FUN_008b7f40(iVar10 * 0x10000,param_2);
      if (iVar2 - iVar10 == 0) {
LAB_008e093d:
        iVar9 = FUN_008b7f40(iVar2 << 0x10,param_2);
        if (iVar4 - iVar2 == 0) goto LAB_008e0980;
        iVar9 = FUN_008b7dc0(iVar7 - iVar9,iVar5 - iVar1,iVar4 - iVar2);
        iVar10 = FUN_008b7f40(iVar1 << 0x10,param_2);
        *param_4 = iVar9 + iVar10;
      }
      else {
        iVar9 = FUN_008b7dc0(iVar7 - iVar9,iVar1 - iVar3,iVar2 - iVar10);
        iVar10 = FUN_008b7f40(iVar3 << 0x10,param_2);
        *param_4 = iVar9 + iVar10;
      }
    }
    else {
      iVar10 = FUN_008b7dc0(iVar7 - iVar11,iVar3 - iVar9,iVar8);
      iVar9 = FUN_008b7f40(iVar9 << 0x10,param_2);
      *param_4 = iVar10 + iVar9;
    }
  }
  else {
    if (iVar8 < iVar2 * 0x10000) goto LAB_008e08ef;
    if (iVar8 < iVar4 * 0x10000) goto LAB_008e093d;
LAB_008e0980:
    iVar9 = FUN_008b7f40(iVar5 << 0x10,param_2);
    *param_4 = iVar9;
  }
  iVar9 = FUN_008b7f40(*param_4,param_1 * 2);
  *param_4 = iVar9;
LAB_008e09b1:
  *param_4 = *param_4 + param_5 / 2;
  return;
}

