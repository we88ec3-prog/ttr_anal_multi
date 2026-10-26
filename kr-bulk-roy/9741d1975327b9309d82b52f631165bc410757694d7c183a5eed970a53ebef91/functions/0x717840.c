
undefined4 * FUN_00717840(undefined4 *param_1)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f2e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined8 *)(param_1 + 0x44) = 0x409f640000000000;
  param_1[1] = 0;
  param_1[2] = 0;
  _memset(param_1 + 3,0,0x100);
  local_8 = 0;
  *param_1 = Package::DirectoryNode::vftable;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x4a] = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    param_1[0x49] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x49] + 4) = param_1[0x49];
    *(undefined4 *)(param_1[0x49] + 8) = param_1[0x49];
    *(undefined1 *)(param_1[0x49] + 0x2c) = 1;
    *(undefined1 *)(param_1[0x49] + 0x2d) = 1;
    param_1[0x4c] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

