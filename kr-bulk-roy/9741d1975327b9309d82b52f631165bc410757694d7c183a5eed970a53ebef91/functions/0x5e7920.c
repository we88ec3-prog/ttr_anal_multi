
void FUN_005e7920(undefined4 param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f85a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = 0xffffffff;
    local_14 = 0x256;
    FUN_005740f0(&local_14);
    if (local_18 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar2 = (undefined4 *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (in_ECX != 0) {
      FUN_005e47e0(param_1,puVar2);
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 599;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar2 = (undefined4 *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (param_3 != 0) {
      FUN_005e47e0(param_1,puVar2);
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 2;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 600;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar2 = (undefined4 *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (param_4 != 0) {
      FUN_005e47e0(param_1,puVar2);
    }
  }
  ExceptionList = local_10;
  return;
}

