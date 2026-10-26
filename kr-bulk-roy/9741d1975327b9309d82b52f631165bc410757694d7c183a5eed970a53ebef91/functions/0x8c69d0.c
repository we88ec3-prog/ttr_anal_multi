
void FUN_008c69d0(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined **ppuVar4;
  int local_94;
  undefined4 local_90;
  undefined2 local_8c;
  undefined2 local_8a;
  undefined1 *local_88;
  uint local_84;
  int local_80;
  undefined4 local_7c;
  undefined **local_78;
  int local_74;
  undefined *local_70;
  undefined **local_6c;
  undefined1 *local_68;
  undefined **local_64;
  undefined **local_60;
  undefined1 local_5c [12];
  int local_50;
  undefined1 local_4c [64];
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_88 = *(undefined1 **)(param_1 + 500);
  local_78 = (undefined **)(local_88 + *(int *)(param_1 + 0x1f8));
  local_74 = param_1;
  if (((local_88 == (undefined1 *)0x0) || (local_78 < local_88 + 4)) ||
     (CONCAT11(*local_88,local_88[1]) != 0)) {
    local_60 = (undefined **)local_88;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_6c = (undefined **)(uint)CONCAT11(local_88[2],local_88[3]);
  ppuVar2 = (undefined **)(local_88 + 4);
  ppuVar4 = local_6c;
  iVar1 = param_1;
  iVar3 = local_94;
  do {
    local_94 = iVar1;
    local_74 = local_94;
    if ((local_6c == (undefined **)0x0) || (local_78 < ppuVar2 + 2)) {
      local_94 = iVar3;
      local_60 = ppuVar2;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,ppuVar4);
      return;
    }
    local_8c = CONCAT11(*(undefined1 *)ppuVar2,*(undefined1 *)((int)ppuVar2 + 1));
    local_8a = CONCAT11(*(undefined1 *)((int)ppuVar2 + 2),*(undefined1 *)((int)ppuVar2 + 3));
    local_90 = 0;
    local_60 = ppuVar2 + 2;
    ppuVar2 = (undefined **)
              CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(ppuVar2 + 1),
                                         *(undefined1 *)((int)ppuVar2 + 5)),
                                *(undefined1 *)((int)ppuVar2 + 6)),*(undefined1 *)((int)ppuVar2 + 7)
                      );
    ppuVar4 = local_60;
    if ((ppuVar2 != (undefined **)0x0) &&
       (ppuVar4 = (undefined **)(*(int *)(local_94 + 0x1f8) + -2), ppuVar2 <= ppuVar4)) {
      local_68 = (undefined1 *)((int)ppuVar2 + (int)local_88);
      local_84 = (uint)CONCAT11(*local_68,local_68[1]);
      local_64 = &PTR_DAT_00bd821c;
      do {
        local_70 = *local_64;
        if (*(uint *)(local_70 + 0x28) == local_84) {
          local_7c = 0;
          FUN_008b8440(local_5c,local_68,local_78,0);
          local_c = (uint)*(ushort *)(local_74 + 0x108);
          iVar3 = __setjmp3(local_4c,0);
          if (iVar3 == 0) {
            local_7c = (**(code **)(local_70 + 0x2c))(local_68,local_5c);
          }
          ppuVar4 = local_64;
          if ((local_50 == 0) &&
             (iVar3 = FUN_008bcc30(local_70,local_68,&local_94,&local_80), ppuVar4 = local_64,
             iVar3 == 0)) {
            *(undefined4 *)(local_80 + 0x14) = local_7c;
          }
          break;
        }
        ppuVar4 = local_64 + 1;
        local_64 = ppuVar4;
      } while (*ppuVar4 != (undefined *)0x0);
    }
    local_6c = (undefined **)((int)local_6c + -1);
    ppuVar2 = local_60;
    iVar1 = local_74;
    iVar3 = local_94;
  } while( true );
}

