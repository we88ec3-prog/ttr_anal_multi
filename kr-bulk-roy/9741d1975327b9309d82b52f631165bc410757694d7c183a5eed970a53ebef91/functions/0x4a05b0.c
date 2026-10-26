
void FUN_004a05b0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  undefined4 extraout_EDX;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927886;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = param_1;
  FUN_0089289d(local_14);
  iVar2 = FUN_0049fd10("Voice/Macro/M%05d_%02d_%02d.ogg");
  if ((iVar2 != 0) || (iVar2 = FUN_0049fd10("Voice/Macro/M%05d_%02d_01.ogg"), iVar2 != 0)) {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffffff00;
    FUN_0040b310("Voice");
    local_8 = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    local_40 = FUN_0080c1c0(local_30);
    if ((local_40 == DAT_00fab054) || (cVar1 = FUN_005436a0(), cVar1 != '\0')) {
      local_3c = DAT_00fab054;
      piVar3 = &local_3c;
    }
    else {
      piVar3 = &local_40;
    }
    uVar5 = DAT_00fab04c;
    if (*piVar3 != DAT_00fab054) {
      uVar5 = *(undefined4 *)(*piVar3 + 0x28);
    }
    local_8 = 0xffffffff;
    *(undefined4 *)(iVar2 + 8) = uVar5;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  puVar4 = (undefined1 *)FUN_004a0740(local_34);
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  FUN_0049fe30(puVar4 + 4);
  *puVar4 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,extraout_EDX,uVar5,uVar6,uVar7);
  return;
}

