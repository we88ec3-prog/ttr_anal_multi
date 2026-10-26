
void FUN_00402c50(void)

{
  undefined4 *in_ECX;
  
  if (0xf < (uint)in_ECX[5]) {
    FUN_0089120c(*in_ECX);
  }
  in_ECX[5] = 0xf;
  in_ECX[4] = 0;
  *(undefined1 *)in_ECX = 0;
  return;
}

