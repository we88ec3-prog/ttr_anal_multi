
void FUN_006bb440(byte param_1)

{
  void *in_ECX;
  
  FUN_006bb470(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

