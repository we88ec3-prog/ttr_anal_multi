
void FUN_0078db40(int param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined **local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = (in_EAX - param_1) / 0x30;
  if (0 < iVar1) {
    iVar2 = param_1 + 8 + iVar1 * 0x18;
    do {
      local_18 = *(undefined4 *)(iVar2 + -0x1c);
      local_14 = *(undefined4 *)(iVar2 + -0x18);
      local_c = *(undefined4 *)(iVar2 + -0x10);
      local_8 = *(undefined4 *)(iVar2 + -0xc);
      iVar1 = iVar1 + -1;
      local_1c = gbBezKey<float>::vftable;
      local_10 = 0;
      FUN_0078f650(&local_1c,param_2);
      iVar2 = iVar2 + -0x18;
    } while (0 < iVar1);
  }
  return;
}

