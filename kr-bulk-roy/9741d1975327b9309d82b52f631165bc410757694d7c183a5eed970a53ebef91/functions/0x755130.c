
int * FUN_00755130(void)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6e8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = _malloc(0x8c);
  local_8 = 0;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_007451f0(uVar2);
    piVar3[0x20] = 0x3f800000;
    *piVar3 = (int)FoxUI::FXUIRDTarget::vftable;
    piVar3[0x21] = 0;
    piVar3[0x22] = 0;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00404de0(in_ECX);
  piVar3[0x20] = *(int *)(in_ECX + 0x80);
  piVar3[0x21] = *(int *)(in_ECX + 0x84);
  pcVar1 = *(code **)(*piVar3 + 0x34);
  piVar3[0x22] = *(int *)(in_ECX + 0x88);
  (*pcVar1)();
  ExceptionList = local_10;
  return piVar3;
}

