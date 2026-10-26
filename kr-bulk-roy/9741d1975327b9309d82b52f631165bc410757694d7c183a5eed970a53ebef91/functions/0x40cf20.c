
void * FUN_0040cf20(byte param_1)

{
  void *in_ECX;
  
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(in_ECX,0x28c,*(int *)((int)in_ECX + -4),FUN_0060c0e0);
    if ((param_1 & 1) != 0) {
      FUN_00891d3d((void *)((int)in_ECX + -4));
    }
    return (void *)((int)in_ECX + -4);
  }
  FUN_0060c0e0();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return in_ECX;
}

