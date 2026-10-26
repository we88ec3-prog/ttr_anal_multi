
int FUN_0078d750(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 != in_EAX) {
    puVar2 = (undefined4 *)(param_2 + 0x54);
    do {
      iVar1 = in_EAX + -0x60;
      param_2 = param_2 + -0x60;
      FUN_00788f50();
      puVar2[-0x19] = *(undefined4 *)(in_EAX + -0x10);
      puVar2[-0x18] = *(undefined4 *)(in_EAX + -0xc);
      puVar2[-0x17] = *(undefined4 *)(in_EAX + -8);
      puVar2[-0x16] = *(undefined4 *)(in_EAX + -4);
      in_EAX = iVar1;
      puVar2 = puVar2 + -0x18;
    } while (iVar1 != param_1);
  }
  return param_2;
}

