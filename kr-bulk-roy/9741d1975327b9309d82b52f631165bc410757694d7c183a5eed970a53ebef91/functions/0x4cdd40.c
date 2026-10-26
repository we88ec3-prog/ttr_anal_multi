
undefined4 FUN_004cdd40(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *in_ECX;
  float10 fVar7;
  float local_c;
  
  uVar5 = FUN_004c8580();
  if (in_ECX[0x109] != 0) {
    puVar6 = (undefined4 *)(**(code **)(*in_ECX + 0x4c))();
    uVar1 = puVar6[1];
    fVar2 = (float)puVar6[2];
    uVar3 = *puVar6;
    if ((in_ECX[0x57] == 0) || (in_ECX[0xdc] == 0)) {
      local_c = 0.0;
    }
    else {
      fVar7 = (float10)FUN_007a7100();
      local_c = (float)fVar7;
    }
    iVar4 = *(int *)(in_ECX[0x109] + 0x24);
    if (iVar4 != 0) {
      *(undefined4 *)(iVar4 + 0x28) = uVar3;
      *(undefined4 *)(iVar4 + 0x2c) = uVar1;
      *(float *)(iVar4 + 0x30) = local_c + 3.0 + fVar2;
      *(undefined4 *)(iVar4 + 0x70) = 1;
    }
    FUN_00550780();
    if (*(int *)(in_ECX[0x109] + 0x74) != 0) {
      if (*(int *)(in_ECX[0x109] + 0x24) != 0) {
        FUN_007be5f0();
      }
      if (in_ECX[0x109] != 0) {
        FUN_004c7db0();
        in_ECX[0x109] = 0;
      }
    }
    return uVar5;
  }
  return uVar5;
}

