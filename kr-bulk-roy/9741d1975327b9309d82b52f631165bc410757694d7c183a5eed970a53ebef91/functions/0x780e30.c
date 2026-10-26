
undefined4
FUN_00780e30(undefined4 param_1,float param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,float param_6)

{
  float fVar1;
  undefined4 in_EAX;
  undefined4 *in_ECX;
  undefined1 local_28 [16];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  fVar1 = param_2 * 0.5;
  local_8 = 0.0;
  if (3.1414926 <= fVar1) {
    if (3.1414926 < fVar1) {
      do {
        fVar1 = fVar1 - 3.1415927;
        local_8 = local_8 + 1.0;
      } while (fVar1 < 3.1414926 == (fVar1 == 3.1414926));
    }
    if (fVar1 < 0.0) {
      fVar1 = 0.0;
    }
    param_2 = (param_6 * param_2) / 3.1415927;
    if (1.0 <= param_2) {
      local_8 = (param_2 + 1.0) - (local_8 + fVar1 / 3.1415927) * 2.0;
      if (local_8 <= 0.0) {
        if (!NAN(param_2) && 2.0 < param_2 != (param_2 == 2.0)) {
          do {
            param_2 = param_2 - 2.0;
          } while (2.0 <= param_2);
        }
        local_18 = *in_ECX;
        local_14 = in_ECX[1];
        local_10 = in_ECX[2];
        local_c = 0;
        FUN_0077e880(in_EAX);
        FUN_00780c60(local_28,param_2);
        return param_1;
      }
      local_18 = *in_ECX;
      local_14 = in_ECX[1];
      local_10 = in_ECX[2];
      local_c = 0;
      FUN_0077e880(param_5);
      FUN_00780dc0(param_1,local_28,param_5,local_8);
      return param_1;
    }
    local_18 = *in_ECX;
    local_14 = in_ECX[1];
    local_10 = in_ECX[2];
    local_c = 0;
    FUN_0077e880(in_EAX);
  }
  FUN_00780dc0(param_1);
  return param_1;
}

