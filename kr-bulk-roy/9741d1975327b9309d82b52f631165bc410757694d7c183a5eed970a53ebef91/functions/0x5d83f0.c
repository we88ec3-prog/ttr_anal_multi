
void FUN_005d83f0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_EDI;
  int local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f23a;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(unaff_EDI + 0x2b0) == -1) {
    if (*(int *)(unaff_EDI + 0x2b4) == 0) {
      FUN_00757710(local_14);
      goto LAB_005d8644;
    }
    local_50 = 0x33c;
    iVar3 = FUN_00585620();
    FUN_005740f0(&local_50);
    if (local_54 == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar4 = (uint)*(byte *)(unaff_EDI + 0x2b4);
    FUN_0048a930(uVar4);
    FUN_0082b710(uVar4);
    uVar2 = FUN_004ed610();
    local_8 = 4;
    FUN_00757800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    iVar3 = FUN_00404ba0();
    if (*(int *)(unaff_EDI + 0x2b4) <= *(int *)(iVar3 + 0x68cc)) {
      *(undefined4 *)(*(int *)(unaff_EDI + 0x29c) + 0x154) = 0xffffffff;
      goto LAB_005d8644;
    }
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = 0xffffffff;
    local_54 = 0x33b;
    FUN_005740f0(&local_54);
    if (local_50 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar2 = FUN_004068f0();
    local_8 = 1;
    FUN_00757800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    if ((DAT_00fbad10 & 1) == 0) {
      DAT_00fbad10 = DAT_00fbad10 | 1;
      local_8 = 2;
      FUN_004e8010();
      _atexit((_func_4879 *)&LAB_00bcd6b0);
      local_8 = 0xffffffff;
    }
    if (DAT_00fc0bd8 != 0) {
      if ((DAT_00fbad10 & 1) == 0) {
        DAT_00fbad10 = DAT_00fbad10 | 1;
        local_8 = 3;
        FUN_004e8010();
        _atexit((_func_4879 *)&LAB_00bcd6b0);
      }
      if (*(int *)(unaff_EDI + 0x2b0) <= DAT_00fc0be8) {
        *(undefined4 *)(*(int *)(unaff_EDI + 0x29c) + 0x154) = 0xffffffff;
        goto LAB_005d8644;
      }
    }
  }
  *(undefined4 *)(*(int *)(unaff_EDI + 0x29c) + 0x154) = 0xffff0000;
LAB_005d8644:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

