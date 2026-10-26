
int FUN_0071cde0(void)

{
  char cVar1;
  uint uVar2;
  char *in_EDX;
  
  uVar2 = 0;
  cVar1 = *in_EDX;
  while (cVar1 != '\0') {
    uVar2 = (uVar2 + (int)cVar1) * 0x401;
    in_EDX = in_EDX + 1;
    uVar2 = uVar2 ^ uVar2 >> 6;
    cVar1 = *in_EDX;
  }
  return (uVar2 * 9 >> 0xb ^ uVar2 * 9) * 0x8001;
}

