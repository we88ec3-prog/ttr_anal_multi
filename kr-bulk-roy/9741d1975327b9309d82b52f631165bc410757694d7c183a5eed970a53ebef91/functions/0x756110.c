
void FUN_00756110(char param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  int *in_ECX;
  undefined4 ***pppuVar3;
  undefined4 local_8c;
  uint local_78;
  undefined4 **local_70 [4];
  undefined4 local_60;
  uint local_5c;
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ec73;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = FUN_004297b0(local_14);
  local_8 = 0;
  local_5c = 0xf;
  local_60 = 0;
  local_70[0] = (undefined4 **)((uint)local_70[0] & 0xffffff00);
  FUN_00402bb0(uVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (0xf < local_78) {
    FUN_0089120c(local_8c);
  }
  pppuVar3 = (undefined4 ***)local_70[0];
  if (local_5c < 0x10) {
    pppuVar3 = local_70;
  }
  uVar1 = (**(code **)(*in_ECX + 0x14))();
  pcVar2 = "true";
  if (param_1 == '\0') {
    pcVar2 = "false";
  }
  FUN_00730d80(local_54,&DAT_00bfc638,pcVar2);
  FUN_0072e770(uVar1,pppuVar3);
  if (0xf < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

