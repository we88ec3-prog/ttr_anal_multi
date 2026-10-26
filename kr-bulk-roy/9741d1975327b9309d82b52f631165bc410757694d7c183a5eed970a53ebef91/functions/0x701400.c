
byte FUN_00701400(int param_1)

{
  char *pcVar1;
  char *unaff_EDI;
  byte bVar2;
  
  pcVar1 = _strchr(unaff_EDI,99);
  bVar2 = pcVar1 != (char *)0x0;
  pcVar1 = _strchr(unaff_EDI,0x72);
  if (pcVar1 != (char *)0x0) {
    bVar2 = bVar2 | 2;
  }
  pcVar1 = _strchr(unaff_EDI,0x6c);
  if (pcVar1 != (char *)0x0) {
    bVar2 = bVar2 | 4;
  }
  if (0 < param_1) {
    bVar2 = bVar2 | 8;
  }
  return bVar2;
}

