
undefined4 FUN_005dda80(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *in_ECX;
  
  if (*(char *)((int)in_ECX + 0x2a1) != '\0') {
    return 0;
  }
  piVar1 = (int *)param_1[1];
  if (piVar1 != in_ECX) {
    if ((piVar1 != (int *)0x0) && (*param_1 == 100)) {
      iVar5 = (**(code **)(*piVar1 + 8))();
      if (iVar5 == 0xf4246) {
        iVar5 = param_1[1];
        puVar6 = (undefined4 *)FUN_00891268(0x20);
        if (puVar6 != (undefined4 *)0x0) {
          iVar2 = *(int *)(iVar5 + 0x20);
          iVar3 = in_ECX[8];
          uVar4 = *(undefined4 *)(iVar5 + 0x2d0);
          puVar6[1] = 0xffffffff;
          puVar6[2] = 0xffffffff;
          puVar6[3] = 0;
          puVar6[4] = 0xf436d;
          *puVar6 = FoxUI::FXUIEventI3::vftable;
          puVar6[5] = uVar4;
          puVar6[6] = iVar2 + 1;
          puVar6[7] = iVar3 + 1;
          FUN_00748900();
          return 1;
        }
        FUN_00748900();
        return 1;
      }
    }
    if ((param_1[1] != 0) && (*param_1 == 100)) {
      iVar5 = (**(code **)(*(int *)param_1[1] + 8))();
      if ((iVar5 == 0xf4245) && (param_1[1] != 0)) {
        FUN_005de0a0(in_ECX[0xb4],in_ECX[8] + 1);
        return 1;
      }
    }
  }
  return 0;
}

