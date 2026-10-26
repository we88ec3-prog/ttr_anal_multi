
void FUN_0067f930(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 extraout_ECX;
  undefined4 uVar3;
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
  
  puStack_10 = &LAB_0093cb86;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_94;
  ExceptionList = &local_14;
  local_84 = param_2;
  local_94 = 0;
  if ((param_2 != -1) || (in_ECX != -1)) {
    local_88 = in_ECX;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff60);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if ((local_84 == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
      if (99 < local_88 - 1U) {
        FUN_006edb60(&DAT_00c0ddc0);
        FUN_0067dd00();
        goto LAB_0067fbcb;
      }
      iVar1 = local_88 * 0x20 + iVar2;
      if (((*(int *)(local_88 * 0x20 + 0xc + iVar2) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
         (iVar1 != 0)) {
        local_90 = *(int *)(iVar1 + 0xc);
        local_8c = FUN_00404c10();
        FUN_008438c0(&local_90);
        if ((local_94 != *(int *)(local_8c + 4)) &&
           (local_90 = *(int *)(local_94 + 0x10), local_90 != 0)) {
          local_80 = *(undefined4 *)(iVar1 + 0x10);
          local_7c = *(undefined4 *)(iVar1 + 0x14);
          local_94 = FUN_00409560();
          FUN_004dd400(local_94,&local_8c,&local_80);
          if ((local_8c == *(int *)(local_94 + 4)) ||
             ((*(int *)(local_8c + 0x18) == 0 || (*(int *)(*(int *)(local_8c + 0x18) + 0x24) == 0)))
             ) {
            uVar3 = *(undefined4 *)(iVar1 + 4);
            FUN_004034e0(uVar3);
            iVar2 = FUN_00523230(uVar3);
            local_94 = iVar2;
            if (iVar2 != 0) {
              FUN_0067dd00();
              local_c = 1;
              if (*(int *)(iVar2 + 8) == 0xb) {
                uVar3 = *(undefined4 *)(iVar1 + 4);
                FUN_0045af80(extraout_ECX,uVar3);
                iVar2 = FUN_0052cc90(uVar3);
                if (iVar2 != 0) {
                  local_38 = *(undefined4 *)(iVar2 + 8);
                  local_34 = *(undefined4 *)(iVar2 + 0xc);
                  local_30 = *(undefined4 *)(iVar2 + 0x10);
                  local_2c = *(undefined4 *)(iVar2 + 0x14);
                  iVar2 = local_94;
                  goto LAB_0067fb64;
                }
                FUN_0067dd00();
              }
              else {
LAB_0067fb64:
                FUN_004026e0(local_90,0,0xffffffff);
                local_78 = local_84;
                local_74 = local_88;
                local_6c = *(undefined4 *)(iVar1 + 0xc);
                local_68 = *(undefined4 *)(iVar1 + 0x10);
                local_64 = *(undefined4 *)(iVar1 + 0x14);
                local_70 = *(undefined4 *)(iVar1 + 4);
                local_44 = *(undefined4 *)(iVar2 + 8);
                local_40 = *(undefined4 *)(iVar2 + 0x5c);
                local_28 = *(undefined4 *)(iVar2 + 0x6c);
                FUN_00609da0();
              }
              FUN_0067dea0();
              goto LAB_0067fbcb;
            }
          }
        }
      }
      FUN_0067dd00();
      goto LAB_0067fbcb;
    }
  }
  local_c = 0xffffffff;
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffffffff;
  param_1[3] = 0xffffffff;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0xb] = 7;
  param_1[10] = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  param_1[0xd] = 0xffffffff;
  param_1[0xe] = 0xffffffff;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0xffffffff;
LAB_0067fbcb:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_94);
  return;
}

