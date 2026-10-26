
void FUN_0050bee0(code *param_1,int param_2,uint param_3,undefined4 param_4,uint param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined2 local_24;
  undefined1 local_22;
  uint local_14;
  int local_10;
  
  if (param_3 != param_5) {
    uVar5 = param_3;
    while (uVar6 = uVar5 + 1, uVar6 != param_5) {
      local_10 = param_2;
      uVar4 = uVar6;
      if (*(uint *)(param_2 + 8) <= uVar6) {
        uVar4 = uVar6 - *(uint *)(param_2 + 8);
      }
      puVar1 = *(undefined4 **)(*(int *)(param_2 + 4) + uVar4 * 4);
      local_34 = *puVar1;
      local_30 = puVar1[1];
      local_2c = puVar1[2];
      local_28 = puVar1[3];
      local_24 = *(undefined2 *)(puVar1 + 4);
      local_22 = *(undefined1 *)((int)puVar1 + 0x12);
      uVar4 = param_3;
      if (*(uint *)(param_2 + 8) <= param_3) {
        uVar4 = param_3 - *(uint *)(param_2 + 8);
      }
      local_14 = uVar6;
      cVar3 = (*param_1)(&local_34,*(undefined4 *)(*(int *)(param_2 + 4) + uVar4 * 4));
      if (cVar3 == '\0') {
        while( true ) {
          uVar4 = uVar6 - 1;
          uVar5 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            uVar5 = uVar4 - *(uint *)(param_2 + 8);
          }
          cVar3 = (*param_1)(&local_34,*(undefined4 *)(*(int *)(param_2 + 4) + uVar5 * 4));
          if (cVar3 == '\0') break;
          uVar5 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            uVar5 = uVar4 - *(uint *)(param_2 + 8);
          }
          if (*(uint *)(local_10 + 8) <= uVar6) {
            uVar6 = uVar6 - *(uint *)(local_10 + 8);
          }
          puVar1 = *(undefined4 **)(*(int *)(param_2 + 4) + uVar5 * 4);
          puVar2 = *(undefined4 **)(*(int *)(local_10 + 4) + uVar6 * 4);
          *puVar2 = *puVar1;
          puVar2[1] = puVar1[1];
          puVar2[2] = puVar1[2];
          puVar2[3] = puVar1[3];
          *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(puVar1 + 4);
          *(undefined1 *)((int)puVar2 + 0x12) = *(undefined1 *)((int)puVar1 + 0x12);
          uVar6 = uVar4;
          local_10 = param_2;
        }
        if (*(uint *)(local_10 + 8) <= uVar6) {
          uVar6 = uVar6 - *(uint *)(local_10 + 8);
        }
        puVar1 = *(undefined4 **)(*(int *)(local_10 + 4) + uVar6 * 4);
        *puVar1 = local_34;
        puVar1[1] = local_30;
        puVar1[2] = local_2c;
        puVar1[3] = local_28;
        *(undefined2 *)(puVar1 + 4) = local_24;
        *(undefined1 *)((int)puVar1 + 0x12) = local_22;
        uVar5 = local_14;
      }
      else {
        FUN_0050c3e0(param_2,param_3,param_2,uVar6,local_10,uVar5 + 2,param_3);
        uVar5 = param_3;
        if (*(uint *)(param_2 + 8) <= param_3) {
          uVar5 = param_3 - *(uint *)(param_2 + 8);
        }
        puVar1 = *(undefined4 **)(*(int *)(param_2 + 4) + uVar5 * 4);
        *puVar1 = local_34;
        puVar1[1] = local_30;
        puVar1[2] = local_2c;
        puVar1[3] = local_28;
        *(undefined2 *)(puVar1 + 4) = local_24;
        *(undefined1 *)((int)puVar1 + 0x12) = local_22;
        uVar5 = uVar6;
      }
    }
  }
  return;
}

