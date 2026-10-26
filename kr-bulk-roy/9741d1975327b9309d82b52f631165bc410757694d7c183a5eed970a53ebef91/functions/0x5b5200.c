
void FUN_005b5200(byte param_1)

{
  void *in_ECX;
  
  FUN_005b5230();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

