
void FUN_0078df00(undefined4 param_1)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
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
  int local_8;
  
  local_8 = (in_EAX - in_ECX) / 0x2c;
  iVar1 = local_8 / 2;
  if (0 < iVar1) {
    iVar2 = iVar1 * 0x2c + 8 + in_ECX;
    do {
      local_30 = *(undefined4 *)(iVar2 + -0x30);
      local_2c = *(undefined4 *)(iVar2 + -0x2c);
      local_28 = *(undefined4 *)(iVar2 + -0x28);
      local_24 = *(undefined4 *)(iVar2 + -0x24);
      local_20 = *(undefined4 *)(iVar2 + -0x20);
      local_1c = *(undefined4 *)(iVar2 + -0x1c);
      local_18 = *(undefined4 *)(iVar2 + -0x18);
      iVar1 = iVar1 + -1;
      local_14 = *(undefined4 *)(iVar2 + -0x14);
      local_34 = gbTCBKey<float>::vftable;
      local_10 = *(undefined4 *)(iVar2 + -0x10);
      local_c = *(undefined4 *)(iVar2 + -0xc);
      FUN_0078f7c0(&local_34,param_1);
      iVar2 = iVar2 + -0x2c;
    } while (0 < iVar1);
  }
  return;
}

