
void FUN_0062ed60(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint in_ECX;
  int in_EDX;
  undefined4 *local_b0;
  undefined4 *local_ac;
  uint local_a8;
  undefined4 local_98;
  uint local_94;
  undefined1 local_8c [56];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00946a0a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_b0;
  ExceptionList = &local_14;
  iVar2 = FUN_00630570(DAT_00d61f20 ^ (uint)&stack0xffffff48);
  if (iVar2 < 0x14) {
    if (in_ECX < (uint)(*(int *)(in_EDX + 0x118) - *(int *)(in_EDX + 0x114) >> 2)) {
      local_b0 = (undefined4 *)FUN_00891268(0x18);
      if (local_b0 == (undefined4 *)0x0) {
        local_b0 = (undefined4 *)0x0;
      }
      else {
        uVar4 = **(undefined4 **)(*(int *)(in_EDX + 0x114) + in_ECX * 4);
        local_b0[1] = 0xffffffff;
        local_b0[2] = 0xffffffff;
        local_b0[3] = 0;
        local_b0[4] = 0xf438a;
        *local_b0 = FoxUI::FXUIEventI1::vftable;
        local_b0[5] = uVar4;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c = 6;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_c = 0xffffffff;
      }
      FUN_00804260(&local_b0);
    }
  }
  else {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_ac = (undefined4 *)0x196;
    FUN_005740f0(&local_ac);
    if (local_b0 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar3 = local_b0 + 4;
    if (7 < (uint)local_b0[9]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    FUN_007572f0(puVar3);
    local_c._1_3_ = 0;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 2;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_c._0_1_ = 1;
    local_b0 = (undefined4 *)&DAT_0000001b;
    FUN_005740f0(&local_b0);
    if (local_ac == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar4 = FUN_004068f0();
    local_c._0_1_ = 3;
    FUN_007574a0(uVar4);
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c._0_1_ = 5;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    local_c._0_1_ = 4;
    FUN_007531a0(&DAT_00f94810,local_8c,local_54,0,0);
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_00757640(local_8c);
    if (7 < local_94) {
      FUN_0089120c(local_a8);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8 = local_a8 & 0xffff0000;
    local_c = 0xffffffff;
    FUN_00757640(local_54);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_b0);
  return;
}

