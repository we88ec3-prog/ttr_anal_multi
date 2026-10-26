
void FUN_008ee9c0(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort *in_EAX;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int unaff_ESI;
  
  if ((((in_EAX[6] < *(ushort *)(unaff_ESI + 0x2c)) && (in_EAX[8] < *(ushort *)(unaff_ESI + 0x2c)))
      && (in_EAX[2] < *(ushort *)(unaff_ESI + 0x50))) &&
     ((in_EAX[4] < *(ushort *)(unaff_ESI + 0x50) && (*in_EAX < *(ushort *)(unaff_ESI + 0x74))))) {
    iVar13 = *(int *)(unaff_ESI + 0x34);
    iVar3 = (uint)in_EAX[8] * 8;
    iVar4 = (uint)in_EAX[6] * 8;
    iVar14 = *(int *)(iVar4 + iVar13);
    iVar15 = *(int *)(iVar4 + 4 + iVar13);
    iVar7 = *(int *)(iVar13 + 4 + iVar3) - iVar15;
    iVar18 = *(int *)(iVar13 + iVar3) - iVar14;
    iVar5 = (uint)in_EAX[4] * 8;
    iVar6 = (uint)in_EAX[2] * 8;
    iVar13 = *(int *)(iVar6 + *(int *)(unaff_ESI + 0x58));
    iVar10 = *(int *)(unaff_ESI + 0x58);
    iVar8 = *(int *)(iVar10 + iVar5) - iVar13;
    iVar2 = *(int *)(iVar6 + 4 + iVar10);
    iVar19 = *(int *)(iVar10 + 4 + iVar5) - iVar2;
    uVar9 = (uint)*in_EAX;
    pbVar1 = (byte *)(uVar9 + *(int *)(unaff_ESI + 0x84));
    *pbVar1 = *pbVar1 | 0x18;
    iVar10 = -iVar7;
    iVar11 = FUN_008b7dc0(iVar8,iVar10,0x40);
    iVar12 = FUN_008b7dc0(iVar19,iVar18,0x40);
    uVar16 = iVar11 + iVar12;
    iVar7 = FUN_008b7dc0(iVar19,iVar7,0x40);
    iVar11 = FUN_008b7dc0(iVar8,iVar18,0x40);
    uVar17 = iVar11 + iVar7 >> 0x1f;
    iVar11 = (iVar11 + iVar7 ^ uVar17) - uVar17;
    iVar7 = ((uVar16 ^ (int)uVar16 >> 0x1f) - ((int)uVar16 >> 0x1f)) * 0x13;
    if (iVar7 - iVar11 != 0 && iVar11 <= iVar7) {
      iVar13 = FUN_008b7dc0(iVar14 - iVar13,iVar10,0x40);
      iVar14 = FUN_008b7dc0(iVar15 - iVar2,iVar18,0x40);
      iVar15 = FUN_008b7dc0(iVar13 + iVar14,iVar8,uVar16);
      iVar13 = FUN_008b7dc0(iVar13 + iVar14,iVar19,uVar16);
      *(int *)(*(int *)(unaff_ESI + 0x7c) + uVar9 * 8) =
           *(int *)(*(int *)(unaff_ESI + 0x58) + iVar6) + iVar15;
      *(int *)(*(int *)(unaff_ESI + 0x7c) + 4 + uVar9 * 8) =
           *(int *)(*(int *)(unaff_ESI + 0x58) + 4 + iVar6) + iVar13;
      return;
    }
    iVar13 = *(int *)(iVar6 + *(int *)(unaff_ESI + 0x58)) +
             *(int *)(*(int *)(unaff_ESI + 0x58) + iVar5) +
             *(int *)(iVar4 + *(int *)(unaff_ESI + 0x34)) +
             *(int *)(*(int *)(unaff_ESI + 0x34) + iVar3);
    *(int *)(*(int *)(unaff_ESI + 0x7c) + uVar9 * 8) = (int)(iVar13 + (iVar13 >> 0x1f & 3U)) >> 2;
    iVar13 = *(int *)(iVar6 + 4 + *(int *)(unaff_ESI + 0x58)) +
             *(int *)(*(int *)(unaff_ESI + 0x58) + 4 + iVar5) +
             *(int *)(iVar4 + 4 + *(int *)(unaff_ESI + 0x34)) +
             *(int *)(*(int *)(unaff_ESI + 0x34) + 4 + iVar3);
    *(int *)(*(int *)(unaff_ESI + 0x7c) + 4 + uVar9 * 8) =
         (int)(iVar13 + (iVar13 >> 0x1f & 3U)) >> 2;
    return;
  }
  if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
  return;
}

