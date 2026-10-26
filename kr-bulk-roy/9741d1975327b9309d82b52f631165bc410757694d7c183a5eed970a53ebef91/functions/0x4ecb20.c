
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ecb20(int param_1)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  short *psVar4;
  wchar_t *in_ECX;
  short *psVar5;
  int local_44;
  wchar_t local_3e [21];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092fb14;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((*(int *)(param_1 + 0x5ec0) == 0) || (iVar2 = *(int *)(param_1 + 0x5ebc), iVar2 == 0)) ||
     ((*(char *)(iVar2 + 0x12) == '\0' && ((*(byte *)(iVar2 + 0x14) & 4) == 0)))) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
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
    if (local_44 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar5 = (short *)(local_44 + 0x10);
    if (7 < *(uint *)(local_44 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
  else {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    _wcscpy_s(local_3e,0x15,in_ECX);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

