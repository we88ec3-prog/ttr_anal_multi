
void FUN_008c3d40(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int unaff_EDI;
  
  if (*(uint *)(unaff_EDI + 0x18) < 0xffff) {
    uVar5 = *(uint *)(unaff_EDI + 0x18) + 1;
    do {
      uVar3 = *(uint *)(unaff_EDI + 0x28);
      if (uVar5 < uVar3) {
        uVar5 = uVar3;
      }
      if (uVar5 <= *(uint *)(unaff_EDI + 0x2c)) {
        if (*(int *)(unaff_EDI + 0x34) == 0) {
          do {
            uVar3 = *(int *)(unaff_EDI + 0x30) + uVar5 & 0xffff;
            if (uVar3 != 0) goto LAB_008c3de1;
            uVar5 = uVar5 + 1;
          } while (uVar5 <= *(uint *)(unaff_EDI + 0x2c));
        }
        else {
          iVar4 = *(int *)(unaff_EDI + 0x34) + -1 + (uVar5 - uVar3) * 2;
          do {
            puVar1 = (undefined1 *)(iVar4 + 1);
            puVar2 = (undefined1 *)(iVar4 + 2);
            iVar4 = iVar4 + 2;
            uVar3 = (uint)CONCAT11(*puVar1,*puVar2);
            if ((uVar3 != 0) && (uVar3 = uVar3 + *(int *)(unaff_EDI + 0x30) & 0xffff, uVar3 != 0)) {
LAB_008c3de1:
              *(uint *)(unaff_EDI + 0x18) = uVar5;
              *(uint *)(unaff_EDI + 0x1c) = uVar3;
              return;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 <= *(uint *)(unaff_EDI + 0x2c));
        }
      }
      iVar4 = FUN_008c3bf0();
    } while (-1 < iVar4);
  }
  *(undefined4 *)(unaff_EDI + 0x18) = 0xffffffff;
  *(undefined4 *)(unaff_EDI + 0x1c) = 0;
  return;
}

