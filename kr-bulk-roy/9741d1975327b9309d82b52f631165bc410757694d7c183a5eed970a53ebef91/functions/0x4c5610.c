
void FUN_004c5610(void)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  uint uVar4;
  short *psVar5;
  undefined4 *puVar6;
  short *psVar7;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936b0e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_c = 0;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
  }
  local_c = 0xffffffff;
  local_3c = 6;
  FUN_005740f0(&local_3c);
  if (local_44 == DAT_00fe5aec) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  psVar7 = (short *)(local_44 + 0x10);
  if (7 < *(uint *)(local_44 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  local_24 = 7;
  local_28 = 0;
  local_38 = (uint)local_38._2_2_ << 0x10;
  psVar5 = psVar7;
  do {
    sVar2 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar2 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_c = 1;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_c._0_1_ = 2;
    local_c._1_3_ = 0;
    FUN_004d4d10(uVar4);
    _atexit((_func_4879 *)&LAB_00bccef0);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  FUN_004d6b30(&local_38);
  local_c = 0xffffffff;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  local_24 = 7;
  local_28 = 0;
  local_38 = local_38 & 0xffff0000;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 3;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  if (DAT_00fab228 == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar6 = (undefined4 *)FUN_00891268(0x18);
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[1] = 0xffffffff;
      puVar6[2] = 0xffffffff;
      puVar6[3] = 0;
      puVar6[4] = 0xf4269;
      *puVar6 = FoxUI::FXUIEventB1::vftable;
      *(undefined1 *)(puVar6 + 5) = 1;
      goto LAB_004c586a;
    }
  }
  else {
    cVar1 = *(char *)(DAT_00fab228 + 0x28);
    if (cVar1 != '\0') {
      *(undefined4 *)(local_40 + 0xbd54) = 1;
      *(undefined4 *)(local_40 + 0xbd58) = 0x41200000;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 4;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar6 = (undefined4 *)FUN_00891268(0x18);
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[1] = 0xffffffff;
      puVar6[2] = 0xffffffff;
      puVar6[3] = 0;
      puVar6[4] = 0xf4269;
      *puVar6 = FoxUI::FXUIEventB1::vftable;
      *(char *)(puVar6 + 5) = cVar1;
      goto LAB_004c586a;
    }
  }
  puVar6 = (undefined4 *)0x0;
LAB_004c586a:
  FUN_0058aa50(puVar6);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

