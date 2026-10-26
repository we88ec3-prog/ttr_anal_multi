
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007d0fb0(char *param_1)

{
  int iVar1;
  undefined **local_20 [3];
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009076f6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fe3220 = *param_1;
  local_14 = &DAT_00fe3220;
  _DAT_00fe3228 = 0;
  iVar1 = FUN_00891268(0x28,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fe3224 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3224 + 4) = DAT_00fe3224;
    DAT_00fe3230 = 0;
    _DAT_00fe3234 = 0;
    _DAT_00fe3238 = 0;
    local_8 = 1;
    _DAT_00fe3248 = 0x3f800000;
    FUN_007dcc30(8);
    ExceptionList = local_10;
    return &DAT_00fe3220;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_20,&param_1);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

