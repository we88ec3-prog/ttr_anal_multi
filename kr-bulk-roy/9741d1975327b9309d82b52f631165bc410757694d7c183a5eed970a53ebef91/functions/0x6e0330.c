
void FUN_006e0330(undefined4 param_1,undefined4 param_2)

{
  double *in_ECX;
  
  if ((float)in_ECX[3] <= (float)((float10)(double)CONCAT44(param_2,param_1) - (float10)*in_ECX)) {
    *(undefined4 *)(in_ECX + 4) = 1;
    *(undefined4 *)((int)in_ECX + 0x24) = 0;
    *in_ECX = in_ECX[3] + *in_ECX;
    return;
  }
  in_ECX[1] = (double)CONCAT44(param_2,param_1);
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)((int)in_ECX + 0x24) = 1;
  return;
}

