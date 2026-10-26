
void FUN_00865de0(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 ****ppppuVar4;
  undefined1 local_188 [4];
  undefined1 local_184 [4];
  undefined1 local_180 [4];
  undefined1 local_17c [4];
  undefined1 local_178 [4];
  undefined1 local_174 [4];
  uint local_170;
  int local_16c;
  int local_168;
  uint local_164;
  uint local_160;
  uint local_15c;
  undefined1 *local_158;
  undefined1 local_154 [4];
  undefined4 *local_150;
  undefined1 local_144 [128];
  undefined1 local_c4 [132];
  undefined4 local_40;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927f79;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_168 = param_1;
  local_14 = uVar2;
  FUN_00725100(0,0,0);
  local_170 = 0;
  if (*(int *)(local_168 + 0x28) != 0) {
    do {
      local_16c = 0;
      FUN_006ddcc0(param_2,&local_16c,4,0,uVar2);
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
      local_8 = 0;
      if (local_16c == 0) {
        FUN_00402c80(0,0xffffffff);
      }
      else {
        FUN_00429630(local_16c,0);
      }
      ppppuVar4 = (undefined4 ****)local_30[0];
      if (local_1c < 0x10) {
        ppppuVar4 = local_30;
      }
      FUN_006ddcc0(param_2,ppppuVar4,local_16c,local_16c >> 0x1f);
      FUN_00440c60();
      FUN_00842f30(local_154);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_15c = 0;
      FUN_006ddcc0(param_2,&local_15c,4,0);
      local_158 = (undefined1 *)0x0;
      if (local_15c != 0) {
        do {
          FUN_006ddcc0(param_2,local_180,4,0);
          FUN_006ddcc0(param_2,local_188,4,0);
          uVar3 = FUN_0057ef20();
          FUN_0057e850(local_154,uVar3);
          local_158 = (undefined1 *)((int)local_158 + 1);
          local_40 = 1;
        } while (local_158 < local_15c);
      }
      local_158 = local_144;
      local_164 = 8;
      do {
        FUN_006ddcc0(param_2,&local_15c,4,0);
        local_160 = 0;
        if (local_15c != 0) {
          do {
            FUN_006ddcc0(param_2,local_17c,4,0);
            FUN_006ddcc0(param_2,local_174,4,0);
            puVar1 = local_158;
            uVar3 = FUN_0057ef20();
            FUN_0057e850(puVar1,uVar3);
            local_160 = local_160 + 1;
            local_40 = 1;
          } while (local_160 < local_15c);
        }
        local_158 = local_158 + 0x10;
        local_164 = local_164 + -1;
      } while (local_164 != 0);
      local_158 = local_c4;
      local_160 = 8;
      local_164 = 0;
      do {
        FUN_006ddcc0(param_2,&local_15c,4,0);
        local_164 = 0;
        if (local_15c != 0) {
          do {
            FUN_006ddcc0(param_2,local_184,4,0);
            FUN_006ddcc0(param_2,local_178,4,0);
            puVar1 = local_158;
            uVar3 = FUN_0057ef20();
            FUN_0057e850(puVar1,uVar3);
            local_164 = local_164 + 1;
            local_40 = 1;
          } while (local_164 < local_15c);
        }
        local_158 = local_158 + 0x10;
        local_160 = local_160 - 1;
      } while (local_160 != 0);
      FUN_00866530();
      local_8._0_1_ = 4;
      FUN_00843650(local_154);
      local_8._0_1_ = 3;
      _eh_vector_destructor_iterator_(local_c4,0x10,8,FUN_00843020);
      local_8._0_1_ = 2;
      _eh_vector_destructor_iterator_(local_144,0x10,8,FUN_00843020);
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_005540c0(*local_150,local_150);
      FUN_0089120c(local_150);
      local_8 = 0xffffffff;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_170 = local_170 + 1;
    } while (local_170 < *(uint *)(local_168 + 0x28));
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

