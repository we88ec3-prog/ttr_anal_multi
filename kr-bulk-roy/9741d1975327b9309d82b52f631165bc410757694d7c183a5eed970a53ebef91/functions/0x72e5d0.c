
void FUN_0072e5d0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_EAX;
  
  puVar1 = *(undefined4 **)(in_EAX + 0x18);
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    puVar1 = (undefined4 *)puVar1[0x10];
    (*(code *)*puVar2)(1);
  }
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  do {
    puVar1 = *(undefined4 **)(in_EAX + 0x94);
    if ((puVar1 == (undefined4 *)(in_EAX + 0x44)) || (puVar2 = puVar1, puVar1 == (undefined4 *)0x0))
    {
      return;
    }
    for (; puVar2 != (undefined4 *)(in_EAX + 0x44); puVar2 = (undefined4 *)puVar2[0x14]) {
      if (puVar2 == puVar1) {
        *(undefined4 *)(puVar2[0x13] + 0x50) = puVar2[0x14];
        *(undefined4 *)(puVar2[0x14] + 0x4c) = puVar2[0x13];
        puVar2[0x14] = 0;
        puVar2[0x13] = 0;
        break;
      }
    }
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
  } while( true );
}

