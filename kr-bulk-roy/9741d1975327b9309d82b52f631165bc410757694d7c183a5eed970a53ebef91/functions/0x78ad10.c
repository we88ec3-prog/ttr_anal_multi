
void FUN_0078ad10(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  undefined4 *puVar3;
  undefined4 *in_EDX;
  
  if (param_1 != in_EDX) {
    puVar3 = param_1 + 2;
    do {
      if (in_EAX != (undefined4 *)0x0) {
        *in_EAX = gbKey<float>::vftable;
        in_EAX[1] = puVar3[-1];
        in_EAX[2] = *puVar3;
        in_EAX[3] = puVar3[1];
        *in_EAX = gbBezKey<float>::vftable;
        in_EAX[4] = puVar3[2];
        uVar2 = puVar3[3];
        in_EAX[3] = 0;
        in_EAX[5] = uVar2;
      }
      puVar1 = puVar3 + 4;
      in_EAX = in_EAX + 6;
      puVar3 = puVar3 + 6;
    } while (puVar1 != in_EDX);
  }
  return;
}

