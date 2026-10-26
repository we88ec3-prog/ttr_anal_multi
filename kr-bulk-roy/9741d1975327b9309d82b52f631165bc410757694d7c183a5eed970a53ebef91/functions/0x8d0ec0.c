
int FUN_008d0ec0(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_2;
  do {
    uVar1 = uVar1 + 1;
    if (0xff < uVar1) {
      *param_2 = 0;
      return 0;
    }
    iVar2 = FUN_008d0e30(param_1,uVar1);
  } while (iVar2 == 0);
  *param_2 = uVar1;
  return iVar2;
}

