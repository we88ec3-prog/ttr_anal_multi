
undefined4 * FUN_0084cef0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar3 = param_2;
  puStack_c = &LAB_0091e912;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  local_8 = 0;
  *param_1 = gbBase::vftable;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_00403040(param_2 + 8,0,0xffffffff);
  param_1[9] = 1;
  *param_1 = gbMesh::vftable;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  piVar1 = param_1 + 0x12;
  *piVar1 = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  local_8._0_1_ = 4;
  local_8._1_3_ = 0;
  FUN_0084bb90(param_1 + 0x1b);
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  local_8._0_1_ = 6;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x1a] = 0;
  if (*(int *)(param_2 + 0x40) != 0) {
    iVar5 = FUN_00891268(0x10,uVar4);
    local_8._0_1_ = 7;
    if (iVar5 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_00856de0(iVar5,*(undefined4 *)(param_2 + 0x40));
    }
    param_1[0x10] = uVar6;
    param_2 = iVar5;
  }
  local_8._0_1_ = 6;
  if (*(int *)(iVar3 + 0x44) != 0) {
    param_2 = FUN_00891268(0x20,uVar4);
    local_8._0_1_ = 8;
    if (param_2 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_00857650(param_2,*(undefined4 *)(iVar3 + 0x44));
    }
    param_1[0x11] = uVar6;
  }
  local_8._0_1_ = 6;
  uVar6 = *(undefined4 *)(iVar3 + 0x48);
  uVar2 = *(undefined4 *)(iVar3 + 0x4c);
  if (*piVar1 != param_1[0x13]) {
    param_2 = FUN_008525a0(param_1[0x13]);
    FUN_008510f0(param_1[0x13]);
    param_1[0x13] = param_2;
  }
  FUN_00853e60(piVar1,*piVar1,uVar6,uVar2,param_2);
  FUN_00853350(*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x2c),param_2);
  uVar6 = *(undefined4 *)(iVar3 + 0x5c);
  uVar2 = *(undefined4 *)(iVar3 + 0x58);
  piVar1 = param_1 + 0x16;
  if (*piVar1 != param_1[0x17]) {
    uVar7 = FUN_004fa270(*piVar1);
    param_1[0x17] = uVar7;
  }
  FUN_008541d0(piVar1,*piVar1,uVar2,uVar6,uVar6);
  param_1[0xe] = *(undefined4 *)(iVar3 + 0x38);
  param_1[0xf] = *(undefined4 *)(iVar3 + 0x3c);
  FUN_00850540(param_1 + 0x30,iVar3 + 0xc0);
  ExceptionList = local_10;
  return param_1;
}

