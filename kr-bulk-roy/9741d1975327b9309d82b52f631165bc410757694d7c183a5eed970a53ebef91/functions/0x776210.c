
void FUN_00776210(void)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920948;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004297b0(local_14);
  pppuVar1 = (undefined4 ***)local_30[0];
  if (local_1c < 0x10) {
    pppuVar1 = local_30;
  }
  iVar2 = FUN_0072e2e0(pppuVar1);
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
  if (iVar2 != 0) {
    uVar3 = FUN_00764d80(local_4c,&DAT_00bed1fc);
    local_8 = 0;
    FUN_00402800(uVar3);
    local_8 = 0xffffffff;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
    uVar3 = FUN_00764fb0(0xffffffff);
    *(undefined4 *)(in_ECX + 0x20) = uVar3;
    FUN_00429860(in_ECX + 0x24);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

