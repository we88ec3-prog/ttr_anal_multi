
void FUN_0060e150(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d7aa;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fc1094 & 1) == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 0;
    FUN_0052f7e0(local_14);
    _atexit((_func_4879 *)&LAB_00bcdc80);
  }
  local_8 = 0xffffffff;
  FUN_00402160(&DAT_00bed1fc,0);
  iVar4 = 0;
  local_58 = (undefined *)0x0;
  uVar2 = FUN_005302d0();
  switch(uVar2) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 8:
  case 9:
  case 10:
    iVar3 = FUN_00530330();
    if (iVar3 == 1) {
      uVar2 = 0x1ce;
LAB_0060e20f:
      FUN_00585620(uVar2);
      iVar4 = FUN_00585330(uVar2);
    }
    else {
      if (iVar3 == 2) {
        uVar2 = 0x1cf;
        goto LAB_0060e20f;
      }
      if (iVar3 == 3) {
        uVar2 = 0x1d0;
        goto LAB_0060e20f;
      }
    }
    iVar3 = FUN_005303d0();
    if ((-1 < iVar3) && (iVar3 < 7)) {
      local_58 = (&PTR_DAT_00d6a18c)[iVar3];
    }
    goto LAB_0060e25f;
  case 5:
    uVar2 = 0x1d1;
    break;
  case 6:
    uVar2 = 0x1d2;
    break;
  case 7:
    uVar2 = 0x1d3;
    break;
  default:
    goto switchD_0060e1e0_default;
  }
  FUN_00585620(uVar2);
  iVar4 = FUN_00585330(uVar2);
LAB_0060e25f:
  if (iVar4 != 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_54 = 0x1cc;
    FUN_005740f0(&local_54);
    if (local_50 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar2 = FUN_004ed610();
    local_8 = 2;
    FUN_004041f0(uVar2,0,0xffffffff);
    local_8 = 0xffffffff;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  if (local_58 != (undefined *)0x0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 3;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_50 = 0x1cd;
    FUN_005740f0(&local_50);
    if (local_54 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar2 = FUN_004ed610();
    local_8 = 4;
    FUN_004041f0(uVar2,0,0xffffffff);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
switchD_0060e1e0_default:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

