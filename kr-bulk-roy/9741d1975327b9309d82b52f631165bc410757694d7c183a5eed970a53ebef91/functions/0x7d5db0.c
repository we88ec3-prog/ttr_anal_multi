
void FUN_007d5db0(float param_1)

{
  float fVar1;
  float fVar2;
  float *unaff_ESI;
  float10 fVar3;
  int local_c;
  float local_8;
  
  if (param_1 == 0.0) {
    *unaff_ESI = 0.0;
    unaff_ESI[1] = 0.0;
    unaff_ESI[2] = 0.0;
    return;
  }
  local_8 = 0.0;
  FUN_0071baa0(&DAT_00c0ecb8);
  if (local_c != 0) {
    if (*(int *)(local_c + 8) == 0) {
      local_8 = 0.0;
    }
    else {
      fVar3 = (float10)FUN_00898a3f(*(int *)(local_c + 8),0);
      local_8 = (float)fVar3;
    }
  }
  fVar1 = local_8;
  local_8 = 0.0;
  FUN_0071baa0(&DAT_00c0ecbc);
  if (local_c != 0) {
    if (*(int *)(local_c + 8) == 0) {
      local_8 = 0.0;
    }
    else {
      fVar3 = (float10)FUN_00898a3f(*(int *)(local_c + 8),0);
      local_8 = (float)fVar3;
    }
  }
  fVar2 = local_8;
  local_8 = 0.0;
  FUN_0071baa0(&DAT_00c50174);
  if (local_c != 0) {
    if (*(int *)(local_c + 8) == 0) {
      param_1 = 0.0;
    }
    else {
      fVar3 = (float10)FUN_00898a3f(*(int *)(local_c + 8),0);
      param_1 = (float)fVar3;
    }
    local_8 = param_1;
  }
  *unaff_ESI = fVar1;
  unaff_ESI[1] = fVar2;
  unaff_ESI[2] = local_8;
  return;
}

