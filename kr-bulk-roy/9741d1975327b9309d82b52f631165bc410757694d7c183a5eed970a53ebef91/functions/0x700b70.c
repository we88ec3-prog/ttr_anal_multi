
void FUN_00700b70(char *param_1)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  
  if (unaff_ESI == in_EAX) {
    puVar2 = *(undefined4 **)(unaff_ESI + 8);
    *puVar2 = puVar2[-8];
    puVar2[1] = puVar2[-7];
    puVar2[2] = puVar2[-6];
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    puVar3 = *(undefined4 **)(unaff_ESI + 8);
    puVar2 = puVar3 + -8;
    if (puVar2 < puVar3) {
      puVar3 = puVar3 + -0xc;
      do {
        *puVar3 = *puVar2;
        puVar3[1] = puVar2[1];
        puVar3[2] = puVar3[6];
        puVar2 = puVar2 + 4;
        puVar3 = puVar3 + 4;
      } while (puVar2 < *(undefined4 **)(unaff_ESI + 8));
    }
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
  }
  else {
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
    puVar2 = *(undefined4 **)(in_EAX + 8);
    puVar3 = *(undefined4 **)(unaff_ESI + 8);
    *(undefined4 **)(unaff_ESI + 8) = puVar3 + 4;
    *puVar3 = *puVar2;
    puVar3[1] = puVar2[1];
    puVar3[2] = puVar2[2];
  }
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
  return;
}

