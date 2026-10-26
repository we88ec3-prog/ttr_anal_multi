
void FUN_008f47a0(void)

{
  ushort *puVar1;
  ushort *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  int in_EDX;
  char *pcVar4;
  
  puVar2 = *(ushort **)(in_ECX + 0x1c);
  pcVar4 = *(char **)(in_EDX + 8);
  puVar1 = puVar2 + *(int *)(in_ECX + 0x18) * 0x14;
  puVar3 = *(undefined4 **)(in_EDX + 4);
  for (; puVar2 < puVar1; puVar2 = puVar2 + 0x14) {
    *puVar3 = *(undefined4 *)(puVar2 + 8);
    puVar3[1] = *(undefined4 *)(puVar2 + 10);
    if ((*puVar2 & 1) == 0) {
      *pcVar4 = ((*puVar2 & 2) != 0) + '\x01';
    }
    else {
      *pcVar4 = '\0';
    }
    puVar3 = puVar3 + 2;
    pcVar4 = pcVar4 + 1;
  }
  return;
}

