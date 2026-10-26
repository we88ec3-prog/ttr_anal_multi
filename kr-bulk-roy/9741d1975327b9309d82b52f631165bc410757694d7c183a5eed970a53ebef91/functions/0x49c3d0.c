
void FUN_0049c3d0(void)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int in_EAX;
  undefined4 *in_ECX;
  
  uVar1 = *(undefined4 *)(in_EAX + 0x15c);
  iVar2 = *(int *)(in_EAX + 0x160);
  *in_ECX = 0;
  in_ECX[1] = 0;
  if (iVar2 != 0) {
    cVar3 = FUN_0047c250();
    if (cVar3 != '\0') {
      FUN_007a31c0(uVar1,iVar2);
    }
  }
  return;
}

