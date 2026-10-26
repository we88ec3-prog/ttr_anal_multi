
undefined4 * FUN_007e4020(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (in_EAX != param_1) {
    puVar3 = param_2 + 6;
    puVar2 = in_EAX + 6;
    do {
      *param_2 = puVar2[-6];
      param_2[1] = puVar2[-5];
      param_2[2] = puVar2[-4];
      puVar3[-3] = puVar2[-3];
      puVar3[-2] = puVar2[-2];
      puVar3[-1] = puVar2[-1];
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar3[2] = puVar2[2];
      puVar3[3] = puVar2[3];
      FUN_00403040(puVar2 + 4,0,0xffffffff);
      puVar1 = puVar2 + 0xb;
      param_2 = param_2 + 0x11;
      puVar3 = puVar3 + 0x11;
      puVar2 = puVar2 + 0x11;
    } while (puVar1 != param_1);
  }
  return param_2;
}

