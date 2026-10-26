
void FUN_005f2ac0(void)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  short *psVar4;
  short ****ppppsVar5;
  int in_ECX;
  uint *puStack_ac;
  uint *puStack_a8;
  short ***pppsStack_a4;
  undefined4 local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  undefined1 *local_6c;
  uint local_68 [4];
  undefined4 local_58;
  uint local_54;
  short ***local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00948e76;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (**(int **)(in_ECX + 0x184) != 0) {
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    local_54 = 7;
    local_58 = 0;
    local_68[0] = local_68[0] & 0xffff0000;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    if ((*(int **)(in_ECX + 0x184))[2] == 0x19) {
      pppsStack_a4 = (short ***)0x5f2b3c;
      FUN_005e2440();
      puStack_a8 = (undefined4 *)0x5f2b46;
      FUN_005e2510();
    }
    if ((DAT_00f8d9a8 & 1) == 0) {
      DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
      local_8._0_1_ = 3;
      FUN_00523540();
      local_8._0_1_ = 4;
      pppsStack_a4 = (short ***)0x5f2b70;
      FUN_00521080();
      pppsStack_a4 = (short ***)0x5f2b7a;
      _atexit((_func_4879 *)&LAB_00bccc50);
      local_8._0_1_ = 2;
    }
    local_70 = *(undefined4 *)(*(int *)(in_ECX + 0x184) + 0x60);
    pppsStack_a4 = (short ***)0x5f2b9e;
    FUN_008438c0();
    if ((local_6c != DAT_00f8d9b0) &&
       (puVar2 = *(undefined4 **)(local_6c + 0x10), puVar2 != (undefined4 *)0x0)) {
      local_6c = (undefined1 *)&puStack_ac;
      FUN_007e8a90(&puStack_ac,puVar2 + 0x4e);
      FUN_005e6f40();
      pppsStack_a4 = (short ***)local_30;
      puStack_a8 = (uint *)0x5f2bdf;
      FUN_005e1c60();
      FUN_005e4af0();
      pppsStack_a4 = (short ***)0x5f2bf1;
      FUN_005e2440();
      puStack_a8 = (uint *)0x5f2bfa;
      FUN_005e2510();
      if (*(int *)(in_ECX + 0x180) != 0) {
        pppsStack_a4 = (short ***)0x5f2c0c;
        FUN_005e8d20();
      }
      pppsStack_a4 = (short ***)puVar2[10];
      puStack_ac = local_30;
      puStack_a8 = puVar2;
      FUN_005e7580();
      pppsStack_a4 = (short ***)puVar2[0xd];
      puStack_ac = local_30;
      puStack_a8 = puVar2;
      FUN_005e7920();
      pppsStack_a4 = (short ***)0x5f2c41;
      FUN_005e5ee0();
    }
    if ((*(int *)(in_ECX + 0x180) != 0) && (iVar3 = FUN_0051c080(), iVar3 == 0)) {
      if (*(int *)(*(int *)(in_ECX + 0x184) + 8) != 0x19) {
        pppsStack_a4 = (short ***)0x5f2c6c;
        FUN_00585620();
        pppsStack_a4 = (short ***)0x5f2c73;
        FUN_00585330();
        pppsStack_a4 = (short ***)0x5f2c7e;
        FUN_00404420();
      }
      pppsStack_a4 = (short ***)0x5f2c88;
      FUN_00585620();
      pppsStack_a4 = (short ***)0x5f2c8f;
      pppsStack_a4 = (short ***)FUN_00585330();
      psVar4 = (short *)pppsStack_a4;
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar1 != 0);
      puStack_a8 = (undefined4 *)0x5f2cad;
      FUN_00404300();
    }
    pppsStack_a4 = (short ***)0x5f2cb8;
    FUN_005e2770();
    pppsStack_a4 = (short ***)0x0;
    puStack_a8 = local_30;
    puStack_ac = (uint *)0x5f2cc8;
    FUN_004041f0();
    if (*(int *)(*(int *)(in_ECX + 0x184) + 0xc4) != 0) {
      pppsStack_a4 = (short ***)0xc26b70;
      puStack_a8 = (uint *)0x5f2ce6;
      FUN_00404300();
      iVar3 = *(int *)(in_ECX + 0x184);
      if (*(uint *)(iVar3 + 200) < 8) {
        psVar4 = (short *)(iVar3 + 0xb4);
        pppsStack_a4 = (short ***)psVar4;
      }
      else {
        psVar4 = *(short **)(iVar3 + 0xb4);
        pppsStack_a4 = (short ***)psVar4;
      }
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar1 != 0);
      puStack_a8 = (uint *)0x5f2d29;
      FUN_00404300();
      pppsStack_a4 = (short ***)0xc02b9c;
      puStack_a8 = (uint *)0x5f2d35;
      FUN_00404300();
    }
    if (*(int *)(*(int *)(in_ECX + 0x184) + 0xe0) != 0) {
      pppsStack_a4 = (short ***)0xc26268;
      puStack_a8 = (uint *)0x5f2d53;
      FUN_00404300();
      iVar3 = *(int *)(in_ECX + 0x184);
      if (*(uint *)(iVar3 + 0xe4) < 8) {
        psVar4 = (short *)(iVar3 + 0xd0);
        pppsStack_a4 = (short ***)psVar4;
      }
      else {
        psVar4 = *(short **)(iVar3 + 0xd0);
        pppsStack_a4 = (short ***)psVar4;
      }
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar1 != 0);
      puStack_a8 = (uint *)0x5f2d8e;
      FUN_00404300();
      pppsStack_a4 = (short ***)0xc02b9c;
      puStack_a8 = (uint *)0x5f2d9a;
      FUN_00404300();
    }
    pppsStack_a4 = (short ***)0x0;
    puStack_a8 = local_68;
    puStack_ac = (uint *)0x5f2daa;
    FUN_004041f0();
    if (*(int *)(in_ECX + 0x180) != 0) {
      pppsStack_a4 = (short ***)0x5f2dbd;
      FUN_005e86e0();
    }
    pppsStack_a4 = (short ***)local_4c;
    puStack_a8 = (uint *)0x5f2dcd;
    FUN_005e8c10();
    pppsStack_a4 = local_4c[0];
    if (local_38 < 8) {
      pppsStack_a4 = (short ***)local_4c;
    }
    local_78 = 7;
    local_7c = 0;
    local_8c = (uint)local_8c._2_2_ << 0x10;
    ppppsVar5 = (short ****)pppsStack_a4;
    do {
      sVar1 = *(short *)ppppsVar5;
      ppppsVar5 = (short ****)((int)ppppsVar5 + 2);
    } while (sVar1 != 0);
    puStack_a8 = (uint *)0x5f2e12;
    FUN_00402160();
    iVar3 = *(int *)(in_ECX + 0x198);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_007578f0();
    pppsStack_a4 = (short ***)0x7b;
    puStack_a8 = &local_8c;
    puStack_ac = (uint *)(iVar3 + 0xe8);
    FUN_00759ed0();
    if (7 < local_78) {
      pppsStack_a4 = (short ***)0x5f2e4e;
      FUN_0089120c();
    }
    if (7 < local_54) {
      pppsStack_a4 = (short ***)0x5f2e5f;
      FUN_0089120c();
    }
    local_54 = 7;
    local_58 = 0;
    local_68[0] = local_68[0] & 0xffff0000;
    if (7 < local_1c) {
      pppsStack_a4 = (short ***)0x5f2e7e;
      FUN_0089120c();
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    if (7 < local_38) {
      pppsStack_a4 = (short ***)0x5f2e9b;
      FUN_0089120c();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

