
/* WARNING: Removing unreachable block (ram,0x006a86e4) */
/* WARNING: Removing unreachable block (ram,0x006a86ed) */
/* WARNING: Removing unreachable block (ram,0x006a86f0) */
/* WARNING: Removing unreachable block (ram,0x006a86f9) */
/* WARNING: Removing unreachable block (ram,0x006a8719) */
/* WARNING: Removing unreachable block (ram,0x006a8789) */
/* WARNING: Removing unreachable block (ram,0x006a8792) */
/* WARNING: Removing unreachable block (ram,0x006a8795) */
/* WARNING: Removing unreachable block (ram,0x006a87a6) */
/* WARNING: Removing unreachable block (ram,0x006a8729) */
/* WARNING: Removing unreachable block (ram,0x006a87b3) */
/* WARNING: Removing unreachable block (ram,0x006a8629) */
/* WARNING: Removing unreachable block (ram,0x006a8632) */
/* WARNING: Removing unreachable block (ram,0x006a863b) */
/* WARNING: Removing unreachable block (ram,0x006a865b) */
/* WARNING: Removing unreachable block (ram,0x006a86b2) */
/* WARNING: Removing unreachable block (ram,0x006a86a5) */
/* WARNING: Removing unreachable block (ram,0x006a86ae) */
/* WARNING: Removing unreachable block (ram,0x006a86b8) */
/* WARNING: Removing unreachable block (ram,0x006a86d4) */
/* WARNING: Removing unreachable block (ram,0x006a86df) */
/* WARNING: Removing unreachable block (ram,0x006a8620) */
/* WARNING: Removing unreachable block (ram,0x006a87b9) */
/* WARNING: Removing unreachable block (ram,0x006a87bd) */

void FUN_006a84a0(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int in_ECX;
  short *psVar4;
  short *psVar5;
  int local_34;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009428f8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(*(int *)(in_ECX + 0xf4) + 0x141) != '\0') {
    FUN_006edb10();
  }
  FUN_004026e0();
  local_8._1_3_ = 0;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8._0_1_ = 0;
  FUN_00402160();
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 3;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
  }
  local_8._0_1_ = 2;
  FUN_005740f0();
  if (local_34 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar4 = (short *)(local_34 + 0x10);
  psVar5 = psVar4;
  if (7 < *(uint *)(local_34 + 0x24)) {
    psVar4 = *(short **)psVar4;
    psVar5 = psVar4;
  }
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
  local_8._0_1_ = 0;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

