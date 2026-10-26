
void FUN_00790680(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  
  if (param_1 != in_ECX) {
    puVar2 = in_ECX + 4;
    do {
      *(undefined4 *)(in_EAX + -0x40) = puVar2[-0x14];
      *(undefined4 *)(in_EAX + -0x3c) = puVar2[-0x13];
      *(undefined4 *)(in_EAX + -0x38) = puVar2[-0x12];
      *(undefined4 *)(in_EAX + -0x34) = puVar2[-0x11];
      *(undefined4 *)(in_EAX + -0x30) = puVar2[-0x10];
      *(undefined4 *)(in_EAX + -0x2c) = puVar2[-0xf];
      *(undefined4 *)(in_EAX + -0x28) = puVar2[-0xe];
      *(undefined4 *)(in_EAX + -0x24) = puVar2[-0xd];
      *(undefined4 *)(in_EAX + -0x20) = puVar2[-0xc];
      *(undefined4 *)(in_EAX + -0x1c) = puVar2[-0xb];
      *(undefined4 *)(in_EAX + -0x18) = puVar2[-10];
      *(undefined4 *)(in_EAX + -0x14) = puVar2[-9];
      *(undefined4 *)(in_EAX + -0x10) = puVar2[-8];
      *(undefined4 *)(in_EAX + -0xc) = puVar2[-7];
      *(undefined4 *)(in_EAX + -8) = puVar2[-6];
      *(undefined4 *)(in_EAX + -4) = puVar2[-5];
      puVar1 = puVar2 + -0x15;
      in_EAX = in_EAX + -0x44;
      puVar2 = puVar2 + -0x11;
    } while (puVar1 != param_1);
  }
  return;
}

