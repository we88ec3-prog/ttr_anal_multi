
undefined4 FUN_00875580(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00f7b014;
  bVar1 = 0;
  if (param_1 != (int *)0x0) {
    for (iVar2 = (**(code **)(*param_1 + 4))(); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x28)) {
      if (*(int *)(iVar2 + 4) == iVar3) {
        bVar1 = 1;
        goto LAB_008755c2;
      }
    }
    bVar1 = 0;
  }
LAB_008755c2:
  if ((-(uint)bVar1 & (uint)param_1) != 0) {
    iVar3 = FUN_00876040(param_2);
    if (iVar3 != 0) {
      FUN_00855350();
    }
    iVar3 = FUN_008760c0(param_2);
    if (iVar3 != 0) {
      FUN_00855010();
    }
    iVar3 = FUN_00875700(param_2);
    if (iVar3 != 0) {
      FUN_00854fd0();
    }
    iVar3 = FUN_00875780(param_2);
    if (iVar3 != 0) {
      FUN_00855290();
    }
    iVar3 = FUN_00875800(param_2);
    if (iVar3 != 0) {
      FUN_008551d0();
    }
    iVar3 = FUN_00876240(param_2);
    if (iVar3 != 0) {
      FUN_00855110();
    }
    iVar3 = FUN_00875880(param_2);
    if (iVar3 != 0) {
      FUN_00855050();
    }
    return 1;
  }
  return 0;
}

