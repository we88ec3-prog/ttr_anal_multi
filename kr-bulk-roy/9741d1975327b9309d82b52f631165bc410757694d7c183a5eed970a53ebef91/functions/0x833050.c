
void FUN_00833050(int param_1)

{
  int *piVar1;
  void *pvVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009050fb;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  pvVar2 = *(void **)(param_1 + 0x18);
  if (pvVar2 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar2,0x10,*(int *)((int)pvVar2 + -4),FUN_00837b60);
    FUN_00891d3d((int)pvVar2 + -4);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  piVar1 = (int *)(param_1 + 0x1c);
  FUN_008333d0(piVar1,uVar3);
  if (*piVar1 != 0) {
    FUN_0089120c(*piVar1);
  }
  *piVar1 = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  ExceptionList = local_10;
  return;
}

