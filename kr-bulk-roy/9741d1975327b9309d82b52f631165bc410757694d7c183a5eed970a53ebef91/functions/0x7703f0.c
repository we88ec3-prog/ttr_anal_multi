
undefined4 * FUN_007703f0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905830;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = FoxUI::FXUIManagerContainer<unsigned_int,FoxUI::FXUIFontSet>::vftable;
  param_1[3] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[2] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(param_1[2] + 4) = param_1[2];
  *(undefined4 *)(param_1[2] + 8) = param_1[2];
  *(undefined1 *)(param_1[2] + 0x14) = 1;
  *(undefined1 *)(param_1[2] + 0x15) = 1;
  local_8 = 1;
  *param_1 = FoxUI::FXUIManagerFont::vftable;
  param_1[9] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[8] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[8] + 4) = param_1[8];
    *(undefined4 *)(param_1[8] + 8) = param_1[8];
    *(undefined1 *)(param_1[8] + 0x14) = 1;
    *(undefined1 *)(param_1[8] + 0x15) = 1;
    param_1[5] = 0;
    param_1[6] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

