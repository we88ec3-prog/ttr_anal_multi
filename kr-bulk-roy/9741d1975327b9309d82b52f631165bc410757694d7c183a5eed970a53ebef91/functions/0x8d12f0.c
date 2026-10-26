
int FUN_008d12f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int local_8;
  
  puVar1 = (undefined4 *)FUN_008baee0(param_2,0x10,&local_8);
  if (local_8 != 0) {
    return local_8;
  }
  puVar1[1] = param_3;
  *puVar1 = param_3;
  puVar1[2] = param_4;
  puVar1[3] = 2;
  *param_1 = param_2;
  param_1[1] = puVar1;
  param_1[2] = 0;
  param_1[3] = 0;
  return 0;
}

