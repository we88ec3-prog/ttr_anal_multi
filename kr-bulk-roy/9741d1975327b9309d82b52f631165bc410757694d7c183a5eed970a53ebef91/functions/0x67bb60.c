
void FUN_0067bb60(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 ***pppuVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_70;
  int local_6c;
  undefined4 **local_68 [5];
  uint local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932f32;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    iVar2 = *(int *)(in_ECX + 0xf4);
    *(undefined4 *)(iVar2 + 0x98) = *(undefined4 *)(iVar2 + 0xa0);
    *(undefined4 *)(iVar2 + 0x94) = 2;
    *(undefined4 *)(iVar2 + 0xa8) = 0;
    *(undefined4 *)(iVar2 + 0xb0) = 0;
    *(undefined4 *)(iVar2 + 0x90) = 0;
    FUN_0068a590();
    local_1c = 0xf;
    local_20 = 0;
    local_30 = local_30 & 0xffffff00;
    FUN_0040b310("WEAPON_LEVELUP_SUCCESS");
    local_8 = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    piVar1 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))();
    }
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30);
    }
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 2;
      FUN_0051c120();
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_8 = 0xffffffff;
    }
    local_6c = param_2;
    FUN_008438c0(&local_6c);
    if ((local_70 != DAT_00f8d91c) && (piVar1 = *(int **)(local_70 + 0x10), piVar1 != (int *)0x0)) {
      local_70 = piVar1[8];
      iVar2 = FUN_004034e0();
      FUN_008438c0(&local_70);
      if ((local_6c != *(int *)(iVar2 + 4)) && (*(int *)(local_6c + 0x10) != 0)) {
        if (7 < (uint)piVar1[5]) {
          piVar1 = (int *)*piVar1;
        }
        uVar5 = 0xde;
        FUN_005854b0(0xde,piVar1);
        FUN_00585330(uVar5);
        FUN_0067d6a0();
        local_8 = 3;
        pppuVar3 = (undefined4 ***)local_68[0];
        if (local_54 < 8) {
          pppuVar3 = local_68;
        }
        uVar5 = 0x196;
        FUN_005854b0(0x196,0,0);
        uVar5 = FUN_00585330(uVar5);
        FUN_00404b10(0xca,pppuVar3,uVar5);
        if (7 < local_54) {
          FUN_0089120c(local_68[0]);
        }
      }
    }
    goto LAB_0067be7b;
  }
  if (param_1 == 1) {
    iVar2 = *(int *)(in_ECX + 0xf4);
    *(undefined4 *)(iVar2 + 0x98) = *(undefined4 *)(iVar2 + 0xa0);
    *(undefined4 *)(iVar2 + 0x94) = 2;
    *(undefined4 *)(iVar2 + 0xa8) = 1;
    *(undefined4 *)(iVar2 + 0xb0) = 0;
    *(undefined4 *)(iVar2 + 0x90) = 0;
    FUN_0068a540();
    local_38 = 0xf;
    local_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_0040b310("WEAPON_LEVELUP_FAILED");
    local_8 = 4;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 5;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = CONCAT31(local_8._1_3_,4);
    }
    piVar1 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))();
    }
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    goto LAB_0067be7b;
  }
  if (param_1 == 5) {
    uVar5 = 0x196;
    FUN_005854b0(0x196,0,0,local_14);
    uVar5 = FUN_00585330(uVar5);
    uVar4 = 0xb;
LAB_0067be56:
    FUN_005854b0(uVar4,uVar5);
    uVar5 = FUN_00585330(uVar4);
    FUN_00404b10(0xca,uVar5);
  }
  else if (param_1 == 0x12) {
    uVar5 = 0x196;
    FUN_005854b0(0x196,0,0,local_14);
    uVar5 = FUN_00585330(uVar5);
    uVar4 = 0xe8;
    goto LAB_0067be56;
  }
  FUN_0068a350();
LAB_0067be7b:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

