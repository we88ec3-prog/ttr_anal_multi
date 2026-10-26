
void FUN_008cd620(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  int iVar8;
  int in_ECX;
  
  iVar2 = *(int *)(in_EAX * 0xcc + 200 + in_ECX);
  piVar1 = (int *)(in_EAX * 0xcc + 4 + in_ECX);
  iVar3 = *piVar1;
  if (iVar3 != 0) {
    lVar4 = (longlong)piVar1[1] * (longlong)iVar2;
    lVar4 = lVar4 + (ulonglong)((int)(lVar4 >> 0x3f) + 0x8000);
    iVar6 = ((uint)lVar4 >> 0x10) + (int)((ulonglong)lVar4 >> 0x20) * 0x10000;
    piVar1[2] = iVar6;
    piVar1[3] = iVar6 + 0x20U & 0xffffffc0;
    piVar5 = piVar1 + 1;
    while (iVar3 = iVar3 + -1, iVar3 != 0) {
      lVar4 = (longlong)piVar5[3] * (longlong)iVar2;
      lVar4 = lVar4 + (ulonglong)((int)(lVar4 >> 0x3f) + 0x8000);
      iVar7 = ((uint)lVar4 >> 0x10) + (int)((ulonglong)lVar4 >> 0x20) * 0x10000;
      iVar6 = piVar1[2];
      iVar8 = iVar7 - iVar6;
      if (iVar8 < 0) {
        iVar8 = -iVar8;
      }
      if (iVar8 < 0x80) {
        iVar7 = iVar6;
      }
      piVar5[4] = iVar7;
      piVar5[5] = iVar7 + 0x20U & 0xffffffc0;
      piVar5 = piVar5 + 3;
    }
  }
  return;
}

