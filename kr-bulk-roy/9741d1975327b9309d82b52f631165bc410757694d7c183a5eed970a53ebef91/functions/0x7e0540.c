
void FUN_007e0540(undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (in_ECX != param_1) {
    puVar1 = in_EAX;
    puVar2 = in_ECX;
    do {
      *puVar1 = *puVar2;
      puVar1[1] = *(undefined4 *)((int)in_ECX + (4 - (int)in_EAX) + (int)puVar1);
      FUN_004738a0(puVar2 + 2);
      puVar2 = puVar2 + 6;
      puVar1 = puVar1 + 6;
    } while (puVar2 != param_1);
  }
  return;
}

