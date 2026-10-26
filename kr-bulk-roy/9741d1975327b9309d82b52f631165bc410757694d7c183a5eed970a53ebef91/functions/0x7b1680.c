
size_t FUN_007b1680(void *param_1,uint param_2)

{
  uint uVar1;
  uint in_ECX;
  undefined4 *in_EDX;
  
  if (in_ECX <= (uint)in_EDX[4]) {
    uVar1 = in_EDX[4] - in_ECX;
    if (uVar1 < param_2) {
      param_2 = uVar1;
    }
    if (0xf < (uint)in_EDX[5]) {
      in_EDX = (undefined4 *)*in_EDX;
    }
    FID_conflict__memcpy(param_1,(void *)((int)in_EDX + in_ECX),param_2);
    return param_2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db7d("invalid string position");
}

