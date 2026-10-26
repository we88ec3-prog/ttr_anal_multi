
void FUN_00839530(float param_1)

{
  float *in_ECX;
  float *in_EDX;
  float local_8;
  
  if (*in_ECX < 1.0) {
    if (*in_ECX <= 0.0) {
      local_8 = 0.0;
      goto LAB_0083956a;
    }
    if (*in_ECX < 1.0) {
      local_8 = *in_ECX;
      goto LAB_0083956a;
    }
  }
  local_8 = 1.0;
LAB_0083956a:
  *in_EDX = local_8;
  if ((1.0 <= in_ECX[1]) || (0.0 < in_ECX[1])) {
    if (1.0 <= in_ECX[1]) {
      local_8 = 1.0;
    }
    else {
      local_8 = in_ECX[1];
    }
  }
  else {
    local_8 = 0.0;
  }
  in_EDX[1] = local_8;
  if ((1.0 <= in_ECX[2]) || (0.0 < in_ECX[2])) {
    if (1.0 <= in_ECX[2]) {
      local_8 = 1.0;
    }
    else {
      local_8 = in_ECX[2];
    }
  }
  else {
    local_8 = 0.0;
  }
  in_EDX[2] = local_8;
  if (param_1 < 1.0) {
    if (param_1 <= 0.0) {
      in_EDX[3] = 0.0;
      return;
    }
    in_EDX[3] = param_1;
    return;
  }
  in_EDX[3] = 1.0;
  return;
}

