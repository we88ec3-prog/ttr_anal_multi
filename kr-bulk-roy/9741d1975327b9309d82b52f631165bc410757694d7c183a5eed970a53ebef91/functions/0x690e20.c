
void FUN_00690e20(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint in_stack_0000001c;
  int in_stack_00000024;
  int in_stack_00000028;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092c718;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = (int *)0x0;
  local_8 = 0;
  iVar2 = *(int *)(*(int *)(param_1 + 0x138) + 0x24c);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0xcc);
    if (iVar2 != 0) {
      piVar3 = (int *)FUN_00412c70(*(undefined4 *)(iVar2 + 0xe4));
    }
    FUN_00757800(&param_2);
    if (piVar3 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar3 + 4))();
      if (iVar2 == 0x4b4) goto LAB_00690eb3;
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
  }
  piVar3 = (int *)0x0;
LAB_00690eb3:
  iVar2 = in_stack_00000028;
  FUN_00691c80(uVar1);
  piVar3[0x92] = in_stack_00000024;
  piVar3[0x93] = iVar2;
  if (7 < in_stack_0000001c) {
    FUN_0089120c(param_2);
  }
  ExceptionList = local_10;
  return;
}

