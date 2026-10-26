
void FUN_0060d600(byte param_1)

{
  void *in_ECX;
  
  FUN_0060d630(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

