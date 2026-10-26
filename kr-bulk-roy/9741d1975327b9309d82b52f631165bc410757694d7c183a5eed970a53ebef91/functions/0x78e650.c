
void FUN_0078e650(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
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
  undefined4 local_8;
  
  iVar2 = (in_EAX - param_1) / 0x60;
  if (0 < iVar2) {
    puVar1 = (undefined4 *)(param_1 + 0x10 + iVar2 * 0x30);
    do {
      local_30 = puVar1[-0xf];
      local_2c = puVar1[-0xe];
      local_28 = puVar1[-0xd];
      local_24 = puVar1[-0xc];
      local_1c = puVar1[-10];
      local_18 = puVar1[-9];
      local_14 = puVar1[-8];
      local_10 = puVar1[-7];
      local_c = puVar1[-6];
      local_8 = puVar1[-5];
      iVar2 = iVar2 + -1;
      local_34 = gbBezKey<gbVec3<float>_>::vftable;
      local_20 = 0;
      FUN_0078fb20(param_1,&local_34,param_2);
      puVar1 = puVar1 + -0xc;
    } while (0 < iVar2);
  }
  return;
}

