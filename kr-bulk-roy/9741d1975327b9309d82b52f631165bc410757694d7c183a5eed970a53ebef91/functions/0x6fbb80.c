
undefined4
FUN_006fbb80(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_2[2];
  if (iVar2 == 5) {
    iVar2 = *(int *)(*param_2 + 8);
  }
  else if (iVar2 == 7) {
    iVar2 = *(int *)(*param_2 + 8);
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x98 + iVar2 * 4);
  }
  if (iVar2 == 0) {
    puVar1 = &DAT_00c0bfc8;
  }
  else {
    puVar1 = (undefined4 *)FUN_006f9c10();
  }
  if (puVar1[2] == 0) {
    puVar1 = (undefined4 *)FUN_006feab0(param_5);
    if (puVar1[2] == 0) {
      return 0;
    }
  }
  FUN_006fb700(param_1,param_4,puVar1,param_2,param_3);
  return 1;
}

