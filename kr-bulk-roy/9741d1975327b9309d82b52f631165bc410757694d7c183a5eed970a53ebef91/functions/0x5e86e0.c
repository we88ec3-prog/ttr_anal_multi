
void FUN_005e86e0(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 unaff_EDI;
  undefined4 uVar6;
  int local_7c;
  uint local_78;
  undefined4 *local_74;
  tm local_70;
  undefined4 local_4c [5];
  uint local_38;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_0093ef98;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = *(int *)(param_1 + 0x68);
  local_14 = uVar2;
  if (iVar4 == 0) goto LAB_005e89b0;
  local_74 = (undefined4 *)(uint)*(ushort *)(iVar4 + 8);
  iVar3 = FUN_00404ba0(uVar2);
  iVar3 = *(int *)(iVar3 + 0x6928);
  local_74 = (undefined4 *)((uint)local_74 & 0xffff);
  FUN_004a4cc0(&local_74);
  if (local_78 == *(uint *)(iVar3 + 0x14)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(local_78 + 0x10);
  }
  local_78 = (uint)*(ushort *)(iVar4 + 8);
  iVar4 = FUN_00404ba0(uVar2);
  iVar4 = *(int *)(iVar4 + 0x6928);
  local_78 = local_78 & 0xffff;
  FUN_004dae30(&local_78);
  if (local_74 == *(undefined4 **)(iVar4 + 4)) {
    puVar5 = (undefined4 *)(iVar4 + 0x30);
  }
  else {
    puVar5 = local_74 + 4;
  }
  if (puVar5 == (undefined4 *)0x0) goto LAB_005e89b0;
  local_74 = puVar5;
  if (7 < (uint)puVar5[5]) {
    local_74 = (undefined4 *)*puVar5;
  }
  uVar6 = 0x1a0;
  FUN_00585620(0x1a0);
  FUN_00585330(uVar6);
  FUN_004ed610();
  local_8 = 0;
  FUN_00404300(L"<br>",4);
  if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) == 0)) {
    uVar6 = 0x1c2;
    FUN_00585620(0x1c2);
    FUN_00585330(uVar6);
    FUN_00404420(unaff_EDI);
    FUN_004041f0(local_4c,0,0xffffffff);
  }
  else {
    uVar6 = 0x1c1;
    FUN_00585620(0x1c1);
    FUN_00585330(uVar6);
    FUN_00404420(unaff_EDI);
    FUN_004041f0(local_4c,0,0xffffffff);
    FUN_00404420(unaff_EDI);
    uVar6 = 0x194;
    FUN_00585620(0x194);
    FUN_00585330(uVar6);
    FUN_00404420(unaff_EDI);
    iVar4 = FUN_00404ba0();
    local_7c = *(int *)(iVar3 + 8) - *(int *)(iVar4 + 0x5f70);
    __gmtime32_s(&local_70,&local_7c);
    bVar1 = true;
    if ((local_70.tm_yday != 0) || (local_70.tm_year != 0x46 && -1 < local_70.tm_year + -0x46)) {
      uVar6 = 0x34;
      FUN_00585620(0x34);
      FUN_00585330(uVar6);
      uVar6 = FUN_004068f0();
      local_8._0_1_ = 1;
      FUN_004041f0(uVar6,0,0xffffffff);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004fa440();
      FUN_00404420(unaff_EDI);
      bVar1 = false;
    }
    if (local_70.tm_hour != 0) {
      uVar6 = 0x35;
      FUN_00585620(0x35);
      FUN_00585330(uVar6);
      uVar6 = FUN_004068f0();
      local_8._0_1_ = 2;
      FUN_004041f0(uVar6,0,0xffffffff);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004fa440();
      FUN_00404420(unaff_EDI);
      bVar1 = false;
    }
    if (local_70.tm_min == 0) {
      if (bVar1) {
        uVar6 = 0x37;
        FUN_00585620(0x37);
        FUN_00585330(uVar6);
        uVar6 = FUN_004068f0();
        local_8._0_1_ = 4;
        goto LAB_005e8946;
      }
    }
    else {
      uVar6 = 0x36;
      FUN_00585620(0x36);
      FUN_00585330(uVar6);
      uVar6 = FUN_004068f0();
      local_8._0_1_ = 3;
LAB_005e8946:
      FUN_004041f0(uVar6,0,0xffffffff);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004fa440();
    }
    FUN_00404420(unaff_EDI);
    FUN_00404420(unaff_EDI);
  }
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
LAB_005e89b0:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

