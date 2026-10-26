
int * FUN_00459000(void)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920d88;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pvVar2 = _malloc(0x2f8);
  piVar3 = (int *)0x0;
  local_8 = 0;
  if (pvVar2 != (void *)0x0) {
    piVar3 = (int *)FUN_00459180(uVar1);
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00408e60(piVar3);
  piVar3[0xa6] = *(int *)(in_ECX + 0x298);
  FUN_0045d560();
  (**(code **)(*piVar3 + 0x34))(in_ECX);
  ExceptionList = local_10;
  return piVar3;
}

