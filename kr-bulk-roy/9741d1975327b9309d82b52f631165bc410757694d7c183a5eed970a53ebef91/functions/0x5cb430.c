
void FUN_005cb430(void)

{
  int *piVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *unaff_EDI;
  
  piVar1 = *(int **)(*(int *)(in_EAX + 4) + 0x14);
  if ((piVar1 != (int *)0x0) && (piVar1[0x3d] != 0)) {
    (**(code **)(*piVar1 + 0x1a8))();
    (**(code **)(*piVar1 + 0x1ac))();
    FUN_008fed10();
    uVar2 = FUN_008fed10();
    uVar3 = FUN_008fed10();
    uVar4 = FUN_008fed10();
    uVar5 = FUN_008fed10();
    *unaff_EDI = uVar2;
    unaff_EDI[1] = uVar4;
    unaff_EDI[2] = uVar3;
    unaff_EDI[3] = uVar5;
  }
  return;
}

