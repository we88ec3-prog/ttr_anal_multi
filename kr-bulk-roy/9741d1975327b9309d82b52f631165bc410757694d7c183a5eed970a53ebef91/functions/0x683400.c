
/* WARNING: Removing unreachable block (ram,0x00683a5c) */

void FUN_00683400(void)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  int in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0092c97e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  uStack_7 = 0;
  uVar1 = *(undefined4 *)(in_ECX + 0x10c);
  FUN_00684140(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(uVar1);
  iVar2 = *(int *)(in_ECX + 0x10c);
  FUN_00684220();
  FUN_005a9f40(iVar2 + 4);
  iVar2 = *(int *)(in_ECX + 0x10c);
  FUN_00684300();
  FUN_005a9f40(iVar2 + 8);
  iVar2 = *(int *)(in_ECX + 0x10c);
  FUN_006843e0();
  FUN_005a9f40(iVar2 + 0xc);
  iVar2 = *(int *)(in_ECX + 0x10c);
  FUN_006844c0();
  FUN_005a9f40(iVar2 + 0x10);
  iVar2 = *(int *)(in_ECX + 0x10c);
  FUN_006845a0();
  FUN_005a9f40(iVar2 + 0x14);
  iVar2 = *(int *)(in_ECX + 0x10c);
  FUN_00684680();
  FUN_005a9f40(iVar2 + 0x1c);
  iVar2 = *(int *)(in_ECX + 0x10c);
  FUN_00684760();
  FUN_005a9f40(iVar2 + 0x20);
  iVar2 = *(int *)(in_ECX + 0x10c);
  FUN_00684840();
  FUN_005a9f40(iVar2 + 0x18);
  FUN_0040b670(0);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  local_14 = 0x332;
  FUN_005740f0(&local_14);
  if (local_18 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
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
  local_18 = 0x339;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
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
  local_18 = 0x33a;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 5;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  local_18 = 0x335;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 6;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  local_18 = 0x336;
  FUN_005740f0(&local_18);
  if (local_14 != DAT_00fe5ac8) {
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 7;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 1;
    }
    local_18 = 0x337;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 8;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 1;
    }
    local_18 = 0x334;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 9;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 1;
    }
    local_18 = 0x333;
    FUN_005740f0(&local_18);
    if (local_14 != DAT_00fe5ac8) {
      FUN_00757710();
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 10;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 1;
      }
      local_18 = 0x338;
      FUN_005740f0(&local_18);
      if (local_14 == DAT_00fe5ac8) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_00757710();
      **(undefined4 **)(in_ECX + 0x11c) = *(undefined4 *)(**(int **)(in_ECX + 0x10c) + 0x80);
      *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 4) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10c) + 4) + 0x80);
      *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 8) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10c) + 8) + 0x80);
      *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 0xc) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10c) + 0xc) + 0x80);
      *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 0x10) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10c) + 0x10) + 0x80);
      *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 0x14) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10c) + 0x14) + 0x80);
      *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 0x18) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10c) + 0x18) + 0x80);
      *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 0x1c) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10c) + 0x1c) + 0x80);
      *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 0x20) =
           *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x10c) + 0x20) + 0x80);
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

