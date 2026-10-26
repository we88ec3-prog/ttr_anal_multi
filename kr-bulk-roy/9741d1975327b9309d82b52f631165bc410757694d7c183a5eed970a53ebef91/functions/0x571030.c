
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00571030(int param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_bc [4];
  int local_b8;
  int local_b4;
  int local_b0;
  undefined4 local_ac;
  uint local_a8;
  undefined4 local_98;
  uint local_94;
  undefined1 local_8c [56];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093fb34;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_bc;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff38;
  ExceptionList = &local_14;
  local_b0 = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  switch(DAT_00f9392c) {
  case 3:
  case 5:
  case 7:
  case 8:
  case 0x15:
  case 0x17:
  case 0x18:
  case 0x1b:
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    iVar5 = *(int *)(DAT_00f94300 + 0x2398);
    iVar6 = 0;
    if (0 < iVar5) {
      piVar3 = (int *)(DAT_00f94300 + 0x1720);
      do {
        if ((piVar3[1] == 0) && (*piVar3 == 0)) {
          iVar6 = iVar6 + 1;
        }
        piVar3 = piVar3 + 8;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    if (iVar6 == 0) {
      FUN_007572f0(&DAT_00bed1fc);
      local_c._1_3_ = 0;
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c._0_1_ = 3;
        local_c._1_3_ = 0;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
      }
      local_c._0_1_ = 2;
      local_b0 = 0xc2;
      FUN_005740f0(&local_b0);
      if (local_b8 == DAT_00fe5b10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar4 = FUN_004068f0();
      local_c._0_1_ = 4;
      FUN_007574a0(uVar4);
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c._0_1_ = 6;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
      }
      local_c._0_1_ = 5;
      FUN_007531a0(&DAT_00f94810,local_8c,local_54,0,0);
      local_c = CONCAT31(local_c._1_3_,4);
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
    else {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 7;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
      }
      local_c = 0xffffffff;
      FUN_008438c0(&local_b8);
      if ((local_b4 != DAT_00f8d91c) && (iVar5 = *(int *)(local_b4 + 0x10), iVar5 != 0)) {
        if ((DAT_00fe2878 & 1) == 0) {
          DAT_00fe2878 = DAT_00fe2878 | 1;
          local_c = 8;
          FUN_0052b6c0();
          _atexit((_func_4879 *)&LAB_00bcf300);
          local_c = 0xffffffff;
        }
        local_b4 = *(int *)(iVar5 + 0x20);
        FUN_008438c0(&local_b4);
        if (local_b8 == DAT_00fe2884) {
          uVar2 = 0;
        }
        else {
          _DAT_00fe287c = *(undefined4 *)(*(int *)(local_b8 + 0x10) + 4);
          uVar2 = *(uint *)(*(int *)(local_b8 + 0x10) + 4);
        }
        if ((DAT_00fe2878 & 1) == 0) {
          DAT_00fe2878 = DAT_00fe2878 | 1;
          local_c = 9;
          FUN_0052b6c0();
          _atexit((_func_4879 *)&LAB_00bcf300);
          local_c = 0xffffffff;
        }
        iVar5 = *(int *)(iVar5 + 0x20);
        local_b4 = iVar5;
        FUN_008438c0(&local_b4);
        if (local_b8 == DAT_00fe2884) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = *(undefined4 *)(*(int *)(local_b8 + 0x10) + 8);
        }
        if ((uVar2 < 3) && (piVar3 = *(int **)(local_b0 + uVar2 * 4), piVar3 != (int *)0x0)) {
          (**(code **)(*piVar3 + 0x28))(param_2,param_3,local_ac,iVar5,uVar4);
          *(int **)(local_b0 + 0xc) = piVar3;
          *(undefined4 *)(local_b0 + 0x10) = 1;
        }
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_bc);
  return;
}

