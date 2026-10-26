
void FUN_0078e2e0(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined **local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = (in_EAX - param_1) / 0x30;
  if (0 < iVar2) {
    puVar1 = (undefined4 *)(param_1 + 0x10 + iVar2 * 0x18);
    do {
      local_18 = puVar1[-9];
      local_14 = puVar1[-8];
      local_10 = puVar1[-7];
      local_c = puVar1[-6];
      local_8 = puVar1[-5];
      iVar2 = iVar2 + -1;
      local_1c = gbKey<gbVec3<float>_>::vftable;
      FUN_0078f9c0(param_1,&local_1c,param_2);
      puVar1 = puVar1 + -6;
    } while (0 < iVar2);
  }
  return;
}

