
void FUN_0073e030(void)

{
  int *in_EAX;
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (in_EAX == (int *)0x0) {
    in_EAX = &DAT_00f88d1c;
  }
  iVar2 = in_EAX[2] - *in_EAX;
  iVar4 = in_EAX[3] - in_EAX[1];
  iVar1 = in_ECX[2] - *in_ECX;
  if (in_ECX[2] < 0) {
    iVar1 = iVar2;
  }
  iVar3 = in_ECX[3] - in_ECX[1];
  if (in_ECX[3] < 0) {
    iVar3 = iVar4;
  }
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (iVar4 < iVar3) {
    iVar3 = iVar4;
  }
  in_ECX[2] = *in_ECX + iVar1;
  in_ECX[3] = in_ECX[1] + iVar3;
  return;
}

