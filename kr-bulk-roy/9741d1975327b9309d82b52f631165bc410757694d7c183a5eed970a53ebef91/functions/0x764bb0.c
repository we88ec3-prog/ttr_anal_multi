
void FUN_00764bb0(void)

{
  undefined4 ***pppuVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 **local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ee13;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004297b0(local_14);
  local_8 = 0;
  uVar2 = FUN_00891268(0x98);
  iVar3 = (int)uVar2;
  local_8 = CONCAT31(local_8._1_3_,1);
  if (iVar3 != 0) {
    pppuVar1 = (undefined4 ***)local_30[0];
    if (local_1c < 0x10) {
      pppuVar1 = local_30;
    }
    FUN_0072e420(iVar3,pppuVar1);
    uVar2 = CONCAT44(extraout_EDX,iVar3);
  }
  uVar4 = (undefined4)uVar2;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
    uVar2 = CONCAT44(extraout_EDX_00,uVar4);
  }
  ExceptionList = local_10;
  __security_check_cookie
            (local_14 ^ (uint)&stack0xfffffffc,(int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
  return;
}

