
void FUN_00725700(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 *local_8;
  
  puVar3 = param_1 + 2;
  if (puVar3 != param_2) {
    local_8 = param_1;
    do {
      local_c = puVar3[1];
      uVar1 = *puVar3;
      local_10 = uVar1;
      cVar2 = FUN_0071c4a0(&local_10);
      puVar4 = puVar3;
      if (cVar2 == '\0') {
        cVar2 = FUN_0071c4a0(&local_10);
        puVar5 = local_8;
        while (cVar2 != '\0') {
          uVar1 = *puVar5;
          puVar4[1] = puVar5[1];
          puVar5 = puVar5 + -2;
          *puVar4 = uVar1;
          puVar4 = puVar4 + -2;
          cVar2 = FUN_0071c4a0(&local_10);
        }
        *puVar4 = local_10;
        puVar4[1] = local_c;
      }
      else {
        for (; param_1 != puVar4; puVar4 = puVar4 + -2) {
          *puVar4 = puVar4[-2];
          puVar4[1] = puVar4[-1];
        }
        *param_1 = uVar1;
        param_1[1] = local_c;
      }
      local_8 = local_8 + 2;
      puVar3 = puVar3 + 2;
    } while (puVar3 != param_2);
  }
  return;
}

