
void FUN_0040a3c0(void)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int in_ECX;
  int iVar9;
  int *piVar10;
  undefined1 *puVar11;
  undefined1 auStack_15c [4];
  undefined4 *local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  uint local_134;
  undefined4 local_124;
  uint local_120;
  uint local_118;
  undefined4 local_108;
  uint local_104;
  undefined1 local_fc [56];
  undefined1 local_c4 [56];
  undefined1 local_8c [56];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00942147;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_15c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffe98;
  ExceptionList = &local_14;
  iVar9 = *(int *)(*(int *)(in_ECX + 0x100) + 0xf4) - *(int *)(*(int *)(in_ECX + 0x100) + 0xf0) >> 2
  ;
  local_14c = 0;
  local_158 = (undefined4 *)0x0;
  local_144 = 0;
  local_148 = in_ECX;
  if (0 < iVar9) {
    do {
      iVar4 = local_144;
      uVar8 = *(undefined4 *)(local_148 + 0x100);
      cVar2 = FUN_00408780(uVar8,local_144);
      if (cVar2 != '\0') {
        iVar4 = FUN_004084f0(uVar8,iVar4);
        iVar5 = FUN_00408580(uVar8,local_144);
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 0;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        if ((iVar4 == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
          if (iVar5 - 1U < 100) {
            piVar10 = (int *)(iVar5 * 0x20 + DAT_00f94300 + 0x16f8);
            if (((piVar10[3] != 0) && (piVar10[2] != 0)) && (piVar10 != (int *)0x0)) {
              if ((DAT_00faaffc & 1) == 0) {
                DAT_00faaffc = DAT_00faaffc | 1;
                local_c = 1;
                FUN_008132e0();
                _atexit((_func_4879 *)&LAB_00bccce0);
                local_c = 0xffffffff;
              }
              local_154 = *piVar10;
              piVar6 = (int *)FUN_008438c0(&local_154);
              if (*piVar6 == DAT_00fab014) {
                iVar4 = 0;
              }
              else {
                iVar4 = *(int *)(*piVar6 + 0x10);
              }
              local_14c = local_14c + iVar4;
              if (local_158 == (undefined4 *)0x0) {
                local_140 = piVar10[4];
                local_13c = piVar10[5];
                iVar4 = FUN_00409560();
                FUN_004dd400(iVar4,&local_150,&local_140);
                if ((local_150 != *(int *)(iVar4 + 4)) && (*(int *)(local_150 + 0x18) != 0)) {
                  local_158 = (undefined4 *)(uint)(0 < *(int *)(*(int *)(local_150 + 0x18) + 0x30));
                }
              }
            }
          }
          else {
            FUN_006edb60(&DAT_00c0ddc0);
          }
        }
      }
      local_144 = local_144 + 1;
    } while (local_144 < iVar9);
    if (local_158 != (undefined4 *)0x0) {
      local_158 = (undefined4 *)FUN_00891268(0x18,uVar3);
      if (local_158 == (undefined4 *)0x0) {
        local_158 = (undefined4 *)0x0;
      }
      else {
        local_158[1] = 0xffffffff;
        local_158[2] = 0xffffffff;
        local_158[3] = 0;
        local_158[4] = 0xf442e;
        *local_158 = FoxUI::FXUIEventI1::vftable;
        local_158[5] = local_14c;
      }
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c = 2;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
        local_c = 0xffffffff;
      }
      local_150 = 0x196;
      FUN_005740f0(&local_150);
      if (local_154 == DAT_00fe5b10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar7 = (undefined4 *)(local_154 + 0x10);
      if (7 < *(uint *)(local_154 + 0x24)) {
        puVar7 = (undefined4 *)*puVar7;
      }
      FUN_007572f0(puVar7);
      local_c._1_3_ = 0;
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c._0_1_ = 4;
        local_c._1_3_ = 0;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
      }
      local_c._0_1_ = 3;
      local_150 = 0x1dc;
      FUN_005740f0(&local_150);
      if (local_154 == DAT_00fe5b10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar8 = FUN_0040aff0();
      local_c._0_1_ = 5;
      FUN_007574a0(uVar8);
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c._0_1_ = 7;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
      }
      local_c._0_1_ = 6;
      FUN_007531a0(&DAT_00f94810,local_fc,local_8c,local_158,local_148);
      local_c = CONCAT31(local_c._1_3_,5);
      FUN_00757640(local_fc);
      if (7 < local_120) {
        FUN_0089120c(local_134);
      }
      puVar11 = local_8c;
      local_120 = 7;
      local_124 = 0;
      local_134 = local_134 & 0xffff0000;
      goto LAB_0040a9de;
    }
  }
  local_158 = (undefined4 *)FUN_00891268(0x14,uVar3);
  if (local_158 == (undefined4 *)0x0) {
    local_158 = (undefined4 *)0x0;
  }
  else {
    *local_158 = FoxUI::FXUIEvent::vftable;
    local_158[1] = 0xffffffff;
    local_158[2] = 0xffffffff;
    local_158[3] = 0;
    local_158[4] = 0xf442d;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 8;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_c = 0xffffffff;
  }
  local_150 = 0x196;
  FUN_005740f0(&local_150);
  if (local_154 == DAT_00fe5b10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar7 = (undefined4 *)(local_154 + 0x10);
  if (7 < *(uint *)(local_154 + 0x24)) {
    puVar7 = (undefined4 *)*puVar7;
  }
  FUN_007572f0(puVar7);
  local_c._1_3_ = 0;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 10;
    local_c._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  local_c._0_1_ = 9;
  local_150 = 0x1db;
  FUN_005740f0(&local_150);
  if (local_154 == DAT_00fe5b10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  uVar8 = FUN_004068f0();
  local_c._0_1_ = 0xb;
  FUN_007574a0(uVar8);
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c._0_1_ = 0xd;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_c._0_1_ = 0xc;
  FUN_007531a0(&DAT_00f94810,local_c4,local_54,local_158,local_148);
  local_c = CONCAT31(local_c._1_3_,0xb);
  FUN_00757640(local_c4);
  if (7 < local_104) {
    FUN_0089120c(local_118);
  }
  puVar11 = local_54;
  local_104 = 7;
  local_108 = 0;
  local_118 = local_118 & 0xffff0000;
LAB_0040a9de:
  local_c = 0xffffffff;
  FUN_00757640(puVar11);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_15c);
  return;
}

