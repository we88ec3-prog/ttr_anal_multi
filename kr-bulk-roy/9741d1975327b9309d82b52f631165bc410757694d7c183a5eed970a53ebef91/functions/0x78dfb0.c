
void FUN_0078dfb0(undefined4 param_1)

{
  int in_EAX;
  int in_ECX;
  undefined4 *puVar1;
  undefined **local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (1 < (in_EAX - in_ECX) / 0x2c) {
    puVar1 = (undefined4 *)(in_EAX + -0x24);
    local_8 = 0x24 - in_ECX;
    do {
      local_30 = puVar1[-1];
      local_2c = *puVar1;
      local_28 = puVar1[1];
      local_24 = puVar1[2];
      local_20 = puVar1[3];
      local_1c = puVar1[4];
      local_34 = gbTCBKey<float>::vftable;
      local_18 = puVar1[5];
      local_14 = puVar1[6];
      local_10 = puVar1[7];
      local_c = puVar1[8];
      puVar1[-1] = *(undefined4 *)(in_ECX + 4);
      *puVar1 = *(undefined4 *)(in_ECX + 8);
      puVar1[1] = *(undefined4 *)(in_ECX + 0xc);
      puVar1[2] = *(undefined4 *)(in_ECX + 0x10);
      puVar1[3] = *(undefined4 *)(in_ECX + 0x14);
      puVar1[4] = *(undefined4 *)(in_ECX + 0x18);
      puVar1[5] = *(undefined4 *)(in_ECX + 0x1c);
      puVar1[6] = *(undefined4 *)(in_ECX + 0x20);
      puVar1[7] = *(undefined4 *)(in_ECX + 0x24);
      puVar1[8] = *(undefined4 *)(in_ECX + 0x28);
      FUN_0078f7c0(&local_34,param_1);
      puVar1 = puVar1 + -0xb;
    } while (1 < (local_8 + (int)puVar1) / 0x2c);
  }
  return;
}

