
int * FUN_00838980(int *param_1,int *param_2)

{
  int *piVar1;
  code *pcVar2;
  uint uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009050a8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = (int)gbDxVB::vftable;
  param_1[1] = (int)param_2;
  param_1[2] = 0;
  param_1[3] = in_ECX;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2,uVar3);
  }
  local_8 = 0;
  *param_1 = (int)gbDxDynamicVB::vftable;
  if ((param_1[5] != 0) && (piVar1 = (int *)param_1[2], piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x30))(piVar1);
    param_1[5] = 0;
  }
  pcVar2 = *(code **)(*param_1 + 8);
  param_1[4] = 0;
  (*pcVar2)();
  ExceptionList = local_10;
  return param_1;
}

