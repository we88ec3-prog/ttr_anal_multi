
void FUN_004fcc10(uint *param_1)

{
  uint *puVar1;
  uint *in_EAX;
  uint *puVar2;
  
  if (in_EAX != param_1) {
    puVar2 = in_EAX + 9;
    do {
      if (puVar2[2] != 0) {
        FUN_0089120c(puVar2[2]);
      }
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      if (7 < *puVar2) {
        FUN_0089120c(puVar2[-5]);
      }
      *puVar2 = 7;
      puVar2[-1] = 0;
      *(undefined2 *)(puVar2 + -5) = 0;
      puVar1 = puVar2 + 6;
      puVar2 = puVar2 + 0xf;
    } while (puVar1 != param_1);
  }
  return;
}

