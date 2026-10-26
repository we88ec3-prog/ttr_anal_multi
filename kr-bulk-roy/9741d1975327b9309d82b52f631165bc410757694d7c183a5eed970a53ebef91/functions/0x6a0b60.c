
void FUN_006a0b60(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint in_ECX;
  uint uVar5;
  undefined1 auStack_6c [4];
  uint local_68;
  int local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009359d4;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6c;
  ExceptionList = &local_14;
  local_60 = in_ECX;
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_c = 0;
    FUN_00533f80(DAT_00d61f20 ^ (uint)&stack0xffffff88);
    _atexit((_func_4879 *)&LAB_00bced30);
  }
  local_c = 0xffffffff;
  iVar1 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc);
  local_68 = (DAT_00fe1c30 - DAT_00fe1c2c) / 0x1f;
  if (iVar1 == 0) {
    local_5c = 0xffffffff;
    local_58 = 0;
    uVar5 = 0;
    puVar3 = (undefined4 *)(in_ECX + 0x11c);
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xdc);
    if (iVar1 == 0) {
      local_5c = 0xffffffff;
      local_58 = 0;
      uVar5 = 0;
      puVar3 = (undefined4 *)(in_ECX + 0x11c);
    }
    else {
      local_5c = *(uint *)(iVar1 + 0x20);
      local_58 = 0;
      uVar5 = 0;
      puVar3 = (undefined4 *)(in_ECX + 0x11c);
    }
  }
  do {
    local_64 = 0;
    if ((((local_68 <= local_58) || (local_64 = DAT_00fe1c2c + uVar5, local_64 == 0)) &&
        (local_58 == local_5c)) && (*(int *)(*(int *)(in_ECX + 0xec) + 0xcc) != 0)) {
      FUN_0042c8e0(0xffffffff);
    }
    FUN_0069f540(local_64);
    (**(code **)(*(int *)*puVar3 + 200))();
    local_58 = local_58 + 1;
    uVar5 = uVar5 + 0x1f;
    puVar3 = puVar3 + 1;
    in_ECX = local_60;
  } while (uVar5 < 0x136);
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_c = 1;
    FUN_00533f80();
    _atexit((_func_4879 *)&LAB_00bced30);
    local_c = 0xffffffff;
  }
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_c = 2;
    FUN_00533f80();
    _atexit((_func_4879 *)&LAB_00bced30);
    local_c = 0xffffffff;
  }
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_c = 3;
    FUN_00533f80();
    _atexit((_func_4879 *)&LAB_00bced30);
    local_c = 0xffffffff;
  }
  local_64 = DAT_00fe1c24;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 4;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_68 = 0x14c;
  FUN_005740f0(&local_68);
  if (local_5c != DAT_00fe5ac8) {
    puVar3 = (undefined4 *)(local_5c + 0x10);
    if (7 < *(uint *)(local_5c + 0x24)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    uVar4 = FUN_0040e460(puVar3);
    uVar5 = local_60;
    local_c = 5;
    FUN_00757800(uVar4);
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    (**(code **)(**(int **)(uVar5 + 0xf8) + 200))();
    if (local_64 == 0) {
      FUN_00757710();
    }
    else {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_c = 6;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_c = 0xffffffff;
      }
      local_68 = 0x12;
      FUN_005740f0(&local_68);
      if (local_60 == DAT_00fe5ac8) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar4 = FUN_004068f0();
      local_c = 7;
      FUN_00757800(uVar4);
      local_c = 0xffffffff;
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
      uStack_40 = 7;
      uStack_44 = 0;
      uStack_54 = uStack_54 & 0xffff0000;
    }
    (**(code **)(**(int **)(uVar5 + 0x144) + 200))();
    ExceptionList = local_14;
    __security_check_cookie(local_1c ^ (uint)auStack_6c);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

