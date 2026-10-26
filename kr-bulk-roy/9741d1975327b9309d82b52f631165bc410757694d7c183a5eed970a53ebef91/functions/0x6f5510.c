
void FUN_006f5510(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  if (param_1 != (char *)0x0) {
    do {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    if (*(uint *)(*(int *)(unaff_ESI + 0x10) + 0x40) <= *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x44)
       ) {
      FUN_006fb3a0();
    }
    puVar2 = *(undefined4 **)(unaff_ESI + 8);
    uVar3 = FUN_006fec70();
    *puVar2 = uVar3;
    puVar2[2] = 4;
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    return;
  }
  *(undefined4 *)(*(int *)(unaff_ESI + 8) + 8) = 0;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return;
}

