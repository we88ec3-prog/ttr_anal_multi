
/* WARNING: Removing unreachable block (ram,0x004d6a7d) */
/* WARNING: Removing unreachable block (ram,0x004d6afb) */

void FUN_004d69a0(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  int unaff_ESI;
  undefined4 local_68;
  uint local_54;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bc56;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(unaff_ESI + 7) == '\x01') {
    FUN_004d8c20(uVar2);
    local_8._1_3_ = 0;
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
    }
    local_8._0_1_ = 0;
    psVar3 = (short *)FUN_00585250();
    psVar4 = psVar3;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_004d65b0(param_1,*(undefined4 *)(unaff_ESI + 2),*(undefined1 *)(unaff_ESI + 6));
    if (0xf < local_54) {
      FUN_0089120c(local_68);
    }
  }
  else {
    psVar4 = (short *)(unaff_ESI + 8);
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160((short *)(unaff_ESI + 8),(int)psVar4 - (unaff_ESI + 10) >> 1);
    local_8 = 3;
    FUN_004d65b0(param_1,*(undefined4 *)(unaff_ESI + 2),*(undefined1 *)(unaff_ESI + 6));
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

