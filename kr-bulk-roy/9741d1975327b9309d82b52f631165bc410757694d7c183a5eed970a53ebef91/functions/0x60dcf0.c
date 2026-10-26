
void FUN_0060dcf0(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  int unaff_EDI;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092ab80;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(unaff_EDI + 0x15c) != -1) {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    local_8 = 0;
    FUN_00757710(local_14);
    psVar3 = (short *)FUN_0060edb0(unaff_EDI,*(undefined4 *)(unaff_EDI + 0x15c),local_30);
    local_4c = (uint)local_4c._2_2_ << 0x10;
    local_38 = 7;
    local_3c = 0;
    psVar4 = psVar3;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
    iVar2 = *(int *)(unaff_EDI + 0x188);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_007578f0();
    FUN_00759ed0(iVar2 + 0xe8,&local_4c,0x7b,0x7d);
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

