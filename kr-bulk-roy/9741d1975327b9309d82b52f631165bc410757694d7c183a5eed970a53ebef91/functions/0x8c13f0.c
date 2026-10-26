
void FUN_008c13f0(void)

{
  int in_EAX;
  int in_ECX;
  int *in_EDX;
  uint uVar1;
  int iVar2;
  
  uVar1 = in_EAX - in_EDX[4];
  if (in_EDX[3] < in_ECX) {
    in_ECX = in_EDX[3];
  }
  iVar2 = in_ECX - in_EDX[2];
  if (iVar2 < 0) {
    iVar2 = -1;
  }
  if ((iVar2 != *in_EDX) || (uVar1 != in_EDX[1])) {
    if (in_EDX[10] == 0) {
      FUN_008c13d0();
    }
    in_EDX[8] = 0;
    in_EDX[9] = 0;
    *in_EDX = iVar2;
    in_EDX[1] = uVar1;
  }
  if ((uVar1 < (uint)in_EDX[7]) && (iVar2 < in_EDX[6])) {
    in_EDX[10] = 0;
    return;
  }
  in_EDX[10] = 1;
  return;
}

