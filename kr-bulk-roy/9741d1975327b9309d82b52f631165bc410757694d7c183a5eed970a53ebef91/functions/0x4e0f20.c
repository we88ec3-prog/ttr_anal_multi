
void FUN_004e0f20(void)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  uVar1 = *in_EAX;
  iVar2 = in_EAX[1];
  if (iVar2 != 0) {
    cVar3 = FUN_0047c250();
    if (cVar3 != '\0') {
      FUN_007a31c0(uVar1,iVar2);
    }
  }
  return;
}

