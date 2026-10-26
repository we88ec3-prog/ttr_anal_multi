
undefined4 * FUN_007b8a50(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00918bc6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CField::vftable;
  param_1[6] = 0xf;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[0xd] = 0xf;
  param_1[0xc] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  local_8 = 3;
  uStack_7 = 0;
  local_14 = (char *)FUN_00891268(0x44,uVar1);
  local_8 = 4;
  if (local_14 == (char *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_007e0990(local_14);
  }
  param_1[0x15] = uVar2;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  local_8 = 5;
  local_14 = (char *)FUN_00891268(0x18,uVar1);
  local_8 = 6;
  if (local_14 == (char *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_007e20b0();
  }
  local_8 = 5;
  param_1[0x1a] = uVar2;
  param_1[0x1d] = 0;
  iVar3 = FUN_00891268(0x30,uVar1);
  if (iVar3 != 0) {
    param_1[0x1c] = iVar3;
    *(int *)iVar3 = iVar3;
    *(undefined4 *)(param_1[0x1c] + 4) = param_1[0x1c];
    *(undefined4 *)(param_1[0x1c] + 8) = param_1[0x1c];
    *(undefined1 *)(param_1[0x1c] + 0x2c) = 1;
    *(undefined1 *)(param_1[0x1c] + 0x2d) = 1;
    param_1[0x1f] = 0;
    param_1[0x20] = 0;
    param_1[0x21] = 0;
    local_8 = 8;
    param_1[0x23] = 0;
    FUN_007e2a90(param_1 + 0x24);
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
    param_1[0x2b] = 0;
    param_1[0x2d] = 0;
    param_1[0x2e] = 0;
    param_1[0x2f] = 0;
    param_1[0x31] = 4;
    param_1[0x32] = 0;
    param_1[0x33] = 0;
    param_1[0x34] = 0;
    local_8 = 0xc;
    param_1[0x37] = 0;
    param_1[0x3a] = 0;
    iVar3 = FUN_00891268(0x18);
    if (iVar3 != 0) {
      param_1[0x39] = iVar3;
      *(int *)iVar3 = iVar3;
      *(undefined4 *)(param_1[0x39] + 4) = param_1[0x39];
      *(undefined4 *)(param_1[0x39] + 8) = param_1[0x39];
      *(undefined1 *)(param_1[0x39] + 0x14) = 1;
      *(undefined1 *)(param_1[0x39] + 0x15) = 1;
      param_1[0x41] = 0xf;
      param_1[0x40] = 0;
      *(undefined1 *)(param_1 + 0x3c) = 0;
      _local_8 = CONCAT31(uStack_7,0xe);
      FUN_00402a70(&DAT_00bf2375,0);
      ExceptionList = local_10;
      return param_1;
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_14);
    local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_20,&DAT_00c857a8);
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

