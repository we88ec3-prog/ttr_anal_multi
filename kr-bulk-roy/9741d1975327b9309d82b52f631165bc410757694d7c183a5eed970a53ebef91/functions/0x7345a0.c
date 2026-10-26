
void FUN_007345a0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091941a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_84;
  ExceptionList = &local_14;
  local_84 = param_2;
  if (*(int *)(in_ECX + 0x44) == 0) {
    FUN_006edb60(&DAT_00c45408);
  }
  else {
    local_28 = 0;
    local_2c = 0;
    local_30 = 0;
    local_34 = 0;
    local_3c = 0;
    local_40 = 0;
    local_44 = 0;
    local_48 = 0;
    local_50 = 0;
    local_54 = 0;
    local_58 = 0;
    local_5c = 0;
    local_24 = 0x3f800000;
    local_38 = 0x3f800000;
    local_4c = 0x3f800000;
    local_60 = 0x3f800000;
    if (param_1 == (undefined4 *)0x0) {
      param_1 = &local_60;
    }
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_c = 0;
      FUN_00736880(DAT_00d61f20 ^ (uint)&stack0xffffff70);
      _atexit(FUN_00bce6f0);
    }
    local_c = 0xffffffff;
    (**(code **)(*DAT_00fcde28 + 0x14))(DAT_00fcde28,param_1);
    uStack_74 = 0;
    uStack_70 = 0;
    if (param_3 != (undefined4 *)0x0) {
      local_84 = *param_3;
      uStack_80 = param_3[1];
      uStack_7c = 0;
      uStack_78 = uStack_80;
      uStack_74 = local_84;
      uStack_70 = uStack_80;
    }
    uStack_6c = 0;
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_14 = (void *)0x1;
      FUN_00736880();
      _atexit(FUN_00bce6f0);
      local_14 = (void *)0xffffffff;
    }
    iVar2 = (**(code **)(*DAT_00fcde28 + 0x24))
                      (DAT_00fcde28,*(undefined4 *)(in_ECX + 0x44),unaff_ESI,&uStack_74,0,param_5);
    if (iVar2 < 0) {
      FUN_006edb60("CTexture::Draw error: hr = 0x%8x");
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_2c = 2;
      FUN_00736880();
      _atexit(FUN_00bce6f0);
      local_2c = 0xffffffff;
    }
    (**(code **)(*DAT_00fcde28 + 0x14))(DAT_00fcde28,&uStack_80);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_84);
  return;
}

