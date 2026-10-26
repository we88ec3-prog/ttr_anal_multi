
void FUN_00789ab0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_1c [4];
  undefined4 local_c;
  undefined4 local_8;
  
  if (in_ECX != 0) {
    puVar1 = (undefined4 *)(in_EAX + 8);
    do {
      if (puVar1 != (undefined4 *)0x8) {
        puVar1[-2] = gbKey<gbQuat>::vftable;
        puVar1[-1] = 0;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0x3f800000;
        if (puVar1 + -1 != local_1c) {
          puVar1[2] = 0x3f800000;
          puVar1[-1] = 0;
          *puVar1 = 0;
          puVar1[1] = 0;
        }
        puVar1[3] = local_c;
        puVar1[4] = local_8;
      }
      puVar1 = puVar1 + 7;
      in_ECX = in_ECX + -1;
    } while (in_ECX != 0);
  }
  return;
}

