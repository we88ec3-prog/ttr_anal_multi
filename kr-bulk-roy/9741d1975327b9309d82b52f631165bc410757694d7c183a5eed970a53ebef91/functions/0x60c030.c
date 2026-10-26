
void FUN_0060c030(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  FUN_0060ba50(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x25c) = *(undefined4 *)(unaff_EDI + 0x25c);
  FUN_004026e0(unaff_EDI + 0x260,0,0xffffffff);
  *(undefined2 *)(unaff_ESI + 0x27c) = *(undefined2 *)(unaff_EDI + 0x27c);
  *(undefined4 *)(unaff_ESI + 0x280) = *(undefined4 *)(unaff_EDI + 0x280);
  *(undefined4 *)(unaff_ESI + 0x284) = *(undefined4 *)(unaff_EDI + 0x284);
  *(undefined4 *)(unaff_ESI + 0x288) = *(undefined4 *)(unaff_EDI + 0x288);
  return;
}

