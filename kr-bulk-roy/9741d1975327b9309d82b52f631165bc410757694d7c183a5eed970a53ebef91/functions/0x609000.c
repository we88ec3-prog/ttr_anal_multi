
void FUN_00609000(byte param_1)

{
  void *in_ECX;
  
  FUN_00609060();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

