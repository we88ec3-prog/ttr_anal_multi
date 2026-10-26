
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005624b0(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined1 local_3c [4];
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00943d60;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_3c;
  ExceptionList = &local_14;
  if (((param_1 != 0) && (*(int *)(in_ECX + 0x38) == 1000)) &&
     ((iVar4 = *(int *)(in_ECX + 0x3c), iVar4 == 0xf ||
      (((iVar4 == 0x10 || (iVar4 == 0x11)) || (iVar4 == 0x12)))))) {
    DAT_00fba7a0 = 1;
  }
  if (*(int *)(in_ECX + 0x28) != 0) {
    if ((DAT_00fb761c & 1) == 0) {
      DAT_00fb761c = DAT_00fb761c | 1;
      local_c = 0;
      FUN_0054e750(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
      _atexit((_func_4879 *)&LAB_00bcd260);
    }
    local_c = 0xffffffff;
    if (DAT_00fb7620 != (int *)0x0) {
      (**(code **)(*DAT_00fb7620 + 0xc))();
    }
    puVar2 = (undefined4 *)FUN_00489c60();
    iVar4 = 0x20;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 5;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if ((DAT_00fc1b88 & 1) == 0) {
      DAT_00fc1b88 = DAT_00fc1b88 | 1;
      local_c = 1;
      FUN_00581c10();
      _atexit((_func_4879 *)&LAB_00bcdfa0);
      local_c = 0xffffffff;
    }
    _DAT_00fc1bc0 = 0;
    _DAT_00fc1bbc = 0;
    if (DAT_00fc1b90 != 0) {
      FUN_004a47d0(DAT_00fc1b90);
      DAT_00fc1b90 = 0;
    }
    if ((DAT_00fc1bf4 & 1) == 0) {
      DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
      local_c = 2;
      FUN_0057ef90();
      _atexit((_func_4879 *)&LAB_00bcdfb0);
      local_c = 0xffffffff;
    }
    DAT_00fc1c6c = 0;
    if (*(int *)(in_ECX + 0x54) == 0) {
      if ((DAT_00fe1ee8 & 1) == 0) {
        DAT_00fe1ee8 = DAT_00fe1ee8 | 1;
        local_c = 3;
        FUN_0055c610();
        _atexit((_func_4879 *)&LAB_00bcf290);
        local_c = 0xffffffff;
      }
      uVar3 = FUN_0055ffc0(&DAT_00fe1eec);
      local_c = 4;
      FUN_00402bb0(uVar3);
      local_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
    }
    FUN_00563fa0();
    FUN_00563a70();
    FUN_00562b00();
    if (param_1 != 0) {
      if ((DAT_00fc1b14 & 1) == 0) {
        DAT_00fc1b14 = DAT_00fc1b14 | 1;
        local_c = 5;
        FUN_0055ee90();
        _atexit((_func_4879 *)&LAB_00bcdf90);
        local_c = 0xffffffff;
      }
      FUN_0055f8a0();
    }
    iVar4 = FUN_0055ff70();
    uVar1 = DAT_00fe2740 & 1;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    if (uVar1 == 0) {
      DAT_00fe2740 = DAT_00fe2740 | 1;
      local_c = 6;
      FUN_0055e680();
      _atexit((_func_4879 *)&DAT_00bcf2a0);
      local_c = 0xffffffff;
    }
    if (param_1 != 0) {
      _DAT_00fe2754 = 0;
    }
    _DAT_00fe2750 = 0;
    if ((_DAT_00fe36dc & 1) == 0) {
      _DAT_00fe36dc = _DAT_00fe36dc | 1;
    }
    _DAT_00fe36d4 = 4;
    _DAT_00fe36d8 = 0;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 7;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    _DAT_00fab1e0 = 0;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 8;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    FUN_0058aad0(0xf434e);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 9;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    FUN_0058b510();
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 10;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    _DAT_00fab1d8 = 0;
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_c = 0xb;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      local_c = 0xffffffff;
    }
    DAT_00fb8830 = DAT_00fb8830 & 0xfffffffd;
    if ((DAT_00fb7354 & 1) == 0) {
      DAT_00fb7354 = DAT_00fb7354 | 1;
      local_c = 0xc;
      FUN_005533d0();
      _atexit((_func_4879 *)&LAB_00bcd100);
      local_c = 0xffffffff;
    }
    FUN_00553740();
    FUN_00561db0();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_3c);
  return;
}

