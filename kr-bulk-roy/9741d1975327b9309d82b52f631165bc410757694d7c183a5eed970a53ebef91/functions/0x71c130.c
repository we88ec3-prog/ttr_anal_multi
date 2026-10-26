
bool FUN_0071c130(void)

{
  char *in_EAX;
  char cVar1;
  int in_EDX;
  int iVar2;
  
  cVar1 = *in_EAX;
  if (cVar1 != '\0') {
    iVar2 = in_EDX - (int)in_EAX;
    do {
      if (in_EAX[iVar2] != cVar1) break;
      cVar1 = in_EAX[1];
      in_EAX = in_EAX + 1;
    } while (cVar1 != '\0');
  }
  return *in_EAX == '\0';
}

