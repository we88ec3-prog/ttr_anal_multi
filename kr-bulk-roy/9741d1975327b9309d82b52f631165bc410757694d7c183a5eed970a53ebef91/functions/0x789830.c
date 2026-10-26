
void FUN_00789830(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (in_ECX != 0) {
    puVar1 = (undefined4 *)(in_EAX + 8);
    do {
      if (puVar1 != (undefined4 *)0x8) {
        puVar1[-1] = local_10;
        puVar1[-2] = gbKey<float>::vftable;
        *puVar1 = local_c;
        puVar1[1] = local_8;
      }
      puVar1 = puVar1 + 4;
      in_ECX = in_ECX + -1;
    } while (in_ECX != 0);
  }
  return;
}

