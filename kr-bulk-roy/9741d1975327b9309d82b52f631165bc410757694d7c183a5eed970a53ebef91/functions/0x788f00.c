
int FUN_00788f00(int param_1,int param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  
  if (in_EAX != param_1) {
    puVar1 = (undefined4 *)(param_2 + 0x54);
    do {
      FUN_00788f50();
      puVar1[-1] = *(undefined4 *)(in_EAX + 0x50);
      *puVar1 = *(undefined4 *)(in_EAX + 0x54);
      puVar1[1] = *(undefined4 *)(in_EAX + 0x58);
      puVar1[2] = *(undefined4 *)(in_EAX + 0x5c);
      in_EAX = in_EAX + 0x60;
      param_2 = param_2 + 0x60;
      puVar1 = puVar1 + 0x18;
    } while (in_EAX != param_1);
  }
  return param_2;
}

