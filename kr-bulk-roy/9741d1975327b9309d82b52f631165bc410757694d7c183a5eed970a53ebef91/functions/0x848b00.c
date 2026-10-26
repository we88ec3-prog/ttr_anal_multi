
int FUN_00848b00(undefined4 *param_1,int param_2)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (in_EAX != param_1) {
    puVar2 = in_EAX + 0x14;
    do {
      FUN_00403040(puVar2 + -0x14,0,0xffffffff);
      puVar3 = puVar2 + -0xd;
      puVar4 = (undefined4 *)(param_2 + 0x1c);
      for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      *(undefined4 *)(param_2 + 0x50) = *puVar2;
      FUN_00848bc0(param_2 + 0x54,puVar2 + 1);
      param_2 = param_2 + 100;
      puVar3 = puVar2 + 5;
      puVar2 = puVar2 + 0x19;
    } while (puVar3 != param_1);
  }
  return param_2;
}

