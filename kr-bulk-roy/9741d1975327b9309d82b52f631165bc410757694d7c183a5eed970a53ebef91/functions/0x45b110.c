
void FUN_0045b110(undefined4 param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int local_78;
  int local_74;
  undefined1 local_70 [16];
  int local_60;
  int local_5c;
  undefined4 local_58;
  uint local_44;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941786;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0045b670(local_70,param_1);
  local_8 = 0;
  if ((local_60 == -1) || (local_5c == -1)) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    local_78 = 0x1b2;
    FUN_005740f0(&local_78);
    if (local_74 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_0045b330();
  }
  else {
    local_74 = local_5c;
    iVar3 = FUN_00459c20(uVar2);
    FUN_008438c0(&local_74);
    if ((local_78 != *(int *)(iVar3 + 8)) && (0 < *(int *)(local_78 + 0x10))) {
      if (7 < local_44) {
        FUN_0089120c(local_58);
      }
      goto LAB_0045b275;
    }
    local_74 = 0x1b2;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&local_74);
    if (local_78 == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_0045b330();
  }
  if (7 < local_44) {
    FUN_0089120c(local_58);
  }
LAB_0045b275:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

