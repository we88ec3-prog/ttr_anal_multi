
void FUN_00776ca0(void)

{
  undefined4 ***pppuVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  int local_28;
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
    local_28 = 0;
    FUN_00429860(&local_28);
    iVar3 = (**(code **)(*unaff_EDI + 4))();
    if (local_28 != iVar3) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    (**(code **)(*unaff_EDI + 0x14))(iVar2);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

