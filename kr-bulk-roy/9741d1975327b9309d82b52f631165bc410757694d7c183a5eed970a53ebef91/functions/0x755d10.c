
void FUN_00755d10(void)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_EDI;
  undefined4 **local_24 [4];
  undefined4 local_14;
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_004297b0();
  pppuVar1 = (undefined4 ***)local_24[0];
  if (local_10 < 0x10) {
    pppuVar1 = local_24;
  }
  iVar2 = FUN_0072e2e0(pppuVar1);
  if (0xf < local_10) {
    FUN_0089120c(local_24[0]);
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24[0] = (undefined4 **)((uint)local_24[0] & 0xffffff00);
  if (iVar2 != 0) {
    uVar3 = FUN_00764fb0(0);
    *unaff_EDI = uVar3;
    uVar3 = FUN_00764fb0(0);
    unaff_EDI[2] = uVar3;
    uVar3 = FUN_00764fb0(0);
    unaff_EDI[1] = uVar3;
    uVar3 = FUN_00764fb0(0);
    unaff_EDI[3] = uVar3;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

