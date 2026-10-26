
void FUN_0046cb70(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  puVar2 = (undefined4 *)(in_ECX + 0x1d8);
  piVar4 = (int *)(in_ECX + 0xf4);
  do {
    iVar1 = *piVar4;
    piVar4[0xfd] = iVar3;
    *puVar2 = *(undefined4 *)(iVar1 + 8);
    puVar2[1] = *(undefined4 *)(iVar1 + 0xc);
    puVar2[2] = *(undefined4 *)(iVar1 + 0x10);
    puVar2[3] = *(undefined4 *)(iVar1 + 0x14);
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
    puVar2 = puVar2 + 4;
  } while (iVar3 < 0x31);
  FUN_0046d690();
  return;
}

