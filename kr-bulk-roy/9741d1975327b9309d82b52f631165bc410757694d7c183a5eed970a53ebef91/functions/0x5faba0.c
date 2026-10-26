
undefined4 FUN_005faba0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1[1] == 0) {
    return 0;
  }
  if ((*param_1 == 100) && (iVar1 = (**(code **)(*(int *)param_1[1] + 8))(), iVar1 == 0xf4245)) {
    iVar1 = param_1[1];
    if (*(int *)(in_ECX + 0x20) + 1 == *(int *)(iVar1 + 0x2d0)) {
      return 0;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x20);
    if (puVar2 == (undefined4 *)0x0) {
LAB_005fac41:
      FUN_00748980();
      return 1;
    }
    iVar3 = *(int *)(iVar1 + 0x20);
    uVar4 = *(undefined4 *)(iVar1 + 0x2d0);
    iVar1 = *(int *)(in_ECX + 0x20);
    puVar2[4] = 0xf436e;
  }
  else {
    if (param_1[1] == 0) {
      return 0;
    }
    if (*param_1 != 100) {
      return 0;
    }
    iVar1 = (**(code **)(*(int *)param_1[1] + 8))();
    if (iVar1 != 0xf4246) {
      return 0;
    }
    iVar1 = param_1[1];
    puVar2 = (undefined4 *)FUN_00891268(0x20);
    if (puVar2 == (undefined4 *)0x0) goto LAB_005fac41;
    iVar3 = *(int *)(iVar1 + 0x20);
    uVar4 = *(undefined4 *)(iVar1 + 0x2d0);
    iVar1 = *(int *)(in_ECX + 0x20);
    puVar2[4] = 0xf4370;
  }
  puVar2[3] = 0;
  puVar2[2] = 0xffffffff;
  puVar2[1] = 0xffffffff;
  *puVar2 = FoxUI::FXUIEventI3::vftable;
  puVar2[5] = uVar4;
  puVar2[6] = iVar3 + 1;
  puVar2[7] = iVar1 + 1;
  FUN_00748980();
  return 1;
}

