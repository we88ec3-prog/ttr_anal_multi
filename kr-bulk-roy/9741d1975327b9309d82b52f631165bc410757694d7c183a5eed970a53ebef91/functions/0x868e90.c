
void FUN_00868e90(undefined4 *param_1,int param_2)

{
  void *pvVar1;
  code *pcVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917f60;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  local_8 = 0;
  *param_1 = gbBase::vftable;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_00403040(param_2 + 8,0,0xffffffff);
  param_1[9] = 1;
  *param_1 = gbController::vftable;
  param_1[10] = *(undefined4 *)(param_2 + 0x28);
  param_1[0xb] = *(undefined4 *)(param_2 + 0x2c);
  local_8 = 1;
  *param_1 = gbMorphController::vftable;
  param_1[10] = 0xa1240000;
  param_1[0xc] = *(undefined4 *)(param_2 + 0x30);
  pvVar1 = (void *)param_1[0xd];
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar1,0x58,*(int *)((int)pvVar1 + -4),FUN_00868c00);
    FUN_00891d3d((int)pvVar1 + -4,uVar3);
    param_1[0xd] = 0;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

