
void FUN_0088b1fa(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX != param_1) {
    FID_conflict__Tidy(1,0);
    if ((uint)param_1[5] < 8) {
      FID_conflict__memcpy(in_ECX,param_1,param_1[4] * 2 + 2);
    }
    else {
      *in_ECX = *param_1;
      *param_1 = 0;
    }
    in_ECX[4] = param_1[4];
    in_ECX[5] = param_1[5];
    param_1[4] = 0;
    param_1[5] = 7;
    *(undefined2 *)param_1 = 0;
  }
  return;
}

