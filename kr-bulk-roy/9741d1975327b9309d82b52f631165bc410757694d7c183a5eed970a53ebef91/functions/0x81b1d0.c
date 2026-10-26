
void FUN_0081b1d0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009072e3;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CSkillInterrupt::vftable;
  piVar1 = param_1 + 2;
  local_8 = 1;
  FUN_00523e40(piVar1,uVar2);
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
    param_1[6] = 0;
  }
  if (*piVar1 != 0) {
    FUN_0089120c(*piVar1);
  }
  *piVar1 = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = CRTTI<CModifier>::vftable;
  ExceptionList = local_10;
  return;
}

