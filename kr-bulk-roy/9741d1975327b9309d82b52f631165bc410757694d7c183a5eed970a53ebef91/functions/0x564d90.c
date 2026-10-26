
void FUN_00564d90(char *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int local_54;
  int local_50;
  uint local_4c [4];
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
  puStack_c = &LAB_0091ff0c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30 = local_30 & 0xffffff00;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_0040b310(param_1);
  local_8 = 0;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0080a3a0(uVar2);
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
  if (piVar4 == (int *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (**(code **)(*piVar4 + 0x14))();
  }
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30 = local_30 & 0xffffff00;
  if (iVar5 != 0) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffffff00;
    FUN_0040b310("Voice");
    local_8 = 2;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    local_54 = FUN_0080c1c0(local_4c);
    if ((local_54 == DAT_00fab054) || (cVar1 = FUN_005436a0(), cVar1 != '\0')) {
      local_50 = DAT_00fab054;
      piVar4 = &local_50;
    }
    else {
      piVar4 = &local_54;
    }
    uVar6 = DAT_00fab04c;
    if (*piVar4 != DAT_00fab054) {
      uVar6 = *(undefined4 *)(*piVar4 + 0x28);
    }
    *(undefined4 *)(*(int *)(iVar5 + 4) + 8) = uVar6;
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

