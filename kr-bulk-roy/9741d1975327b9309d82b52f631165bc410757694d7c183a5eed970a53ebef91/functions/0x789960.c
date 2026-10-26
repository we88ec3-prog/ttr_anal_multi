
void FUN_00789960(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (in_ECX != 0) {
    puVar1 = (undefined4 *)(in_EAX + 4);
    do {
      if (puVar1 != (undefined4 *)0x4) {
        puVar1[-1] = gbKey<gbVec3<float>_>::vftable;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = local_10;
        puVar1[4] = local_c;
      }
      puVar1 = puVar1 + 6;
      in_ECX = in_ECX + -1;
    } while (in_ECX != 0);
  }
  return;
}

