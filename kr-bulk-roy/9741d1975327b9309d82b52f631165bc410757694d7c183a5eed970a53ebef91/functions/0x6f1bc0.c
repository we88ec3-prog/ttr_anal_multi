
int FUN_006f1bc0(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int unaff_EDI;
  int local_8;
  
  *(undefined4 *)(unaff_EDI + 0x24) = 0;
  *(undefined4 *)(unaff_EDI + 0x28) = 0;
  *(undefined4 *)(unaff_EDI + 0x2c) = 0;
  if (*(int *)(unaff_EDI + 0x20) != 0) {
    local_8 = 4;
    piVar3 = (int *)(unaff_EDI + 0x18);
    do {
      if (((*piVar3 != 0) && (iVar1 = (**(code **)(*(int *)*piVar3 + 0x30))(), iVar1 != 0)) &&
         (iVar1 = (**(code **)(*(int *)*piVar3 + 0x24))(), iVar1 != 0)) {
        piVar2 = (int *)(**(code **)(*(int *)*piVar3 + 0x24))();
        *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_EDI + 0x24) + *piVar2;
        iVar1 = (**(code **)(*(int *)*piVar3 + 0x24))();
        *(int *)(unaff_EDI + 0x28) = *(int *)(unaff_EDI + 0x28) + *(int *)(iVar1 + 4);
        iVar1 = (**(code **)(*(int *)*piVar3 + 0x24))();
        *(int *)(unaff_EDI + 0x2c) = *(int *)(unaff_EDI + 0x2c) + *(int *)(iVar1 + 8);
      }
      local_8 = local_8 + -1;
      piVar3 = piVar3 + -1;
    } while (-1 < local_8);
  }
  return unaff_EDI + 0x24;
}

