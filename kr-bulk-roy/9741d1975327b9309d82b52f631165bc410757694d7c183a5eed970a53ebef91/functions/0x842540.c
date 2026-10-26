
void FUN_00842540(int param_1,int param_2)

{
  void **ppvVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00909130;
  ppvVar1 = &local_10;
  local_10 = ExceptionList;
  for (; ExceptionList = ppvVar1, param_1 != param_2; param_1 = param_1 + 0x11c) {
    local_8 = 2;
    FUN_00843650(param_1);
    local_8._0_1_ = 1;
    _eh_vector_destructor_iterator_((void *)(param_1 + 0x90),0x10,8,FUN_00843020);
    local_8 = (uint)local_8._1_3_ << 8;
    _eh_vector_destructor_iterator_((void *)(param_1 + 0x10),0x10,8,FUN_00843020);
    local_8 = 3;
    FUN_005540c0(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
    local_8 = 0xffffffff;
    FUN_0089120c(*(undefined4 *)(param_1 + 4));
    ppvVar1 = ExceptionList;
  }
  ExceptionList = local_10;
  return;
}

