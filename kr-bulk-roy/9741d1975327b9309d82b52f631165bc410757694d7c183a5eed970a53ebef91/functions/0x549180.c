
void FUN_00549180(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  char cVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0x54) != 0) && (*(int *)(unaff_ESI + 0x50) != 0)) {
    bVar4 = *(byte *)(*(int *)(unaff_ESI + 0x54) + 0xb0);
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    uVar10 = (uint)bVar4;
    fVar6 = (float)(&DAT_00fb8020)[uVar10 * 2];
    fVar7 = (float)(&DAT_00fb8024)[uVar10 * 2];
    cVar5 = *(char *)(*(int *)(unaff_ESI + 0x54) + 0xb0);
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    uVar10 = (uint)(byte)(cVar5 - 0x40);
    fVar8 = (float)(&DAT_00fb8020)[uVar10 * 2];
    fVar9 = (float)(&DAT_00fb8024)[uVar10 * 2];
    *(undefined4 *)(unaff_ESI + 100) = *(undefined4 *)(*(int *)(unaff_ESI + 0x54) + 0xa0);
    *(undefined4 *)(unaff_ESI + 0x68) = *(undefined4 *)(*(int *)(unaff_ESI + 0x54) + 0xa4);
    iVar1 = (*(int *)(unaff_ESI + 0x5c) + *(int *)(unaff_ESI + 0x6c) * 2) * 8;
    fVar2 = *(float *)(&DAT_00e49054 + iVar1);
    fVar3 = *(float *)(&DAT_00e49058 + iVar1);
    *(float *)(unaff_ESI + 100) = *(float *)(unaff_ESI + 100) - (fVar3 * fVar6 + fVar2 * fVar8);
    *(float *)(unaff_ESI + 0x68) = *(float *)(unaff_ESI + 0x68) - (fVar3 * fVar7 + fVar2 * fVar9);
  }
  return;
}

