
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d7cf0(short *param_1,int *param_2,int param_3,byte param_4)

{
  short sVar1;
  short *psVar2;
  short ****ppppsVar3;
  undefined4 ****ppppuVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined1 auStack_13c [4];
  uint local_138;
  int local_134;
  int *local_130;
  int local_12c;
  undefined4 uStack_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  undefined4 local_110;
  undefined4 local_10c;
  int local_108;
  undefined4 local_104;
  undefined4 ***local_100 [4];
  undefined4 local_f0;
  uint local_ec;
  short ***local_e4 [4];
  undefined4 local_d4;
  uint local_d0;
  undefined1 auStack_c8 [172];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  puStack_10 = &LAB_009216ce;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_13c;
  ExceptionList = &local_14;
  local_130 = param_2;
  local_138 = (uint)((param_4 & 1) != 0);
  if ((param_4 & 2) != 0) {
    local_138 = local_138 | 2;
  }
  if ((param_4 & 4) != 0) {
    local_138 = local_138 | 4;
  }
  if ((param_4 & 8) != 0) {
    local_138 = local_138 | 8;
  }
  local_d0 = 7;
  local_d4 = 0;
  local_e4[0] = (short ***)((uint)local_e4[0] & 0xffff0000);
  local_c = 0;
  uStack_b = 0;
  psVar2 = param_1;
  if (param_3 < 0) {
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
  }
  FUN_00402160(param_1);
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_c = 1;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_c = 0;
  }
  iVar6 = *(int *)(in_ECX + 0xc);
  local_124 = DAT_00fb7b90;
  local_134 = iVar6;
  FUN_00736180();
  if ((local_12c == DAT_00fb7b80) || (DAT_00fb7b90 = iVar6, local_12c == -0x10)) {
    DAT_00fb7b90 = DAT_00fb7b8c;
  }
  ppppsVar3 = (short ****)local_e4[0];
  if (local_d0 < 8) {
    ppppsVar3 = local_e4;
  }
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_c = 2;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_c = 0;
  }
  if (ppppsVar3 != (short ****)0x0) {
    psVar2 = (short *)((int)ppppsVar3 + 2);
    do {
      sVar1 = *(short *)ppppsVar3;
      ppppsVar3 = (short ****)((int)ppppsVar3 + 2);
    } while (sVar1 != 0);
    if ((int)ppppsVar3 - (int)psVar2 >> 1 != 0) {
      local_134 = *param_2;
      iVar6 = param_2[1];
      FUN_0073ce20();
      local_c = 3;
      ppppuVar4 = (undefined4 ****)local_100[0];
      if (local_ec < 8) {
        ppppuVar4 = local_100;
      }
      iVar5 = FUN_00735620(&DAT_00fb7b70,DAT_00fb7b90,ppppuVar4);
      uVar7 = DAT_00fb7b74;
      if (iVar5 == 0) {
        local_c = 0;
        if (7 < local_ec) {
          FUN_0089120c();
        }
      }
      else {
        local_110 = *(undefined4 *)(iVar5 + 0x24);
        local_10c = *(undefined4 *)(iVar5 + 0x28);
        local_108 = *(int *)(iVar5 + 0x2c);
        local_104 = *(undefined4 *)(iVar5 + 0x30);
        if ((local_138 & 1) != 0) {
          local_134 = local_134 +
                      (((local_130[2] - local_108) - *local_130) + *(int *)(iVar5 + 0x24)) / 2;
        }
        if ((local_138 & 4) != 0) {
          iVar6 = iVar6 + (((local_130[3] - *(int *)(iVar5 + 0x30)) + *(int *)(iVar5 + 0x28)) -
                          local_130[1]) / 2;
        }
        local_118 = (*(int *)(iVar5 + 0x2c) - *(int *)(iVar5 + 0x24)) + local_134;
        local_120 = local_134;
        local_c = 0;
        local_114 = (*(int *)(iVar5 + 0x30) - *(int *)(iVar5 + 0x28)) + iVar6;
        local_11c = iVar6;
        if (7 < local_ec) {
          FUN_0089120c();
        }
        local_ec = 7;
        local_f0 = 0;
        local_100[0] = (undefined4 ***)((uint)local_100[0] & 0xffff0000);
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          local_c = 4;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          local_c = 0;
        }
        local_12c = 0x45000000;
        uStack_128 = 0x44800000;
        if ((_DAT_00fe1bc4 & 1) == 0) {
          _DAT_00fe1bc4 = _DAT_00fe1bc4 | 1;
          _atexit((_func_4879 *)&DAT_00bcec00);
        }
        FUN_007396c0(auStack_c8,&local_120,0x3f800000,local_12c);
        local_130 = (int *)0x0;
        local_134 = 0;
        local_138 = 0;
        (**(code **)(**(int **)(in_ECX + 0x10) + 0xe8))(*(int **)(in_ECX + 0x10),0xce);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0xe8))
                  (*(int **)(in_ECX + 0x10),0xcf,&stack0xfffffec0);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0xe8))
                  (*(int **)(in_ECX + 0x10),0xd0,&stack0xfffffeb0);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0xe4))(*(int **)(in_ECX + 0x10),0xce,1);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0xe4))(*(int **)(in_ECX + 0x10),0xd0,2);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0xe4))(*(int **)(in_ECX + 0x10),0xcf,2);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0x164))(*(int **)(in_ECX + 0x10),0x144);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0x104))(*(int **)(in_ECX + 0x10),0,uVar7);
        piVar8 = &local_124;
        (**(code **)(**(int **)(in_ECX + 0x10) + 0x14c))(*(int **)(in_ECX + 0x10),4,2,piVar8,0x1c);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0xe4))(*(int **)(in_ECX + 0x10),0xce,uVar7);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0xe4))(*(int **)(in_ECX + 0x10),0xcf,piVar8);
        (**(code **)(**(int **)(in_ECX + 0x10) + 0xe4))(*(int **)(in_ECX + 0x10),0xd0,uVar7);
      }
    }
  }
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_c = 5;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
  }
  iVar6 = local_124;
  FUN_00736180();
  if ((local_12c == DAT_00fb7b80) || (local_12c == -0x10)) {
    DAT_00fb7b90 = DAT_00fb7b8c;
  }
  else {
    DAT_00fb7b90 = iVar6;
  }
  if (7 < local_d0) {
    FUN_0089120c();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_13c);
  return;
}

