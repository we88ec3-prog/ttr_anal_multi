
void FUN_0060dfd0(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *unaff_EDI;
  undefined2 auStack_7c [8];
  undefined4 uStack_6c;
  undefined *puStack_68;
  undefined4 local_54;
  undefined1 *local_50;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928ec6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  unaff_EDI[4] = 0;
  if (7 < (uint)unaff_EDI[5]) {
    unaff_EDI = (undefined4 *)*unaff_EDI;
  }
  *(undefined2 *)unaff_EDI = 0;
  if (in_ECX - 1U < 8) {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    local_8 = 0;
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00590760();
      puStack_68 = (undefined *)0x60e054;
      _atexit((_func_4879 *)&LAB_00bce760);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    puStack_68 = &DAT_00fdfb18;
    uStack_6c = 0x60e070;
    FUN_00594610();
    if (in_ECX == 8) {
      puStack_68 = &DAT_00c1ad60;
      uStack_6c = 0x60e084;
      FUN_00404300();
    }
    local_50 = (undefined1 *)auStack_7c;
    puStack_68 = (undefined *)0x7;
    uStack_6c = 0;
    auStack_7c[0] = 0;
    FUN_004026e0(local_30,0,0xffffffff);
    local_8._0_1_ = 2;
    local_54 = 0x1cb;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_54);
    if (local_50 == *(undefined1 **)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar3 = (undefined4 *)(local_50 + 0x10);
    if (7 < *(uint *)(local_50 + 0x24)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    local_8._0_1_ = 0;
    FUN_00424c80(puVar3);
    local_8 = CONCAT31(local_8._1_3_,3);
    puStack_68 = (undefined *)0x60e0ff;
    FUN_00402800();
    if (7 < local_38) {
      puStack_68 = (undefined *)0x60e112;
      FUN_0089120c();
    }
    if (7 < local_1c) {
      puStack_68 = (undefined *)0x60e123;
      FUN_0089120c();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

