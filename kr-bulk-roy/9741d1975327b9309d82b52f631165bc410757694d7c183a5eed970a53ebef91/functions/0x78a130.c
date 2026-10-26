
void FUN_0078a130(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  int iVar3;
  undefined **local_64 [20];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = (in_EAX - param_1) / 0x60;
  iVar3 = iVar1 / 2;
  if (0 < iVar3) {
    puVar2 = (undefined4 *)(iVar3 * 0x60 + 0x54 + param_1);
    do {
      iVar3 = iVar3 + -1;
      FUN_007852a0();
      local_14 = puVar2[-0x19];
      local_10 = puVar2[-0x18];
      local_c = puVar2[-0x17];
      local_8 = puVar2[-0x16];
      local_64[0] = gbTCBRotKey::vftable;
      FUN_0078b050(param_1,iVar1,local_64,param_2);
      puVar2 = puVar2 + -0x18;
    } while (0 < iVar3);
  }
  return;
}

