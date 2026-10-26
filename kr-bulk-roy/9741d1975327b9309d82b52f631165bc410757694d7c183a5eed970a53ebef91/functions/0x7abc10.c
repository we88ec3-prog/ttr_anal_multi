
void FUN_007abc10(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int *unaff_EDI;
  
  piVar4 = *(int **)*unaff_EDI;
  if (piVar4 != (int *)*unaff_EDI) {
    do {
      iVar1 = piVar4[2];
      uVar3 = 0;
      if (*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2 != 0) {
        do {
          *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x14) + uVar3 * 4) + 0x58) = 0;
          uVar3 = uVar3 + 1;
        } while (uVar3 < (uint)(*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2));
      }
      if (*(undefined4 **)(iVar1 + 4) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar1 + 4))(1);
        *(undefined4 *)(iVar1 + 4) = 0;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)*unaff_EDI);
  }
  uVar3 = 0;
  if (unaff_EDI[0x51] - unaff_EDI[0x50] >> 2 != 0) {
    do {
      if (*(int *)(unaff_EDI[0x50] + uVar3 * 4) != 0) {
        puVar2 = *(undefined4 **)(unaff_EDI[0x50] + uVar3 * 4);
        if (puVar2 != (undefined4 *)0x0) {
          (**(code **)*puVar2)(1);
        }
        *(undefined4 *)(unaff_EDI[0x50] + uVar3 * 4) = 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(unaff_EDI[0x51] - unaff_EDI[0x50] >> 2));
  }
  return;
}

