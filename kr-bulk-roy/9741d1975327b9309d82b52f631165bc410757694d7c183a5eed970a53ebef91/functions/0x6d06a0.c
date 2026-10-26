
float10 FUN_006d06a0(float param_1)

{
  uint uVar1;
  uint in_ECX;
  undefined4 local_8;
  
  uVar1 = in_ECX;
  if ((int)in_ECX < 0) {
    uVar1 = -in_ECX;
  }
  local_8 = 1.0;
  while( true ) {
    if ((uVar1 & 1) != 0) {
      local_8 = local_8 * param_1;
    }
    uVar1 = uVar1 >> 1;
    if (uVar1 == 0) break;
    param_1 = param_1 * param_1;
  }
  if ((int)in_ECX < 0) {
    local_8 = 1.0 / local_8;
  }
  return (float10)local_8;
}

