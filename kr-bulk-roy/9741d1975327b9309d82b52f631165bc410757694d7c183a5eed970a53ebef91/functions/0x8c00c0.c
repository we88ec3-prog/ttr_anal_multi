
undefined4 FUN_008c00c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_008bfab0();
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    if (iVar1 == 1) {
      *param_3 = 1;
      param_3[1] = *(undefined4 *)(iVar2 + 0xc);
      return 0;
    }
    if (iVar1 == 2) {
      *param_3 = 2;
      param_3[1] = *(undefined4 *)(iVar2 + 0xc);
      return 0;
    }
    if (iVar1 == 3) {
      *param_3 = 3;
      param_3[1] = *(undefined4 *)(iVar2 + 0xc);
      return 0;
    }
  }
  return 6;
}

