
int * FUN_005358c0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uStack_34;
  undefined **local_24 [3];
  char *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009084d8;
  local_10 = ExceptionList;
  uStack_34 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  param_1[1] = 0;
  iVar1 = FUN_00891268(0xc);
  if (iVar1 != 0) {
    *param_1 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*param_1 + 4) = *param_1;
    local_8 = 1;
    FUN_00404cc0(param_1,*(undefined4 *)*param_1,*(undefined4 *)*param_2,(undefined4 *)*param_2,
                 param_1);
    ExceptionList = local_10;
    return param_1;
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_18);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

