
void FUN_008d7a30(void)

{
  void *unaff_ESI;
  
  _memset(unaff_ESI,0,0x130);
  *(undefined4 *)((int)unaff_ESI + 0x90) = 0;
  *(undefined4 *)((int)unaff_ESI + 0x58) = 0;
  *(undefined4 *)((int)unaff_ESI + 0x68) = 0;
  *(undefined4 *)((int)unaff_ESI + 0xd4) = 0;
  *(undefined4 *)((int)unaff_ESI + 0xa0) = 0;
  return;
}

