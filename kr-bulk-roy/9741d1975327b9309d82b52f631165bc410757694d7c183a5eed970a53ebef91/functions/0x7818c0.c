
undefined4 * FUN_007818c0(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907bd6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = gbArchive::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  local_8 = 1;
  param_1[0xb] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[10] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[10] + 4) = param_1[10];
    *(undefined4 *)(param_1[10] + 8) = param_1[10];
    *(undefined1 *)(param_1[10] + 0x14) = 1;
    *(undefined1 *)(param_1[10] + 0x15) = 1;
    param_1[0x12] = 0xf;
    param_1[0x11] = 0;
    *(undefined1 *)(param_1 + 0xd) = 0;
    param_1[0x17] = 0x641;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
    param_1[0x1c] = 0;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    param_1[0x14] = 2;
    param_1[0x21] = 0;
    param_1[0x22] = 0;
    *(undefined2 *)(param_1 + 0x23) = 0;
    param_1[0x24] = param_2;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

