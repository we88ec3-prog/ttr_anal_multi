
void FUN_00559d60(int param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  short *unaff_EDI;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (unaff_EDI != (short *)0x0) {
    psVar3 = unaff_EDI;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    if ((int)psVar3 - (int)(unaff_EDI + 1) >> 1 != 0) {
      local_30[0] = local_30[0] & 0xffff0000;
      local_1c = 7;
      local_20 = 0;
      psVar3 = unaff_EDI;
      do {
        sVar1 = *psVar3;
        psVar3 = psVar3 + 1;
      } while (sVar1 != 0);
      FUN_00402160(unaff_EDI,(int)psVar3 - (int)(unaff_EDI + 1) >> 1);
      local_8 = 0;
      FUN_0046fac0(local_30);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30[0],uVar2);
      }
      local_30[0] = local_30[0] & 0xffff0000;
      local_1c = 7;
      local_20 = 0;
      iVar4 = FUN_00559e90(0,0);
      if (4 < iVar4) {
        FUN_004a3150();
      }
      FUN_00559f30();
      *(undefined4 *)(param_1 + 0xe8) = 1;
      psVar3 = unaff_EDI + 1;
      do {
        sVar1 = *unaff_EDI;
        unaff_EDI = unaff_EDI + 1;
      } while (sVar1 != 0);
      *(int *)(param_1 + 8) = ((int)unaff_EDI - (int)psVar3 >> 1) * 2 + 0x3c;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

