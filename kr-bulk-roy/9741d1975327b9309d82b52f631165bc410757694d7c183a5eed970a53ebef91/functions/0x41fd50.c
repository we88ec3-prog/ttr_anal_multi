
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041fd50(undefined4 param_1)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  undefined4 uVar4;
  short *psVar5;
  ushort in_FPUControlWord;
  undefined1 auStack_6c [4];
  int local_68;
  uint local_64;
  longlong local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00941dd0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6c;
  ExceptionList = &local_14;
  local_58 = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff88);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_68 = CONCAT22(local_68._2_2_,in_FPUControlWord);
  local_64 = in_FPUControlWord | 0xc00;
  local_60 = (longlong)ROUND(_DAT_00f942b4);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_c = 0xffffffff;
  local_64 = 0x15e;
  FUN_005740f0(&local_64);
  if (local_68 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar5 = (short *)(local_68 + 0x10);
  if (7 < *(uint *)(local_68 + 0x24)) {
    psVar5 = *(short **)psVar5;
  }
  local_54 = (uint)local_54._2_2_ << 0x10;
  local_40 = 7;
  local_44 = 0;
  psVar3 = psVar5;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar3 - (int)(psVar5 + 1) >> 1);
  local_c._0_1_ = 2;
  local_c._1_3_ = 0;
  FUN_00404300(L"\n<#FFFF00>[",0xb);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c._0_1_ = 2;
  }
  local_64 = 0x36;
  FUN_005740f0(&local_64);
  if (local_68 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uVar4 = FUN_00420070();
  local_c._0_1_ = 4;
  FUN_004041f0(uVar4,0,0xffffffff);
  local_c._0_1_ = 2;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 5;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c._0_1_ = 2;
  }
  local_64 = 0x37;
  FUN_005740f0(&local_64);
  if (local_68 != DAT_00fe5ac8) {
    uVar4 = FUN_00420070();
    local_c._0_1_ = 6;
    FUN_004041f0(uVar4,0,0xffffffff);
    local_c = CONCAT31(local_c._1_3_,2);
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    FUN_00404300(L"]</#>",5);
    FUN_004026e0(&local_54,0,0xffffffff);
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    ExceptionList = local_14;
    __security_check_cookie(local_1c ^ (uint)auStack_6c);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

