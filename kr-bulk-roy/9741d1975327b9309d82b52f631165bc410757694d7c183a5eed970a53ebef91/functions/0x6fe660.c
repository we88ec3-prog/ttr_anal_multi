
undefined4 FUN_006fe660(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_EAX;
  undefined4 uVar3;
  char *in_EDX;
  
  puVar2 = (undefined4 *)**(int **)(in_EAX + 0x14);
  *(undefined4 **)(in_EAX + 8) = puVar2;
  do {
    cVar1 = *in_EDX;
    in_EDX = in_EDX + 1;
  } while (cVar1 != '\0');
  uVar3 = FUN_006fec70();
  *puVar2 = uVar3;
  puVar2[2] = 4;
  if (*(int *)(in_EAX + 0x1c) - *(int *)(in_EAX + 8) < 0x11) {
    if (0 < *(int *)(in_EAX + 0x2c)) {
      FUN_006fdcb0();
      *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
      return 2;
    }
    FUN_006fdcb0();
  }
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  return 2;
}

