
void FUN_006343d0(void)

{
  ushort uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 local_a8 [8];
  undefined4 local_98;
  undefined4 local_94;
  undefined1 auStack_7c [4];
  undefined1 *local_78;
  uint local_74;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009464f8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  ExceptionList = &local_14;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 0;
    FUN_004ffe60();
    local_94 = 0x634435;
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  local_c = 0xffffffff;
  local_94 = 0x63444d;
  uVar3 = FUN_005013a0();
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 1;
    FUN_004ffe60();
    local_94 = 0x634475;
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_c = 0xffffffff;
  }
  iVar5 = DAT_00fb114c;
  local_94 = 0x63449d;
  local_74 = uVar3 & 0xffff;
  FUN_00503d20();
  if (local_78 == (undefined1 *)*(int *)(iVar5 + 4)) {
    iVar5 = 0;
  }
  else {
    iVar5 = (int)local_78 + 0x10;
  }
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 2;
    FUN_004ffe60();
    local_94 = 0x6344d9;
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_c = 0xffffffff;
  }
  local_94 = 0x634500;
  local_78 = (undefined1 *)(uVar3 & 0xffff);
  FUN_00503cb0();
  if (local_74 == DAT_00fb119c) {
    iVar4 = 0;
  }
  else {
    iVar4 = local_74 + 0x10;
  }
  if ((iVar5 != 0) && (iVar4 != 0)) {
    local_78 = (undefined1 *)0x30f;
    iVar4 = FUN_00585620();
    local_94 = 0x634542;
    FUN_005740f0();
    if (local_74 == *(uint *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    local_94 = 0x63456e;
    FUN_007572f0();
    local_c._0_1_ = 3;
    local_c._1_3_ = 0;
    local_94 = 0x634590;
    FUN_00759ac0();
    local_94 = 0x63459e;
    FUN_007597b0();
    if ((DAT_00fe17b8 & 1) == 0) {
      DAT_00fe17b8 = DAT_00fe17b8 | 1;
      local_c._0_1_ = 4;
      FUN_0050caf0();
      local_94 = 0x6345c5;
      _atexit((_func_4879 *)&LAB_00bce7e0);
      local_c._0_1_ = 3;
    }
    local_78 = *(undefined1 **)(iVar5 + 0x20);
    local_94 = 0x6345ea;
    FUN_0050db00();
    if ((local_74 == DAT_00fe17c4) || (local_74 + 0x10 == 0)) {
      local_94 = 0x634675;
      FUN_00759ac0();
    }
    else {
      local_78 = (undefined1 *)local_a8;
      local_94 = 7;
      local_98 = 0;
      local_a8[0] = 0;
      FUN_004026e0(local_74 + 0x10,0,0xffffffff);
      FUN_00633f80();
      local_c._0_1_ = 5;
      local_94 = 0x634648;
      FUN_00759ac0();
      local_c._0_1_ = 3;
      if (7 < local_24) {
        local_94 = 0x634660;
        FUN_0089120c();
      }
    }
    uVar1 = *(ushort *)(iVar5 + 0x28);
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c._0_1_ = 6;
      FUN_004f3d80();
      local_94 = 0x6346a6;
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c._0_1_ = 3;
    }
    local_78 = (undefined1 *)(uVar1 | 0x6000000);
    FUN_004f7a70();
    local_94 = 0x6346e3;
    FUN_00759ac0();
    local_c = 0xffffffff;
    local_94 = 0x6346f8;
    FUN_00757640();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
}

