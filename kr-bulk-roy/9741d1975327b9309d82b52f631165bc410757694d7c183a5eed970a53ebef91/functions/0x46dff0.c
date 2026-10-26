
void FUN_0046dff0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_8;
  
  local_8 = 2;
  puVar3 = (undefined4 *)(param_1 + 4);
  do {
    if (puVar3 == param_2) {
      return;
    }
    uVar6 = 0x7fff;
    uVar4 = FUN_0089289d();
    uVar4 = uVar4 & 0x7fff;
    if (0x7fff < local_8) {
      do {
        if (uVar6 == 0xffffffff) break;
        uVar5 = FUN_0089289d();
        uVar6 = uVar6 << 0xf | 0x7fff;
        uVar4 = uVar4 << 0xf | uVar5 & 0x7fff;
      } while (uVar6 < local_8);
    }
    uVar4 = uVar4 % local_8;
    uVar2 = *puVar3;
    local_8 = local_8 + 1;
    puVar1 = (undefined4 *)(param_1 + uVar4 * 4);
    *puVar3 = *puVar1;
    *puVar1 = uVar2;
    puVar3 = puVar3 + 1;
  } while( true );
}

