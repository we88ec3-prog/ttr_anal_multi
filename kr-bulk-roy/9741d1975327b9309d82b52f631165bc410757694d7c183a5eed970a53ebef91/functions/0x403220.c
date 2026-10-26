
undefined4 FUN_00403220(void)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d9c8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pvVar2 = _malloc(0x284);
  local_8 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_00403580(uVar1,pvVar2);
    ExceptionList = local_10;
    return uVar3;
  }
  ExceptionList = local_10;
  return 0;
}

