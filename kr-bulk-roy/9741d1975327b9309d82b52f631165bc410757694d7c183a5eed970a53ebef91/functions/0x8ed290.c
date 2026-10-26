
void FUN_008ed290(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *in_EAX;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int unaff_EDI;
  
  uVar1 = *in_EAX;
  uVar6 = *(int *)(unaff_EDI + 0x1a4) + 1;
  if (uVar1 < uVar6) {
    uVar2 = *(uint *)(unaff_EDI + 0x194);
    uVar4 = uVar2 + uVar1 * 0x18;
    if ((uVar6 != *(uint *)(unaff_EDI + 0x18c)) || (*(uint *)(uVar4 + 0xc) != uVar1)) {
      uVar6 = uVar2 + *(uint *)(unaff_EDI + 0x18c) * 0x18;
      for (uVar4 = uVar2; (uVar4 < uVar6 && (*(uint *)(uVar4 + 0xc) != uVar1)); uVar4 = uVar4 + 0x18
          ) {
      }
      if (uVar4 == uVar6) goto LAB_008ed2dc;
    }
    if (*(char *)(uVar4 + 0x10) != '\0') {
      if (*(int *)(unaff_EDI + 0x1b0) <= *(int *)(unaff_EDI + 0x1ac)) {
        *(undefined4 *)(unaff_EDI + 0xc) = 0x82;
        return;
      }
      puVar5 = (undefined4 *)(*(int *)(unaff_EDI + 0x1ac) * 0x10 + *(int *)(unaff_EDI + 0x1b4));
      *puVar5 = *(undefined4 *)(unaff_EDI + 0x160);
      iVar3 = *(int *)(unaff_EDI + 0x168);
      puVar5[3] = uVar4;
      puVar5[1] = iVar3 + 1;
      puVar5[2] = 1;
      *(int *)(unaff_EDI + 0x1ac) = *(int *)(unaff_EDI + 0x1ac) + 1;
      FUN_008ec690();
      *(undefined1 *)(unaff_EDI + 0x178) = 0;
      return;
    }
  }
LAB_008ed2dc:
  *(undefined4 *)(unaff_EDI + 0xc) = 0x86;
  return;
}

