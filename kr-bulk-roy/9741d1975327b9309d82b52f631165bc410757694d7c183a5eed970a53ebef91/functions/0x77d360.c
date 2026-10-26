
undefined4 * FUN_0077d360(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907c68;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  param_1[1] = DAT_00fba828;
  local_8 = 0;
  *param_1 = FoxUI::FXUIFontSet::vftable;
  param_1[5] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[4] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[4] + 4) = param_1[4];
    *(undefined4 *)(param_1[4] + 8) = param_1[4];
    *(undefined1 *)(param_1[4] + 0x14) = 1;
    *(undefined1 *)(param_1[4] + 0x15) = 1;
    param_1[2] = 0xffffffff;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

