
undefined4 FUN_00873760(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00f7ad68;
  bVar1 = 0;
  if (param_1 != (int *)0x0) {
    for (iVar2 = (**(code **)(*param_1 + 4))(); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x28)) {
      if (*(int *)(iVar2 + 4) == iVar3) {
        bVar1 = 1;
        goto LAB_008737a2;
      }
    }
    bVar1 = 0;
  }
LAB_008737a2:
  if ((-(uint)bVar1 & (uint)param_1) != 0) {
    iVar3 = FUN_00873970(param_2);
    if (iVar3 != 0) {
      FUN_0077f030(0,0,0);
    }
    iVar3 = FUN_00873900(param_2);
    if (iVar3 != 0) {
      FUN_0077efc0();
    }
    iVar3 = FUN_00873880(param_2);
    if (iVar3 != 0) {
      FUN_0077ef50(0,0,0);
    }
    return 1;
  }
  return 0;
}

