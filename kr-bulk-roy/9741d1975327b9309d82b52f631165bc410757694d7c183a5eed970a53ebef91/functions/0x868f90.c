
void FUN_00868f90(void)

{
  void *pvVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908ca8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbMorphController::vftable;
  local_8 = 0;
  pvVar1 = (void *)in_ECX[0xd];
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar1,0x58,*(int *)((int)pvVar1 + -4),FUN_00868c00);
    FUN_00891d3d((int)pvVar1 + -4);
    in_ECX[0xd] = 0;
  }
  in_ECX[0xc] = 0;
  *in_ECX = gbBase::vftable;
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2],uVar2);
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = gbRefCount::vftable;
  ExceptionList = local_10;
  return;
}

