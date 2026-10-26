
undefined4 * FUN_0072ffb0(void)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  
  puVar2 = (undefined4 *)FUN_00891268(0x44);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[2] = 0xffffffff;
    puVar2[1] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[0xd] = 0xf;
    puVar2[0xc] = 0;
    *(undefined1 *)(puVar2 + 8) = 0;
    pcVar4 = (char *)(in_ECX + 0x20);
    puVar2[4] = 0;
    puVar2[5] = 3;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[0xf] = 0;
    puVar2[0x10] = 0;
    *puVar2 = TiXmlUnknown::vftable;
    if (0xf < *(uint *)(in_ECX + 0x34)) {
      pcVar4 = *(char **)pcVar4;
    }
    pcVar3 = pcVar4;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar4,(int)pcVar3 - (int)(pcVar4 + 1));
    puVar2[3] = *(undefined4 *)(in_ECX + 0xc);
    return puVar2;
  }
  return (undefined4 *)0x0;
}

