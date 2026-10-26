
int * FUN_006486f0(void)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6e8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pvVar2 = _malloc(0x250);
  piVar3 = (int *)0x0;
  local_8 = 0;
  if (pvVar2 != (void *)0x0) {
    piVar3 = (int *)FUN_006487b0(uVar1);
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00405370();
  *(undefined1 *)(piVar3 + 0x56) = *(undefined1 *)(in_ECX + 0x158);
  FUN_00405420(in_ECX + 0x15c);
  piVar3[0x92] = *(int *)(in_ECX + 0x248);
  piVar3[0x93] = *(int *)(in_ECX + 0x24c);
  (**(code **)(*piVar3 + 0x34))();
  ExceptionList = local_10;
  return piVar3;
}

