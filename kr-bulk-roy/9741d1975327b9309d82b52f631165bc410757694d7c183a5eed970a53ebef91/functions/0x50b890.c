
void FUN_0050b890(int *param_1,code *param_2,int param_3,uint param_4,undefined4 param_5,
                 uint param_6)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_14;
  uint local_c;
  
  local_14 = (int)(param_6 - param_4) / 2 + param_4;
  FUN_0050bbc0(param_3,param_4,param_3,local_14,param_5,param_6 - 1);
  local_c = local_14 + 1;
  if (param_4 < local_14) {
    while( true ) {
      uVar3 = local_14;
      if (*(uint *)(param_3 + 8) <= local_14) {
        uVar3 = local_14 - *(uint *)(param_3 + 8);
      }
      uVar4 = local_14 - 1;
      if (*(uint *)(param_3 + 8) <= uVar4) {
        uVar4 = uVar4 - *(uint *)(param_3 + 8);
      }
      cVar2 = (*param_2)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar4 * 4),
                         *(undefined4 *)(*(int *)(param_3 + 4) + uVar3 * 4));
      if (cVar2 != '\0') break;
      uVar3 = local_14 - 1;
      if (*(uint *)(param_3 + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(param_3 + 8);
      }
      uVar4 = local_14;
      if (*(uint *)(param_3 + 8) <= local_14) {
        uVar4 = local_14 - *(uint *)(param_3 + 8);
      }
      cVar2 = (*param_2)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar4 * 4),
                         *(undefined4 *)(*(int *)(param_3 + 4) + uVar3 * 4));
      if ((cVar2 != '\0') || (local_14 = local_14 - 1, local_14 <= param_4)) break;
    }
  }
  uVar3 = local_c;
  uVar4 = local_c;
  uVar1 = local_c;
  uVar8 = local_14;
  if (local_c < param_6) {
    while( true ) {
      uVar3 = local_14;
      if (*(uint *)(param_3 + 8) <= local_14) {
        uVar3 = local_14 - *(uint *)(param_3 + 8);
      }
      uVar4 = local_c;
      if (*(uint *)(param_3 + 8) <= local_c) {
        uVar4 = local_c - *(uint *)(param_3 + 8);
      }
      cVar2 = (*param_2)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar4 * 4),
                         *(undefined4 *)(*(int *)(param_3 + 4) + uVar3 * 4));
      uVar3 = local_c;
      uVar4 = local_c;
      uVar1 = local_c;
      if (cVar2 != '\0') break;
      uVar5 = local_c;
      if (*(uint *)(param_3 + 8) <= local_c) {
        uVar5 = local_c - *(uint *)(param_3 + 8);
      }
      uVar6 = local_14;
      if (*(uint *)(param_3 + 8) <= local_14) {
        uVar6 = local_14 - *(uint *)(param_3 + 8);
      }
      cVar2 = (*param_2)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar6 * 4),
                         *(undefined4 *)(*(int *)(param_3 + 4) + uVar5 * 4));
      if ((cVar2 != '\0') ||
         (local_c = local_c + 1, uVar3 = local_c, uVar4 = local_c, uVar1 = local_c,
         param_6 <= local_c)) break;
    }
  }
joined_r0x0050b9d4:
  do {
    uVar5 = local_14;
    if (uVar3 < param_6) {
      uVar6 = uVar3;
      if (*(uint *)(param_3 + 8) <= uVar3) {
        uVar6 = uVar3 - *(uint *)(param_3 + 8);
      }
      uVar7 = uVar8;
      if (*(uint *)(param_3 + 8) <= uVar8) {
        uVar7 = uVar8 - *(uint *)(param_3 + 8);
      }
      cVar2 = (*param_2)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar7 * 4),
                         *(undefined4 *)(*(int *)(param_3 + 4) + uVar6 * 4));
      local_c = uVar1;
      if (cVar2 == '\0') {
        uVar6 = uVar8;
        if (*(uint *)(param_3 + 8) <= uVar8) {
          uVar6 = uVar8 - *(uint *)(param_3 + 8);
        }
        uVar7 = uVar3;
        if (*(uint *)(param_3 + 8) <= uVar3) {
          uVar7 = uVar3 - *(uint *)(param_3 + 8);
        }
        cVar2 = (*param_2)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar7 * 4),
                           *(undefined4 *)(*(int *)(param_3 + 4) + uVar6 * 4));
        if (cVar2 != '\0') goto joined_r0x0050ba6f;
        local_c = uVar1 + 1;
        FUN_0050bcc0(param_3,uVar1,param_3,uVar3);
      }
      uVar3 = uVar3 + 1;
      uVar4 = uVar3;
      uVar1 = local_c;
      goto joined_r0x0050b9d4;
    }
joined_r0x0050ba6f:
    while (local_14 = uVar5, uVar6 = uVar3, param_4 < local_14) {
      uVar3 = uVar8;
      if (*(uint *)(param_3 + 8) <= uVar8) {
        uVar3 = uVar8 - *(uint *)(param_3 + 8);
      }
      uVar5 = local_14 - 1;
      uVar6 = uVar5;
      if (*(uint *)(param_3 + 8) <= uVar5) {
        uVar6 = uVar5 - *(uint *)(param_3 + 8);
      }
      cVar2 = (*param_2)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar6 * 4),
                         *(undefined4 *)(*(int *)(param_3 + 4) + uVar3 * 4));
      uVar3 = uVar4;
      if (cVar2 == '\0') {
        uVar6 = uVar5;
        if (*(uint *)(param_3 + 8) <= uVar5) {
          uVar6 = uVar5 - *(uint *)(param_3 + 8);
        }
        uVar7 = uVar8;
        if (*(uint *)(param_3 + 8) <= uVar8) {
          uVar7 = uVar8 - *(uint *)(param_3 + 8);
        }
        cVar2 = (*param_2)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar7 * 4),
                           *(undefined4 *)(*(int *)(param_3 + 4) + uVar6 * 4));
        uVar6 = uVar4;
        if (cVar2 != '\0') break;
        uVar8 = uVar8 - 1;
        FUN_0050bcc0(param_3,uVar8,param_3,uVar5);
      }
    }
    if (local_14 == param_4) {
      if (uVar6 == param_6) {
        *param_1 = param_3;
        param_1[1] = uVar8;
        param_1[2] = param_3;
        param_1[3] = uVar1;
        return;
      }
      if (uVar1 != uVar6) {
        FUN_0050bcc0(param_3,uVar8,param_3,uVar1);
      }
      FUN_0050bcc0(param_3,uVar8,param_3,uVar6);
      uVar3 = uVar6 + 1;
      uVar4 = uVar6 + 1;
      uVar1 = uVar1 + 1;
      uVar8 = uVar8 + 1;
    }
    else {
      local_14 = local_14 - 1;
      if (uVar6 == param_6) {
        uVar8 = uVar8 - 1;
        if (local_14 != uVar8) {
          FUN_0050bcc0(param_3,local_14,param_3,uVar8);
        }
        FUN_0050bcc0(param_3,uVar8,param_3,uVar1 - 1);
        uVar3 = uVar6;
        uVar1 = uVar1 - 1;
      }
      else {
        FUN_0050bcc0(param_3,uVar6,param_3,local_14);
        uVar3 = uVar6 + 1;
        uVar4 = uVar6 + 1;
      }
    }
  } while( true );
}

