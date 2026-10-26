
void FUN_007090e0(undefined4 param_1,char *param_2)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = (undefined4 *)FUN_00707a00();
  *puVar2 = param_1;
  if (0 < in_EAX) {
    puVar2 = *(undefined4 **)(in_ECX + 8);
    *puVar2 = puVar2[-4];
    puVar2[1] = puVar2[-3];
    puVar2[2] = puVar2[-2];
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
    FUN_006f5870();
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = puVar2[-8];
  puVar2[1] = puVar2[-7];
  puVar2[2] = puVar2[-6];
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
  FUN_006f59b0();
  do {
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x10;
  return;
}

