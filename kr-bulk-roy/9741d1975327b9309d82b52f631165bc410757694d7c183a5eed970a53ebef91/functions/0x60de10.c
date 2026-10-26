
void FUN_0060de10(void)

{
  float fVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EDI;
  int local_3c;
  int local_38;
  float local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092de84;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fc1094 & 1) == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 0;
    FUN_0052f7e0(local_14);
    _atexit((_func_4879 *)&LAB_00bcdc80);
  }
  local_8 = 0xffffffff;
  iVar3 = FUN_005306e0(&DAT_00fc1098);
  local_34 = (float)iVar3;
  *(undefined4 *)(*(int *)(unaff_EDI + 0x18c) + 0x154) = 0xffffffff;
  local_38 = *(int *)(unaff_EDI + 0x1b8);
  if ((local_38 != 0) || (*(float *)(unaff_EDI + 0x1bc) != 0.0)) {
    fVar1 = *(float *)(unaff_EDI + 0x1bc);
    *(undefined4 *)(*(int *)(unaff_EDI + 0x18c) + 0x154) = 0xff5aff78;
    local_34 = (((float)local_38 + local_34) * fVar1) / 100.0 + (float)local_38 + local_34;
  }
  if (0.0 < local_34) {
    local_34 = local_34 / 10.0;
  }
  if (*(char *)(unaff_EDI + 0x160) == '\0') {
    local_34 = 0.0;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_38 = 0x1d4;
  FUN_005740f0(&local_38);
  if (local_3c != DAT_00fe5ac8) {
    uVar4 = FUN_00438510(local_34);
    local_8 = 2;
    FUN_00757800(uVar4);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

