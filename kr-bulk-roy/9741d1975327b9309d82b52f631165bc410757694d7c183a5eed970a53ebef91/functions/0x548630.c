
void FUN_00548630(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090cf78;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CSingleController::vftable;
  local_8 = 0;
  if ((undefined4 *)param_1[0x2e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x2e])(1,uVar2);
    param_1[0x2e] = 0;
  }
  piVar1 = (int *)param_1[0x2d];
  if (piVar1 != (int *)0x0) {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
      *piVar1 = 0;
    }
    FUN_0089120c(piVar1);
    param_1[0x2d] = 0;
  }
  local_8 = 0xffffffff;
  FUN_00544e80();
  ExceptionList = local_10;
  return;
}

