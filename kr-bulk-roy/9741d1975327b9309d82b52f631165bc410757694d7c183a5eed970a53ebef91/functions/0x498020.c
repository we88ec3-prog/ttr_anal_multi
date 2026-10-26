
void FUN_00498020(void)

{
  short in_AX;
  int in_ECX;
  
  if (*(short *)(in_ECX + 0xe) < in_AX) {
    in_AX = *(short *)(in_ECX + 0xe);
  }
  if (in_AX < *(short *)(in_ECX + 0xc)) {
    in_AX = *(short *)(in_ECX + 0xc);
  }
  *(short *)(in_ECX + 10) = in_AX;
  return;
}

