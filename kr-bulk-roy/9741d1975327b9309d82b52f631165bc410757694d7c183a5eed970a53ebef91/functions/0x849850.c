
undefined4 * FUN_00849850(undefined4 *param_1)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904e5c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = gbRenderer::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  local_8 = 3;
  _memset(param_1 + 0x15,0,0x44);
  param_1[0x24] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  param_1[0x1a] = 0x3f800000;
  param_1[0x15] = 0x3f800000;
  param_1[0x32] = 7;
  _memset(param_1 + 0x26,0,0x34);
  param_1[0x2e] = 0x3f800000;
  param_1[0x2a] = 0x3f800000;
  param_1[0x26] = 0x3f800000;
  param_1[0x38] = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    param_1[0x37] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x37] + 4) = param_1[0x37];
    *(undefined4 *)(param_1[0x37] + 8) = param_1[0x37];
    *(undefined1 *)(param_1[0x37] + 0x2c) = 1;
    *(undefined1 *)(param_1[0x37] + 0x2d) = 1;
    param_1[0x35] = 1;
    param_1[0x34] = 0;
    param_1[0x33] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

