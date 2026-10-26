
void FUN_0045b670(undefined4 *param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined1 auStack_9c [4];
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined2 local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941736;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_9c;
  ExceptionList = &local_14;
  local_88 = param_2;
  local_98 = 0;
  if ((param_2 == -1) && (in_ECX == -1)) {
LAB_0045b6cf:
    *param_1 = 0xffffffff;
    param_1[1] = 0xffffffff;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0xffffffff;
    param_1[5] = 0xffffffff;
    param_1[0xb] = 7;
    param_1[10] = 0;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  else {
    local_84 = in_ECX;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff58);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if ((local_88 != 1) || (DAT_00f94300 + 0x16f8 == 0)) goto LAB_0045b6cf;
    if (99 < local_84 - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      goto LAB_0045b6cf;
    }
    local_90 = DAT_00f94300 + 0x16f8 + local_84 * 0x20;
    if (((*(int *)(local_90 + 0xc) == 0) || (*(int *)(local_90 + 8) == 0)) || (local_90 == 0))
    goto LAB_0045b6cf;
    local_94 = *(int *)(local_90 + 0xc);
    local_8c = FUN_00404c10();
    FUN_008438c0(&local_94);
    if ((local_98 != *(int *)(local_8c + 4)) &&
       (local_94 = *(int *)(local_98 + 0x10), local_94 != 0)) {
      local_80 = *(undefined4 *)(local_90 + 0x10);
      local_7c = *(undefined4 *)(local_90 + 0x14);
      local_98 = FUN_00409560();
      FUN_004dd400(local_98,&local_8c,&local_80);
      if ((local_8c != *(int *)(local_98 + 4)) &&
         ((*(int *)(local_8c + 0x18) != 0 && (*(int *)(*(int *)(local_8c + 0x18) + 0x24) != 0)))) {
        FUN_00445270();
        goto LAB_0045b9d1;
      }
      uVar2 = *(undefined4 *)(local_90 + 4);
      FUN_004034e0(uVar2);
      local_98 = FUN_00523230(uVar2);
      if (local_98 == 0) {
        *param_1 = 0xffffffff;
        param_1[1] = 0xffffffff;
        param_1[2] = 0;
        param_1[3] = 0;
        param_1[4] = 0xffffffff;
        param_1[5] = 0xffffffff;
        param_1[0xb] = 7;
        param_1[10] = 0;
        *(undefined2 *)(param_1 + 6) = 0;
        param_1[0xd] = 0xffffffff;
        param_1[0xe] = 0xffffffff;
        param_1[0x10] = 0;
        param_1[0x11] = 0;
        param_1[0x12] = 0xffffffff;
        param_1[0x13] = 0xffffffff;
        param_1[0x14] = 0xffffffff;
        goto LAB_0045b9d1;
      }
      local_78 = -1;
      local_74 = -1;
      local_70 = 0;
      local_6c = 0;
      local_68 = 0xffffffff;
      local_64 = 0xffffffff;
      local_4c = 7;
      local_50 = 0;
      local_60 = 0;
      local_44 = 0xffffffff;
      local_40 = 0xffffffff;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0xffffffff;
      local_2c = 0xffffffff;
      local_28 = 0xffffffff;
      local_c = 1;
      if (*(int *)(local_98 + 8) == 0xb) {
        uVar2 = *(undefined4 *)(local_90 + 4);
        FUN_0045af80(uVar2,uVar2);
        iVar1 = FUN_0052cc90(uVar2);
        if (iVar1 != 0) {
          local_38 = *(undefined4 *)(iVar1 + 8);
          local_34 = *(undefined4 *)(iVar1 + 0xc);
          local_30 = *(undefined4 *)(iVar1 + 0x10);
          local_2c = *(undefined4 *)(iVar1 + 0x14);
          goto LAB_0045b965;
        }
        FUN_00445270();
      }
      else {
LAB_0045b965:
        iVar1 = local_98;
        FUN_004026e0(local_94,0,0xffffffff);
        local_74 = local_84;
        local_78 = local_88;
        local_64 = *(undefined4 *)(local_90 + 0xc);
        local_70 = *(undefined4 *)(local_90 + 0x10);
        local_6c = *(undefined4 *)(local_90 + 0x14);
        local_68 = *(undefined4 *)(local_90 + 4);
        local_44 = *(undefined4 *)(iVar1 + 8);
        local_40 = *(undefined4 *)(iVar1 + 0x5c);
        local_28 = *(undefined4 *)(iVar1 + 0x6c);
        FUN_00609da0();
      }
      FUN_00609030();
      goto LAB_0045b9d1;
    }
    *param_1 = 0xffffffff;
    param_1[1] = 0xffffffff;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0xffffffff;
    param_1[5] = 0xffffffff;
    param_1[0xb] = 7;
    param_1[10] = 0;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  param_1[0xd] = 0xffffffff;
  param_1[0xe] = 0xffffffff;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0xffffffff;
  param_1[0x13] = 0xffffffff;
  param_1[0x14] = 0xffffffff;
LAB_0045b9d1:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_9c);
  return;
}

