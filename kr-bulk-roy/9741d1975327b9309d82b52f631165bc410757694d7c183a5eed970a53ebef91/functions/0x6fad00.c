
void FUN_006fad00(void)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int unaff_EDI;
  
  iVar2 = *(int *)(unaff_EDI + 0x10);
  piVar3 = *(int **)(iVar2 + 0x30);
  piVar4 = (int *)*piVar3;
  if (piVar4 == piVar3) {
    *(undefined4 *)(iVar2 + 0x30) = 0;
  }
  else {
    *piVar3 = *piVar4;
  }
  *piVar4 = **(undefined4 **)(iVar2 + 0x70);
  **(int **)(iVar2 + 0x70) = (int)piVar4;
  *(byte *)((int)piVar4 + 5) = *(byte *)(iVar2 + 0x14) & 3 | *(byte *)((int)piVar4 + 5) & 0xf8;
  if ((piVar4[2] != 0) && ((*(byte *)(piVar4[2] + 6) & 4) == 0)) {
    puVar8 = (undefined4 *)FUN_006fea60(2);
    if (puVar8 != (undefined4 *)0x0) {
      uVar1 = *(undefined1 *)(unaff_EDI + 0x39);
      uVar5 = *(undefined4 *)(iVar2 + 0x40);
      *(undefined1 *)(unaff_EDI + 0x39) = 0;
      *(int *)(iVar2 + 0x40) = *(int *)(iVar2 + 0x44) * 2;
      puVar6 = *(undefined4 **)(unaff_EDI + 8);
      *puVar6 = *puVar8;
      puVar6[1] = puVar8[1];
      puVar6[2] = puVar8[2];
      iVar7 = *(int *)(unaff_EDI + 8);
      *(int **)(iVar7 + 0x10) = piVar4;
      *(undefined4 *)(iVar7 + 0x18) = 7;
      *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 0x20;
      FUN_006fe550();
      *(undefined1 *)(unaff_EDI + 0x39) = uVar1;
      *(undefined4 *)(iVar2 + 0x40) = uVar5;
    }
  }
  return;
}

