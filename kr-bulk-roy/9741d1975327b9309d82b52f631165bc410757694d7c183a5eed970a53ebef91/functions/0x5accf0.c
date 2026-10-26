
undefined4 * FUN_005accf0(undefined4 *param_1)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091da54;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00598760(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  local_8 = 0;
  *param_1 = FUI::CMissionFieldPage::vftable;
  param_1[0x89] = 0;
  param_1[0x8b] = 0;
  *(undefined1 *)(param_1 + 0x8c) = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  *(undefined1 *)(param_1 + 0x91) = 0;
  param_1[0x92] = 0;
  param_1[0x94] = 0;
  iVar1 = FUN_00891268(0xc);
  if (iVar1 != 0) {
    param_1[0x93] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x93] + 4) = param_1[0x93];
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    param_1[0x96] = DAT_00f95bd4;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

