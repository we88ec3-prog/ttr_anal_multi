
void FUN_006ff030(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    pcVar2 = (&PTR_DAT_00c0bec0)[iVar4];
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    iVar3 = FUN_006fec70();
    *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) | 0x20;
    cVar1 = (char)iVar4;
    iVar4 = iVar4 + 1;
    *(char *)(iVar3 + 6) = cVar1 + '\x01';
  } while (iVar4 < 0x15);
  return;
}

