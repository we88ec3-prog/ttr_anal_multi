
void FUN_005763b0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined **local_58 [3];
  undefined4 *local_4c;
  undefined **local_48 [3];
  char *local_3c;
  char *local_38;
  undefined4 *local_34;
  undefined4 local_30 [3];
  tagRECT local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927254;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_4c = param_1;
  FUN_005716f0(local_14);
  local_8 = 0;
  *param_1 = GaCha::CGaChaMgr::vftable;
  puVar2 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[5] = 0;
  }
  param_1[1] = puVar2;
  local_3c = (char *)FUN_00891268(0x48);
  local_8._0_1_ = 1;
  if (local_3c == (char *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00572bc0(local_3c);
  }
  local_8._0_1_ = 0;
  param_1[2] = uVar3;
  local_3c = (char *)FUN_00891268(0xf8);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_3c == (char *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0044e800(local_3c);
  }
  param_1[3] = uVar3;
  puVar2 = param_1 + 5;
  local_34 = (undefined4 *)0x2;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    SetRectEmpty((LPRECT)(puVar2 + 3));
    puVar2 = puVar2 + 7;
    local_34 = (undefined4 *)((int)local_34 + -1);
  } while (-1 < (int)local_34);
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x2b] = 7;
  param_1[0x2a] = 0;
  *(undefined2 *)(param_1 + 0x26) = 0;
  local_8._0_1_ = 3;
  param_1[0x39] = 0x43c80000;
  param_1[0x3a] = 0x42c80000;
  param_1[0x3b] = 0x3f800000;
  param_1[0x3c] = 0x3f800000;
  param_1[0x2d] = 0xffffffff;
  param_1[0x2e] = 0xffffffff;
  param_1[0x2f] = 0xffffffff;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x42] = 0;
  iVar4 = FUN_00891268(0xc);
  if (iVar4 == 0) {
LAB_0057669e:
    local_38 = (char *)0x0;
    std::exception::exception((exception *)local_48,&local_38);
    local_48[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_48,&DAT_00c857a8);
  }
  param_1[0x41] = iVar4;
  *(int *)iVar4 = iVar4;
  *(undefined4 *)(param_1[0x41] + 4) = param_1[0x41];
  local_8._0_1_ = 4;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x48] = 0;
  iVar4 = FUN_00891268(0x18);
  if (iVar4 == 0) {
    local_3c = (char *)0x0;
    std::exception::exception((exception *)local_58,&local_3c);
    local_58[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_58,&DAT_00c857a8);
  }
  param_1[0x47] = iVar4;
  *(int *)iVar4 = iVar4;
  *(undefined4 *)(param_1[0x47] + 4) = param_1[0x47];
  *(undefined4 *)(param_1[0x47] + 8) = param_1[0x47];
  *(undefined1 *)(param_1[0x47] + 0x14) = 1;
  *(undefined1 *)(param_1[0x47] + 0x15) = 1;
  local_8._0_1_ = 5;
  local_38 = (char *)0x3;
  local_34 = param_1 + 5;
  do {
    local_30[1] = 0;
    local_30[0] = 0;
    local_30[2] = 0x41a00000;
    SetRectEmpty(&local_24);
    puVar2 = local_34 + 7;
    local_38 = local_38 + -1;
    puVar5 = local_30;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
      *local_34 = *puVar5;
      puVar5 = puVar5 + 1;
      local_34 = local_34 + 1;
    }
    local_34 = puVar2;
  } while (local_38 != (char *)0x0);
  piVar1 = (int *)param_1[1];
  if (*piVar1 == 0) {
    puVar2 = (undefined4 *)FUN_00891268(0x10);
    local_8._0_1_ = 6;
    local_34 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2[2] = 0;
      iVar4 = FUN_00891268(0x34);
      if (iVar4 == 0) goto LAB_0057669e;
      puVar2[1] = iVar4;
      *(int *)iVar4 = iVar4;
      *(undefined4 *)(puVar2[1] + 4) = puVar2[1];
      *(undefined4 *)(puVar2[1] + 8) = puVar2[1];
      *(undefined1 *)(puVar2[1] + 0x30) = 1;
      *(undefined1 *)(puVar2[1] + 0x31) = 1;
    }
    local_8._0_1_ = 5;
    *piVar1 = (int)puVar2;
  }
  iVar4 = *piVar1;
  FUN_007d0240(*(undefined4 *)(*(int *)(iVar4 + 4) + 4));
  *(int *)(*(int *)(iVar4 + 4) + 4) = *(int *)(iVar4 + 4);
  *(undefined4 *)*(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 4);
  *(int *)(*(int *)(iVar4 + 4) + 8) = *(int *)(iVar4 + 4);
  *(undefined4 *)(iVar4 + 8) = 0;
  piVar1[4] = -1;
  piVar1[5] = 0;
  piVar1[6] = 0;
  FUN_00573b50();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

