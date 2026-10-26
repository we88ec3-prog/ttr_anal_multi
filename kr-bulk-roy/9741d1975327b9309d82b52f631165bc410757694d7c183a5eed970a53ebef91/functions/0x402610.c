
bool FUN_00402610(uint param_1,char param_2)

{
  uint uVar1;
  void *_Src;
  undefined4 *in_ECX;
  uint uVar2;
  
  if (0x7ffffffe < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  uVar1 = in_ECX[5];
  if (uVar1 < param_1) {
    FUN_00402490(param_1,in_ECX[4]);
    return param_1 != 0;
  }
  if ((param_2 != '\0') && (param_1 < 8)) {
    uVar2 = in_ECX[4];
    if (param_1 < (uint)in_ECX[4]) {
      uVar2 = param_1;
    }
    if (7 < uVar1) {
      _Src = (void *)*in_ECX;
      if (uVar2 != 0) {
        FID_conflict__memcpy(in_ECX,_Src,uVar2 * 2);
      }
      FUN_0089120c(_Src);
    }
    in_ECX[4] = uVar2;
    in_ECX[5] = 7;
    *(undefined2 *)((int)in_ECX + uVar2 * 2) = 0;
    return param_1 != 0;
  }
  if (param_1 == 0) {
    in_ECX[4] = 0;
    if (7 < uVar1) {
      in_ECX = (undefined4 *)*in_ECX;
    }
    *(undefined2 *)in_ECX = 0;
  }
  return param_1 != 0;
}

