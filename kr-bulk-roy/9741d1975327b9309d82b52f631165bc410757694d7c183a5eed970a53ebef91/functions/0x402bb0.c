
void FUN_00402bb0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  if (in_ECX != param_1) {
    if (0xf < (uint)in_ECX[5]) {
      FUN_0089120c(*in_ECX);
    }
    in_ECX[5] = 0xf;
    in_ECX[4] = 0;
    *(undefined1 *)in_ECX = 0;
    if ((uint)param_1[5] < 0x10) {
      FID_conflict__memcpy(in_ECX,param_1,param_1[4] + 1);
    }
    else {
      *in_ECX = *param_1;
      *param_1 = 0;
    }
    in_ECX[4] = param_1[4];
    in_ECX[5] = param_1[5];
    param_1[5] = 0xf;
    param_1[4] = 0;
    *(undefined1 *)param_1 = 0;
  }
  return;
}

