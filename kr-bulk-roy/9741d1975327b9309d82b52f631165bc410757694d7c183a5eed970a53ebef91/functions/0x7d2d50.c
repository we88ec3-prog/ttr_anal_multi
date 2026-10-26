
void FUN_007d2d50(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  int unaff_EDI;
  
  uVar6 = 0;
  if (*(int *)(unaff_EDI + 0x1c) - *(int *)(unaff_EDI + 0x18) >> 2 != 0) {
    do {
      piVar1 = *(int **)(*(int *)(unaff_EDI + 0x18) + uVar6 * 4);
      iVar4 = (**(code **)(*piVar1 + 4))();
      iVar2 = *piVar1;
      if (iVar4 == 0) {
        pcVar5 = *(code **)(iVar2 + 0x24);
        uVar3 = param_1;
      }
      else {
        pcVar5 = *(code **)(iVar2 + 0x20);
        uVar3 = param_2;
      }
      (*pcVar5)(uVar3);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)(*(int *)(unaff_EDI + 0x1c) - *(int *)(unaff_EDI + 0x18) >> 2));
  }
  return;
}

