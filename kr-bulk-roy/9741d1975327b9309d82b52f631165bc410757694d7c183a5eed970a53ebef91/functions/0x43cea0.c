
void FUN_0043cea0(int param_1)

{
  code *pcVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint local_7c;
  uint local_78;
  int local_74 [12];
  uint local_44;
  uint local_38;
  undefined4 uStack_28;
  uint local_24;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00941a60;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  ExceptionList = &local_14;
  local_74[0] = param_1;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  local_c = 0xffffffff;
  local_78 = 0x1d2;
  FUN_005740f0(&local_78);
  if (local_7c == DAT_00fe5b10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar4 = (undefined4 *)(local_7c + 0x10);
  if (7 < *(uint *)(local_7c + 0x24)) {
    puVar4 = (undefined4 *)*puVar4;
  }
  FUN_007572f0(puVar4);
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  local_7c = 0;
  FUN_00848020(&local_7c);
  if (local_78 != local_44) {
    *(undefined4 *)(local_78 + 0x18) = 0xffff6600;
    *(undefined1 *)(local_78 + 0x1c) = 1;
    FUN_007591a0(*(int *)(local_78 + 0x10),*(int *)(local_78 + 0x14) - *(int *)(local_78 + 0x10),
                 0xffff6600);
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 2;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_c._0_1_ = 1;
  }
  local_7c = 0x1d3;
  FUN_005740f0(&local_7c);
  if (local_78 != DAT_00fe5b10) {
    FUN_004068f0();
    local_c._0_1_ = 3;
    FUN_00759ac0(0);
    local_c._0_1_ = 1;
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    FUN_00405300(*(int *)(local_74[0] + 0xf0) + 0xe8);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 4;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c._0_1_ = 1;
    }
    uVar2 = DAT_00f942ca;
    if ((DAT_00fb7b58 & 1) == 0) {
      DAT_00fb7b58 = DAT_00fb7b58 | 1;
      local_c._0_1_ = 5;
      FUN_0081faa0();
      _atexit(FUN_00bcd450);
      local_c._0_1_ = 1;
    }
    local_7c = (uint)uVar2;
    FUN_0081fd20(&local_7c);
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 6;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c._0_1_ = 1;
    }
    local_7c = 0x1d6;
    FUN_005740f0(&local_7c);
    if (local_78 != DAT_00fe5b10) {
      FUN_00757710();
      local_7c = 0;
      FUN_00848020(&local_7c);
      if (local_78 != local_44) {
        *(undefined4 *)(local_78 + 0x18) = 0xffff6600;
        *(undefined1 *)(local_78 + 0x1c) = 1;
        FUN_007591a0(*(int *)(local_78 + 0x10),*(int *)(local_78 + 0x14) - *(int *)(local_78 + 0x10)
                     ,0xffff6600);
      }
      FUN_007597b0(0);
      local_7c = 1;
      FUN_00848020(&local_7c);
      if (local_78 != local_44) {
        *(undefined4 *)(local_78 + 0x18) = 0xffff6600;
        *(undefined1 *)(local_78 + 0x1c) = 1;
        FUN_007591a0(*(int *)(local_78 + 0x10),*(int *)(local_78 + 0x14) - *(int *)(local_78 + 0x10)
                     ,0xffff6600);
      }
      FUN_00412df0();
      local_c._0_1_ = 7;
      FUN_00759ac0(1);
      local_c = CONCAT31(local_c._1_3_,1);
      if (7 < local_24) {
        FUN_0089120c(local_38);
      }
      iVar3 = local_74[0];
      local_24 = 7;
      uStack_28 = 0;
      local_38 = local_38 & 0xffff0000;
      FUN_00405300(*(int *)(local_74[0] + 0xf4) + 0xe8);
      (**(code **)(**(int **)(iVar3 + 0xf8) + 0x90))(1 < (short)uVar2);
      (**(code **)(**(int **)(iVar3 + 0xf8) + 200))();
      puStack_10 = (undefined1 *)0xffffffff;
      FUN_00757640(local_74);
      ExceptionList = pvStack_18;
      __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff80);
      return;
    }
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

