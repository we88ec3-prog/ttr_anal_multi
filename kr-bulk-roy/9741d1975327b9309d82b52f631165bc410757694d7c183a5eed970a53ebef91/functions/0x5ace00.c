
void FUN_005ace00(byte param_1)

{
  void *in_ECX;
  
  FUN_005ace30();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

