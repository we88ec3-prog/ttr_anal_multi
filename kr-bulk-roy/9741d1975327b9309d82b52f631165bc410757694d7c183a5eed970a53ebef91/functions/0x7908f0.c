
void FUN_007908f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 != in_ECX) {
    puVar2 = in_ECX + 2;
    puVar3 = (undefined4 *)(in_EAX + 8);
    do {
      if (puVar3 + -0x10 != puVar2 + -0x10) {
        puVar3[-0xd] = puVar2[-0xd];
        puVar3[-0x10] = puVar2[-0x10];
        puVar3[-0xf] = puVar2[-0xf];
        puVar3[-0xe] = puVar2[-0xe];
      }
      puVar3[-0xc] = puVar2[-0xc];
      puVar3[-0xb] = puVar2[-0xb];
      if (puVar3 + -10 != puVar2 + -10) {
        puVar3[-7] = puVar2[-7];
        puVar3[-10] = puVar2[-10];
        puVar3[-9] = puVar2[-9];
        puVar3[-8] = puVar2[-8];
      }
      if (puVar3 + -6 != puVar2 + -6) {
        puVar3[-3] = puVar2[-3];
        puVar3[-6] = puVar2[-6];
        puVar3[-5] = puVar2[-5];
        puVar3[-4] = puVar2[-4];
      }
      puVar1 = puVar2 + -0x11;
      puVar2 = puVar2 + -0xf;
      puVar3 = puVar3 + -0xf;
    } while (puVar1 != param_1);
  }
  return;
}

