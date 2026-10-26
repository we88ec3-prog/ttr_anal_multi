
void * FUN_00572780(void)

{
  size_t _Size;
  int in_EAX;
  void *in_ECX;
  void *unaff_EDI;
  
  _Size = (in_EAX - (int)in_ECX >> 2) * 4;
  FID_conflict__memcpy(unaff_EDI,in_ECX,_Size);
  return (void *)(_Size + (int)unaff_EDI);
}

