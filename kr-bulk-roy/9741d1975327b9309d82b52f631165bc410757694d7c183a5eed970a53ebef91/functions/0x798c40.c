
undefined4 * FUN_00798c40(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00915231;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 0x12) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = param_3;
      for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      param_3[0x10] = 0xf;
      param_3[0xf] = 0;
      *(undefined1 *)(param_3 + 0xb) = 0;
      FUN_00403040(param_1 + 0xb,0,0xffffffff);
    }
    param_3 = param_3 + 0x12;
  }
  ExceptionList = local_10;
  return param_3;
}

