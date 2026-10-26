
undefined4 FUN_004d11c0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_004c88f0();
  if (*(int *)(in_ECX + 0x370) != 0) {
    if (*(int *)(in_ECX + 0x15c) == 0) {
      local_10 = *(undefined4 *)(in_ECX + 0xa0);
      local_c = *(undefined4 *)(in_ECX + 0xa4);
      local_8 = *(undefined4 *)(in_ECX + 0xa8);
    }
    else {
      FUN_007a8630(0x3f800000);
    }
    FUN_004c9b60(in_ECX + 6,local_10,local_c,local_8,0xfffff000,0xff000000,0);
  }
  if ((*(int *)(in_ECX + 0x424) != 0) &&
     (iVar1 = *(int *)(*(int *)(in_ECX + 0x424) + 0x24), iVar1 != 0)) {
    FUN_007bdf40(iVar1);
  }
  return 0;
}

