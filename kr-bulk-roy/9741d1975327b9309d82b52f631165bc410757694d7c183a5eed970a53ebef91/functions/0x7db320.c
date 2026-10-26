
void FUN_007db320(int param_1,float *param_2)

{
  float fVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  float local_14;
  float local_10;
  undefined8 local_c;
  
  fVar1 = *param_2;
  if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
    if (0.0 < *param_2) {
      local_c._0_4_ = (uint)(longlong)ROUND(*param_2 * 255.0 + 0.5);
      uVar2 = (uint)local_c;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xff;
  }
  fVar1 = param_2[1];
  if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
    if (0.0 < param_2[1]) {
      local_c._0_4_ = (uint)(longlong)ROUND(param_2[1] * 255.0 + 0.5);
      uVar4 = (uint)local_c;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xff;
  }
  if (1.0 < param_2[2] == (param_2[2] == 1.0)) {
    if (0.0 < param_2[2]) {
      local_c._0_4_ = (uint)(longlong)ROUND(param_2[2] * 255.0 + 0.5);
      uVar3 = (uint)local_c;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xff;
  }
  if (1.0 < param_2[3] == (param_2[3] == 1.0)) {
    if (0.0 < param_2[3]) {
      local_c._0_4_ = (uint)(longlong)ROUND(param_2[3] * 255.0 + 0.5);
    }
    else {
      local_c._0_4_ = 0;
    }
  }
  else {
    local_c._0_4_ = 0xff;
  }
  *(uint *)(in_ECX + 0xc + param_1 * 4) = (((uint)local_c << 8 | uVar2) << 8 | uVar4) << 8 | uVar3;
  local_14 = *param_2;
  local_10 = param_2[1];
  local_c = *(undefined8 *)(param_2 + 2);
  FUN_00855b30(&local_14);
  return;
}

