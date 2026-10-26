
void FUN_00653d90(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 *puVar4;
  bool bVar5;
  int local_38;
  int local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092d034;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007459c0(local_14);
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00653df8;
    iVar2 = FUN_00745c20();
  }
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) &&
      ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar2 + 0x60) != 0)) {
    FUN_0074a010(iVar2);
  }
LAB_00653df8:
  iVar2 = DAT_00fe1aa4;
  uVar3 = FUN_0040ef80();
  local_8 = 0;
  FUN_00757800(uVar3);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  uVar3 = FUN_0040ef80();
  local_8 = 1;
  FUN_00757800(uVar3);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  uVar3 = FUN_0040ef80();
  local_8 = 2;
  FUN_00757800(uVar3);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  uVar3 = FUN_0040ef80();
  local_8 = 3;
  FUN_00757800(uVar3);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  uVar3 = FUN_0040ef80();
  local_8 = 4;
  FUN_00757800(uVar3);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  puVar4 = (undefined4 *)(in_ECX + 0xf4);
  local_34 = 5;
  do {
    (**(code **)(*(int *)*puVar4 + 200))();
    puVar4 = puVar4 + 1;
    local_34 = local_34 + -1;
  } while (local_34 != 0);
  bVar5 = *(char *)(iVar2 + 0x1c) != '\x01';
  *(bool *)(in_ECX + 0x130) = bVar5;
  if (bVar5) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 5;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_34 = 0x15a;
    FUN_005740f0(&local_34);
    if (local_38 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
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
    local_38 = 0x159;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  FUN_00757710();
  (**(code **)(**(int **)(in_ECX + 0xf0) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

