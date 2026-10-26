
void FUN_0041f320(uint *param_1)

{
  uint *puVar1;
  uint *in_EAX;
  uint *puVar2;
  
  if (in_EAX != param_1) {
    puVar2 = in_EAX + 0xd;
    do {
      if (7 < *puVar2) {
        FUN_0089120c(puVar2[-5]);
      }
      *puVar2 = 7;
      puVar2[-1] = 0;
      *(undefined2 *)(puVar2 + -5) = 0;
      if (7 < puVar2[-8]) {
        FUN_0089120c(puVar2[-0xd]);
      }
      puVar2[-8] = 7;
      puVar2[-9] = 0;
      *(undefined2 *)(puVar2 + -0xd) = 0;
      puVar1 = puVar2 + 3;
      puVar2 = puVar2 + 0x10;
    } while (puVar1 != param_1);
  }
  return;
}

