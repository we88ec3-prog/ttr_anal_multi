
void FUN_0083d790(int param_1)

{
  float fVar1;
  float *unaff_ESI;
  undefined1 local_24 [8];
  int local_1c;
  int local_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (**(code **)(**(int **)(param_1 + 0xec) + 0xc0))(*(int **)(param_1 + 0xec),local_24);
  fVar1 = (float)local_1c;
  if (local_1c < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  *unaff_ESI = fVar1;
  fVar1 = (float)local_18;
  if (local_18 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  unaff_ESI[1] = fVar1;
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

