
/* WARNING: Removing unreachable block (ram,0x0061ee2c) */

void FUN_0061eba0(void)

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
  
  puStack_c = &LAB_0092dd5a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  uStack_7 = 0;
  FUN_0061f070(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0xf8);
  FUN_0061f150();
  FUN_005a9f40(in_ECX + 0xfc);
  FUN_0061f230();
  FUN_005a9f40(in_ECX + 0x100);
  FUN_0040b670(in_ECX);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  local_14 = 0x23d;
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
  local_18 = 0x23e;
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
  local_18 = 0x23f;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  FUN_00757710();
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,0,*(undefined4 *)(in_ECX + 0xf8));
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,1,*(undefined4 *)(in_ECX + 0xfc));
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,2,*(undefined4 *)(in_ECX + 0x100));
  }
  FUN_00749920(*(undefined4 *)(in_ECX + 0xf4));
  (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  FUN_0040b5b0(0);
  ExceptionList = local_10;
  return;
}

