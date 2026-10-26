
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068e3a0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00945d0e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0();
  iVar3 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0068e409;
    iVar3 = FUN_00745c20();
  }
  if ((((iVar3 != 0) && (*(int *)(iVar3 + 0x60) != 0)) &&
      ((*(uint *)(iVar3 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar3 + 0x60) != 0)) {
    FUN_0074a010();
  }
LAB_0068e409:
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (DAT_00f9392c == 7) {
    if ((DAT_00fb725c & 1) == 0) {
      DAT_00fb725c = DAT_00fb725c | 1;
      local_c = 1;
      FUN_004a79a0();
      _atexit((_func_4879 *)&DAT_00bccf80);
      local_c = 0xffffffff;
    }
    FUN_004462a0();
    local_c = 2;
    if (*(int *)(in_ECX + 0x210) != *(int *)(in_ECX + 0x214)) {
      uVar1 = FUN_00692570();
      FUN_006925b0();
      *(undefined4 *)(in_ECX + 0x214) = uVar1;
    }
    uVar2 = local_24 - local_28 >> 2;
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        FUN_004a78b0(*(undefined4 *)(local_28 + uVar4 * 4));
        FUN_00691240();
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
    FUN_00691440();
    local_c = 0xffffffff;
    if (local_28 != 0) {
      FUN_0089120c();
    }
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 3;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if ((DAT_00f9392c == 0x18) || (iVar3 = FUN_00404ba0(), *(int *)(iVar3 + 0x5f4c) == 0x17)) {
      if ((DAT_00fb725c & 1) == 0) {
        DAT_00fb725c = DAT_00fb725c | 1;
        local_c = 4;
        FUN_004a79a0();
        _atexit((_func_4879 *)&DAT_00bccf80);
        local_c = 0xffffffff;
      }
      if (*(int *)(in_ECX + 0x210) != *(int *)(in_ECX + 0x214)) {
        uVar1 = FUN_00692570();
        FUN_006925b0();
        *(undefined4 *)(in_ECX + 0x214) = uVar1;
      }
      uVar2 = 0;
      if (DAT_00fb7294 - DAT_00fb7290 >> 2 != 0) {
        do {
          FUN_004a78b0(*(undefined4 *)(DAT_00fb7290 + uVar2 * 4));
          FUN_00691240();
          uVar2 = uVar2 + 1;
        } while (uVar2 < (uint)(DAT_00fb7294 - DAT_00fb7290 >> 2));
      }
      FUN_00691440();
    }
  }
  FUN_0068e6f0();
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 5;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_c = 0xffffffff;
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))();
  }
  ExceptionList = local_14;
  return;
}

