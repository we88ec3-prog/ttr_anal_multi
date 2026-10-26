
void FUN_0078ce00(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_c;
  uint local_8;
  
  local_c = param_2 + ((int)(param_3 - param_2) / 0x38) * 0x1c;
  FUN_0078ed00(param_2,local_c,param_3 - 0x1c,param_4);
  uVar1 = local_c + 0x1c;
  for (; param_2 < local_c; local_c = local_c - 0x1c) {
    if ((*(int *)(local_c - 8) < *(int *)(local_c + 0x14)) ||
       (*(int *)(local_c + 0x14) < *(int *)(local_c - 8))) break;
  }
  uVar2 = uVar1;
  local_8 = uVar1;
  uVar4 = local_c;
  if (uVar1 < param_3) {
    do {
      uVar2 = uVar1;
      local_8 = uVar1;
      if ((*(int *)(uVar1 + 0x14) < *(int *)(local_c + 0x14)) ||
         (*(int *)(local_c + 0x14) < *(int *)(uVar1 + 0x14))) break;
      uVar1 = uVar1 + 0x1c;
      uVar2 = uVar1;
      local_8 = uVar1;
    } while (uVar1 < param_3);
  }
joined_r0x0078ce93:
  do {
    if (param_3 <= uVar1) {
joined_r0x0078cec1:
      for (; param_2 < local_c; local_c = local_c - 0x1c) {
        if (*(int *)(uVar4 + 0x14) <= *(int *)(local_c - 8)) {
          if (*(int *)(uVar4 + 0x14) < *(int *)(local_c - 8)) break;
          uVar4 = uVar4 - 0x1c;
          FUN_0078fdf0();
          uVar2 = local_8;
        }
      }
      if (local_c == param_2) {
        if (uVar1 == param_3) {
          *param_1 = uVar4;
          param_1[1] = uVar2;
          return;
        }
        uVar3 = uVar2;
        if (uVar2 != uVar1) {
          FUN_0078fdf0();
          uVar3 = local_8;
        }
        uVar1 = uVar1 + 0x1c;
        FUN_0078fdf0();
        uVar2 = uVar3 + 0x1c;
        local_8 = uVar3 + 0x1c;
        uVar4 = uVar4 + 0x1c;
      }
      else {
        local_c = local_c - 0x1c;
        if (uVar1 == param_3) {
          uVar3 = uVar2;
          if (local_c != uVar4 - 0x1c) {
            FUN_0078fdf0();
            uVar3 = local_8;
          }
          FUN_0078fdf0();
          uVar2 = uVar3 - 0x1c;
          local_8 = uVar3 - 0x1c;
          uVar4 = uVar4 - 0x1c;
        }
        else {
          FUN_0078fdf0();
          uVar1 = uVar1 + 0x1c;
          uVar2 = local_8;
        }
      }
      goto joined_r0x0078ce93;
    }
    if (*(int *)(uVar1 + 0x14) <= *(int *)(uVar4 + 0x14)) {
      if (*(int *)(uVar1 + 0x14) < *(int *)(uVar4 + 0x14)) goto joined_r0x0078cec1;
      uVar2 = uVar2 + 0x1c;
      FUN_0078fdf0();
      local_8 = uVar2;
    }
    uVar1 = uVar1 + 0x1c;
  } while( true );
}

