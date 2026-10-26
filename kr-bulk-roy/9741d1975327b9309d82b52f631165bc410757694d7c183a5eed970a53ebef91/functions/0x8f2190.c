
int FUN_008f2190(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  int *unaff_EBX;
  int iVar7;
  int local_c;
  int *local_8;
  
  iVar2 = unaff_EBX[3];
  iVar7 = (int)*(short *)(iVar2 + 0x3a);
  iVar6 = *(int *)(iVar2 + 0x3c);
  *(int *)(iVar6 + iVar7 * 8) = unaff_EBX[0x11];
  *(int *)(iVar6 + 4 + iVar7 * 8) = unaff_EBX[0x12];
  iVar6 = *(int *)(iVar2 + 0x3c);
  *(int *)(iVar6 + 8 + iVar7 * 8) = unaff_EBX[0x13];
  *(int *)(iVar6 + 0xc + iVar7 * 8) = unaff_EBX[0x14];
  iVar6 = *(int *)(iVar2 + 0x3c);
  *(int *)(iVar6 + 0x10 + iVar7 * 8) = unaff_EBX[0x2e];
  *(int *)(iVar6 + 0x14 + iVar7 * 8) = unaff_EBX[0x2f];
  iVar6 = *(int *)(iVar2 + 0x3c);
  *(int *)(iVar6 + 0x18 + iVar7 * 8) = unaff_EBX[0x30];
  *(int *)(iVar6 + 0x1c + iVar7 * 8) = unaff_EBX[0x31];
  *(undefined1 *)(iVar7 + *(int *)(iVar2 + 0x40)) = 0;
  *(undefined1 *)(iVar7 + 1 + *(int *)(iVar2 + 0x40)) = 0;
  *(undefined1 *)(iVar7 + 2 + *(int *)(iVar2 + 0x40)) = 0;
  *(undefined1 *)(iVar7 + 3 + *(int *)(iVar2 + 0x40)) = 0;
  iVar7 = iVar7 + 4;
  if (*(char *)(*unaff_EBX + 0x2a0) != '\0') {
    uVar3 = *(undefined4 *)(*unaff_EBX + 100);
    iVar6 = FUN_008f1390(unaff_EBX[5],&local_8,iVar7);
    if (iVar6 != 0) {
      return iVar6;
    }
    if (0 < iVar7) {
      iVar6 = 0;
      do {
        piVar1 = (int *)(*(int *)(iVar2 + 0x3c) + iVar6 * 8);
        *piVar1 = *piVar1 + local_8[iVar6 * 2];
        piVar1 = (int *)(*(int *)(iVar2 + 0x3c) + 4 + iVar6 * 8);
        *piVar1 = *piVar1 + local_8[iVar6 * 2 + 1];
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar7);
    }
    FUN_008b9f80(uVar3,local_8);
  }
  local_c = 0;
  if ((*(byte *)(unaff_EBX + 4) & 2) == 0) {
    FUN_008eb180();
    FID_conflict__memcpy
              ((void *)unaff_EBX[0x24],(void *)unaff_EBX[0x23],
               (uint)*(ushort *)(unaff_EBX + 0x21) * 8 + 0x20);
  }
  local_8 = *(int **)(iVar2 + 0x3c);
  piVar1 = local_8 + iVar7 * 2;
  if ((*(byte *)(unaff_EBX + 4) & 1) == 0) {
    iVar6 = *(int *)(unaff_EBX[1] + 0x30);
    iVar4 = *(int *)(unaff_EBX[1] + 0x34);
    for (; local_8 < piVar1; local_8 = local_8 + 2) {
      lVar5 = (longlong)*local_8 * (longlong)iVar6;
      lVar5 = lVar5 + (ulonglong)((int)(lVar5 >> 0x3f) + 0x8000);
      *local_8 = ((uint)lVar5 >> 0x10) + (int)((ulonglong)lVar5 >> 0x20) * 0x10000;
      lVar5 = (longlong)local_8[1] * (longlong)iVar4;
      lVar5 = lVar5 + (ulonglong)((int)(lVar5 >> 0x3f) + 0x8000);
      local_8[1] = ((uint)lVar5 >> 0x10) + (int)((ulonglong)lVar5 >> 0x20) * 0x10000;
    }
    iVar6 = *(int *)(iVar2 + 0x3c);
    unaff_EBX[0x11] = *(int *)(iVar6 + -0x20 + iVar7 * 8);
    unaff_EBX[0x12] = *(int *)(iVar6 + -0x1c + iVar7 * 8);
    iVar6 = *(int *)(iVar2 + 0x3c);
    unaff_EBX[0x13] = *(int *)(iVar6 + -0x18 + iVar7 * 8);
    unaff_EBX[0x14] = *(int *)(iVar6 + -0x14 + iVar7 * 8);
    iVar6 = *(int *)(iVar2 + 0x3c);
    unaff_EBX[0x2e] = *(int *)(iVar6 + -0x10 + iVar7 * 8);
    unaff_EBX[0x2f] = *(int *)(iVar6 + -0xc + iVar7 * 8);
    iVar2 = *(int *)(iVar2 + 0x3c);
    unaff_EBX[0x30] = *(int *)(iVar2 + -8 + iVar7 * 8);
    unaff_EBX[0x31] = *(int *)(iVar2 + -4 + iVar7 * 8);
  }
  if ((*(byte *)(unaff_EBX + 4) & 2) == 0) {
    *(short *)(unaff_EBX + 0x21) = (short)unaff_EBX[0x21] + 4;
    local_c = FUN_008f1f40();
  }
  return local_c;
}

