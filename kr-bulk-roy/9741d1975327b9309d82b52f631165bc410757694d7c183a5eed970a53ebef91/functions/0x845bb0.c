
undefined4 FUN_00845bb0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *unaff_ESI;
  int local_8;
  
  iVar1 = (**(code **)(*unaff_ESI + 4))();
  if (*(int *)(iVar1 + 4) == -0x5ecc0000) {
    local_8 = unaff_ESI[0x5b];
    uVar2 = (**(code **)(*param_1 + 0x104))(&local_8);
    return uVar2;
  }
  iVar1 = (**(code **)(*unaff_ESI + 0x38))();
  if (0 < iVar1) {
    iVar5 = 0;
    do {
      piVar3 = (int *)(**(code **)(*unaff_ESI + 0x28))(iVar5);
      iVar4 = (**(code **)(*piVar3 + 4))();
      if (*(int *)(iVar4 + 4) == -0x5ecc0000) {
        local_8 = piVar3[0x5b];
        iVar4 = (**(code **)(*param_1 + 0x104))(&local_8);
        if (iVar4 == 0) {
          return 0;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  return 1;
}

