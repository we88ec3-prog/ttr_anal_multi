
void FUN_0078c1e0(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_10;
  uint local_8;
  
  local_10 = ((int)(param_3 - param_2) / 0x60) * 0x30 + param_2;
  FUN_0078e4b0(param_2,local_10,param_3 - 0x30,param_4);
  uVar2 = local_10 + 0x30;
  for (; param_2 < local_10; local_10 = local_10 - 0x30) {
    if ((*(int *)(local_10 - 0x20) < *(int *)(local_10 + 0x10)) ||
       (*(int *)(local_10 + 0x10) < *(int *)(local_10 - 0x20))) break;
  }
  uVar3 = uVar2;
  local_8 = uVar2;
  uVar1 = local_10;
  if (uVar2 < param_3) {
    do {
      uVar3 = uVar2;
      local_8 = uVar2;
      if ((*(int *)(uVar2 + 0x10) < *(int *)(local_10 + 0x10)) ||
         (*(int *)(local_10 + 0x10) < *(int *)(uVar2 + 0x10))) break;
      uVar2 = uVar2 + 0x30;
      uVar3 = uVar2;
      local_8 = uVar2;
    } while (uVar2 < param_3);
  }
joined_r0x0078c273:
  do {
    if (param_3 <= uVar2) {
joined_r0x0078c2a7:
      for (; param_2 < local_10; local_10 = local_10 - 0x30) {
        if (*(int *)(uVar1 + 0x10) <= *(int *)(local_10 - 0x20)) {
          if (*(int *)(uVar1 + 0x10) < *(int *)(local_10 - 0x20)) break;
          uVar1 = uVar1 - 0x30;
          FUN_0078fa80();
          uVar3 = local_8;
        }
      }
      if (local_10 == param_2) {
        if (uVar2 == param_3) {
          param_1[1] = uVar3;
          *param_1 = uVar1;
          return;
        }
        uVar4 = uVar3;
        if (uVar3 != uVar2) {
          FUN_0078fa80();
          uVar4 = local_8;
        }
        uVar2 = uVar2 + 0x30;
        FUN_0078fa80();
        uVar3 = uVar4 + 0x30;
        local_8 = uVar4 + 0x30;
        uVar1 = uVar1 + 0x30;
      }
      else {
        local_10 = local_10 - 0x30;
        if (uVar2 == param_3) {
          uVar4 = uVar3;
          if (local_10 != uVar1 - 0x30) {
            FUN_0078fa80();
            uVar4 = local_8;
          }
          FUN_0078fa80();
          uVar3 = uVar4 - 0x30;
          local_8 = uVar4 - 0x30;
          uVar1 = uVar1 - 0x30;
        }
        else {
          FUN_0078fa80();
          uVar2 = uVar2 + 0x30;
          uVar3 = local_8;
        }
      }
      goto joined_r0x0078c273;
    }
    if (*(int *)(uVar2 + 0x10) <= *(int *)(uVar1 + 0x10)) {
      if (*(int *)(uVar2 + 0x10) < *(int *)(uVar1 + 0x10)) goto joined_r0x0078c2a7;
      uVar3 = uVar3 + 0x30;
      FUN_0078fa80();
      local_8 = uVar3;
    }
    uVar2 = uVar2 + 0x30;
  } while( true );
}

