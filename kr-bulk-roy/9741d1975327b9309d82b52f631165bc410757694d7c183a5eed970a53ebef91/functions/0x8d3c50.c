
void FUN_008d3c50(void)

{
  undefined1 uVar1;
  int in_EAX;
  undefined1 *puVar2;
  uint in_ECX;
  uint uVar3;
  
  if (3 < in_ECX) {
    puVar2 = (undefined1 *)(in_EAX + 1);
    uVar3 = in_ECX >> 2;
    do {
      uVar1 = puVar2[-1];
      puVar2[-1] = puVar2[2];
      puVar2[2] = uVar1;
      uVar1 = *puVar2;
      *puVar2 = puVar2[1];
      puVar2[1] = uVar1;
      puVar2 = puVar2 + 4;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}

