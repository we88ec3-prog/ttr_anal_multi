
void FUN_00824f10(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint local_8;
  
  puVar5 = (undefined4 *)(param_1 + 8);
  local_8 = 2;
  do {
    if (puVar5 == param_2) {
      return;
    }
    uVar6 = 0x7fff;
    uVar3 = FUN_0089289d();
    uVar3 = uVar3 & 0x7fff;
    if (0x7fff < local_8) {
      do {
        if (uVar6 == 0xffffffff) break;
        uVar4 = FUN_0089289d();
        uVar6 = uVar6 << 0xf | 0x7fff;
        uVar3 = uVar3 << 0xf | uVar4 & 0x7fff;
      } while (uVar6 < local_8);
    }
    puVar1 = (undefined4 *)(param_1 + (uVar3 % local_8) * 8);
    if (puVar5 != puVar1) {
      uVar2 = *puVar5;
      *puVar5 = *puVar1;
      *puVar1 = uVar2;
      uVar2 = puVar5[1];
      puVar5[1] = puVar1[1];
      puVar1[1] = uVar2;
    }
    local_8 = local_8 + 1;
    puVar5 = puVar5 + 2;
  } while( true );
}

