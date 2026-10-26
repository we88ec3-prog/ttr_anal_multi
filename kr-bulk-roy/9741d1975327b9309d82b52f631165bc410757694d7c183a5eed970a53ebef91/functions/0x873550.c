
undefined4 * FUN_00873550(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917e00;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  local_8 = 0;
  *param_1 = gbBase::vftable;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_00403040(unaff_EDI + 8,0,0xffffffff);
  param_1[9] = 1;
  local_8 = 1;
  *param_1 = gbTransformController::vftable;
  param_1[10] = 0xa1130000;
  param_1[0xb] = 1;
  param_1[0xc] = 0;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  if (*(int *)(unaff_EDI + 0x38) != 0) {
    uVar2 = (**(code **)(**(int **)(unaff_EDI + 0x38) + 8))(uVar1);
    param_1[0xe] = uVar2;
  }
  if (*(int *)(unaff_EDI + 0x30) != 0) {
    uVar2 = (**(code **)(**(int **)(unaff_EDI + 0x30) + 8))();
    param_1[0xc] = uVar2;
  }
  if (*(int *)(unaff_EDI + 0x34) != 0) {
    uVar2 = (**(code **)(**(int **)(unaff_EDI + 0x34) + 8))();
    param_1[0xd] = uVar2;
  }
  ExceptionList = local_10;
  return param_1;
}

