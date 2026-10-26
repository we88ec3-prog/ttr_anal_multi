
void FUN_00402f30(char param_1,size_t param_2)

{
  void *_Src;
  undefined4 *in_ECX;
  
  if ((param_1 != '\0') && (0xf < (uint)in_ECX[5])) {
    _Src = (void *)*in_ECX;
    if (param_2 != 0) {
      FID_conflict__memcpy(in_ECX,_Src,param_2);
    }
    FUN_0089120c(_Src);
  }
  in_ECX[4] = param_2;
  in_ECX[5] = 0xf;
  *(undefined1 *)(param_2 + (int)in_ECX) = 0;
  return;
}

