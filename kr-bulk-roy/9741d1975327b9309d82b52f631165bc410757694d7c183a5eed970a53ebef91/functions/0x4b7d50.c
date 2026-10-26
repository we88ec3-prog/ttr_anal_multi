
void FUN_004b7d50(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_006edc70("Scene isn\'t valid");
  }
  if (*(int **)(unaff_ESI + 0x5eac) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x5eac) + 0x14))();
    if (*(undefined4 **)(unaff_ESI + 0x5eac) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_ESI + 0x5eac))(1);
      *(undefined4 *)(unaff_ESI + 0x5eac) = 0;
    }
  }
  uVar1 = DAT_00d6a674;
  uVar3 = DAT_00d6a674 >> 8;
  uVar4 = DAT_00d6a674 >> 0x10;
  uVar2 = DAT_00d6a674 >> 0x18;
  *(int **)(unaff_ESI + 0x5eac) = unaff_EDI;
  FUN_006edd00("Next Scene: %c%c%c%c",uVar2,uVar4,uVar3,uVar1);
  (**(code **)(*unaff_EDI + 0x10))();
  return;
}

