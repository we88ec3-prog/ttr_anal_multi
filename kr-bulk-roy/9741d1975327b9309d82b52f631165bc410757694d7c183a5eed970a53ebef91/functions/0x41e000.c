
undefined4 FUN_0041e000(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = (undefined4 *)(in_EAX + 0x30);
  iVar2 = 10;
  do {
    if (puVar1[-8] != 0) {
      if ((float)puVar1[2] != 0.0) {
        local_c = *puVar1;
        local_8 = local_c;
        (**(code **)(*(int *)puVar1[-8] + 0x28))
                  (puVar1 + -7,0,&local_c,0,0,(int)(float)puVar1[1] << 0x18 | 0xffffff);
      }
    }
    puVar1 = puVar1 + 0xf;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

