
void FUN_00473790(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int unaff_ESI;
  uint uVar8;
  
  iVar6 = *(int *)(*(int *)(unaff_ESI + 0x24c) + 0xcc);
  uVar7 = *(int *)(unaff_ESI + 600) - *(int *)(unaff_ESI + 0x254) >> 2;
  if (iVar6 != 0) {
    FUN_00408920(iVar6,uVar7);
  }
  uVar8 = 0;
  if (uVar7 != 0) {
    do {
      iVar6 = *(int *)(*(int *)(unaff_ESI + 0x24c) + 0xcc);
      if (((iVar6 == 0) || ((int)uVar8 < 0)) ||
         (*(int *)(iVar6 + 0xac) - *(int *)(iVar6 + 0xa8) >> 2 <= (int)uVar8)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(*(int *)(iVar6 + 0xa8) + uVar8 * 4);
      }
      uVar2 = *(undefined4 *)(unaff_ESI + 0x264);
      uVar1 = *(undefined1 *)(unaff_ESI + 0x268);
      *(undefined4 *)(iVar6 + 0x250) = *(undefined4 *)(*(int *)(unaff_ESI + 0x254) + uVar8 * 4);
      *(undefined1 *)(iVar6 + 0x254) = uVar1;
      *(undefined4 *)(iVar6 + 600) = uVar2;
      *(byte *)(iVar6 + 0x255) =
           (byte)((uint)*(undefined4 *)(*(int *)(unaff_ESI + 0x250) + 0x28) >> 8) & 1;
      FUN_00473260();
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar7);
  }
  piVar3 = *(int **)(unaff_ESI + 0x24c);
  puVar4 = (undefined4 *)piVar3[0x19];
  for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
    iVar6 = puVar5[2];
    if ((*(int *)(iVar6 + 0x60) != 0) && ((*(int **)(iVar6 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar6 + 0x1c) + 0x30))(iVar6);
    }
  }
  (**(code **)(*piVar3 + 0x128))();
  (**(code **)(**(int **)(unaff_ESI + 0x24c) + 200))();
  return;
}

