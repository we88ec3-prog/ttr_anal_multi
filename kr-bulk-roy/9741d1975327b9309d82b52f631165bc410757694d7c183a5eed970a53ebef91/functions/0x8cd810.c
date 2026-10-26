
void FUN_008cd810(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *in_ECX;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int local_8;
  
  if (param_5 == 0) {
    puVar7 = in_ECX + 0x81;
  }
  else {
    puVar7 = in_ECX + 0x183;
    in_ECX = in_ECX + 0x102;
  }
  *in_ECX = 0;
  *puVar7 = 0;
  FUN_008cd6f0(0);
  FUN_008cd6f0(1,param_3,in_ECX,puVar7);
  uVar4 = *in_ECX;
  uVar1 = *puVar7;
  if (0 < (int)uVar4) {
    puVar2 = in_ECX + 1;
    uVar5 = uVar4;
    do {
      if ((1 < uVar5) && ((int)(puVar2[8] - *puVar2) < (int)puVar2[1])) {
        puVar2[1] = puVar2[8] - *puVar2;
      }
      puVar2[3] = *puVar2;
      puVar2[2] = puVar2[1] + *puVar2;
      puVar2 = puVar2 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  if (0 < (int)uVar1) {
    puVar2 = puVar7 + 1;
    for (uVar5 = uVar1; uVar5 != 0; uVar5 = uVar5 - 1) {
      if ((1 < uVar5) && ((int)puVar2[1] < (int)(*puVar2 - puVar2[8]))) {
        puVar2[1] = *puVar2 - puVar2[8];
      }
      puVar2[2] = *puVar2;
      puVar2[3] = puVar2[1] + *puVar2;
      puVar2 = puVar2 + 8;
    }
  }
  local_8 = 1;
  do {
    puVar2 = in_ECX + 1;
    if (uVar4 != 0) {
      in_ECX[4] = in_ECX[4] - param_4;
      iVar6 = uVar4 - 1;
      uVar4 = in_ECX[3];
      if (iVar6 != 0) {
        do {
          iVar3 = puVar2[0xb] - uVar4;
          if (iVar3 < param_4 * 2) {
            uVar4 = iVar3 / 2 + uVar4;
            puVar2[0xb] = uVar4;
            puVar2[2] = uVar4;
          }
          else {
            puVar2[2] = uVar4 + param_4;
            puVar2[0xb] = puVar2[0xb] - param_4;
          }
          uVar4 = puVar2[10];
          puVar2 = puVar2 + 8;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      puVar2[2] = uVar4 + param_4;
    }
    local_8 = local_8 + -1;
    uVar4 = uVar1;
    in_ECX = puVar7;
  } while (-1 < local_8);
  return;
}

