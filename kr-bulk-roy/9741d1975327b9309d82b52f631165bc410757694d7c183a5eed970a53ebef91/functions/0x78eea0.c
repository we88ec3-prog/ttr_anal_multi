
void FUN_0078eea0(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined **local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = (in_EAX - param_1) / 0x1c;
  iVar2 = iVar1 / 2;
  if (0 < iVar2) {
    puVar3 = (undefined4 *)(param_1 + 8 + iVar2 * 0x1c);
    do {
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      iVar2 = iVar2 + -1;
      local_20 = gbKey<gbQuat>::vftable;
      local_10 = 0x3f800000;
      if (&local_1c != puVar3 + -8) {
        local_10 = puVar3[-5];
        local_1c = puVar3[-8];
        local_18 = puVar3[-7];
        local_14 = puVar3[-6];
      }
      local_c = puVar3[-4];
      local_8 = puVar3[-3];
      FUN_0078fe90(param_1,iVar1,&local_20,param_2);
      puVar3 = puVar3 + -7;
    } while (0 < iVar2);
  }
  return;
}

