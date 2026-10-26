
void FUN_007899c0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_28;
  
  if (in_ECX != 0) {
    puVar1 = (undefined4 *)(in_EAX + 4);
    do {
      if (puVar1 != (undefined4 *)0x4) {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = local_28;
        puVar1[5] = 0;
        puVar1[6] = 0;
        puVar1[7] = 0;
        puVar1[8] = 0;
        puVar1[9] = 0;
        puVar1[-1] = gbBezKey<gbVec3<float>_>::vftable;
        puVar1[10] = 0;
        puVar1[4] = 0;
      }
      in_ECX = in_ECX + -1;
      puVar1 = puVar1 + 0xc;
    } while (in_ECX != 0);
  }
  return;
}

