
void FUN_00454b70(byte param_1)

{
  void *in_ECX;
  
  FUN_00454ba0(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

