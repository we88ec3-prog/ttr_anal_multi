
void FUN_006aaff0(int param_1)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  LPCWSTR lpFileName;
  DWORD DVar4;
  short *psVar5;
  short *psVar6;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938704;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = *(int *)(param_1 + 0xf4);
  if (*(char *)(iVar2 + 0x141) != '\0') {
    FUN_006edb10();
  }
  lpFileName = (LPCWSTR)(iVar2 + 0x108);
  if (7 < *(uint *)(iVar2 + 0x11c)) {
    lpFileName = *(LPCWSTR *)lpFileName;
  }
  DVar4 = GetFileAttributesW(lpFileName);
  if ((DVar4 != 0xffffffff) && ((DVar4 & 0x10) != 0)) {
    if (*(char *)(*(int *)(param_1 + 0xf4) + 0x141) != '\0') {
      FUN_006edb10();
    }
    FUN_004026e0();
    FUN_006aa7f0();
    ExceptionList = local_10;
    return;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_00402160();
  local_8 = 1;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_005740f0();
  if (local_18 != DAT_00fe5b10) {
    psVar6 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
    iVar2 = *(int *)(param_1 + 0xf4);
    if (*(char *)(iVar2 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10();
    }
    *(undefined4 *)(iVar2 + 0x168) = 0;
    *(undefined4 *)(iVar2 + 0x160) = 0;
    *(undefined4 *)(iVar2 + 0x164) = 0;
    *(undefined4 *)(iVar2 + 0x14c) = 0;
    ExceptionList = local_10;
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}

