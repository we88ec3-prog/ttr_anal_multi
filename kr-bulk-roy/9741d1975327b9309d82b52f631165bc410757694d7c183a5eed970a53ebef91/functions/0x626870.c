
/* WARNING: Removing unreachable block (ram,0x00626bd3) */

void FUN_00626870(void)

{
  int iVar1;
  code *pcVar2;
  int in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0092d428;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  uStack_7 = 0;
  FUN_00627b70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0x10c);
  FUN_00627c50();
  FUN_005a9f40(in_ECX + 0x110);
  FUN_00627d30();
  FUN_005a9f40(in_ECX + 0x114);
  FUN_00627e10();
  FUN_005a9f40(in_ECX + 0x118);
  FUN_0040b670(in_ECX);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  local_14 = 0x244;
  FUN_005740f0(&local_14);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  local_18 = 0x245;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 4;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  local_18 = 0x246;
  FUN_005740f0(&local_18);
  if (local_14 != DAT_00fe5ac8) {
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 5;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 1;
    }
    local_18 = 0x247;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00757710();
    *(int *)(*(int *)(in_ECX + 0x10c) + 0x110) = in_ECX;
    *(int *)(*(int *)(in_ECX + 0x110) + 0x110) = in_ECX;
    *(int *)(*(int *)(in_ECX + 0x114) + 0x110) = in_ECX;
    *(int *)(*(int *)(in_ECX + 0x118) + 0x110) = in_ECX;
    iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
    if (iVar1 != 0) {
      FUN_0040acb0(iVar1,0,*(undefined4 *)(in_ECX + 0x10c));
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
    if (iVar1 != 0) {
      FUN_0040acb0(iVar1,1,*(undefined4 *)(in_ECX + 0x110));
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
    if (iVar1 != 0) {
      FUN_0040acb0(iVar1,2,*(undefined4 *)(in_ECX + 0x114));
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
    if (iVar1 != 0) {
      FUN_0040acb0(iVar1,3,*(undefined4 *)(in_ECX + 0x118));
    }
    FUN_00749920(*(undefined4 *)(in_ECX + 0xf8));
    (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
    FUN_0040b5b0(0);
    ExceptionList = local_10;
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

