
void FUN_006dae50(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009080d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
    (**(code **)(*(int *)**(undefined4 **)(param_1 + 4) + 0xc))
              (DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    piVar1 = *(int **)(param_1 + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0xc))();
      if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar1)(1);
      }
      FUN_0089120c(piVar1);
      *(undefined4 *)(param_1 + 4) = 0;
    }
  }
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_((void *)(param_1 + 8),0x10,4,FUN_006dade0);
  ExceptionList = local_10;
  return;
}

