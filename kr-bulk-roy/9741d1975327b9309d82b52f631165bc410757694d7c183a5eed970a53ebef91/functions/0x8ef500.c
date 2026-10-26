
void FUN_008ef500(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int unaff_EDI;
  
  uVar4 = *(uint *)(unaff_EDI + 0x1a0);
  uVar1 = uVar4 + *(int *)(unaff_EDI + 0x198) * 0x18;
  if (uVar4 < uVar1) {
    do {
      if ((*(char *)(uVar4 + 0xc) == *(char *)(unaff_EDI + 0x170)) &&
         (*(char *)(uVar4 + 0x10) != '\0')) {
        iVar2 = *(int *)(unaff_EDI + 0x1ac);
        if (*(int *)(unaff_EDI + 0x1b0) <= iVar2) {
          *(undefined4 *)(unaff_EDI + 0xc) = 0x82;
          return;
        }
        *(int *)(unaff_EDI + 0x1ac) = iVar2 + 1;
        puVar3 = (undefined4 *)(iVar2 * 0x10 + *(int *)(unaff_EDI + 0x1b4));
        *puVar3 = *(undefined4 *)(unaff_EDI + 0x160);
        puVar3[1] = *(int *)(unaff_EDI + 0x168) + 1;
        puVar3[2] = 1;
        puVar3[3] = uVar4;
        FUN_008ec690();
        *(undefined1 *)(unaff_EDI + 0x178) = 0;
        return;
      }
      uVar4 = uVar4 + 0x18;
    } while (uVar4 < uVar1);
  }
  *(undefined4 *)(unaff_EDI + 0xc) = 0x80;
  return;
}

