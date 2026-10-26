
/* WARNING: Removing unreachable block (ram,0x0069d19c) */

void FUN_0069cf90(void)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00935acc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_0069d7c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0x100);
  FUN_0069d8a0();
  FUN_005a9f40(in_ECX + 0xfc);
  FUN_0040b670(in_ECX);
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 2;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  local_14 = 0xc9;
  FUN_005740f0(&local_14);
  if (local_18 != DAT_00fe5b10) {
    FUN_00757710();
    iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
    if (iVar1 != 0) {
      FUN_0040acb0(iVar1,0,*(undefined4 *)(in_ECX + 0xfc));
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
    if (iVar1 != 0) {
      FUN_0040acb0(iVar1,1,*(undefined4 *)(in_ECX + 0x100));
    }
    FUN_00749920(*(undefined4 *)(in_ECX + 0xf8));
    (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
    FUN_0040b5b0(0);
    uVar3 = DAT_00fe5b2c & 1;
    *(undefined4 *)(in_ECX + 0xf4) = 0;
    if (uVar3 == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 3;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    local_18 = 0xcc;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00757710();
    (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
    FUN_006a0110(*(undefined4 *)(in_ECX + 0xfc));
    ExceptionList = local_10;
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

