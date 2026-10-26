
/* WARNING: Removing unreachable block (ram,0x0061a28a) */

void FUN_00619f50(void)

{
  int iVar1;
  code *pcVar2;
  int in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092dd5a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_0061a5e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0xf8);
  FUN_0061a6c0();
  FUN_005a9f40(in_ECX + 0xfc);
  FUN_0061a7a0();
  FUN_005a9f40(in_ECX + 0x100);
  FUN_0040b670(in_ECX);
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
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  local_14 = 0x2dc;
  FUN_005740f0(&local_14);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(int *)(*(int *)(in_ECX + 0xf4) + 0xd8) != 0) {
    local_18 = 0;
    FUN_0082ef00(&local_18);
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  local_18 = 0x2cb;
  FUN_005740f0(&local_18);
  if (local_14 != DAT_00fe5ac8) {
    if (*(int *)(*(int *)(in_ECX + 0xf4) + 0xd8) != 0) {
      local_18 = 1;
      FUN_0082ef00(&local_18);
    }
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 4;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    local_18 = 0x2dd;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(int *)(*(int *)(in_ECX + 0xf4) + 0xd8) != 0) {
      local_18 = 2;
      FUN_0082ef00(&local_18);
    }
    FUN_00757710();
    FUN_00749920(*(undefined4 *)(in_ECX + 0xf4));
    (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
    FUN_0040b5b0(0);
    ExceptionList = local_10;
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

