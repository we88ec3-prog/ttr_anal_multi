
uint FUN_0071d0a0(void)

{
  int *in_EAX;
  uint uVar1;
  uint uVar2;
  int unaff_EDI;
  
  uVar2 = in_EAX[1] - *in_EAX;
  uVar1 = 0;
  if (uVar2 != 0) {
    do {
      if (*(char *)(uVar1 + unaff_EDI) != *(char *)(*in_EAX + uVar1)) {
        return uVar1 & 0xffffff00;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  return CONCAT31((int3)(uVar1 >> 8),*(char *)(uVar2 + unaff_EDI) == '\0');
}

