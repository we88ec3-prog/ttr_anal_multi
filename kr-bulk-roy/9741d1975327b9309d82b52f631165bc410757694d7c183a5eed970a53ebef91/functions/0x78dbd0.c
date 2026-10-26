
void FUN_0078dbd0(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined **local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (1 < (in_EAX - param_1) / 0x18) {
    puVar1 = (undefined4 *)(in_EAX + -0x10);
    local_8 = 0x10 - param_1;
    do {
      local_1c = puVar1[-1];
      local_18 = *puVar1;
      local_10 = puVar1[2];
      local_20 = gbBezKey<float>::vftable;
      local_14 = 0;
      local_c = puVar1[3];
      puVar1[-1] = *(undefined4 *)(param_1 + 4);
      *puVar1 = *(undefined4 *)(param_1 + 8);
      puVar1[1] = *(undefined4 *)(param_1 + 0xc);
      puVar1[2] = *(undefined4 *)(param_1 + 0x10);
      puVar1[3] = *(undefined4 *)(param_1 + 0x14);
      FUN_0078f650(&local_20,param_2);
      puVar1 = puVar1 + -6;
    } while (1 < (local_8 + (int)puVar1) / 0x18);
  }
  return;
}

