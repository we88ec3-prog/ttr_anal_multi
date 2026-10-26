
undefined4 * FUN_004fcbb0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  
  if (in_EAX != param_1) {
    puVar2 = in_EAX + 2;
    do {
      *in_ECX = puVar2[-2];
      in_ECX[1] = puVar2[-1];
      in_ECX[2] = *puVar2;
      in_ECX[3] = puVar2[1];
      FUN_004026e0(puVar2 + 2,0,0xffffffff);
      FUN_004fcdc0(puVar2 + 9);
      puVar1 = puVar2 + 0xd;
      in_ECX = in_ECX + 0xf;
      puVar2 = puVar2 + 0xf;
    } while (puVar1 != param_1);
  }
  return in_ECX;
}

