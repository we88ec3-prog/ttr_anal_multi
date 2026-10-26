
void FUN_004cdad0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00913328;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CCharacter::vftable;
  param_1[0x3c] = CCharacter::vftable;
  local_8 = 0;
  if ((undefined4 *)param_1[0x10b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x10b])(1,uVar2);
    param_1[0x10b] = 0;
  }
  if ((undefined4 *)param_1[0x10c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x10c])(1);
    param_1[0x10c] = 0;
  }
  iVar1 = param_1[0x10f];
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_0089120c(*(int *)(iVar1 + 8));
    }
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    FUN_0089120c(iVar1);
    param_1[0x10f] = 0;
  }
  param_1[0x10e] = 0;
  local_8 = 0xffffffff;
  FUN_004c7b90();
  ExceptionList = local_10;
  return;
}

