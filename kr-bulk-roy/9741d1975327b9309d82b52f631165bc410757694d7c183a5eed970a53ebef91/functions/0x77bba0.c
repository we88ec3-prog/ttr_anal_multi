
void FUN_0077bba0(void *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907ca3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar1 = *(int **)((int)param_1 + 0x78);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    *(undefined4 *)((int)param_1 + 0x78) = 0;
  }
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(param_1,0x14,6,FUN_005f5d10);
  ExceptionList = local_10;
  return;
}

