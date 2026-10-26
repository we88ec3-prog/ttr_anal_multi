
undefined4 * FUN_0077fed0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined **local_24 [4];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911ae8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  local_8 = 0;
  *param_1 = gbBase::vftable;
  param_1[6] = 0;
  param_1[7] = 0xf;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_00403040(in_ECX + 8,0,0xffffffff);
  param_1[9] = 1;
  local_8 = 1;
  *param_1 = gbAnimatible::vftable;
  param_1[10] = *(undefined4 *)(in_ECX + 0x28);
  param_1[0xb] = *(undefined4 *)(in_ECX + 0x2c);
  param_1[0xc] = *(undefined4 *)(in_ECX + 0x30);
  param_1[0xf] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[0xe] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0xe] + 4) = param_1[0xe];
    *(undefined4 *)(param_1[0xe] + 8) = param_1[0xe];
    *(undefined1 *)(param_1[0xe] + 0x14) = 1;
    *(undefined1 *)(param_1[0xe] + 0x15) = 1;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    local_14 = (char *)(in_ECX + 0x34);
    local_8 = CONCAT31(local_8._1_3_,3);
    if ((char *)(param_1 + 0xd) != local_14) {
      FUN_00844d40(*(undefined4 *)param_1[0xe],(undefined4 *)param_1[0xe]);
      FUN_00844e00(local_14);
    }
    if (param_1[0xf] != 0) {
      param_1[9] = 0;
    }
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

