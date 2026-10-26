
void FUN_008f73a0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  bool bVar5;
  ushort *puVar6;
  uint uVar7;
  int in_EDX;
  int iVar8;
  int unaff_EBX;
  int iVar9;
  int *piVar10;
  
  iVar8 = in_EDX + 0x2c + unaff_EBX * 0x1c;
  uVar1 = *(uint *)(iVar8 + 0x14);
  uVar7 = *(int *)(iVar8 + 0xc) * 0x30 + uVar1;
  if (unaff_EBX == 0) {
    bVar4 = *(byte *)(in_EDX + 0x68) & 1;
joined_r0x008f741b:
    if (bVar4 != 0) {
      bVar5 = true;
      goto LAB_008f73cf;
    }
  }
  else if (unaff_EBX == 1) {
    bVar4 = *(byte *)(in_EDX + 0x68) & 2;
    goto joined_r0x008f741b;
  }
  bVar5 = false;
LAB_008f73cf:
  if (uVar1 < uVar7) {
    piVar10 = (int *)(uVar1 + 8);
    iVar8 = ((uVar7 - uVar1) - 1) / 0x30 + 1;
    do {
      iVar9 = piVar10[8];
      if (bVar5) {
        do {
          puVar6 = *(ushort **)(iVar9 + 0x28);
          while( true ) {
            iVar2 = *piVar10;
            if (unaff_EBX == 0) {
              *puVar6 = *puVar6 | 0x40;
              *(int *)(puVar6 + 8) = iVar2;
            }
            else {
              *(int *)(puVar6 + 10) = iVar2;
              *puVar6 = *puVar6 | 0x80;
            }
            if (puVar6 == *(ushort **)(iVar9 + 0x2c)) break;
            puVar6 = *(ushort **)(puVar6 + 0x10);
          }
          iVar9 = *(int *)(iVar9 + 0x10);
        } while (iVar9 != piVar10[8]);
      }
      else {
        iVar2 = *piVar10;
        iVar3 = piVar10[-1];
        do {
          puVar6 = *(ushort **)(iVar9 + 0x28);
          while( true ) {
            if (unaff_EBX == 0) {
              *(int *)(puVar6 + 8) = *(int *)(puVar6 + 8) + (iVar2 - iVar3);
              *puVar6 = *puVar6 | 0x40;
            }
            else {
              *(int *)(puVar6 + 10) = *(int *)(puVar6 + 10) + (iVar2 - iVar3);
              *puVar6 = *puVar6 | 0x80;
            }
            if (puVar6 == *(ushort **)(iVar9 + 0x2c)) break;
            puVar6 = *(ushort **)(puVar6 + 0x10);
          }
          iVar9 = *(int *)(iVar9 + 0x10);
        } while (iVar9 != piVar10[8]);
      }
      piVar10 = piVar10 + 0xc;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  return;
}

