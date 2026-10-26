
void FUN_006ac1a0(void)

{
  code *pcVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c3da;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (int *)0xb;
  FUN_0082ef00(&local_14);
  if (local_18 == *(int **)(in_ECX + 0x50)) {
    iVar4 = 0;
  }
  else {
    iVar4 = local_18[4];
  }
  local_18 = (int *)(in_ECX + 0xec);
  *(int *)(in_ECX + 0x80) = iVar4;
  FUN_006ad0e0(uVar3);
  FUN_0043c570(500);
  local_1c = in_ECX + 0x144;
  FUN_0043c570(600);
  FUN_0043c570(700);
  piVar2 = local_18;
  if (*(int *)(*local_18 + 0xcc) != 0) {
    *(undefined1 *)(*(int *)(*local_18 + 0xcc) + 0xe0) = 0;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = (int *)0x2ae;
  FUN_005740f0(&local_18);
  if (local_14 != DAT_00fe5ac8) {
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = (int *)0x2af;
    FUN_005740f0(&local_18);
    if (local_14 != DAT_00fe5ac8) {
      FUN_00757710();
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 2;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      local_1c = 0x2b0;
      FUN_005740f0(&local_1c);
      if (local_18 != DAT_00fe5ac8) {
        FUN_00757710();
        *(undefined4 *)(*piVar2 + 0xd4) = 0;
        FUN_00749920(*piVar2);
        (**(code **)(*(int *)*piVar2 + 200))();
        ExceptionList = local_10;
        return;
      }
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

