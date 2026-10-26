
bool FUN_00402f80(uint param_1,char param_2)

{
  uint uVar1;
  void *_Src;
  undefined4 *in_ECX;
  uint _Size;
  
  if (param_1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  uVar1 = in_ECX[5];
  if (uVar1 < param_1) {
    FUN_00402dc0(param_1,in_ECX[4]);
    return param_1 != 0;
  }
  if ((param_2 != '\0') && (param_1 < 0x10)) {
    _Size = in_ECX[4];
    if (param_1 < (uint)in_ECX[4]) {
      _Size = param_1;
    }
    if (0xf < uVar1) {
      _Src = (void *)*in_ECX;
      if (_Size != 0) {
        FID_conflict__memcpy(in_ECX,_Src,_Size);
      }
      FUN_0089120c(_Src);
    }
    in_ECX[4] = _Size;
    in_ECX[5] = 0xf;
    *(undefined1 *)(_Size + (int)in_ECX) = 0;
    return param_1 != 0;
  }
  if (param_1 == 0) {
    in_ECX[4] = 0;
    if (0xf < uVar1) {
      in_ECX = (undefined4 *)*in_ECX;
    }
    *(undefined1 *)in_ECX = 0;
  }
  return param_1 != 0;
}

