
void FUN_008ed8d0(void)

{
  ushort *in_EAX;
  int unaff_ESI;
  
  if ((*in_EAX < *(ushort *)(unaff_ESI + 0x50)) && (in_EAX[2] < *(ushort *)(unaff_ESI + 0x74))) {
    FUN_008ecef0(unaff_ESI + 0x122);
    FUN_008ecef0(unaff_ESI + 0x126);
    FUN_008ecda0();
    return;
  }
  if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
  return;
}

