
void FUN_008ed0e0(void)

{
  char cVar1;
  int *in_EAX;
  int iVar2;
  int unaff_EDI;
  bool bVar3;
  
  if (*in_EAX == 0) {
    iVar2 = 1;
LAB_008ed0f0:
    do {
      cVar1 = FUN_008ed050();
      if (cVar1 == '\x01') {
        return;
      }
      cVar1 = *(char *)(unaff_EDI + 0x170);
      if (cVar1 == '\x1b') {
        bVar3 = iVar2 == 1;
      }
      else {
        if (cVar1 == 'X') {
          iVar2 = iVar2 + 1;
          goto LAB_008ed0f0;
        }
        if (cVar1 != 'Y') goto LAB_008ed0f0;
        iVar2 = iVar2 + -1;
        bVar3 = iVar2 == 0;
      }
    } while (!bVar3);
  }
  return;
}

