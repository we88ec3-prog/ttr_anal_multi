
void FUN_0083c120(LPCSTR param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *in_ECX;
  uint uVar4;
  uint uStack_bc;
  int iStack_b8;
  LPCSTR local_b4;
  int iStack_b0;
  char *pcStack_ac;
  uint uStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  int iStack_84;
  undefined **local_80;
  undefined1 local_7c;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  puStack_10 = &LAB_00928260;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_bc;
  ExceptionList = &local_14;
  local_b4 = param_1;
  local_80 = GSArchive::vftable;
  local_68 = 0xf;
  local_6c = 0;
  local_7c = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_60 = 1;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_2c = 0;
  local_c = 0;
  iStack_b8 = (**(code **)(*in_ECX + 0xac))(DAT_00d61f20 ^ (uint)&stack0xffffff38);
  uStack_94 = 0xf;
  uStack_98 = 0;
  uStack_a8 = uStack_a8 & 0xffffff00;
  FUN_00402a70("_gbDefaultStateBlock",0x14);
  local_c._0_1_ = 1;
  FUN_00440c60();
  FUN_00866530();
  local_c = (uint)local_c._1_3_ << 8;
  if (0xf < uStack_94) {
    FUN_0089120c(uStack_a8);
  }
  iStack_b0 = 0;
  if (0 < iStack_b8) {
    do {
      uStack_bc = 0;
      pcStack_ac = (char *)0x0;
      (**(code **)(*in_ECX + 0xb0))(iStack_b0,&pcStack_ac,&uStack_bc);
      if ((((uStack_bc != 0) &&
           (uVar4 = uStack_bc & 0xffff, uVar4 < (uint)((in_ECX[99] - in_ECX[0x62]) / 0x11c))) &&
          (*(uint *)(in_ECX[0x66] + uVar4 * 4) == uStack_bc >> 0x10)) &&
         ((iStack_84 = uVar4 * 0x11c + in_ECX[0x62], iStack_84 != 0 &&
          (*(int *)(iStack_84 + 0x114) == 0)))) {
        uStack_94 = 0xf;
        uStack_98 = 0;
        uStack_a8 = uStack_a8 & 0xffffff00;
        pcVar3 = pcStack_ac;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcStack_ac,(int)pcVar3 - (int)(pcStack_ac + 1));
        local_c._0_1_ = 2;
        FUN_00440c60();
        FUN_00866530();
        local_c = (uint)local_c._1_3_ << 8;
        if (0xf < uStack_94) {
          FUN_0089120c(uStack_a8);
        }
        uStack_94 = 0xf;
        uStack_98 = 0;
        uStack_a8 = uStack_a8 & 0xffffff00;
      }
      iStack_b0 = iStack_b0 + 1;
    } while (iStack_b0 < iStack_b8);
  }
  iVar2 = local_4c - local_50 >> 0x1f;
  if ((local_4c - local_50) / 0x11c + iVar2 == iVar2) {
    local_c = 0xffffffff;
    FUN_00865a00(&local_80);
  }
  else {
    FUN_00865b70(local_b4);
    OutputDebugStringA(&DAT_00c53f18);
    OutputDebugStringA(local_b4);
    OutputDebugStringA("\n");
    local_c = 0xffffffff;
    FUN_00865a00(&local_80);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&uStack_bc);
  return;
}

