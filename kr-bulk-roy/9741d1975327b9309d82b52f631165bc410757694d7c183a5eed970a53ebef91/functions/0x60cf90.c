
undefined4 * FUN_0060cf90(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00921820;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0;
  *param_1 = FUI::UICachingData<234,FUI::CPhaseToolTip>::vftable;
  puVar2 = _malloc(0x174);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00754880(uVar1);
    *(undefined1 *)(puVar2 + 0x56) = 1;
    *puVar2 = FUI::CPhaseToolTip::vftable;
    *(undefined2 *)(puVar2 + 0x57) = 0;
    puVar2[0x58] = 0;
    puVar2[0x59] = 0;
    puVar2[0x5a] = 0;
    puVar2[0x5b] = 0;
    puVar2[0x5c] = 0;
  }
  param_1[3] = puVar2;
  param_1[1] = 0xea;
  ExceptionList = local_10;
  return param_1;
}

