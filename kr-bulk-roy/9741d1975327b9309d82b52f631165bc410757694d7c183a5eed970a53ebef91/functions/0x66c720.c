
undefined4 * FUN_0066c720(undefined4 *param_1,undefined **param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  char acStack_54 [8];
  undefined4 uStack_4c;
  undefined *puStack_48;
  undefined ***pppuStack_44;
  uint uStack_3c;
  undefined **local_20 [3];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090cc28;
  local_10 = ExceptionList;
  uStack_3c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  *param_1 = 0;
  pppuStack_44 = (undefined ***)0x66c75c;
  puVar1 = (undefined4 *)FUN_00891268();
  if (puVar1 != (undefined4 *)0x0) {
    *param_1 = puVar1;
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined4 **)*param_1 = param_1;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_2 = &puStack_48;
    local_8 = 1;
    uStack_4c = 0x66c798;
    FUN_004d8460();
    param_2 = (undefined **)acStack_54;
    local_58 = 0x66c7a7;
    FUN_00542210();
    local_58 = 0x66c7b1;
    piVar2 = (int *)FUN_00542210();
    param_2 = (undefined **)&local_60;
    local_60 = 0;
    local_5c = 0;
    if (((int *)*piVar2 != (int *)0x0) &&
       (puVar1 = *(undefined4 **)*piVar2, puVar1 != (undefined4 *)0x0)) {
      local_60 = *puVar1;
    }
    local_58 = piVar2[2];
    FUN_0066cb30(param_1);
    ExceptionList = local_10;
    return param_1;
  }
  param_2 = (undefined **)0x0;
  pppuStack_44 = (undefined ***)0x66c810;
  std::exception::exception((exception *)local_20,(char **)&param_2);
  pppuStack_44 = local_20;
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  puStack_48 = &UNK_0066c825;
  __CxxThrowException_8();
}

