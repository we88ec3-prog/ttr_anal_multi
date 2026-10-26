
void FUN_0058ec10(int param_1,undefined4 param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  undefined4 uVar4;
  short *in_EDX;
  char *local_7c;
  undefined4 local_78;
  undefined **local_74;
  char local_70 [4];
  undefined4 *local_6c;
  undefined4 local_68;
  undefined4 local_60 [2];
  undefined **local_58 [3];
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined **local_30;
  undefined1 local_2c [16];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091f988;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  local_60[0] = param_2;
  local_4c[0] = local_4c[0] & 0xffff0000;
  local_38 = 7;
  local_3c = 0;
  psVar3 = in_EDX;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160(in_EDX,(int)psVar3 - (int)(in_EDX + 1) >> 1);
  local_c = 0;
  FUN_0058f3c0(&local_7c);
  local_c = 0xffffffff;
  if (7 < local_38) {
    FUN_0089120c(local_4c[0],uVar2);
  }
  if (local_7c == *(char **)(param_1 + 0x48)) {
    local_74 = FUI::FXUIAttributeHistory::vftable;
    local_68 = 0;
    local_6c = (undefined4 *)FUN_00891268(0x48);
    if (local_6c == (undefined4 *)0x0) {
      local_7c = (char *)0x0;
      std::exception::exception((exception *)local_58,&local_7c);
      local_58[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_58,&DAT_00c857a8);
    }
    *local_6c = local_6c;
    local_6c[1] = local_6c;
    local_6c[2] = local_6c;
    *(undefined1 *)(local_6c + 0x11) = 1;
    *(undefined1 *)((int)local_6c + 0x45) = 1;
    local_c = 1;
    FUN_0058cd50(&local_74,local_78);
    local_4c[0] = local_4c[0] & 0xffff0000;
    local_38 = 7;
    local_3c = 0;
    psVar3 = in_EDX;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00402160(in_EDX,(int)psVar3 - (int)(in_EDX + 1) >> 1);
    local_c._0_1_ = 2;
    local_30 = FUI::FXUIAttributeHistory::vftable;
    FUN_0051abd0(local_2c,local_70);
    local_c._0_1_ = 3;
    uVar4 = FUN_0058ff30(local_4c);
    FUN_0058fb80(param_1 + 0x44,local_60,uVar4);
    local_c = CONCAT31(local_c._1_3_,1);
    FUN_00590100(local_4c);
    local_7c = local_70;
    local_74 = FUI::FXUIAttributeHistory::vftable;
    local_c = 4;
    FUN_0051af60(*local_6c,local_6c);
    FUN_0089120c(local_6c);
  }
  else {
    FUN_0058cd50(local_7c + 0x28,local_78);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_7c);
  return;
}

