
undefined1 * FUN_00848d70(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00914089;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 100) {
    local_8 = 1;
    if (param_3 != (undefined1 *)0x0) {
      *(undefined4 *)(param_3 + 0x14) = 0xf;
      *(undefined4 *)(param_3 + 0x10) = 0;
      *param_3 = 0;
      FUN_00403040(param_1,0,0xffffffff);
      local_8 = 2;
      puVar2 = (undefined4 *)(param_1 + 0x1c);
      puVar3 = (undefined4 *)(param_3 + 0x1c);
      for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      *(undefined4 *)(param_3 + 0x50) = *(undefined4 *)(param_1 + 0x50);
      FUN_00848e90(param_3 + 0x54,param_1 + 0x54);
    }
    param_3 = param_3 + 100;
  }
  ExceptionList = local_10;
  return param_3;
}

