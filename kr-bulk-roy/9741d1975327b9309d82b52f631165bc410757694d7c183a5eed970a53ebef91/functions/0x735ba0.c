
void FUN_00735ba0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  short *in_ECX;
  int unaff_ESI;
  undefined4 ***pppuVar4;
  undefined4 **local_34 [5];
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919518;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX != (short *)0x0) {
    psVar1 = in_ECX + 1;
    do {
      sVar2 = *in_ECX;
      in_ECX = in_ECX + 1;
    } while (sVar2 != 0);
    if ((int)in_ECX - (int)psVar1 >> 1 != 0) {
      FUN_0073ce20(local_18);
      local_8 = 0;
      pppuVar4 = (undefined4 ***)local_34[0];
      if (local_20 < 8) {
        pppuVar4 = local_34;
      }
      iVar3 = FUN_00735620(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x20),pppuVar4,param_3);
      if (iVar3 != 0) {
        FUN_00735c90(0,pppuVar4,param_4,param_5);
      }
      if (7 < local_20) {
        FUN_0089120c(local_34[0]);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

