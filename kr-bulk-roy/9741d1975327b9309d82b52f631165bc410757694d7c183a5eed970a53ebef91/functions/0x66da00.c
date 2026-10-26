
undefined4 * FUN_0066da00(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00908201;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 0x14) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      iVar1 = 0xf;
      puVar2 = param_1;
      puVar3 = param_3;
      while( true ) {
        puVar3 = puVar3 + 1;
        puVar2 = puVar2 + 1;
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        *puVar3 = *puVar2;
      }
      FUN_00507f70(param_3 + 0x10,param_1 + 0x10);
    }
    param_3 = param_3 + 0x14;
  }
  ExceptionList = local_10;
  return param_3;
}

