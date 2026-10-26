
void FUN_00678ef0(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int local_5c;
  int local_58;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = -1;
  puStack_10 = &LAB_0092ca3e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_5c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  if (param_1 == 0) {
    iVar3 = *(int *)(in_ECX + 0xf4);
    *(undefined4 *)(iVar3 + 0x98) = 0x3f666666;
    *(undefined4 *)(iVar3 + 0x94) = 2;
    *(undefined4 *)(iVar3 + 0xa8) = 0;
    *(undefined4 *)(iVar3 + 0xb0) = 0;
    *(undefined4 *)(iVar3 + 0x90) = 0;
    FUN_0068a590(uVar2);
    local_40 = 0xf;
    local_44 = 0;
    local_54 = local_54 & 0xffffff00;
    FUN_0040b310("SUCCESS_DISMANTLEITEM");
    local_c = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c = (uint)local_c._1_3_ << 8;
    }
    piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))();
    }
    if (0xf < local_40) {
      FUN_0089120c(local_54);
    }
  }
  else {
    if (param_1 == 9) {
      local_5c = 0xc2;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&local_5c);
      if (local_58 == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      FUN_004068f0();
      local_c = 2;
      FUN_00679d40();
      local_c = -1;
      if (7 < uStack_24) {
        FUN_0089120c(local_38);
      }
      uStack_24 = 7;
      uStack_28 = 0;
      local_38 = local_38 & 0xffff0000;
    }
    else {
      local_58 = 0xc0;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&local_58);
      if (local_5c == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (*(uint *)(local_5c + 0x24) < 8) {
        FUN_00679d40();
      }
      else {
        FUN_00679d40();
      }
    }
    iVar3 = *(int *)(in_ECX + 0xf4);
    *(undefined4 *)(iVar3 + 0x94) = 2;
    *(undefined4 *)(iVar3 + 0xa8) = 3;
    *(undefined4 *)(iVar3 + 0xb0) = 0;
    *(undefined4 *)(iVar3 + 0x90) = 0;
    *(undefined4 *)(iVar3 + 0x98) = 0;
    FUN_00679310();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_5c);
  return;
}

