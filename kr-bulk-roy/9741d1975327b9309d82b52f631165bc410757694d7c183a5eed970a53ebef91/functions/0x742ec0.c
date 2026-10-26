
uint FUN_00742ec0(void)

{
  int *piVar1;
  longlong lVar2;
  uint in_EAX;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 0x54) != '\0') {
    return in_EAX & 0xffffff00;
  }
  piVar3 = (int *)(unaff_ESI + 0x28);
  if (0xf < *(uint *)(unaff_ESI + 0x3c)) {
    piVar3 = (int *)*piVar3;
  }
  piVar1 = (int *)(unaff_ESI + 0x58);
  iVar4 = FUN_008bda60(*(undefined4 *)(unaff_ESI + 8),piVar3,*(undefined4 *)(unaff_ESI + 0x44),
                       piVar1);
  if (iVar4 == 2) {
    *(undefined1 *)(unaff_ESI + 0x54) = 1;
    uVar5 = FID_conflict__wprintf("ERR: Unknown file format\n");
    return uVar5 & 0xffffff00;
  }
  if (iVar4 != 0) {
    *(undefined1 *)(unaff_ESI + 0x54) = 1;
    uVar5 = FID_conflict__wprintf("ERR %d\n",iVar4);
    return uVar5 & 0xffffff00;
  }
  iVar4 = FUN_008b8c70(*piVar1,0x756e6963);
  if (iVar4 != 0) {
    *(undefined1 *)(unaff_ESI + 0x54) = 1;
    uVar5 = FUN_008bbe50(*piVar1);
    return uVar5 & 0xffffff00;
  }
  uVar5 = FUN_008fed10();
  *(uint *)(unaff_ESI + 0x5c) = uVar5;
  uVar6 = FUN_008fed10();
  *(uint *)(unaff_ESI + 0x60) = uVar6;
  iVar4 = FUN_008b8af0(*piVar1,(uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f),
                       (uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f),0x48,0x48);
  if (iVar4 == 0) {
    if (-1 < *(int *)(unaff_ESI + 0x60)) {
      iVar4 = *piVar1;
      lVar2 = (longlong)((int)*(short *)(iVar4 + 0x46) - (int)*(short *)(iVar4 + 0x48)) *
              (longlong)*(int *)(*(int *)(iVar4 + 0x58) + 0x14);
      lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
      iVar4 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
      if (iVar4 != *(int *)(unaff_ESI + 0x60) && -1 < iVar4 - *(int *)(unaff_ESI + 0x60)) {
        uVar7 = FUN_008fed10(0x48,0x48);
        uVar7 = FUN_008fed10(uVar7);
        iVar4 = FUN_008b8af0(*piVar1,uVar7);
        if (iVar4 != 0) goto LAB_0074306d;
      }
    }
    if ((*(byte *)(*piVar1 + 0xc) & 2) == 0) {
      iVar4 = __stricmp("Bold",*(char **)(*piVar1 + 0x18));
      if (iVar4 != 0) {
        *(undefined4 *)(unaff_ESI + 0x50) = 0;
        return 1;
      }
    }
    *(undefined4 *)(unaff_ESI + 0x50) = 1;
    return 1;
  }
LAB_0074306d:
  uVar5 = FUN_008bbe50(*piVar1);
  return uVar5 & 0xffffff00;
}

