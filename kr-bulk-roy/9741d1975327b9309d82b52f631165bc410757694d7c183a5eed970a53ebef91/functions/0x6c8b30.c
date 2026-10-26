
undefined4 * FUN_006c8b30(undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined1 *in_EAX;
  undefined4 *in_ECX;
  undefined1 *puVar2;
  
  if (in_EAX != param_1) {
    puVar2 = in_EAX + 0x20;
    do {
      *in_ECX = *(undefined4 *)(puVar2 + -0x20);
      FUN_004026e0(puVar2 + -0x1c,0,0xffffffff);
      *(undefined1 *)(in_ECX + 8) = *puVar2;
      in_ECX[9] = *(undefined4 *)(puVar2 + 4);
      puVar1 = puVar2 + 8;
      in_ECX = in_ECX + 10;
      puVar2 = puVar2 + 0x28;
    } while (puVar1 != param_1);
  }
  return in_ECX;
}

