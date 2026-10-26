
undefined4 * FUN_00508b40(undefined4 *param_1)

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
      FUN_004026e0(puVar2 + 1,0,0xffffffff);
      puVar1 = puVar2 + 8;
      in_ECX = in_ECX + 10;
      puVar2 = puVar2 + 10;
    } while (puVar1 != param_1);
  }
  return in_ECX;
}

