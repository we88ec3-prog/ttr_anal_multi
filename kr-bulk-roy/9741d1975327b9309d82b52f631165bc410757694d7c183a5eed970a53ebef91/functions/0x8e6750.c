
void FUN_008e6750(int param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint local_c;
  
  uVar1 = *(undefined4 *)(param_1 + 100);
  puVar4 = *(uint **)(param_1 + 0x210);
  if (puVar4 != (uint *)0x0) {
    uVar6 = puVar4[1];
    uVar5 = *puVar4;
    FUN_008b9f80(uVar1,puVar4[6]);
    puVar4[6] = 0;
    if (1 < uVar5) {
      puVar2 = puVar4 + 7;
      uVar3 = uVar5;
      while (uVar3 = uVar3 - 1, uVar3 != 0) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
    }
    FUN_008b9f80(uVar1,puVar4[0x36]);
    puVar4[0x36] = 0;
    FUN_008b9f80(uVar1,puVar4[0x25]);
    puVar4[0x25] = 0;
    FUN_008b9f80(uVar1,puVar4[0x48]);
    puVar4[0x48] = 0;
    if (uVar5 != 0) {
      puVar2 = puVar4 + 0x24;
      do {
        puVar2[0x11] = 0;
        *puVar2 = 0;
        puVar2[0x23] = 0;
        puVar2 = puVar2 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    FUN_008b9f80(uVar1,puVar4[0x22]);
    puVar4[0x22] = 0;
    puVar4[0x23] = 0;
    if (uVar6 != 0) {
      puVar2 = puVar4 + 2;
      local_c = uVar6;
      do {
        FUN_008b9f80(uVar1,*puVar2);
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
        local_c = local_c - 1;
      } while (local_c != 0);
    }
    if (uVar6 != 0) {
      puVar4 = puVar4 + 0x17;
      do {
        FUN_008b9f80(uVar1,*puVar4);
        *puVar4 = 0;
        *(undefined1 *)(puVar4 + -1) = 0;
        puVar4 = puVar4 + 3;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    FUN_008b9f80(uVar1,*(undefined4 *)(param_1 + 0x210));
    *(undefined4 *)(param_1 + 0x210) = 0;
  }
  return;
}

