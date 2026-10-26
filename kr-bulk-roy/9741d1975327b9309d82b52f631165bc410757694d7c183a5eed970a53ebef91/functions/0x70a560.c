
void FUN_0070a560(void)

{
  char *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  
  _strchr(in_EAX,0x2d);
  FUN_006f6740(&DAT_00c41190,&DAT_00c43a90);
  FUN_006f5580();
  puVar2 = *(undefined4 **)(unaff_ESI + 8);
  puVar1 = puVar2 + -4;
  if (puVar1 < puVar2) {
    puVar2 = puVar2 + -8;
    do {
      *puVar2 = *puVar1;
      puVar2[1] = puVar1[1];
      puVar2[2] = puVar2[6];
      puVar1 = puVar1 + 4;
      puVar2 = puVar2 + 4;
    } while (puVar1 < *(undefined4 **)(unaff_ESI + 8));
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
  return;
}

