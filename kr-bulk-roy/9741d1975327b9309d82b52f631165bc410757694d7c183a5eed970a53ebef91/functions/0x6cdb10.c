
void FUN_006cdb10(void)

{
  undefined4 *in_ECX;
  
  if (0xf < (uint)in_ECX[0x13]) {
    FUN_0089120c(in_ECX[0xe]);
  }
  in_ECX[0x13] = 0xf;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  if (7 < (uint)in_ECX[0xc]) {
    FUN_0089120c(in_ECX[7]);
  }
  in_ECX[0xc] = 7;
  in_ECX[0xb] = 0;
  *(undefined2 *)(in_ECX + 7) = 0;
  if (7 < (uint)in_ECX[5]) {
    FUN_0089120c(*in_ECX);
  }
  in_ECX[4] = 0;
  in_ECX[5] = 7;
  *(undefined2 *)in_ECX = 0;
  return;
}

