
void FUN_0070d070(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int unaff_EDI;
  int *local_18;
  int iStack_14;
  int iStack_10;
  int *apiStack_c [2];
  
  iVar2 = FUN_006fee90(&local_18,4);
  if (iVar2 != 0) {
    FUN_0070cc10();
  }
  piVar5 = local_18;
  if ((int)local_18 < 0) {
    FUN_0070cc10();
    piVar5 = param_1;
  }
  if ((int)piVar5 + 1U < 0x40000000) {
    iStack_14 = *param_1;
    iVar1 = *(int *)(iStack_14 + 0x10);
    iVar2 = (**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 0x10),0,0,(int)piVar5 * 4);
    if ((iVar2 == 0) && (((uint)local_18 & 0x3fffffff) != 0)) {
      iVar2 = FUN_006fdb40(iStack_14,4);
    }
    *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + (int)local_18 * 4;
    piVar5 = local_18;
  }
  else {
    FUN_006f8b60(*param_1,"memory allocation error: block too big");
    iVar2 = 0;
  }
  *(int *)(unaff_EDI + 0x14) = iVar2;
  *(int **)(unaff_EDI + 0x30) = piVar5;
  iVar2 = FUN_006fee90(iVar2,(int)piVar5 * 4);
  if (iVar2 != 0) {
    FUN_0070cc10();
  }
  iVar2 = FUN_006fee90(&local_18,4);
  if (iVar2 != 0) {
    FUN_0070cc10();
  }
  piVar5 = local_18;
  if ((int)local_18 < 0) {
    FUN_0070cc10();
    piVar5 = param_1;
  }
  if ((int)piVar5 + 1U < 0x15555556) {
    iStack_14 = *param_1;
    iVar1 = (int)piVar5 * 0xc;
    iStack_10 = *(int *)(iStack_14 + 0x10);
    iVar2 = (**(code **)(iStack_10 + 0xc))(*(undefined4 *)(iStack_10 + 0x10),0,0,iVar1);
    if ((iVar2 == 0) && (iVar1 != 0)) {
      iVar2 = FUN_006fdb40(iStack_14,4);
    }
    *(int *)(iStack_10 + 0x44) = *(int *)(iStack_10 + 0x44) + iVar1;
    piVar5 = local_18;
  }
  else {
    FUN_006f8b60(*param_1,"memory allocation error: block too big");
    iVar2 = 0;
  }
  *(int *)(unaff_EDI + 0x18) = iVar2;
  *(int **)(unaff_EDI + 0x38) = piVar5;
  if (0 < (int)piVar5) {
    iVar2 = 0;
    piVar4 = piVar5;
    do {
      *(undefined4 *)(iVar2 + *(int *)(unaff_EDI + 0x18)) = 0;
      iVar2 = iVar2 + 0xc;
      piVar4 = (int *)((int)piVar4 + -1);
    } while (piVar4 != (int *)0x0);
  }
  iStack_14 = 0;
  if (0 < (int)piVar5) {
    piVar5 = (int *)0x0;
    do {
      uVar3 = FUN_0070cc40(param_1);
      *(undefined4 *)((int)piVar5 + *(int *)(unaff_EDI + 0x18)) = uVar3;
      iVar2 = FUN_006fee90(&iStack_10,4);
      if (iVar2 != 0) goto LAB_0070d2a6;
      if (iStack_10 < 0) goto LAB_0070d2b3;
      *(int *)((int)piVar5 + *(int *)(unaff_EDI + 0x18) + 4) = iStack_10;
      iVar2 = FUN_006fee90(apiStack_c,4);
      if (iVar2 != 0) goto LAB_0070d2c0;
      if ((int)apiStack_c[0] < 0) goto LAB_0070d2cd;
      *(int **)((int)piVar5 + *(int *)(unaff_EDI + 0x18) + 8) = apiStack_c[0];
      iStack_14 = iStack_14 + 1;
      piVar5 = piVar5 + 3;
    } while (iStack_14 < (int)local_18);
  }
  iVar2 = FUN_006fee90(apiStack_c,4);
  piVar5 = param_1;
  if (iVar2 != 0) {
    FUN_0070cc10();
LAB_0070d2a6:
    FUN_0070cc10();
LAB_0070d2b3:
    FUN_0070cc10();
LAB_0070d2c0:
    FUN_0070cc10();
LAB_0070d2cd:
    FUN_0070cc10();
  }
  piVar4 = apiStack_c[0];
  if ((int)apiStack_c[0] < 0) {
    FUN_0070cc10();
    piVar4 = piVar5;
  }
  if ((int)piVar4 + 1U < 0x40000000) {
    apiStack_c[0] = (int *)*piVar5;
    iVar1 = apiStack_c[0][4];
    iVar2 = (**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 0x10),0,0,(int)piVar4 * 4);
    if ((iVar2 == 0) && (((uint)piVar4 & 0x3fffffff) != 0)) {
      iVar2 = FUN_006fdb40(apiStack_c[0],4);
    }
    *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + (int)piVar4 * 4;
  }
  else {
    FUN_006f8b60(*piVar5,"memory allocation error: block too big");
    iVar2 = 0;
  }
  *(int *)(unaff_EDI + 0x1c) = iVar2;
  iVar2 = 0;
  *(int **)(unaff_EDI + 0x24) = piVar4;
  if (0 < (int)piVar4) {
    do {
      *(undefined4 *)(*(int *)(unaff_EDI + 0x1c) + iVar2 * 4) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)piVar4);
  }
  iVar2 = 0;
  if (0 < (int)piVar4) {
    do {
      uVar3 = FUN_0070cc40(param_1);
      *(undefined4 *)(*(int *)(unaff_EDI + 0x1c) + iVar2 * 4) = uVar3;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)piVar4);
  }
  return;
}

