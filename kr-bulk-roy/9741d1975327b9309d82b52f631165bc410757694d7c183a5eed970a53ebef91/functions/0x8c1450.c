
void FUN_008c1450(void)

{
  int iVar1;
  int in_EAX;
  int in_ECX;
  int *in_EDX;
  
  if (in_EDX[3] < in_ECX) {
    in_ECX = in_EDX[3];
  }
  iVar1 = in_EDX[2];
  if (in_ECX < iVar1) {
    in_ECX = iVar1 + -1;
  }
  *in_EDX = in_ECX - iVar1;
  in_EDX[1] = in_EAX - in_EDX[4];
  in_EDX[0x12] = in_EAX << 8;
  in_EDX[8] = 0;
  in_EDX[9] = 0;
  in_EDX[10] = 0;
  FUN_008c13f0();
  return;
}

