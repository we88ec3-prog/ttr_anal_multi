
undefined4 * FUN_0086a3b0(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917f29;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  local_8 = 0;
  *param_1 = gbBase::vftable;
  param_1[6] = 0;
  param_1[7] = 0xf;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_00403040(param_2 + 8,0,0xffffffff);
  param_1[9] = 1;
  local_8 = 1;
  *param_1 = gbParticle::vftable;
  FUN_00869f50(uVar1);
  FUN_0086a1b0();
  local_8 = CONCAT31(local_8._1_3_,3);
  puVar5 = param_1 + 0xd0;
  *puVar5 = 0;
  param_1[0xd1] = 0;
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  *puVar5 = 0;
  param_1[0xd1] = 0;
  param_1[0xd6] = 0x3f800000;
  param_1[0xd2] = 0x3f800000;
  param_1[0xd3] = 0x3f800000;
  param_1[0xd5] = 1;
  param_1[0xd4] = 1;
  (**(code **)(param_1[10] + 4))(param_2 + 0x28);
  (**(code **)(param_1[0x19] + 4))(param_2 + 100);
  (**(code **)(param_1[0x28] + 4))(param_2 + 0xa0);
  (**(code **)(param_1[0x37] + 4))(param_2 + 0xdc);
  (**(code **)(param_1[0x46] + 4))(param_2 + 0x118);
  (**(code **)(param_1[0x55] + 4))(param_2 + 0x154);
  (**(code **)(param_1[100] + 4))(param_2 + 400);
  (**(code **)(param_1[0x73] + 4))(param_2 + 0x1cc);
  (**(code **)(param_1[0x82] + 4))(param_2 + 0x208);
  (**(code **)(param_1[0x91] + 4))(param_2 + 0x244);
  (**(code **)(param_1[0xa0] + 4))(param_2 + 0x280);
  (**(code **)(param_1[0xaf] + 4))(param_2 + 700);
  param_1[0xbe] = *(undefined4 *)(param_2 + 0x2f8);
  (**(code **)(param_1[0xbf] + 4))(param_2 + 0x2fc);
  param_1[0xce] = *(undefined4 *)(param_2 + 0x338);
  if (*(int *)(param_2 + 0x35c) == 0) {
    param_1[0xd7] = 0;
  }
  else {
    uVar2 = (**(code **)(**(int **)(param_2 + 0x35c) + 0x10))();
    param_1[0xd7] = uVar2;
  }
  param_1[0xcf] = *(undefined4 *)(param_2 + 0x33c);
  puVar4 = (undefined4 *)(param_2 + 0x340);
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  param_1[0xd8] = *(undefined4 *)(param_2 + 0x360);
  param_1[0xd9] = *(undefined4 *)(param_2 + 0x364);
  puVar5 = (undefined4 *)(param_2 + 0x340);
  puVar4 = param_1 + 0xd0;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[9] = 0;
  ExceptionList = local_10;
  return param_1;
}

