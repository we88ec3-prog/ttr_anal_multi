
undefined4
FUN_008bd160(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4,
            undefined4 *param_5)

{
  int iVar1;
  
  iVar1 = FUN_008bc6b0(*param_1,param_3,"resource.frk/");
  if (iVar1 == 0) {
    return 0x40;
  }
  *param_4 = iVar1;
  *param_5 = 0;
  return 0;
}

