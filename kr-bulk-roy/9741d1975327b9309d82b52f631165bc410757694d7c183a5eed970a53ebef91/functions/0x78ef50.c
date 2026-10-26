
void FUN_0078ef50(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int unaff_EDI;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (1 < (in_EAX - unaff_EDI) / 0x1c) {
    puVar1 = (undefined4 *)(in_EAX + -0x14);
    local_8 = 0x14 - unaff_EDI;
    do {
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0x3f800000;
      if (&local_20 != puVar1 + -1) {
        local_14 = puVar1[2];
        local_20 = puVar1[-1];
        local_1c = *puVar1;
        local_18 = puVar1[1];
      }
      local_10 = puVar1[3];
      local_c = puVar1[4];
      if (puVar1 + -1 != (undefined4 *)(unaff_EDI + 4)) {
        puVar1[2] = *(undefined4 *)(unaff_EDI + 0x10);
        puVar1[-1] = *(undefined4 *)(unaff_EDI + 4);
        *puVar1 = *(undefined4 *)(unaff_EDI + 8);
        puVar1[1] = *(undefined4 *)(unaff_EDI + 0xc);
      }
      puVar1[3] = *(undefined4 *)(unaff_EDI + 0x14);
      puVar1[4] = *(undefined4 *)(unaff_EDI + 0x18);
      FUN_0078fe90();
      puVar1 = puVar1 + -7;
    } while (1 < (local_8 + (int)puVar1) / 0x1c);
  }
  return;
}

