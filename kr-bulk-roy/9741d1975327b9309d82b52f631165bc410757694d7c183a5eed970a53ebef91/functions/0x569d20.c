
undefined4 FUN_00569d20(void)

{
  code *pcVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = DAT_00fe2844;
  puStack_c = &LAB_00938638;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  uVar2 = FUN_0056b630(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  (*pcVar1)(uVar2);
  ExceptionList = local_10;
  return 1;
}

