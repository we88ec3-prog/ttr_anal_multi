
void FUN_00764fb0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 ***pppuVar3;
  undefined4 **local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ed88;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004297b0(local_14);
  local_8 = 0;
  pppuVar3 = (undefined4 ***)local_30[0];
  if (local_1c < 0x10) {
    pppuVar3 = local_30;
  }
  (**(code **)(*in_ECX + 0x14))();
  iVar1 = FUN_007300a0(pppuVar3);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      FUN_008917b4(puVar2);
    }
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

