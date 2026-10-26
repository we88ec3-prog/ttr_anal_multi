
void FUN_00772c70(byte param_1)

{
  void *in_ECX;
  
  FUN_00772e40(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

