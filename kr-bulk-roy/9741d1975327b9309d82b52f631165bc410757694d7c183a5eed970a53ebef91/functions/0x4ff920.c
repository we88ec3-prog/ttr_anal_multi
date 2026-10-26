
undefined4 * FUN_004ff920(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b436;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x18] = 7;
  param_1[0x17] = 0;
  *(undefined2 *)(param_1 + 0x13) = 0;
  local_8 = 1;
  param_1[0x1c] = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 != 0) {
    param_1[0x1b] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x1b] + 4) = param_1[0x1b];
    *(undefined4 *)(param_1[0x1b] + 8) = param_1[0x1b];
    *(undefined1 *)(param_1[0x1b] + 0x2c) = 1;
    *(undefined1 *)(param_1[0x1b] + 0x2d) = 1;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    param_1[0x20] = 0;
    param_1[0x21] = 0;
    param_1[0x22] = 0;
    param_1[0x23] = 0;
    param_1[0x24] = 0;
    param_1[0x25] = 0;
    param_1[0x26] = 0;
    param_1[0x27] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

