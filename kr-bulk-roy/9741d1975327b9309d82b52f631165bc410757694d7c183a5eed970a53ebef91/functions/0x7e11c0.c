
void FUN_007e11c0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  uint local_48;
  
  piVar9 = *(int **)(*(int *)(in_EAX + 0xc + *(int *)(in_EAX + 8) * 4) + 4);
  piVar10 = *(int **)(*(int *)(in_EAX + 0xc + *(int *)(in_EAX + 4) * 4) + 4);
  if (piVar9 == (int *)0x0) {
    piVar9 = *(int **)(*(int *)(in_EAX + 0xc) + 4);
  }
  if (piVar10 == (int *)0x0) {
    piVar10 = *(int **)(*(int *)(in_EAX + 0xc) + 4);
  }
  if ((piVar9 != (int *)0x0) && (piVar10 != (int *)0x0)) {
    uVar8 = piVar9[0xd4];
    fVar2 = 1.0 - *(float *)(in_EAX + 0x30);
    uVar6 = piVar10[0xd4];
    fVar1 = *(float *)(in_EAX + 0x30);
    fVar3 = fVar1 * (float)(uVar8 >> 0x10 & 0xff) * 0.003921569 +
            fVar2 * (float)(uVar6 >> 0x10 & 0xff) * 0.003921569;
    fVar4 = (float)(uVar8 >> 8 & 0xff) * 0.003921569 * fVar1 +
            (float)(uVar6 >> 8 & 0xff) * 0.003921569 * fVar2;
    fVar5 = fVar1 * (float)(uVar8 & 0xff) * 0.003921569 +
            (float)(uVar6 & 0xff) * 0.003921569 * fVar2;
    fVar1 = *(float *)(in_EAX + 0x30);
    if (fVar3 < 1.0) {
      if (0.0 < fVar3) {
        local_48 = (uint)(longlong)ROUND(fVar3 * 255.0 + 0.5);
        uVar8 = local_48;
      }
      else {
        uVar8 = 0;
      }
    }
    else {
      uVar8 = 0xff;
    }
    if (fVar4 < 1.0) {
      if (fVar4 < 0.0 == (fVar4 == 0.0)) {
        local_48 = (uint)(longlong)ROUND(fVar4 * 255.0 + 0.5);
        uVar6 = local_48;
      }
      else {
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0xff;
    }
    if (fVar5 < 1.0) {
      if (fVar5 < 0.0 == (fVar5 == 0.0)) {
        local_48 = (uint)(longlong)ROUND(fVar5 * 255.0 + 0.5);
        uVar7 = local_48;
      }
      else {
        uVar7 = 0;
      }
    }
    else {
      uVar7 = 0xff;
    }
    if (fVar1 < 1.0) {
      if (0.0 < fVar1) {
        local_48 = (uint)(longlong)ROUND(fVar1 * 255.0 + 0.5);
      }
      else {
        local_48 = 0;
      }
    }
    else {
      local_48 = 0xff;
    }
    piVar9[0xd4] = ((local_48 << 8 | uVar8) << 8 | uVar6) << 8 | uVar7;
    if (fVar3 < 1.0) {
      if (0.0 < fVar3) {
        local_48 = (uint)(longlong)ROUND(fVar3 * 255.0 + 0.5);
        uVar8 = local_48;
      }
      else {
        uVar8 = 0;
      }
    }
    else {
      uVar8 = 0xff;
    }
    if (fVar4 < 1.0) {
      if (fVar4 < 0.0 == (fVar4 == 0.0)) {
        local_48 = (uint)(longlong)ROUND(fVar4 * 255.0 + 0.5);
        uVar6 = local_48;
      }
      else {
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0xff;
    }
    if (fVar5 < 1.0) {
      if (fVar5 < 0.0 == (fVar5 == 0.0)) {
        local_48 = (uint)(longlong)ROUND(fVar5 * 255.0 + 0.5);
        uVar7 = local_48;
      }
      else {
        uVar7 = 0;
      }
    }
    else {
      uVar7 = 0xff;
    }
    if (NAN(fVar2) || 1.0 < fVar2 == (fVar2 == 1.0)) {
      if (0.0 < fVar2) {
        local_48 = (uint)(longlong)ROUND(fVar2 * 255.0 + 0.5);
      }
      else {
        local_48 = 0;
      }
    }
    else {
      local_48 = 0xff;
    }
    piVar10[0xd4] = ((local_48 << 8 | uVar8) << 8 | uVar6) << 8 | uVar7;
    (**(code **)(*piVar10 + 8))();
    (**(code **)(*piVar9 + 8))();
  }
  return;
}

