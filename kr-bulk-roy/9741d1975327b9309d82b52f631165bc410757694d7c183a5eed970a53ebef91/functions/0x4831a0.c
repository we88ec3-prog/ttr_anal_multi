
void FUN_004831a0(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_38;
  int local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_009340c6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    iVar3 = *(int *)(in_ECX + 0xf4);
    *(undefined4 *)(iVar3 + 0x98) = *(undefined4 *)(iVar3 + 0xa0);
    *(undefined4 *)(iVar3 + 0x94) = 2;
    *(undefined4 *)(iVar3 + 0xa8) = 0;
    *(undefined4 *)(iVar3 + 0xb0) = 0;
    *(undefined4 *)(iVar3 + 0x90) = 0;
    FUN_0068a590();
    local_1c = 0xf;
    local_20 = 0;
    local_30 = local_30 & 0xffffff00;
    FUN_0040b310("EQUIP_REINFORCE_SUCCESS");
    local_8 = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    piVar2 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
    }
    if (0xf < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  else {
    if (param_1 == 2) {
      local_38 = 0x196;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&local_38);
      if (local_34 == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (*(uint *)(local_34 + 0x24) < 8) {
        iVar3 = local_34 + 0x10;
      }
      else {
        iVar3 = *(int *)(local_34 + 0x10);
      }
      local_34 = 0xb;
      iVar4 = FUN_005854b0();
      FUN_005740f0(&local_34);
      if (local_38 == *(int *)(iVar4 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar5 = (undefined4 *)(local_38 + 0x10);
      if (*(uint *)(local_38 + 0x24) < 8) {
        uVar8 = 0;
        uVar7 = 0;
      }
      else {
        puVar5 = (undefined4 *)*puVar5;
        uVar8 = 0;
        uVar7 = 0;
      }
    }
    else {
      uVar8 = 0;
      uVar7 = 0;
      uVar6 = 0x196;
      if (param_1 == 3) {
        FUN_005854b0(0x196,0,0,local_14);
        iVar3 = FUN_00585330(uVar6);
        uVar6 = 0x16c;
      }
      else if (param_1 == 4) {
        FUN_005854b0(0x196,0,0,local_14);
        iVar3 = FUN_00585330(uVar6);
        uVar6 = 0x16d;
      }
      else if (param_1 == 5) {
        FUN_005854b0(0x196,0,0,local_14);
        iVar3 = FUN_00585330(uVar6);
        uVar6 = 0x16e;
      }
      else if (param_1 == 6) {
        FUN_005854b0(0x196,0,0,local_14);
        iVar3 = FUN_00585330(uVar6);
        uVar6 = 0x171;
      }
      else if (param_1 == 7) {
        FUN_005854b0(0x196,0,0,local_14);
        iVar3 = FUN_00585330(uVar6);
        uVar6 = 0xe8;
      }
      else if (param_1 == 1) {
        FUN_005854b0(0x196,0,0,local_14);
        iVar3 = FUN_00585330(uVar6);
        uVar6 = 0x175;
      }
      else {
        FUN_005854b0(0x196,0,0,local_14);
        iVar3 = FUN_00585330(uVar6);
        uVar6 = 0x176;
      }
      FUN_005854b0(uVar6,iVar3);
      puVar5 = (undefined4 *)FUN_00585330(uVar6);
    }
    FUN_00404b10(0xca,puVar5,iVar3,uVar7,uVar8);
    FUN_0068a350();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

