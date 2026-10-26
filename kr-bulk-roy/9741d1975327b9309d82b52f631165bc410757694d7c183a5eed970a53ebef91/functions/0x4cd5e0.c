
void FUN_004cd5e0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0091e3ce;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fe1bc8 & 1) == 0) {
    DAT_00fe1bc8 = DAT_00fe1bc8 | 1;
    local_c = 0;
    FUN_004cd0a0(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bcec10);
  }
  piVar1 = DAT_00fe1bcc;
  local_c = 0xffffffff;
  if (DAT_00fe1bcc != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_00fe1bcc + 0x10))();
    if (iVar2 != 0) {
      iVar2 = *(int *)(in_ECX + 4) + -1;
      uStack_20 = (**(code **)(*piVar1 + 0x14))();
      uStack_1c = (**(code **)(*piVar1 + 0x18))();
      FUN_004cd490(&uStack_20,(iVar2 / 6) % 7,in_stack_00000010,in_stack_00000014);
      FUN_004cd490(&uStack_20,5 - iVar2 % 6,in_stack_00000010,in_stack_00000014);
    }
  }
  ExceptionList = local_14;
  return;
}

