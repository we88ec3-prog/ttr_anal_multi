
void FUN_00842de0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_1 != in_ECX) {
    puVar3 = in_ECX + 4;
    puVar4 = in_EAX + 4;
    do {
      puVar2 = in_EAX + -0x14;
      puVar1 = puVar3 + -0x18;
      if (puVar2 != puVar1) {
        *puVar2 = puVar3[-0x18];
        in_EAX[-0x13] = puVar3[-0x17];
        in_EAX[-0x12] = puVar3[-0x16];
        if (puVar4 + -0x15 != puVar3 + -0x15) {
          puVar4[-0x12] = puVar3[-0x12];
          puVar4[-0x15] = puVar3[-0x15];
          puVar4[-0x14] = puVar3[-0x14];
          puVar4[-0x13] = puVar3[-0x13];
        }
        puVar4[-0x11] = puVar3[-0x11];
        puVar4[-0x10] = puVar3[-0x10];
        puVar4[-0xf] = puVar3[-0xf];
        puVar4[-0xe] = puVar3[-0xe];
      }
      puVar4[-0xd] = puVar3[-0xd];
      puVar4[-0xc] = puVar3[-0xc];
      puVar4[-0xb] = puVar3[-0xb];
      puVar4[-10] = puVar3[-10];
      puVar4[-9] = puVar3[-9];
      puVar4[-8] = puVar3[-8];
      puVar4[-7] = puVar3[-7];
      puVar4[-6] = puVar3[-6];
      puVar4[-5] = puVar3[-5];
      in_EAX = puVar2;
      puVar3 = puVar3 + -0x14;
      puVar4 = puVar4 + -0x14;
    } while (puVar1 != param_1);
  }
  return;
}

