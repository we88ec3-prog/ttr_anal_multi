
void FUN_00775e20(byte param_1)

{
  void *in_ECX;
  
  FUN_00775e50(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

