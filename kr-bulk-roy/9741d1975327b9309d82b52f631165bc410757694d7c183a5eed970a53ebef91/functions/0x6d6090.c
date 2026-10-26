
void FUN_006d6090(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905be3;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CPostEffectMgr::vftable;
  piVar1 = param_1 + 2;
  local_8 = 1;
  FUN_00523e40(piVar1,uVar2);
  if (*piVar1 != 0) {
    FUN_0089120c(*piVar1);
  }
  *piVar1 = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = CSingleton<CPostEffectMgr>::vftable;
  DAT_00fe2770 = 0;
  ExceptionList = local_10;
  return;
}

