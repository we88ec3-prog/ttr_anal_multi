
undefined4 FUN_005faa20(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar2 = (**(code **)(*(int *)param_1[1] + 8))();
    if (iVar2 == 0xf4245) {
      iVar2 = param_1[1];
      puVar3 = (undefined4 *)FUN_00891268(0x1c);
      if (puVar3 != (undefined4 *)0x0) {
        iVar1 = *(int *)(iVar2 + 0x20);
        puVar3[5] = *(undefined4 *)(iVar2 + 0x2d0);
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0xf4397;
        *puVar3 = FoxUI::FXUIEventI2::vftable;
        puVar3[6] = iVar1 + 1;
        FUN_00748980();
        return 1;
      }
      FUN_00748980();
      return 1;
    }
  }
  return 0;
}

