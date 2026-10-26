
void FUN_0080dbe0(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *unaff_EDI;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009184e6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (0xf < *(uint *)(unaff_EDI + 0x14)) {
    unaff_EDI = *(char **)unaff_EDI;
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar3 = unaff_EDI;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(unaff_EDI,(int)pcVar3 - (int)(unaff_EDI + 1));
  local_8 = 0;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0080a3a0(uVar2);
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  FUN_0080d8e0(param_1,local_30,DAT_00fab048);
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  *param_1 = MoonSound::SoundFile::vftable;
  param_1[1] = MoonSound::SoundFile::vftable;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

