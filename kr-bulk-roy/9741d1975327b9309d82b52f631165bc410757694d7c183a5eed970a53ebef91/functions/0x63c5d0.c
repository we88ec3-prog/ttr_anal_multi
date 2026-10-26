
void FUN_0063c5d0(void)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092d23a;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0xb;
  FUN_0082ef00(&local_14);
  if (local_18 == *(int *)(in_ECX + 0x50)) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(local_18 + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar5;
  FUN_0062dd00(uVar4);
  FUN_00615fc0(300);
  FUN_00615fc0(400);
  FUN_00615fc0(500);
  FUN_0063d100();
  piVar1 = (int *)(in_ECX + 0x100);
  FUN_0063d1f0();
  if ((*(int *)(*piVar1 + 0x24c) != 0) &&
     (iVar2 = *(int *)(*(int *)(*piVar1 + 0x24c) + 0xcc), iVar2 != 0)) {
    FUN_006438f0(iVar2);
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x141;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  puVar6 = (undefined4 *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    puVar6 = (undefined4 *)*puVar6;
  }
  FUN_0075cbb0(puVar6);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x142;
  FUN_005740f0(&local_18);
  if (local_14 != DAT_00fe5ac8) {
    puVar6 = (undefined4 *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      puVar6 = (undefined4 *)*puVar6;
    }
    FUN_0075cbb0(puVar6);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 2;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 0x143;
    FUN_005740f0(&local_18);
    if (local_14 != DAT_00fe5ac8) {
      puVar6 = (undefined4 *)(local_14 + 0x10);
      if (7 < *(uint *)(local_14 + 0x24)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      FUN_0075cbb0(puVar6);
      if (*(int *)(*piVar1 + 0x24c) != 0) {
        FUN_00749920(*(int *)(*piVar1 + 0x24c));
      }
      (**(code **)(*(int *)*piVar1 + 200))();
      ExceptionList = local_10;
      return;
    }
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}

