
int * FUN_00585df0(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920d88;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0x104);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_007564e0(uVar1);
    piVar2[0x3b] = 0;
    *(undefined1 *)(piVar2 + 0x3c) = 0;
    *piVar2 = (int)FUI::CMsgBoxWaitTimer::vftable;
    piVar2[0x3d] = 0;
    piVar2[0x3e] = 0;
    piVar2[0x3f] = 0;
    piVar2[0x40] = 0;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 0x30))();
  FUN_005861c0();
  (**(code **)(*piVar2 + 0x34))(in_ECX);
  ExceptionList = local_10;
  return piVar2;
}

