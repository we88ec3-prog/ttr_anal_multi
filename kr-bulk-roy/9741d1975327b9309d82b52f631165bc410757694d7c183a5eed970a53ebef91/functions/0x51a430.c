
undefined4 * FUN_0051a430(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009103a5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0;
  param_1[6] = 0;
  iVar2 = FUN_00891268(0x28,uVar1);
  if (iVar2 != 0) {
    param_1[5] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[5] + 4) = param_1[5];
    *(undefined4 *)(param_1[5] + 8) = param_1[5];
    *(undefined1 *)(param_1[5] + 0x24) = 1;
    *(undefined1 *)(param_1[5] + 0x25) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00537140(param_1 + 8);
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

