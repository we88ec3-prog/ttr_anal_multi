
void FUN_006064d0(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  undefined1 auStack_60 [20];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  undefined4 local_38;
  undefined1 *local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092df5e;
  local_10 = ExceptionList;
  uStack_44 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uStack_48 = *(undefined4 *)(unaff_EDI + 0x248);
  uStack_4c = 0x606507;
  local_14 = uStack_44;
  FUN_005d77e0();
  local_34 = auStack_60;
  FUN_00412df0();
  local_8 = 0;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_38 = 0x1a;
  FUN_005740f0(&local_38);
  if (local_34 != DAT_00fe5ac8) {
    puVar2 = (undefined4 *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    local_8 = 0xffffffff;
    uStack_48 = FUN_00424c80(puVar2);
    local_8 = 2;
    uStack_4c = 0x6065aa;
    FUN_00757800();
    if (7 < local_1c) {
      uStack_48 = local_30;
      uStack_4c = 0x6065b9;
      FUN_0089120c();
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

