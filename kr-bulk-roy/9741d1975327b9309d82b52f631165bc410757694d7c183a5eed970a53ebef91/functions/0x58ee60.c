
void FUN_0058ee60(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 ***pppuVar3;
  undefined4 uVar4;
  undefined4 in_EDX;
  undefined4 *unaff_ESI;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e268;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
  local_14 = uVar2;
  cVar1 = FUN_0058ef10(param_1,in_EDX);
  if (cVar1 == '\0') {
    if (7 < local_1c) {
      FUN_0089120c(local_30[0],uVar2);
    }
  }
  else {
    pppuVar3 = (undefined4 ***)local_30[0];
    if (local_1c < 8) {
      pppuVar3 = local_30;
    }
    uVar4 = FUN_008935e3(pppuVar3);
    *unaff_ESI = uVar4;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0],uVar2);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

