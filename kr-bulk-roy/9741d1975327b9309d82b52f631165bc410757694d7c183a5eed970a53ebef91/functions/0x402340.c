
void FUN_00402340(uint param_1,undefined4 param_2)

{
  int *in_ECX;
  
  if (param_1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if (0x7ffffffe < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if ((uint)in_ECX[5] < param_1) {
    FUN_00402490(param_1,in_ECX[4]);
    if (param_1 == 0) {
      return;
    }
  }
  else if (param_1 == 0) {
    in_ECX[4] = 0;
    if ((uint)in_ECX[5] < 8) {
      *(undefined2 *)in_ECX = 0;
      return;
    }
    *(undefined2 *)*in_ECX = 0;
    return;
  }
  FUN_004022e0(0,param_1,param_2);
  in_ECX[4] = param_1;
  if ((uint)in_ECX[5] < 8) {
    *(undefined2 *)((int)in_ECX + param_1 * 2) = 0;
    return;
  }
  *(undefined2 *)(*in_ECX + param_1 * 2) = 0;
  return;
}

