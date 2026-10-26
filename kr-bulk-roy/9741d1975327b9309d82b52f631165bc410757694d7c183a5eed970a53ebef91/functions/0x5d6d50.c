
int * FUN_005d6d50(void)

{
  uint uVar1;
  void *pvVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b538;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pvVar2 = _malloc(0x298);
  piVar3 = (int *)0x0;
  local_8 = 0;
  if (pvVar2 != (void *)0x0) {
    piVar3 = (int *)FUN_005d6dd0(uVar1);
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00408e60(piVar3);
  (**(code **)(*piVar3 + 0x34))();
  ExceptionList = local_10;
  return piVar3;
}

