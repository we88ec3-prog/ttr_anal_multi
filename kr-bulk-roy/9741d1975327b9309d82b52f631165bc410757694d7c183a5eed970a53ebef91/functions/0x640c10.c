
void FUN_00640c10(byte param_1)

{
  void *in_ECX;
  
  FUN_00640c40();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

