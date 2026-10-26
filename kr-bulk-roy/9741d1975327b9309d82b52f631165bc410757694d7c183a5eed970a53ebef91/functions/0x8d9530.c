
void FUN_008d9530(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *in_EAX;
  uint uVar4;
  uint uVar5;
  int *in_EDX;
  undefined1 *puVar6;
  uint local_20;
  undefined1 *local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  puVar6 = (undefined1 *)*in_EDX;
  local_10 = in_EDX[2];
  local_14 = in_EDX[4];
  uVar5 = 0;
  bVar3 = true;
  local_8 = 0x80;
  local_c = 0;
  local_20 = 0;
  bVar2 = true;
  local_18 = puVar6;
  if (0 < local_14) {
    do {
      uVar4 = local_20;
      if (bVar2) {
        do {
          if (bVar3) {
            if (param_1 <= in_EAX) break;
            bVar1 = *in_EAX;
            uVar4 = bVar1 & 0xf;
            in_EAX = in_EAX + 1;
            bVar3 = false;
            uVar5 = (int)(uint)bVar1 >> 4;
            local_20 = uVar4;
          }
          else {
            bVar3 = true;
            uVar5 = uVar4;
          }
        } while (uVar5 == 0);
      }
      if (bVar3) {
        local_c = local_c | local_8;
        puVar6 = local_18;
      }
      local_10 = local_10 + -1;
      local_8 = local_8 >> 1;
      if (local_10 < 1) {
        *puVar6 = (undefined1)local_c;
        local_10 = in_EDX[2];
        *in_EDX = *in_EDX + in_EDX[1];
        puVar6 = (undefined1 *)*in_EDX;
LAB_008d95e0:
        local_c = 0;
        local_8 = 0x80;
        local_18 = puVar6;
      }
      else if (local_8 == 0) {
        *puVar6 = (undefined1)local_c;
        puVar6 = puVar6 + 1;
        goto LAB_008d95e0;
      }
      uVar5 = uVar5 - 1;
      bVar2 = (int)uVar5 < 1;
      local_14 = local_14 + -1;
    } while (0 < local_14);
    if (local_8 != 0x80) {
      *puVar6 = (undefined1)local_c;
    }
  }
  return;
}

