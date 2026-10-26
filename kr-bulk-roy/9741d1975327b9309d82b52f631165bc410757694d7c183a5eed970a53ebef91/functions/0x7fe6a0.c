
void FUN_007fe6a0(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined4 auStack_c0 [8];
  undefined4 uStack_a0;
  int iStack_9c;
  undefined4 uStack_98;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093210e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  fVar2 = param_1 * 30.0 + *(float *)(in_ECX + 0x80);
  *(float *)(in_ECX + 0x80) = fVar2;
  if (*(float *)(in_ECX + 0x84) < fVar2) {
    *(undefined4 *)(in_ECX + 0x80) = 0;
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0();
    uStack_98 = 0x7fe722;
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  uStack_98 = 0x7fe73f;
  pfVar5 = (float *)(**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))();
  fVar2 = *(float *)(in_ECX + 0x34) - *pfVar5;
  fVar3 = *(float *)(in_ECX + 0x38) - pfVar5[1];
  fVar4 = *(float *)(in_ECX + 0x3c) - pfVar5[2];
  if ((0.0 < *(float *)(in_ECX + 0x84)) &&
     (fVar1 = *(float *)(*(int *)(in_ECX + 0x7c) + 0x14),
     fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3 < fVar1 * fVar1)) {
    iVar6 = **(int **)(in_ECX + 0x30);
    uStack_98 = 0x7fe7c4;
    uStack_98 = FUN_008fed10();
    iStack_9c = 0x7fe7cc;
    (**(code **)(iVar6 + 0x1c))();
    *(undefined4 *)(in_ECX + 0x78) = 1;
  }
  if ((*(int *)(in_ECX + 0x88) != 0) && (*(int *)(in_ECX + 0x8c) != 0)) {
    *(undefined4 *)(in_ECX + 0x8c) = 0;
    uStack_98 = 0x7fe7fb;
    uVar9 = FUN_0077ef30();
    puVar7 = (undefined4 *)uVar9;
    puVar8 = auStack_c0;
    for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    FUN_00803070((int)((ulonglong)uVar9 >> 0x20));
  }
  if (*(int *)(in_ECX + 0x78) != 0) {
    iStack_9c = *(int *)(in_ECX + 0x30);
    *(undefined4 *)(in_ECX + 0x78) = 0;
    uStack_98 = *(undefined4 *)(iStack_9c + 0x30);
    uStack_a0 = 0x7fe829;
    FUN_00780150();
    if (*(int *)(in_ECX + 0x44) != 0) {
      uStack_98 = 0x7fe836;
      FUN_007fed70();
    }
  }
  ExceptionList = local_10;
  return;
}

