
void FUN_007898d0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (in_ECX != 0) {
    puVar1 = (undefined4 *)(in_EAX + 8);
    do {
      if (puVar1 != (undefined4 *)0x8) {
        *puVar1 = local_28;
        puVar1[-1] = local_2c;
        puVar1[1] = local_24;
        puVar1[-2] = gbTCBKey<float>::vftable;
        puVar1[2] = local_20;
        puVar1[3] = local_1c;
        puVar1[4] = local_18;
        puVar1[5] = local_14;
        puVar1[6] = local_10;
        puVar1[7] = local_c;
        puVar1[8] = local_8;
      }
      puVar1 = puVar1 + 0xb;
      in_ECX = in_ECX + -1;
    } while (in_ECX != 0);
  }
  return;
}

