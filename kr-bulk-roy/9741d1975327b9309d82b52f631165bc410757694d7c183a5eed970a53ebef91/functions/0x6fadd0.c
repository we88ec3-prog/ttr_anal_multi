
void FUN_006fadd0(void)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int unaff_ESI;
  
  iVar2 = *(int *)(*(int *)(unaff_ESI + 0x10) + 0x30);
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = *(int *)(unaff_ESI + 0x10);
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
    iVar5 = piVar4[2];
    *(byte *)((int)piVar4 + 5) = *(byte *)(iVar2 + 0x14) & 3 | *(byte *)((int)piVar4 + 5) & 0xf8;
    if (iVar5 != 0) {
      if ((*(byte *)(iVar5 + 6) & 4) == 0) {
        iVar6 = *(int *)(*(int *)(unaff_ESI + 0x10) + 0xc4);
        for (puVar9 = (undefined4 *)
                      (((1 << (*(byte *)(iVar5 + 7) & 0x1f)) - 1U & *(uint *)(iVar6 + 8)) * 0x20 +
                      *(int *)(iVar5 + 0x10)); puVar9 != (undefined4 *)0x0;
            puVar9 = (undefined4 *)puVar9[7]) {
          if ((puVar9[6] == 4) && (puVar9[4] == iVar6)) goto LAB_006fae6b;
        }
        puVar9 = &DAT_00c0bfc8;
LAB_006fae6b:
        if (puVar9[2] == 0) {
          *(byte *)(iVar5 + 6) = *(byte *)(iVar5 + 6) | 4;
          puVar9 = (undefined4 *)0x0;
        }
      }
      else {
        puVar9 = (undefined4 *)0x0;
      }
      if (puVar9 != (undefined4 *)0x0) {
        uVar1 = *(undefined1 *)(unaff_ESI + 0x39);
        uVar7 = *(undefined4 *)(iVar2 + 0x40);
        *(undefined1 *)(unaff_ESI + 0x39) = 0;
        *(int *)(iVar2 + 0x40) = *(int *)(iVar2 + 0x44) * 2;
        puVar8 = *(undefined4 **)(unaff_ESI + 8);
        *puVar8 = *puVar9;
        puVar8[1] = puVar9[1];
        puVar8[2] = puVar9[2];
        iVar5 = *(int *)(unaff_ESI + 8);
        *(int **)(iVar5 + 0x10) = piVar4;
        *(undefined4 *)(iVar5 + 0x18) = 7;
        *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x20;
        FUN_006fe550();
        *(undefined1 *)(unaff_ESI + 0x39) = uVar1;
        *(undefined4 *)(iVar2 + 0x40) = uVar7;
      }
    }
    iVar2 = *(int *)(*(int *)(unaff_ESI + 0x10) + 0x30);
  } while( true );
}

