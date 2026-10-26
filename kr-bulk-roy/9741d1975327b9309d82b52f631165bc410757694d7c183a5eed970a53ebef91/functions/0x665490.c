
void FUN_00665490(void)

{
  int *in_ECX;
  
  if (((uint)in_ECX[10] >> 8 & 1) != 0) {
    in_ECX[0x44] = 0;
    FUN_004067f0();
    (**(code **)(*in_ECX + 0x90))(1);
  }
  return;
}

