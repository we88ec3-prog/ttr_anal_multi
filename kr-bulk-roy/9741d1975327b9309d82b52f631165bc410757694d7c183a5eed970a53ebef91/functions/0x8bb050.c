
void FUN_008bb050(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int local_8;
  
  puVar1 = (undefined4 *)FUN_008baee0(param_1,0x60,&local_8);
  if (local_8 == 0) {
    *puVar1 = param_1;
    *param_2 = puVar1;
  }
  return;
}

