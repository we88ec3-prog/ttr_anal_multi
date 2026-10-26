
void FUN_008ed350(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int unaff_EDI;
  
  uVar1 = param_1[1];
  uVar6 = *(int *)(unaff_EDI + 0x1a4) + 1;
  if (uVar1 < uVar6) {
    uVar2 = *(uint *)(unaff_EDI + 0x194);
    uVar4 = uVar2 + uVar1 * 0x18;
    if ((uVar6 != *(uint *)(unaff_EDI + 0x18c)) || (*(uint *)(uVar4 + 0xc) != uVar1)) {
      uVar6 = uVar2 + *(uint *)(unaff_EDI + 0x18c) * 0x18;
      for (uVar4 = uVar2; (uVar4 < uVar6 && (*(uint *)(uVar4 + 0xc) != uVar1)); uVar4 = uVar4 + 0x18
          ) {
      }
      if (uVar4 == uVar6) goto LAB_008ed3a6;
    }
    if (*(char *)(uVar4 + 0x10) != '\0') {
      if (*(int *)(unaff_EDI + 0x1b0) <= *(int *)(unaff_EDI + 0x1ac)) {
        *(undefined4 *)(unaff_EDI + 0xc) = 0x82;
        return;
      }
      if (0 < *param_1) {
        puVar5 = (undefined4 *)(*(int *)(unaff_EDI + 0x1ac) * 0x10 + *(int *)(unaff_EDI + 0x1b4));
        *puVar5 = *(undefined4 *)(unaff_EDI + 0x160);
        puVar5[1] = *(int *)(unaff_EDI + 0x168) + 1;
        iVar3 = *param_1;
        puVar5[3] = uVar4;
        puVar5[2] = iVar3;
        *(int *)(unaff_EDI + 0x1ac) = *(int *)(unaff_EDI + 0x1ac) + 1;
        FUN_008ec690();
        *(undefined1 *)(unaff_EDI + 0x178) = 0;
      }
      return;
    }
  }
LAB_008ed3a6:
  *(undefined4 *)(unaff_EDI + 0xc) = 0x86;
  return;
}

