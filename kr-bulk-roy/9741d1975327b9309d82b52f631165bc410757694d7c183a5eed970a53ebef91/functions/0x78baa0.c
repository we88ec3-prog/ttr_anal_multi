
uint * FUN_0078baa0(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_8;
  
  uVar5 = ((int)(param_3 - param_2) / 0x58) * 0x2c + param_2;
  FUN_0078dd80(uVar5,param_3 - 0x2c,param_4);
  uVar1 = uVar5 + 0x2c;
  for (; param_2 < uVar5; uVar5 = uVar5 - 0x2c) {
    if ((*(int *)(uVar5 - 0x24) < *(int *)(uVar5 + 8)) ||
       (*(int *)(uVar5 + 8) < *(int *)(uVar5 - 0x24))) break;
  }
  uVar2 = uVar1;
  local_8 = uVar1;
  uVar4 = uVar5;
  if (uVar1 < param_3) {
    do {
      uVar2 = uVar1;
      local_8 = uVar1;
      if ((*(int *)(uVar1 + 8) < *(int *)(uVar5 + 8)) || (*(int *)(uVar5 + 8) < *(int *)(uVar1 + 8))
         ) break;
      uVar1 = uVar1 + 0x2c;
      uVar2 = uVar1;
      local_8 = uVar1;
    } while (uVar1 < param_3);
  }
joined_r0x0078bb2a:
  do {
    if (param_3 <= uVar1) {
joined_r0x0078bb59:
      for (; param_2 < uVar4; uVar4 = uVar4 - 0x2c) {
        if (*(int *)(uVar5 + 8) <= *(int *)(uVar4 - 0x24)) {
          if (*(int *)(uVar5 + 8) < *(int *)(uVar4 - 0x24)) break;
          uVar5 = uVar5 - 0x2c;
          FUN_0078f700();
          uVar2 = local_8;
        }
      }
      if (uVar4 == param_2) {
        if (uVar1 == param_3) {
          *param_1 = uVar5;
          param_1[1] = uVar2;
          return param_1;
        }
        uVar3 = uVar2;
        if (uVar2 != uVar1) {
          FUN_0078f700();
          uVar3 = local_8;
        }
        uVar5 = uVar5 + 0x2c;
        uVar1 = uVar1 + 0x2c;
        FUN_0078f700();
        uVar2 = uVar3 + 0x2c;
        local_8 = uVar3 + 0x2c;
      }
      else {
        uVar4 = uVar4 - 0x2c;
        if (uVar1 == param_3) {
          uVar5 = uVar5 - 0x2c;
          uVar3 = uVar2;
          if (uVar4 != uVar5) {
            FUN_0078f700();
            uVar3 = local_8;
          }
          FUN_0078f700();
          uVar2 = uVar3 - 0x2c;
          local_8 = uVar3 - 0x2c;
        }
        else {
          FUN_0078f700();
          uVar1 = uVar1 + 0x2c;
          uVar2 = local_8;
        }
      }
      goto joined_r0x0078bb2a;
    }
    if (*(int *)(uVar1 + 8) <= *(int *)(uVar5 + 8)) {
      if (*(int *)(uVar1 + 8) < *(int *)(uVar5 + 8)) goto joined_r0x0078bb59;
      uVar2 = uVar2 + 0x2c;
      FUN_0078f700();
      local_8 = uVar2;
    }
    uVar1 = uVar1 + 0x2c;
  } while( true );
}

