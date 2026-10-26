
void FUN_00743120(void)

{
  void *unaff_ESI;
  
  _memset(unaff_ESI,0,0x800);
  _memset((void *)((int)unaff_ESI + 0x800),0,0x800);
  _memset((void *)((int)unaff_ESI + 0x1000),0,0x800);
  _memset((void *)((int)unaff_ESI + 0x1800),0,0x800);
  _memset((void *)((int)unaff_ESI + 0x2000),0,0x800);
  return;
}

