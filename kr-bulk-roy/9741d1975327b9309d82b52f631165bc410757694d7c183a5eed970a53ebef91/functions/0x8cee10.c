
void FUN_008cee10(void)

{
  uint uVar1;
  int in_EAX;
  uint uVar2;
  char cVar3;
  uint *in_ECX;
  uint *puVar4;
  uint uVar5;
  int local_1c;
  uint local_c;
  uint local_8;
  
  local_8 = *(uint *)in_ECX[in_EAX * 10 + 0xf];
  uVar5 = ((uint *)in_ECX[in_EAX * 10 + 0xf])[2];
  cVar3 = (in_EAX != 0) + '\x01';
  FUN_008b7f40(0x20,*(undefined4 *)(in_EAX * 0xcc + 200 + in_ECX[6]));
  if ((1 < local_8) && (uVar2 = *in_ECX, uVar2 != 0)) {
    uVar1 = *(uint *)(uVar5 + 0xc);
    if (uVar1 <= uVar2) {
      uVar2 = uVar1;
    }
    local_1c = local_8 - 1;
    do {
      local_c = *in_ECX;
      if (*(uint *)(uVar5 + 0x1c) <= *in_ECX) {
        local_c = *(uint *)(uVar5 + 0x1c);
      }
      if (0 < (int)(local_c - uVar2)) {
        uVar1 = in_ECX[2];
        FUN_008ce1d0();
        FUN_008cec30(uVar1 + uVar2 * 0x28,local_c - uVar2,cVar3);
      }
      local_8 = local_8 - 1;
      local_1c = local_1c + -1;
      uVar2 = local_c;
      uVar5 = uVar5 + 0x10;
    } while (local_1c != 0);
  }
  if (local_8 == 1) {
    uVar5 = in_ECX[2];
    uVar2 = *in_ECX;
    FUN_008ce1d0();
    FUN_008cec30(uVar5,uVar2,cVar3);
  }
  uVar5 = *in_ECX;
  if (uVar5 != 0) {
    puVar4 = (uint *)(in_ECX[2] + 0x10);
    do {
      if ((puVar4[2] != 0) && ((*puVar4 & 0x10) == 0)) {
        *puVar4 = *puVar4 | 0x10;
      }
      puVar4 = puVar4 + 10;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return;
}

