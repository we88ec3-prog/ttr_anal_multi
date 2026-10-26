
void FUN_00471a20(int *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 ****ppppuVar4;
  undefined4 ***local_70 [5];
  uint local_5c;
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922488;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  cVar1 = FUN_00749460(param_1);
  if (cVar1 != '\0') {
    FUN_007448d0(uVar2);
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xd0));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xd4));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0xd8));
    FUN_004297b0();
    local_8 = 0;
    ppppuVar4 = (undefined4 ****)local_70[0];
    if (local_5c < 0x10) {
      ppppuVar4 = local_70;
    }
    uVar3 = (**(code **)(*param_1 + 0x14))();
    FUN_00730d80(local_54,&DAT_00bfc638,&DAT_00bf943c);
    FUN_0072e770(uVar3,ppppuVar4);
    if (0xf < local_5c) {
      FUN_0089120c(local_70[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

