
void FUN_00764a50(short param_1)

{
  undefined4 uVar1;
  undefined4 ***pppuVar2;
  int *unaff_EDI;
  undefined4 **local_70 [5];
  uint local_5c;
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ee48;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004297b0(local_14);
  local_8 = 0;
  pppuVar2 = (undefined4 ***)local_70[0];
  if (local_5c < 0x10) {
    pppuVar2 = local_70;
  }
  uVar1 = (**(code **)(*unaff_EDI + 0x14))();
  FUN_00730d80(local_54,&DAT_00c0d6dc,(int)param_1);
  FUN_0072e770(uVar1,pppuVar2);
  if (0xf < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

