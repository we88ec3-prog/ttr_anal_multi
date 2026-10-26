
void FUN_004b5c10(int param_1)

{
  short sVar1;
  short sVar2;
  code *pcVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_00936c9c;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  piVar5 = (int *)FUN_0040f060(uVar4);
  sVar1 = *(short *)(param_1 + 2);
  sVar2 = *(short *)(*piVar5 + 0x5eb4);
  if (sVar1 != sVar2) {
    piVar5 = (int *)FUN_0040f060(uVar4);
    *(undefined2 *)(*piVar5 + 0x5eb4) = *(undefined2 *)(param_1 + 2);
    if ((short)(sVar1 - sVar2) < 1) {
      local_50 = 0x75;
      iVar6 = FUN_005855b0();
      FUN_005740f0(&local_50);
      if (local_54 == *(int *)(iVar6 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      uVar7 = FUN_004068f0();
      local_8 = 2;
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 3;
        local_8._1_3_ = 0;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = CONCAT31(local_8._1_3_,2);
      }
      FUN_004d6b30(uVar7);
    }
    else {
      local_54 = 0x74;
      iVar6 = FUN_005855b0();
      FUN_005740f0(&local_54);
      if (local_50 == *(int *)(iVar6 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      uVar7 = FUN_004330b0();
      local_8 = 0;
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 1;
        local_8._1_3_ = 0;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = (uint)local_8._1_3_ << 8;
      }
      FUN_004d6b30(uVar7);
      local_30 = local_4c;
      local_1c = local_38;
    }
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

