
void FUN_008d9620(byte *param_1,byte *param_2)

{
  bool bVar1;
  bool bVar2;
  int *in_EAX;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  int local_10;
  int local_c;
  
  local_c = in_EAX[2];
  local_10 = in_EAX[4];
  puVar5 = (undefined1 *)*in_EAX;
  uVar3 = 0;
  uVar4 = 0;
  uVar6 = 0x80;
  bVar2 = true;
  bVar1 = true;
  if (0 < local_10) {
    do {
      if (bVar1) {
        do {
          if (param_2 <= param_1) break;
          uVar3 = (uint)*param_1;
          bVar2 = (bool)(bVar2 ^ 1);
          param_1 = param_1 + 1;
        } while (uVar3 == 0);
      }
      if (bVar2) {
        uVar4 = uVar4 | uVar6;
      }
      local_c = local_c + -1;
      uVar6 = uVar6 >> 1;
      if (local_c < 1) {
        *puVar5 = (char)uVar4;
        local_c = in_EAX[2];
        *in_EAX = *in_EAX + in_EAX[1];
        puVar5 = (undefined1 *)*in_EAX;
LAB_008d96ab:
        uVar4 = 0;
        uVar6 = 0x80;
      }
      else if (uVar6 == 0) {
        *puVar5 = (char)uVar4;
        puVar5 = puVar5 + 1;
        goto LAB_008d96ab;
      }
      uVar3 = uVar3 - 1;
      bVar1 = (int)uVar3 < 1;
      local_10 = local_10 + -1;
    } while (0 < local_10);
    if (uVar6 != 0x80) {
      *puVar5 = (char)uVar4;
    }
  }
  return;
}

