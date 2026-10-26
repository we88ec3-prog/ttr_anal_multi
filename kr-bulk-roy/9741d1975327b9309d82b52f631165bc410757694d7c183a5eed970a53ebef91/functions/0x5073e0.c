
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005073e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  __time64_t _Var4;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009064e3;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fe1b54 = param_1;
  param_1[1] = IDataTable::vftable;
  local_8 = 1;
  *param_1 = CGameServerState::vftable;
  param_1[1] = CGameServerState::vftable;
  puVar1 = param_1 + 2;
  *puVar1 = 0;
  puVar3 = (undefined4 *)FUN_00891268(8,uVar2);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar1 = puVar3;
    *puVar3 = 0;
    puVar3[1] = 0;
    *(undefined4 **)*puVar1 = puVar1;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    _Var4 = __time64((__time64_t *)0x0);
    _DAT_00fba7a8 = (int)_Var4;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

