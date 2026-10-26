
void FUN_0058e1c0(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  short *psVar5;
  undefined4 uVar6;
  int in_ECX;
  short *unaff_EDI;
  int local_68;
  int local_64;
  int local_60 [2];
  uint local_58;
  undefined4 local_48;
  uint local_44;
  undefined4 local_3c;
  undefined4 local_2c;
  uint local_28;
  undefined4 *local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091af70;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_68;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  local_58 = local_58 & 0xffff0000;
  local_44 = 7;
  local_48 = 0;
  psVar5 = unaff_EDI;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  local_68 = in_ECX;
  FUN_00402160(unaff_EDI,(int)psVar5 - (int)(unaff_EDI + 1) >> 1);
  local_60[0] = in_ECX + 0x18;
  local_c = 0;
  FUN_00736f40(&local_64);
  local_c = 0xffffffff;
  if (7 < local_44) {
    FUN_0089120c(local_58,uVar3);
  }
  if (local_64 == *(int *)(local_68 + 0x1c)) {
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = FUI::FXUIPositionHistory::vftable;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[6] = 0;
      puVar4[5] = 0;
      puVar4[4] = 0;
      puVar4[3] = 0;
    }
    puVar4[1] = param_1;
    FUN_0058cc10();
    local_3c = (uint)local_3c._2_2_ << 0x10;
    local_28 = 7;
    local_2c = 0;
    psVar5 = unaff_EDI;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(unaff_EDI,(int)psVar5 - (int)(unaff_EDI + 1) >> 1);
    iVar2 = local_60[0];
    local_c = 1;
    local_20 = puVar4;
    uVar6 = FUN_0044fc70(&local_3c);
    FUN_0044fb30(iVar2,local_60,uVar6);
    if (7 < local_28) {
      FUN_0089120c(local_3c);
    }
  }
  else {
    *(undefined4 *)(*(int *)(local_64 + 0x28) + 4) = param_1;
    FUN_0058cc10();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_68);
  return;
}

