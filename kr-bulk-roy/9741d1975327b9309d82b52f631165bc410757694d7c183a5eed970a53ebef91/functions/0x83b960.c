
undefined4 FUN_0083b960(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  iVar1 = FUN_0083fd10(param_1,&local_8);
  if (iVar1 != 0) {
    if (0xf < (uint)local_8[5]) {
      local_8 = (undefined4 *)*local_8;
    }
    *param_2 = local_8;
    return 1;
  }
  return 0;
}

