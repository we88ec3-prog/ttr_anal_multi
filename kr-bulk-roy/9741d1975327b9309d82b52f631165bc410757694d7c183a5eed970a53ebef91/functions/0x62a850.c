
void FUN_0062a850(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  uint *puVar5;
  int iVar6;
  undefined1 auStack_134 [4];
  uint local_130;
  int local_12c;
  undefined1 auStack_128 [44];
  int iStack_fc;
  undefined1 local_f0 [48];
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined2 local_b0;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined2 local_94;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 auStack_78 [56];
  uint local_40 [11];
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00928d6a;
  local_14 = ExceptionList;
  local_40[9] = DAT_00d61f20 ^ (uint)auStack_134;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffec0;
  ExceptionList = &local_14;
  local_40[0] = 1;
  local_40[1] = 2;
  local_40[2] = 3;
  local_40[3] = 4;
  local_40[4] = 0xd;
  local_40[5] = 0xe;
  local_40[6] = 0xf;
  local_40[7] = 0x10;
  local_40[8] = 0x16;
  _eh_vector_constructor_iterator_
            (local_f0,0x10,3,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
  iVar6 = 0;
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_9c = 7;
  local_a0 = 0;
  local_b0 = 0;
  local_80 = 7;
  local_84 = 0;
  local_94 = 0;
  local_c._0_1_ = 0;
  local_c._1_3_ = 0;
  local_130 = *(uint *)(in_ECX + 0x104);
  puVar5 = local_40;
  while ((FUN_0062daa0(puVar5), local_12c == local_130 ||
         ((*(int *)(local_12c + 0x44) - *(int *)(local_12c + 0x40) & 0xfffffffcU) != 0))) {
    iVar6 = iVar6 + 1;
    puVar5 = puVar5 + 1;
    if (8 < iVar6) {
      local_c = 0xffffffff;
      FUN_00628890();
LAB_0062a9ba:
      ExceptionList = local_14;
      __security_check_cookie(local_40[9] ^ (uint)auStack_134);
      return;
    }
  }
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_c._0_1_ = 1;
    FUN_00590760(uVar2);
    _atexit((_func_4879 *)&LAB_00bce760);
    local_c._0_1_ = 0;
  }
  local_130 = local_40[iVar6];
  uVar3 = FUN_004f7ba0();
  FUN_004026e0(uVar3,0,0xffffffff);
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 2;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_c._0_1_ = 0;
  }
  local_130 = 0x1a3;
  FUN_005740f0(&local_130);
  if (local_12c == DAT_00fe5b10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar4 = (undefined4 *)(local_12c + 0x10);
  if (7 < *(uint *)(local_12c + 0x24)) {
    puVar4 = (undefined4 *)*puVar4;
  }
  FUN_007572f0(puVar4);
  local_c._0_1_ = 3;
  local_130 = 0;
  FUN_00848020(&local_130);
  if (local_12c != iStack_fc) {
    *(undefined4 *)(local_12c + 0x18) = 0xffff0000;
    *(undefined1 *)(local_12c + 0x1c) = 1;
    FUN_007591a0(*(int *)(local_12c + 0x10),*(int *)(local_12c + 0x14) - *(int *)(local_12c + 0x10),
                 0xffff0000);
  }
  FUN_00759ac0(0);
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 4;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_c._0_1_ = 3;
  }
  local_130 = 0x196;
  FUN_005740f0(&local_130);
  if (local_12c == DAT_00fe5b10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar4 = (undefined4 *)(local_12c + 0x10);
  if (7 < *(uint *)(local_12c + 0x24)) {
    puVar4 = (undefined4 *)*puVar4;
  }
  FUN_007572f0(puVar4);
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c._0_1_ = 6;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_c._0_1_ = 5;
  FUN_007531a0(&DAT_00f94810,auStack_128,auStack_78,0,0);
  local_c._0_1_ = 3;
  FUN_00757640(auStack_78);
  local_c = (uint)local_c._1_3_ << 8;
  FUN_00757640(auStack_128);
  local_c = 0xffffffff;
  FUN_00628890();
  goto LAB_0062a9ba;
}

