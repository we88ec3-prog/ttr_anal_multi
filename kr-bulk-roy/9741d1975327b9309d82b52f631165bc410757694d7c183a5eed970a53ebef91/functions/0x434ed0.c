
void FUN_00434ed0(byte param_1)

{
  void *in_ECX;
  
  FUN_00434f00(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

