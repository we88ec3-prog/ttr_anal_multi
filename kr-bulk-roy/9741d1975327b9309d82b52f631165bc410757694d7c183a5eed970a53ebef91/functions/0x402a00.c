
void FUN_00402a00(char param_1,int param_2)

{
  void *_Src;
  undefined4 *in_ECX;
  
  if ((param_1 != '\0') && (7 < (uint)in_ECX[5])) {
    _Src = (void *)*in_ECX;
    if (param_2 != 0) {
      FID_conflict__memcpy(in_ECX,_Src,param_2 * 2);
    }
    FUN_0089120c(_Src);
  }
  in_ECX[4] = param_2;
  in_ECX[5] = 7;
  *(undefined2 *)((int)in_ECX + param_2 * 2) = 0;
  return;
}

