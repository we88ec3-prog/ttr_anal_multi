
void FUN_00789be0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *in_EDX;
  
  if (param_1 != in_EDX) {
    puVar2 = param_1 + 2;
    do {
      *(undefined4 *)(in_EAX + 4) = puVar2[-1];
      *(undefined4 *)(in_EAX + 8) = *puVar2;
      *(undefined4 *)(in_EAX + 0xc) = puVar2[1];
      *(undefined4 *)(in_EAX + 0x10) = puVar2[2];
      puVar1 = puVar2 + 9;
      *(undefined4 *)(in_EAX + 0x14) = puVar2[3];
      *(undefined4 *)(in_EAX + 0x18) = puVar2[4];
      *(undefined4 *)(in_EAX + 0x1c) = puVar2[5];
      *(undefined4 *)(in_EAX + 0x20) = puVar2[6];
      *(undefined4 *)(in_EAX + 0x24) = puVar2[7];
      *(undefined4 *)(in_EAX + 0x28) = puVar2[8];
      in_EAX = in_EAX + 0x2c;
      puVar2 = puVar2 + 0xb;
    } while (puVar1 != in_EDX);
  }
  return;
}

