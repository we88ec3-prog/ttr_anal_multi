
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00455e60(void)

{
  undefined1 uVar1;
  short sVar2;
  undefined1 *puVar3;
  code *pcVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  int in_ECX;
  undefined2 local_84 [8];
  undefined4 local_74;
  short *local_70;
  undefined2 local_68 [8];
  undefined4 local_58;
  undefined4 local_54;
  undefined1 auStack_34 [4];
  undefined4 local_30;
  undefined1 *local_2c;
  int local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined2 local_1f;
  undefined1 local_1d;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00931982;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_34;
  ExceptionList = &local_14;
  if ((*(char *)(in_ECX + 400) == '\0') &&
     (*(undefined1 *)(in_ECX + 400) = 1,
     *(int *)(in_ECX + 0x158) - *(int *)(in_ECX + 0x154) >> 2 != 0)) {
    uVar5 = (uint)local_30 >> 0x10;
    puVar3 = *(undefined1 **)(in_ECX + 0x154);
    uVar1 = puVar3[8];
    local_30._0_2_ = CONCAT11(puVar3[4],*puVar3);
    local_30 = (undefined1 *)(CONCAT22((short)uVar5,(undefined2)local_30) & 0xff00ffff);
    if (*(short *)(in_ECX + 0x178) == 0) {
      local_28 = in_ECX;
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 0;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c = 1;
        local_54 = 0x455fb2;
        FUN_00584c40();
        local_54 = 0x455fbc;
        _atexit(FUN_00bcf370);
      }
      local_c = 0xffffffff;
      local_30 = (undefined1 *)0x19a;
      local_54 = 0x455fe2;
      FUN_005740f0();
      if (local_2c == DAT_00fe5b10) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      local_70 = (short *)(local_2c + 0x10);
      if (7 < *(uint *)(local_2c + 0x24)) {
        local_70 = *(short **)local_70;
      }
      local_24 = local_68;
      local_58 = 0;
      local_54 = 7;
      local_68[0] = 0;
      psVar6 = local_70;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      local_74 = 0x456038;
      FUN_00402160();
      local_c = 2;
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c._0_1_ = 3;
        local_c._1_3_ = 0;
        local_70 = (short *)0x45605b;
        FUN_00584c40();
        local_70 = (short *)0x456065;
        _atexit(FUN_00bcf370);
        local_c = CONCAT31(local_c._1_3_,2);
      }
      local_2c = (undefined1 *)0x1d1;
      local_70 = (short *)0x456087;
      FUN_005740f0();
      if (local_30 == DAT_00fe5b10) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      psVar6 = (short *)(local_30 + 0x10);
      if (7 < *(uint *)(local_30 + 0x24)) {
        psVar6 = *(short **)psVar6;
      }
      local_2c = (undefined1 *)local_84;
      local_70 = (short *)0x7;
      local_74 = 0;
      local_84[0] = 0;
      psVar7 = psVar6;
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
      local_c = 0xffffffff;
      FUN_0058b270(0xca);
      *(undefined1 *)(local_28 + 400) = 0;
    }
    else {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_1f = *(undefined2 *)(in_ECX + 0x178);
      local_1d = *(undefined1 *)(in_ECX + 0x17a);
      local_24 = (undefined2 *)CONCAT22((undefined2)local_30,0xef);
      local_20 = uVar1;
      if (DAT_00fba798 == 0) {
        local_54 = 0x455f5c;
        (**(code **)(*DAT_00fba854 + 0x10))();
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_34);
  return;
}

