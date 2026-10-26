
int FUN_00805ca0(int param_1)

{
  uint uVar1;
  LPCRITICAL_SECTION p_Var2;
  int iVar3;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009099dc;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(int *)(param_1 + 0x5018) = param_1 + 0x18;
  p_Var2 = (LPCRITICAL_SECTION)FUN_00891268(0x18,uVar1);
  if (p_Var2 == (LPCRITICAL_SECTION)0x0) {
    p_Var2 = (LPCRITICAL_SECTION)0x0;
  }
  else {
    InitializeCriticalSectionAndSpinCount(p_Var2,4000);
  }
  *(LPCRITICAL_SECTION *)(param_1 + 0x501c) = p_Var2;
  *(undefined1 *)(param_1 + 0xa02c) = 2;
  *(int *)(param_1 + 0xa020) = param_1 + 0x5020;
  *(undefined1 *)(param_1 + 0xa024) = 0;
  *(undefined4 *)(param_1 + 41000) = 0;
  local_8 = 0;
  *(undefined4 *)(param_1 + 0xa04c) = 0;
  *(undefined4 *)(param_1 + 0xa030) = 0;
  *(undefined4 *)(param_1 + 0xa034) = 0;
  *(undefined4 *)(param_1 + 0xa038) = 0;
  *(undefined4 *)(param_1 + 0xa03c) = 0;
  *(undefined4 *)(param_1 + 0xa040) = 0;
  *(undefined4 *)(param_1 + 0xa048) = 0;
  *(undefined4 *)(param_1 + 0xa06c) = 0;
  *(undefined4 *)(param_1 + 0xa050) = 0;
  *(undefined4 *)(param_1 + 0xa054) = 0;
  *(undefined4 *)(param_1 + 0xa058) = 0;
  *(undefined4 *)(param_1 + 0xa05c) = 0;
  *(undefined4 *)(param_1 + 0xa060) = 0;
  *(undefined4 *)(param_1 + 0xa068) = 0;
  *(undefined4 *)(param_1 + 0xa078) = 0;
  iVar3 = FUN_00891268(0xc,uVar1);
  if (iVar3 != 0) {
    *(int *)(param_1 + 0xa074) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(param_1 + 0xa074) + 4) = *(int *)(param_1 + 0xa074);
    local_8 = CONCAT31(local_8._1_3_,1);
    *(undefined4 *)(param_1 + 0xa084) = 0;
    *(undefined4 *)(param_1 + 0xa088) = 0;
    *(undefined4 *)(param_1 + 0xa08c) = 0;
    *(undefined4 *)(param_1 + 0xa090) = 0;
    *(undefined4 *)(param_1 + 0xa094) = 0;
    *(undefined4 *)(param_1 + 0xa098) = 0;
    *(undefined4 *)(param_1 + 0xa09c) = 0;
    *(undefined4 *)(param_1 + 0xa0a0) = 0;
    *(undefined4 *)(param_1 + 0xa0a4) = 0;
    *(undefined4 *)(param_1 + 0xa0b0) = 0;
    *(undefined4 *)(param_1 + 0xa0b4) = 1;
    *(undefined4 *)(param_1 + 0xa0b8) = 0;
    *(undefined4 *)(param_1 + 0xa0bc) = 0;
    p_Var2 = (LPCRITICAL_SECTION)FUN_00891268(0x18,uVar1);
    if (p_Var2 == (LPCRITICAL_SECTION)0x0) {
      p_Var2 = (LPCRITICAL_SECTION)0x0;
    }
    else {
      InitializeCriticalSectionAndSpinCount(p_Var2,4000);
    }
    *(LPCRITICAL_SECTION *)(param_1 + 0xa0d4) = p_Var2;
    FUN_00805f50();
    *(int *)(param_1 + 0xa06c) = param_1;
    *(int *)(param_1 + 0xa04c) = param_1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

