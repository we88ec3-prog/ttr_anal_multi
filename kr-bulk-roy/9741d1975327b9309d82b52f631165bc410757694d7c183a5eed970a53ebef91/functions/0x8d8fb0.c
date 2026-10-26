
uint FUN_008d8fb0(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_8;
  
  uVar5 = *param_2;
  local_8 = 0;
  do {
    uVar5 = uVar5 + 1;
    uVar4 = 0;
    uVar2 = *(uint *)(param_1 + 0x10);
    while( true ) {
      uVar3 = uVar2;
      if (uVar3 <= uVar4) {
        if (*(uint *)(param_1 + 0x10) <= uVar4) {
          *param_2 = 0;
          return local_8;
        }
        if (uVar4 == 0) {
          *param_2 = 0;
          return 0;
        }
        *param_2 = *(uint *)(*(int *)(param_1 + 0x14) + uVar4 * 0x10);
        return uVar4 + 1;
      }
      uVar2 = (uVar3 - uVar4 >> 1) + uVar4;
      uVar1 = *(uint *)(uVar2 * 0x10 + *(int *)(param_1 + 0x14));
      if (uVar1 == uVar5) break;
      if (uVar1 < uVar5) {
        uVar4 = uVar2 + 1;
        uVar2 = uVar3;
      }
    }
    local_8 = uVar2;
    if (uVar2 != 0) {
      *param_2 = uVar5;
      return uVar2 + 1;
    }
  } while( true );
}

