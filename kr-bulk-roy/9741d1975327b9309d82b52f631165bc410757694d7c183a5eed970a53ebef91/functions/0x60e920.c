
void FUN_0060e920(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  short *psVar3;
  int iVar4;
  undefined1 auStack_bc [7];
  char local_b5;
  int local_b4;
  int local_b0;
  short *local_ac;
  uint local_a8;
  undefined4 uStack_98;
  uint local_94;
  undefined1 local_8c [16];
  undefined4 local_7c;
  int local_60;
  undefined1 local_54 [16];
  int local_44;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00928e64;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_bc;
  ExceptionList = &local_14;
  if ((DAT_00fc1094 & 1) == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_c = 0;
    FUN_0052f7e0(DAT_00d61f20 ^ (uint)&stack0xffffff38);
    _atexit((_func_4879 *)&LAB_00bcdc80);
  }
  local_c = 0xffffffff;
  psVar3 = (short *)0x0;
  local_ac = (short *)0x0;
  if (in_ECX != 0) {
    psVar3 = (short *)FUN_00530770(&DAT_00fc1098);
    local_ac = (short *)FUN_00530800(&DAT_00fc1098);
  }
  FUN_00757200(local_54);
  local_c = 1;
  if (psVar3 != (short *)0x0) {
    local_b5 = '\0';
    if ((*(int *)(param_1 + 0x1c4) != 0) || (*(int *)(param_1 + 0x1c0) != 0)) {
      local_b5 = '\x01';
    }
    *(int *)(param_1 + 0x1c0) = *(int *)(param_1 + 0x1c0) + (int)*psVar3;
    *(int *)(param_1 + 0x1c4) = (int)psVar3[1] + *(int *)(param_1 + 0x1c4);
    FUN_007572f0(&DAT_00bf7508);
    local_c._0_1_ = 2;
    iVar4 = (-(uint)(local_b5 != '\0') & 0xff5aff79) - 1;
    local_b0 = 0;
    FUN_00848020(&local_b0);
    if (local_b4 != local_60) {
      *(int *)(local_b4 + 0x18) = iVar4;
      *(undefined1 *)(local_b4 + 0x1c) = 1;
      FUN_007591a0(*(int *)(local_b4 + 0x10),*(int *)(local_b4 + 0x14) - *(int *)(local_b4 + 0x10),
                   iVar4);
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 3;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 2;
    }
    local_b4 = 0x1d5;
    FUN_005740f0(&local_b4);
    if (local_b0 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar2 = (undefined4 *)(local_b0 + 0x10);
    if (7 < *(uint *)(local_b0 + 0x24)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    FUN_0040e460(puVar2);
    local_c._0_1_ = 4;
    FUN_00759ac0(0);
    local_c._0_1_ = 2;
    if (7 < local_94) {
      FUN_0089120c(local_a8);
    }
    FUN_00757c60(local_54,local_8c,0,local_7c,local_44);
    local_c = CONCAT31(local_c._1_3_,1);
    FUN_00757640(local_8c);
  }
  if (local_ac != (short *)0x0) {
    if (local_44 != 0) {
      FUN_00757da0(local_54);
    }
    local_b5 = '\0';
    if ((*(int *)(param_1 + 0x1cc) != 0) || (*(int *)(param_1 + 0x1c8) != 0)) {
      local_b5 = '\x01';
    }
    *(int *)(param_1 + 0x1c8) = *(int *)(param_1 + 0x1c8) + (int)*local_ac;
    *(int *)(param_1 + 0x1cc) = (int)local_ac[1] + *(int *)(param_1 + 0x1cc);
    FUN_007572f0(&DAT_00bf7508);
    local_c._0_1_ = 5;
    iVar4 = (-(uint)(local_b5 != '\0') & 0xff5aff79) - 1;
    local_b4 = 0;
    FUN_00848020(&local_b4);
    if (local_b0 != local_60) {
      *(int *)(local_b0 + 0x18) = iVar4;
      *(undefined1 *)(local_b0 + 0x1c) = 1;
      FUN_007591a0(*(int *)(local_b0 + 0x10),*(int *)(local_b0 + 0x14) - *(int *)(local_b0 + 0x10),
                   iVar4);
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 6;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c._0_1_ = 5;
    }
    local_b4 = 0x1d6;
    FUN_005740f0(&local_b4);
    if (local_b0 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar2 = (undefined4 *)(local_b0 + 0x10);
    if (7 < *(uint *)(local_b0 + 0x24)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    FUN_0040e460(puVar2);
    local_c._0_1_ = 7;
    FUN_00759ac0(0);
    local_c._0_1_ = 5;
    if (7 < local_94) {
      FUN_0089120c(local_a8);
    }
    local_a8 = local_a8 & 0xffff0000;
    local_94 = 7;
    uStack_98 = 0;
    FUN_00757c60(local_54,local_8c,0,local_7c,local_44);
    local_c = CONCAT31(local_c._1_3_,1);
    FUN_00757640(local_8c);
  }
  FUN_00405300(*(int *)(param_1 + 0x184) + 0xe8);
  local_c = 0xffffffff;
  FUN_00757640(local_54);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_bc);
  return;
}

