
undefined4 * FUN_0071c150(undefined4 *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint **ppuVar5;
  int *in_ECX;
  uint *puVar6;
  undefined1 *local_2c;
  undefined1 local_28;
  undefined1 *local_24;
  uint local_20;
  undefined4 local_1c;
  uint *local_18;
  undefined4 local_14;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  if (in_ECX[1] != 0) {
    puVar3 = *(undefined1 **)(in_ECX[1] + 8);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_00bf2375;
    }
    *param_1 = puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return param_1;
  }
  puVar1 = (uint *)*in_ECX;
  if (puVar1 == (uint *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*puVar1 & 7) + 1;
  }
  switch(iVar4) {
  case 1:
  case 2:
    local_24 = &DAT_00bf2375;
    local_20 = local_20 & 0xffffff00;
    local_8 = puVar1;
    FUN_0071bbe0();
    puVar2 = local_c;
    break;
  case 3:
  case 4:
  case 5:
  case 6:
    if ((puVar1 == (uint *)0x0) || (puVar3 = (undefined1 *)puVar1[3], puVar3 == (undefined1 *)0x0))
    {
      puVar3 = &DAT_00bf2375;
    }
    *param_1 = puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return param_1;
  default:
    *(undefined1 *)(param_1 + 1) = 0;
    *param_1 = &DAT_00bf2375;
    return param_1;
  }
joined_r0x0071c1dd:
  do {
    do {
      while( true ) {
        puVar6 = puVar2;
        if ((puVar6 == (uint *)0x0) || (puVar6 == puVar1)) {
          *param_1 = local_24;
          param_1[1] = local_20;
          return param_1;
        }
        if (puVar6 == (uint *)0x0) {
          local_8 = (uint *)0x0;
          ppuVar5 = &local_8;
        }
        else {
          if (((*puVar6 & 7) == 2) || ((*puVar6 & 7) == 3)) {
            local_2c = (undefined1 *)puVar6[3];
            if (local_2c == (undefined1 *)0x0) {
              local_2c = &DAT_00bf2375;
            }
            local_28 = 0;
            FUN_0071c040(&local_24,&local_2c,param_2);
          }
          local_c = (uint *)puVar6[4];
          ppuVar5 = &local_c;
        }
        if (*ppuVar5 == (uint *)0x0) break;
        if (puVar6 == (uint *)0x0) {
          local_14 = 0;
          puVar2 = (uint *)0x0;
        }
        else {
          local_10 = (uint *)puVar6[4];
          puVar2 = local_10;
        }
      }
      if (puVar6 == (uint *)0x0) goto LAB_0071c26a;
      puVar2 = (uint *)puVar6[6];
    } while ((uint *)puVar6[6] != (uint *)0x0);
    while ((puVar6 == (uint *)0x0 || (puVar6[6] == 0))) {
LAB_0071c26a:
      puVar2 = puVar6;
      if (puVar6 == puVar1) goto joined_r0x0071c1dd;
      if (puVar6 == (uint *)0x0) {
        local_1c = 0;
        puVar6 = (uint *)0x0;
      }
      else {
        puVar6 = (uint *)puVar6[1];
        local_18 = puVar6;
      }
    }
    puVar2 = puVar6;
    if (puVar6 != puVar1) {
      if (puVar6 == (uint *)0x0) {
        puVar2 = (uint *)0x0;
      }
      else {
        puVar2 = (uint *)puVar6[6];
      }
    }
  } while( true );
}

