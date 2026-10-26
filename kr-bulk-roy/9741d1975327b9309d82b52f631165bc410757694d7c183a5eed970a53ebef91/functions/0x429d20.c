
int * FUN_00429d20(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926e00;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0x194);
  local_8 = 0;
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    FUN_00744320(uVar1);
    local_8 = CONCAT31(local_8._1_3_,1);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
    *piVar2 = (int)FoxUI::FXUIButtonResizeMB::vftable;
    piVar3 = piVar2;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00404ed0();
  *(undefined1 *)(piVar3 + 0x29) = *(undefined1 *)(in_ECX + 0xa4);
  FUN_00405420(in_ECX + 0xa8);
  (**(code **)(*piVar3 + 0x34))();
  ExceptionList = local_10;
  return piVar3;
}

