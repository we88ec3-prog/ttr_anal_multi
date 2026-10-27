
undefined4 * FUN_004c13e0(undefined4 *param_1)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00949028;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00d6a674 = 0x4e554c4c;
  FUN_004add50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *param_1 = Scene::CExpedition::vftable;
  param_1[0x2f55] = 0;
  param_1[0x2f56] = 10;
  param_1[0x2f57] = 0;
  param_1[0x2f58] = 0;
  param_1[0x2f59] = 0;
  param_1[0x2f5a] = 0;
  param_1[0x2f5b] = 0;
  param_1[0x2f5c] = 0;
  param_1[0x2f5e] = 0;
  param_1[0x2f61] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    param_1[0x2f60] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x2f60] + 4) = param_1[0x2f60];
    *(undefined4 *)(param_1[0x2f60] + 8) = param_1[0x2f60];
    *(undefined1 *)(param_1[0x2f60] + 0x14) = 1;
    *(undefined1 *)(param_1[0x2f60] + 0x15) = 1;
    DAT_00d6a674 = 0x45585044;
    _memset(param_1 + 0x17ab,0,0x5ea8);
    param_1[0x1840] = &DAT_00bf2375;
    param_1[0x187c] = &DAT_00bf2375;
    param_1[0x183f] = FUN_004c21d0;
    param_1[0x187b] = FUN_004c21f0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

