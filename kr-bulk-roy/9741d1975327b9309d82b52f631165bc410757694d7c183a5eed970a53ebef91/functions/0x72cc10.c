
void FUN_0072cc10(short param_1,short param_2,int param_3)

{
  int iVar1;
  ushort uVar2;
  int unaff_ESI;
  int iVar3;
  
  iVar3 = *(int *)(unaff_ESI + 0x16bc);
  uVar2 = param_1 - 0x101;
  if (iVar3 < 0xc) {
    *(ushort *)(unaff_ESI + 0x16b8) =
         *(ushort *)(unaff_ESI + 0x16b8) | uVar2 << ((byte)iVar3 & 0x1f);
    *(int *)(unaff_ESI + 0x16bc) = iVar3 + 5;
  }
  else {
    *(ushort *)(unaff_ESI + 0x16b8) =
         *(ushort *)(unaff_ESI + 0x16b8) | uVar2 << ((byte)iVar3 & 0x1f);
    *(undefined1 *)(*(int *)(unaff_ESI + 0x14) + *(int *)(unaff_ESI + 8)) =
         *(undefined1 *)(unaff_ESI + 0x16b8);
    *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 0x14) + *(int *)(unaff_ESI + 8)) =
         *(undefined1 *)(unaff_ESI + 0x16b9);
    iVar3 = *(int *)(unaff_ESI + 0x16bc);
    *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
    *(int *)(unaff_ESI + 0x16bc) = iVar3 + -0xb;
    *(ushort *)(unaff_ESI + 0x16b8) = uVar2 >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar3 = *(int *)(unaff_ESI + 0x16bc);
  uVar2 = param_2 - 1;
  if (iVar3 < 0xc) {
    *(ushort *)(unaff_ESI + 0x16b8) =
         *(ushort *)(unaff_ESI + 0x16b8) | uVar2 << ((byte)iVar3 & 0x1f);
    *(int *)(unaff_ESI + 0x16bc) = iVar3 + 5;
  }
  else {
    *(ushort *)(unaff_ESI + 0x16b8) =
         *(ushort *)(unaff_ESI + 0x16b8) | uVar2 << ((byte)iVar3 & 0x1f);
    *(undefined1 *)(*(int *)(unaff_ESI + 0x14) + *(int *)(unaff_ESI + 8)) =
         *(undefined1 *)(unaff_ESI + 0x16b8);
    *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 0x14) + *(int *)(unaff_ESI + 8)) =
         *(undefined1 *)(unaff_ESI + 0x16b9);
    iVar3 = *(int *)(unaff_ESI + 0x16bc);
    *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
    *(int *)(unaff_ESI + 0x16bc) = iVar3 + -0xb;
    *(ushort *)(unaff_ESI + 0x16b8) = uVar2 >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar3 = *(int *)(unaff_ESI + 0x16bc);
  uVar2 = (short)param_3 - 4;
  if (iVar3 < 0xd) {
    *(ushort *)(unaff_ESI + 0x16b8) =
         *(ushort *)(unaff_ESI + 0x16b8) | uVar2 << ((byte)iVar3 & 0x1f);
    *(int *)(unaff_ESI + 0x16bc) = iVar3 + 4;
  }
  else {
    *(ushort *)(unaff_ESI + 0x16b8) =
         *(ushort *)(unaff_ESI + 0x16b8) | uVar2 << ((byte)iVar3 & 0x1f);
    *(undefined1 *)(*(int *)(unaff_ESI + 0x14) + *(int *)(unaff_ESI + 8)) =
         *(undefined1 *)(unaff_ESI + 0x16b8);
    *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 0x14) + *(int *)(unaff_ESI + 8)) =
         *(undefined1 *)(unaff_ESI + 0x16b9);
    iVar3 = *(int *)(unaff_ESI + 0x16bc);
    *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
    *(int *)(unaff_ESI + 0x16bc) = iVar3 + -0xc;
    *(ushort *)(unaff_ESI + 0x16b8) = uVar2 >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar3 = 0;
  if (0 < param_3) {
    do {
      iVar1 = *(int *)(unaff_ESI + 0x16bc);
      if (iVar1 < 0xe) {
        *(ushort *)(unaff_ESI + 0x16b8) =
             *(ushort *)(unaff_ESI + 0x16b8) |
             *(short *)(unaff_ESI + 0xa7e + (uint)(byte)(&DAT_00c081cc)[iVar3] * 4) <<
             ((byte)iVar1 & 0x1f);
        *(int *)(unaff_ESI + 0x16bc) = iVar1 + 3;
      }
      else {
        uVar2 = *(ushort *)(unaff_ESI + 0xa7e + (uint)(byte)(&DAT_00c081cc)[iVar3] * 4);
        *(ushort *)(unaff_ESI + 0x16b8) =
             *(ushort *)(unaff_ESI + 0x16b8) | uVar2 << ((byte)iVar1 & 0x1f);
        *(undefined1 *)(*(int *)(unaff_ESI + 0x14) + *(int *)(unaff_ESI + 8)) =
             *(undefined1 *)(unaff_ESI + 0x16b8);
        *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
        *(undefined1 *)(*(int *)(unaff_ESI + 0x14) + *(int *)(unaff_ESI + 8)) =
             *(undefined1 *)(unaff_ESI + 0x16b9);
        *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
        *(ushort *)(unaff_ESI + 0x16b8) =
             uVar2 >> (0x10U - (char)*(int *)(unaff_ESI + 0x16bc) & 0x1f);
        *(int *)(unaff_ESI + 0x16bc) = *(int *)(unaff_ESI + 0x16bc) + -0xd;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
  }
  FUN_0072c5c0(unaff_ESI + 0x94);
  FUN_0072c5c0(unaff_ESI + 0x988);
  return;
}

