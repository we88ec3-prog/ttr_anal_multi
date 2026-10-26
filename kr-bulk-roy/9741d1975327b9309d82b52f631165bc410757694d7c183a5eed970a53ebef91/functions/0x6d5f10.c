
undefined4 * FUN_006d5f10(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905c13;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fe2770 = param_1;
  local_8 = 0;
  piVar1 = param_1 + 2;
  *param_1 = CPostEffectMgr::vftable;
  param_1[1] = 0;
  *piVar1 = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  FUN_006d61d0(uVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  puVar3 = (undefined4 *)FUN_00891268(0x10);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 1;
    puVar3[2] = 1;
    puVar3[3] = 0;
    *puVar3 = CDummyPostEffect::vftable;
  }
  *(undefined4 **)*piVar1 = puVar3;
  puVar3 = (undefined4 *)FUN_00891268(0x78);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 1;
    puVar3[2] = 1;
    puVar3[3] = 1;
    *puVar3 = CPostEffect_Bloom::vftable;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    puVar3[0xc] = 0;
    puVar3[0xd] = 0;
    puVar3[0x1d] = 0;
  }
  *(undefined4 **)(*piVar1 + 4) = puVar3;
  puVar3 = (undefined4 *)FUN_00891268(0x80);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 1;
    puVar3[2] = 1;
    puVar3[3] = 2;
    *puVar3 = CPostEffect_Tone::vftable;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    puVar3[0xc] = 0;
    puVar3[0xd] = 0;
    puVar3[0x1e] = 0x100;
    puVar3[0x1f] = 0;
  }
  *(undefined4 **)(*piVar1 + 8) = puVar3;
  param_1[6] = *(undefined4 *)*piVar1;
  ExceptionList = local_10;
  return param_1;
}

