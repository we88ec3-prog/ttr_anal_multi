
void FUN_006df660(void)

{
  void *unaff_ESI;
  
  FUN_006eb5e0();
  _memset(unaff_ESI,0,0x1350);
  DAT_00d63d09 = 1;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  *(undefined1 *)((int)unaff_ESI + 0x309) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x2fd) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x2d1) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x31a) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x2d3) = 1;
  *(undefined4 *)((int)unaff_ESI + 0x344) = 0xffffffff;
  *(undefined4 *)((int)unaff_ESI + 0x348) = 0xffffffff;
  *(undefined4 *)((int)unaff_ESI + 0x330) = 0xffffffff;
  *(undefined4 *)((int)unaff_ESI + 0x358) = 0xffffffff;
  return;
}

