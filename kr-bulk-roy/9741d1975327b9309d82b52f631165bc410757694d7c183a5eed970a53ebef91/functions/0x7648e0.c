
void FUN_007648e0(float param_1)

{
  undefined4 uVar1;
  int *unaff_EDI;
  undefined1 auStack_1b8 [20];
  undefined4 **local_1a4 [5];
  uint local_190;
  undefined1 auStack_188 [260];
  uint local_84;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  local_44 = 0xffffffff;
  puStack_48 = &LAB_0091ee7b;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_1b8;
  ExceptionList = &local_4c;
  FUN_004297b0(DAT_00d61f20 ^ (uint)&stack0xfffffe40);
  local_44 = 0;
  if (local_190 < 0x10) {
    local_1a4[0] = local_1a4;
  }
  uVar1 = (**(code **)(*unaff_EDI + 0x14))();
  FUN_00730da0(auStack_188,&DAT_00c420d8,(double)param_1);
  FUN_0072e770(uVar1,local_1a4[0]);
  if (0xf < local_190) {
    FUN_0089120c();
  }
  ExceptionList = local_4c;
  __security_check_cookie(local_84 ^ (uint)auStack_1b8);
  return;
}

