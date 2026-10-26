
void FUN_00402800(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX != param_1) {
    if (7 < (uint)in_ECX[5]) {
      FUN_0089120c(*in_ECX);
    }
    in_ECX[5] = 7;
    in_ECX[4] = 0;
    *(undefined2 *)in_ECX = 0;
    if ((uint)param_1[5] < 8) {
      FID_conflict__memcpy(in_ECX,param_1,param_1[4] * 2 + 2);
    }
    else {
      *in_ECX = *param_1;
      *param_1 = 0;
    }
    in_ECX[4] = param_1[4];
    in_ECX[5] = param_1[5];
    param_1[5] = 7;
    param_1[4] = 0;
    *(undefined2 *)param_1 = 0;
  }
  return;
}

