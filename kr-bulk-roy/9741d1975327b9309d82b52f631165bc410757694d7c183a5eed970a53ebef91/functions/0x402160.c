
void FUN_00402160(int *param_1,uint param_2)

{
  uint uVar1;
  size_t _Size;
  int *piVar2;
  int *in_ECX;
  
  if (param_1 != (int *)0x0) {
    uVar1 = in_ECX[5];
    piVar2 = in_ECX;
    if (7 < uVar1) {
      piVar2 = (int *)*in_ECX;
    }
    if (piVar2 <= param_1) {
      piVar2 = in_ECX;
      if (7 < uVar1) {
        piVar2 = (int *)*in_ECX;
      }
      if (param_1 < (int *)((int)piVar2 + in_ECX[4] * 2)) {
        piVar2 = in_ECX;
        if (7 < uVar1) {
          piVar2 = (int *)*in_ECX;
        }
        FUN_004026e0(in_ECX,(int)param_1 - (int)piVar2 >> 1,param_2);
        return;
      }
    }
  }
  if (0x7ffffffe < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if ((uint)in_ECX[5] < param_2) {
    FUN_00402490(param_2,in_ECX[4]);
    if (param_2 == 0) {
      return;
    }
  }
  else if (param_2 == 0) {
    in_ECX[4] = 0;
    if (7 < (uint)in_ECX[5]) {
      *(undefined2 *)*in_ECX = 0;
      return;
    }
    *(undefined2 *)in_ECX = 0;
    return;
  }
  piVar2 = in_ECX;
  if (7 < (uint)in_ECX[5]) {
    piVar2 = (int *)*in_ECX;
  }
  _Size = param_2 * 2;
  FID_conflict__memcpy(piVar2,param_1,_Size);
  in_ECX[4] = param_2;
  if ((uint)in_ECX[5] < 8) {
    *(undefined2 *)(_Size + (int)in_ECX) = 0;
    return;
  }
  *(undefined2 *)(_Size + *in_ECX) = 0;
  return;
}

