
void FUN_00673790(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  short ****ppppsVar6;
  int in_ECX;
  undefined2 local_bc [4];
  undefined4 uStack_b4;
  int iStack_b0;
  uint *local_ac;
  short ***local_a8;
  int local_8c;
  undefined1 *local_88;
  uint local_84 [4];
  undefined4 local_74;
  uint local_70;
  uint local_68;
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
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00946051;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_70 = 7;
  local_74 = 0;
  local_84[0] = local_84[0] & 0xffff0000;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
  local_54 = 7;
  local_58 = 0;
  local_68 = local_68 & 0xffff0000;
  local_8 = 2;
  uStack_7 = 0;
  iVar3 = param_1;
  switch(in_ECX) {
  case 5:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
    break;
  case 6:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
    break;
  case 7:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
    break;
  case 8:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
    break;
  case 9:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
  }
  if ((in_ECX == 2) || (in_ECX == 4)) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 3;
      local_a8 = (short ***)0x673a04;
      FUN_00584c40();
      local_a8 = (short ***)0x673a0e;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 2;
    }
    local_88 = (undefined1 *)0x28b;
    local_a8 = (short ***)0x673a37;
    FUN_005740f0();
    if (local_8c == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    piVar5 = (int *)(local_8c + 0x10);
    local_a8 = (short ***)piVar5;
    if (7 < *(uint *)(local_8c + 0x24)) {
      piVar5 = (int *)*piVar5;
      local_a8 = (short ***)piVar5;
    }
    do {
      iVar3 = *piVar5;
      piVar5 = (int *)((int)piVar5 + 2);
    } while ((short)iVar3 != 0);
    local_ac = (uint *)0x673a7a;
    FUN_00402160();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 4;
      local_a8 = (short ***)0x673a98;
      FUN_00584c40();
      local_a8 = (short ***)0x673aa2;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 2;
    }
    local_88 = (undefined1 *)0x28b;
    local_a8 = (short ***)0x673ac6;
    FUN_005740f0();
    if (local_8c == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 5;
      local_a8 = (short ***)0x673b07;
      FUN_00584c40();
      local_a8 = (short ***)0x673b11;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 2;
    }
    local_88 = (undefined1 *)0x34b;
    local_a8 = (short ***)0x673b39;
    FUN_005740f0();
    if (local_8c == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_004ed610();
    local_8 = 6;
    local_a8 = (short ***)0x673b70;
    FUN_00402800();
    local_8 = 2;
    if (7 < local_1c) {
      local_a8 = (short ***)0x673b82;
      FUN_0089120c();
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 7;
      local_a8 = (short ***)0x673ba3;
      FUN_00584c40();
      local_a8 = (short ***)0x673bad;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 2;
    }
    local_88 = (undefined1 *)0x34d;
    local_a8 = (short ***)0x673bd5;
    FUN_005740f0();
    if (local_8c == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_004068f0();
    local_8 = 8;
  }
  else {
    if ((DAT_00fb725c & 1) == 0) {
      DAT_00fb725c = DAT_00fb725c | 1;
      local_8 = 9;
      FUN_004a79a0();
      local_a8 = (short ***)0x6738aa;
      _atexit((_func_4879 *)&DAT_00bccf80);
      local_8 = 2;
    }
    local_a8 = (short ***)local_30;
    local_ac = (uint *)0x6738c3;
    FUN_004a7f20();
    local_8 = 10;
    local_a8 = (short ***)0x6738d0;
    FUN_00402800();
    local_8 = 2;
    if (7 < local_1c) {
      local_a8 = (short ***)0x6738e7;
      FUN_0089120c();
    }
    local_88 = (undefined1 *)local_bc;
    local_a8 = (short ***)0x7;
    local_ac = (uint *)0x0;
    local_bc[0] = 0;
    FUN_004026e0(iVar3 + 0x4c,0,0xffffffff);
    local_8 = 0xb;
    local_8c = 0x34b;
    iVar3 = FUN_00585620();
    FUN_005740f0(&local_8c);
    if (local_88 == *(undefined1 **)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar4 = (undefined4 *)(local_88 + 0x10);
    if (7 < *(uint *)(local_88 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    local_8 = 2;
    FUN_00424c80(puVar4);
    local_8 = 0xc;
    local_a8 = (short ***)0x673979;
    FUN_00402800();
    local_8 = 2;
    if (7 < local_1c) {
      local_a8 = (short ***)0x67398b;
      FUN_0089120c();
    }
    local_88 = (undefined1 *)0x34d;
    iVar3 = FUN_00585620();
    local_a8 = (short ***)0x6739b3;
    FUN_005740f0();
    if (local_8c == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_004068f0();
    local_8 = 0xd;
  }
  local_a8 = (short ***)0x673c0e;
  FUN_00402800();
  local_8 = 2;
  if (7 < local_1c) {
    local_a8 = (short ***)0x673c20;
    FUN_0089120c();
  }
  local_88 = (undefined1 *)local_bc;
  local_a8 = (short ***)0x7;
  local_ac = (uint *)0x0;
  local_bc[0] = 0;
  FUN_004026e0(local_84,0,0xffffffff);
  FUN_00424c80(&DAT_00bf7508);
  local_8 = 0xe;
  local_a8 = (short ***)0x673c79;
  FUN_00757800();
  local_8 = 2;
  if (7 < local_1c) {
    local_a8 = (short ***)0x673c8b;
    FUN_0089120c();
  }
  local_a8 = local_4c[0];
  if (local_38 < 8) {
    local_a8 = (short ***)local_4c;
  }
  local_30[0] = local_30[0] & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  ppppsVar6 = (short ****)local_a8;
  do {
    sVar1 = *(short *)ppppsVar6;
    ppppsVar6 = (short ****)((int)ppppsVar6 + 2);
  } while (sVar1 != 0);
  local_ac = (uint *)0x673ccb;
  FUN_00402160();
  iVar3 = *(int *)(param_1 + 0xe8);
  local_8 = 0xf;
  FUN_007578f0();
  local_a8 = (short ***)0x7b;
  local_ac = local_30;
  uStack_b4 = 0x673cee;
  iStack_b0 = iVar3 + 0xe8;
  FUN_00759ed0();
  _local_8 = CONCAT31(uStack_7,2);
  if (7 < local_1c) {
    local_a8 = (short ***)0x673d00;
    FUN_0089120c();
  }
  local_a8 = (short ***)0x673d18;
  FUN_00757800();
  if (7 < local_54) {
    local_a8 = (short ***)0x673d26;
    FUN_0089120c();
  }
  local_54 = 7;
  local_58 = 0;
  local_68 = local_68 & 0xffff0000;
  if (7 < local_38) {
    local_a8 = (short ***)0x673d4a;
    FUN_0089120c();
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
  if (7 < local_70) {
    local_a8 = (short ***)0x673d67;
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

