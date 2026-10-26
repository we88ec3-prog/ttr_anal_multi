
int * FUN_0068a840(void)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6e8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = _malloc(0x174);
  local_8 = 0;
  piVar4 = (int *)0x0;
  if (piVar3 != (int *)0x0) {
    FUN_00761150(uVar2);
    piVar3[0x5c] = 0;
    *piVar3 = (int)FUI::CEditDigitalCommaInclude::vftable;
    piVar3[0x5b] = 100000000;
    piVar4 = piVar3;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar4 + 0x30))();
  FUN_00643e20();
  piVar4[0x5b] = *(int *)(in_ECX + 0x16c);
  pcVar1 = *(code **)(*piVar4 + 0x34);
  piVar4[0x5c] = *(int *)(in_ECX + 0x170);
  (*pcVar1)();
  ExceptionList = local_10;
  return piVar4;
}

