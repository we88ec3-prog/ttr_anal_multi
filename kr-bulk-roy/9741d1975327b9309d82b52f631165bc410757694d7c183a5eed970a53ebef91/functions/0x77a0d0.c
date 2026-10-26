
void FUN_0077a0d0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 ****ppppuVar5;
  int local_130;
  undefined4 *local_124;
  undefined4 ***local_11c;
  undefined4 local_118 [5];
  uint local_104;
  uint local_fc [4];
  undefined4 local_ec;
  uint local_e8;
  undefined4 ***local_e0 [4];
  undefined4 local_d0;
  uint local_cc;
  uint local_c4 [4];
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_a8;
  undefined4 local_98;
  uint local_94;
  undefined4 ***local_8c [4];
  undefined4 local_7c;
  uint local_78;
  undefined4 ***local_70 [5];
  uint local_5c;
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009214c9;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    FUN_00756110(*(undefined1 *)(in_ECX + 0x10c),local_14);
    local_fc[0] = local_fc[0] & 0xffff0000;
    local_e8 = 7;
    local_ec = 0;
    FUN_00402160(L"ImageSet",8);
    local_8 = 0;
    local_94 = 7;
    local_98 = 0;
    local_a8 = (uint)local_a8._2_2_ << 0x10;
    FUN_00402160(L"Rect",4);
    local_124 = (undefined4 *)(in_ECX + 0xd0);
    local_130 = 0;
    local_8._0_1_ = 1;
    do {
      FUN_0040ef80();
      local_8._0_1_ = 2;
      FUN_0044fa80(local_8c,local_fc,local_118);
      local_8._0_1_ = 3;
      FUN_0044fa80(local_c4,&local_a8,local_118);
      local_8._0_1_ = 4;
      FUN_007769a0(param_1);
      FUN_004297b0();
      local_8._0_1_ = 5;
      iVar2 = FUN_00891268(0x98);
      local_8._0_1_ = 6;
      if (iVar2 == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        ppppuVar5 = (undefined4 ****)local_e0[0];
        if (local_cc < 0x10) {
          ppppuVar5 = local_e0;
        }
        piVar3 = (int *)FUN_0072e420(iVar2,ppppuVar5);
      }
      local_8._0_1_ = 4;
      if (0xf < local_cc) {
        FUN_0089120c(local_e0[0]);
      }
      uVar1 = local_124[-1];
      local_cc = 0xf;
      local_d0 = 0;
      local_e0[0] = (undefined4 ***)((uint)local_e0[0] & 0xffffff00);
      FUN_004297b0();
      local_8._0_1_ = 7;
      if (local_5c < 0x10) {
        local_11c = local_70;
      }
      else {
        local_11c = local_70[0];
      }
      uVar4 = (**(code **)(*piVar3 + 0x14))();
      FUN_00730d80(local_54,&DAT_00c0d6dc,uVar1);
      FUN_0072e770(uVar4,local_11c);
      local_8._0_1_ = 4;
      if (0xf < local_5c) {
        FUN_0089120c(local_70[0]);
      }
      uVar1 = local_124[1];
      FUN_004297b0();
      local_8._0_1_ = 8;
      if (local_5c < 0x10) {
        local_11c = local_70;
      }
      else {
        local_11c = local_70[0];
      }
      uVar4 = (**(code **)(*piVar3 + 0x14))();
      FUN_00730d80(local_54,&DAT_00c0d6dc,uVar1);
      FUN_0072e770(uVar4,local_11c);
      local_8._0_1_ = 4;
      if (0xf < local_5c) {
        FUN_0089120c(local_70[0]);
      }
      uVar1 = *local_124;
      FUN_004297b0();
      local_8._0_1_ = 9;
      if (local_5c < 0x10) {
        local_11c = local_70;
      }
      else {
        local_11c = local_70[0];
      }
      uVar4 = (**(code **)(*piVar3 + 0x14))();
      FUN_00730d80(local_54,&DAT_00c0d6dc,uVar1);
      FUN_0072e770(uVar4,local_11c);
      local_8._0_1_ = 4;
      if (0xf < local_5c) {
        FUN_0089120c(local_70[0]);
      }
      uVar1 = local_124[2];
      FUN_004297b0();
      local_8._0_1_ = 10;
      if (local_5c < 0x10) {
        local_11c = local_70;
      }
      else {
        local_11c = local_70[0];
      }
      uVar4 = (**(code **)(*piVar3 + 0x14))();
      FUN_00730d80(local_54,&DAT_00c0d6dc,uVar1);
      FUN_0072e770(uVar4,local_11c);
      local_8 = CONCAT31(local_8._1_3_,4);
      if (0xf < local_5c) {
        FUN_0089120c(local_70[0]);
      }
      FUN_0072e0d0();
      if (7 < local_b0) {
        FUN_0089120c(local_c4[0]);
      }
      local_b0 = 7;
      local_b4 = 0;
      local_c4[0] = local_c4[0] & 0xffff0000;
      if (7 < local_78) {
        FUN_0089120c(local_8c[0]);
      }
      local_8._0_1_ = 1;
      local_78 = 7;
      local_7c = 0;
      local_8c[0] = (undefined4 ***)((uint)local_8c[0] & 0xffff0000);
      if (7 < local_104) {
        FUN_0089120c(local_118[0]);
      }
      local_124 = local_124 + 4;
      local_130 = local_130 + 1;
    } while (local_130 < 3);
    FUN_004297b0();
    local_8._0_1_ = 0xb;
    iVar2 = FUN_00891268(0x98);
    local_8._0_1_ = 0xc;
    if (iVar2 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      ppppuVar5 = (undefined4 ****)local_8c[0];
      if (local_78 < 0x10) {
        ppppuVar5 = local_8c;
      }
      piVar3 = (int *)FUN_0072e420(iVar2,ppppuVar5);
    }
    local_8._0_1_ = 1;
    if (0xf < local_78) {
      FUN_0089120c(local_8c[0]);
    }
    uVar1 = *(undefined4 *)(in_ECX + 0xfc);
    local_78 = 0xf;
    local_7c = 0;
    local_8c[0] = (undefined4 ***)((uint)local_8c[0] & 0xffffff00);
    FUN_004297b0();
    local_8._0_1_ = 0xd;
    if (local_5c < 0x10) {
      local_11c = local_70;
    }
    else {
      local_11c = local_70[0];
    }
    uVar4 = (**(code **)(*piVar3 + 0x14))();
    FUN_00730d80(local_54,&DAT_00c0d6dc,uVar1);
    FUN_0072e770(uVar4,local_11c);
    local_8._0_1_ = 1;
    if (0xf < local_5c) {
      FUN_0089120c(local_70[0]);
    }
    uVar1 = *(undefined4 *)(in_ECX + 0x104);
    FUN_004297b0();
    local_8._0_1_ = 0xe;
    if (local_5c < 0x10) {
      local_11c = local_70;
    }
    else {
      local_11c = local_70[0];
    }
    uVar4 = (**(code **)(*piVar3 + 0x14))();
    FUN_00730d80(local_54,&DAT_00c0d6dc,uVar1);
    FUN_0072e770(uVar4,local_11c);
    local_8._0_1_ = 1;
    if (0xf < local_5c) {
      FUN_0089120c(local_70[0]);
    }
    uVar1 = *(undefined4 *)(in_ECX + 0x100);
    FUN_004297b0();
    local_8._0_1_ = 0xf;
    if (local_5c < 0x10) {
      local_11c = local_70;
    }
    else {
      local_11c = local_70[0];
    }
    uVar4 = (**(code **)(*piVar3 + 0x14))();
    FUN_00730d80(local_54,&DAT_00c0d6dc,uVar1);
    FUN_0072e770(uVar4,local_11c);
    local_8._0_1_ = 1;
    if (0xf < local_5c) {
      FUN_0089120c(local_70[0]);
    }
    uVar1 = *(undefined4 *)(in_ECX + 0x108);
    FUN_004297b0();
    local_8._0_1_ = 0x10;
    if (local_5c < 0x10) {
      local_11c = local_70;
    }
    else {
      local_11c = local_70[0];
    }
    uVar4 = (**(code **)(*piVar3 + 0x14))();
    FUN_00730d80(local_54,&DAT_00c0d6dc,uVar1);
    FUN_0072e770(uVar4,local_11c);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (0xf < local_5c) {
      FUN_0089120c(local_70[0]);
    }
    FUN_0072e0d0();
    if (7 < local_94) {
      FUN_0089120c(local_a8);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8 = local_a8 & 0xffff0000;
    if (7 < local_e8) {
      FUN_0089120c(local_fc[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

