
void FUN_006ba400(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int unaff_EDI;
  int local_38;
  int local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092c062;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_8 = 0xffffffff;
  local_34 = 0x2c6;
  FUN_005740f0(&local_34);
  if (local_38 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  FUN_00757710(uVar4);
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 200))();
  iVar3 = DAT_00fe18f8;
  local_34 = *(int *)(DAT_00fe18f8 + 0x2e);
  iVar1 = *(int *)(DAT_00fe18f8 + 0x2a);
  uVar5 = FUN_0040ef80();
  local_8 = 1;
  FUN_00757800(uVar5);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  uVar5 = FUN_0040ef80();
  local_8 = 2;
  FUN_00757800(uVar5);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  uVar5 = FUN_0040ef80();
  local_8 = 3;
  FUN_00757800(uVar5);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  uVar5 = FUN_0040ef80();
  local_8 = 4;
  FUN_00757800(uVar5);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  uVar5 = FUN_0040ef80();
  local_8 = 5;
  FUN_00757800(uVar5);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  puVar6 = (undefined4 *)(unaff_EDI + 0xf8);
  local_34 = 4;
  do {
    (**(code **)(*(int *)*puVar6 + 200))();
    puVar6 = puVar6 + 1;
    local_34 = local_34 + -1;
  } while (local_34 != 0);
  if (*(char *)(iVar3 + 0x24) == '\0') {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 7;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_34 = 0x159;
    FUN_005740f0(&local_34);
    if (iVar1 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 6;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_34 = 0x15a;
    FUN_005740f0(&local_34);
    if (iVar1 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0xf0) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

