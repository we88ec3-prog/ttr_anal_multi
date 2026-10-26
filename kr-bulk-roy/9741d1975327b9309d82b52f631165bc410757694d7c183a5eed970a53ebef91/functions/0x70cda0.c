
void FUN_0070cda0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined1 uStack_1e;
  char cStack_1d;
  int iStack_1c;
  int *local_18;
  int *piStack_14;
  undefined8 uStack_10;
  
  iVar2 = FUN_006fee90(&local_18,4);
  if (iVar2 != 0) {
    FUN_0070cc10();
  }
  piVar6 = local_18;
  if ((int)local_18 < 0) {
    FUN_0070cc10();
    piVar6 = param_1;
  }
  if ((int)piVar6 + 1U < 0x10000000) {
    piStack_14 = (int *)*param_1;
    iVar5 = (int)piVar6 * 0x10;
    iVar1 = piStack_14[4];
    iVar2 = (**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 0x10),0,0,iVar5);
    if ((iVar2 == 0) && (iVar5 != 0)) {
      iVar2 = FUN_006fdb40(piStack_14,4);
    }
    *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + iVar5;
    piVar6 = local_18;
  }
  else {
    FUN_006f8b60(*param_1,"memory allocation error: block too big");
    iVar2 = 0;
  }
  *(int *)(param_2 + 8) = iVar2;
  *(int **)(param_2 + 0x28) = piVar6;
  if (0 < (int)piVar6) {
    iVar2 = 0;
    piVar4 = piVar6;
    do {
      *(undefined4 *)(iVar2 + 8 + *(int *)(param_2 + 8)) = 0;
      iVar2 = iVar2 + 0x10;
      piVar4 = (int *)((int)piVar4 + -1);
    } while (piVar4 != (int *)0x0);
  }
  piStack_14 = (int *)0x0;
  if (0 < (int)piVar6) {
    iStack_1c = 0;
    do {
      piVar6 = (int *)(*(int *)(param_2 + 8) + iStack_1c);
      iVar2 = FUN_006fee90(&uStack_1e,1);
      if (iVar2 != 0) goto LAB_0070cf5c;
      switch(uStack_1e) {
      case 0:
        piVar6[2] = 0;
        break;
      case 1:
        iVar2 = FUN_006fee90(&cStack_1d,1);
        if (iVar2 != 0) goto LAB_0070cf69;
        *piVar6 = (int)cStack_1d;
        piVar6[2] = 1;
        break;
      default:
        goto switchD_0070cea5_caseD_2;
      case 3:
        iVar2 = FUN_006fee90(&uStack_10,8);
        if (iVar2 != 0) goto LAB_0070cf76;
        piVar6[2] = 3;
        *(undefined8 *)piVar6 = uStack_10;
        break;
      case 4:
        iVar2 = FUN_0070cc40(param_1);
        *piVar6 = iVar2;
        piVar6[2] = 4;
      }
      iStack_1c = iStack_1c + 0x10;
      piStack_14 = (int *)((int)piStack_14 + 1);
    } while ((int)piStack_14 < (int)local_18);
  }
  iVar2 = FUN_006fee90(&piStack_14,4);
  piVar6 = param_1;
  if (iVar2 != 0) {
    FUN_0070cc10();
LAB_0070cf5c:
    FUN_0070cc10();
LAB_0070cf69:
    FUN_0070cc10();
LAB_0070cf76:
    FUN_0070cc10();
switchD_0070cea5_caseD_2:
    FUN_0070cc10();
  }
  piVar4 = piStack_14;
  if ((int)piStack_14 < 0) {
    FUN_0070cc10();
    piVar4 = piVar6;
  }
  if ((int)piVar4 + 1U < 0x40000000) {
    piStack_14 = (int *)*piVar6;
    iVar1 = piStack_14[4];
    iVar2 = (**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 0x10),0,0,(int)piVar4 * 4);
    if ((iVar2 == 0) && (((uint)piVar4 & 0x3fffffff) != 0)) {
      iVar2 = FUN_006fdb40(piStack_14,4);
    }
    *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + (int)piVar4 * 4;
  }
  else {
    FUN_006f8b60(*piVar6,"memory allocation error: block too big");
    iVar2 = 0;
  }
  *(int *)(param_2 + 0x10) = iVar2;
  iVar2 = 0;
  *(int **)(param_2 + 0x34) = piVar4;
  if (0 < (int)piVar4) {
    do {
      *(undefined4 *)(*(int *)(param_2 + 0x10) + iVar2 * 4) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)piVar4);
  }
  iVar2 = 0;
  if (0 < (int)piVar4) {
    do {
      uVar3 = FUN_0070d3a0(param_1,*(undefined4 *)(param_2 + 0x20));
      *(undefined4 *)(*(int *)(param_2 + 0x10) + iVar2 * 4) = uVar3;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)piVar4);
  }
  return;
}

