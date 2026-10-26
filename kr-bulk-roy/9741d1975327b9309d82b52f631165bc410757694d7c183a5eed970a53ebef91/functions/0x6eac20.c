
undefined4 FUN_006eac20(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  *param_2 = 0;
  iVar2 = FUN_006e3660(0);
  piVar3 = (int *)FUN_006dfb80();
  iVar5 = 0;
  if (0 < *(int *)(iVar2 + 0x58)) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(iVar2 + 0x54) + iVar5 * 4);
      iVar4 = (**(code **)(*piVar3 + 0x3c))(piVar3,*puVar1);
      if (iVar4 == param_1) {
        *param_2 = *puVar1;
        return 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(iVar2 + 0x58));
  }
  return 0x80004005;
}

