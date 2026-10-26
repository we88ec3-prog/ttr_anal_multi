
void FUN_0058f1a0(void)

{
  uint uVar1;
  undefined4 ***pppuVar2;
  undefined4 uVar3;
  undefined4 *unaff_ESI;
  undefined4 **local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e268;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
  local_14 = uVar1;
  FUN_0058cf70(local_30);
  if (local_20 == 0) {
    if (7 < local_1c) {
      FUN_0089120c(local_30[0],uVar1);
    }
  }
  else {
    pppuVar2 = (undefined4 ***)local_30[0];
    if (local_1c < 8) {
      pppuVar2 = local_30;
    }
    uVar3 = FUN_008935e3(pppuVar2);
    *unaff_ESI = uVar3;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0],uVar1);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

