
void * FUN_0044a9e0(void *param_1)

{
  size_t _Size;
  int in_EAX;
  void *pvVar1;
  void *in_ECX;
  
  _Size = (in_EAX - (int)in_ECX >> 2) * 4;
  pvVar1 = FID_conflict__memcpy(param_1,in_ECX,_Size);
  return (void *)((int)pvVar1 + _Size);
}

