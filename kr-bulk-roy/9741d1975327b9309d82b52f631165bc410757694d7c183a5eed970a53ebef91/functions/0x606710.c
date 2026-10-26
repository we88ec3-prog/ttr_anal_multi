
void FUN_00606710(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  int iVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a7f4;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CPackageProvideProductsDlg::vftable;
  in_ECX[0x3d] = FUI::CPackageProvideProductsDlg::vftable;
  local_8 = 2;
  piVar3 = in_ECX + 0x45;
  iVar2 = 3;
  do {
    if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar3)(1,uVar1);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (in_ECX[0x41] != 0) {
    FUN_0089120c(in_ECX[0x41]);
  }
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = 0;
  in_ECX[0x3d] = IInventoryUpdateObserver::vftable;
  *in_ECX = FoxUI::FXUIWindow::vftable;
  local_8 = 4;
  FUN_00757640(in_ECX + 0x28);
  if (7 < (uint)in_ECX[0x26]) {
    FUN_0089120c(in_ECX[0x21]);
  }
  in_ECX[0x26] = 7;
  in_ECX[0x25] = 0;
  *(undefined2 *)(in_ECX + 0x21) = 0;
  local_8 = 0xffffffff;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

