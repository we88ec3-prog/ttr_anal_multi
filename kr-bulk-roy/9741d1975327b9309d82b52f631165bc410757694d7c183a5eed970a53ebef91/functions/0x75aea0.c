
int * FUN_0075aea0(void)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b538;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pvVar2 = _malloc(0xcc);
  piVar3 = (int *)0x0;
  local_8 = 0;
  if (pvVar2 != (void *)0x0) {
    piVar3 = (int *)FUN_0075af30(uVar1);
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00404f50();
  *(undefined1 *)(piVar3 + 0x32) = *(undefined1 *)(in_ECX + 200);
  (**(code **)(*piVar3 + 0x34))();
  ExceptionList = local_10;
  return piVar3;
}

