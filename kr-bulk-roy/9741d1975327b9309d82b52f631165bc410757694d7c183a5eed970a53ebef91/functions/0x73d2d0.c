
void FUN_0073d2d0(void)

{
  int iVar1;
  uint *in_ECX;
  undefined4 *in_EDX;
  int unaff_ESI;
  
  *in_ECX = 0;
  *in_EDX = 0;
  iVar1 = *(int *)(unaff_ESI + 0x24);
  if (iVar1 == 1) {
    *in_ECX = *in_ECX | 2;
  }
  else if (iVar1 == 2) {
    *in_ECX = *in_ECX | 0x8000;
  }
  else if (iVar1 == 3) {
    *in_ECX = *in_ECX | 0x20;
  }
  switch(*(undefined4 *)(unaff_ESI + 0x2c)) {
  case 0:
    *in_EDX = 0;
    break;
  case 1:
    *in_ECX = *in_ECX | 0x10000;
    *in_EDX = 1;
    break;
  case 2:
    *in_EDX = 2;
    break;
  case 3:
    *in_EDX = 3;
    break;
  case 4:
    *in_EDX = 4;
  }
  if (*(char *)(unaff_ESI + 0x30) != '\0') {
    *in_ECX = *in_ECX | 8;
  }
  return;
}

