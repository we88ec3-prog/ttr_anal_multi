
undefined4 * FUN_007c3220(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00918a18;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CAvatarBase::vftable;
  param_1[6] = 0xf;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[0xd] = 0xf;
  param_1[0xc] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[0x14] = 0xf;
  param_1[0x13] = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  local_8 = 7;
  uStack_7 = 0;
  param_1[0x2f] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_14);
    local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_20,&DAT_00c857a8);
  }
  param_1[0x2e] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(param_1[0x2e] + 4) = param_1[0x2e];
  *(undefined4 *)(param_1[0x2e] + 8) = param_1[0x2e];
  *(undefined1 *)(param_1[0x2e] + 0x14) = 1;
  *(undefined1 *)(param_1[0x2e] + 0x15) = 1;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  local_8 = 9;
  param_1[0x37] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[0x36] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x36] + 4) = param_1[0x36];
    *(undefined4 *)(param_1[0x36] + 8) = param_1[0x36];
    *(undefined1 *)(param_1[0x36] + 0x14) = 1;
    *(undefined1 *)(param_1[0x36] + 0x15) = 1;
    local_8 = 10;
    local_14 = (char *)FUN_00891268(0x44,uVar1);
    _local_8 = CONCAT31(uStack_7,0xb);
    if (local_14 == (char *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_007d5fa0(local_14);
    }
    param_1[0x39] = uVar3;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    *(undefined1 *)(param_1 + 0x3d) = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

