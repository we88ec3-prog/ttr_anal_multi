
void FUN_0070c5d0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_c;
  
  if (param_2 < param_3) {
    do {
      puVar1 = *(undefined4 **)(param_1 + 8);
      puVar2 = (undefined4 *)FUN_006f9b70(param_2);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      puVar1 = *(undefined4 **)(param_1 + 8);
      puVar2 = (undefined4 *)FUN_006f9b70(param_3);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      iVar3 = FUN_0070c4c0(0xfffffffe);
      if (iVar3 == 0) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x20;
      }
      else {
        FUN_006f5870(param_2);
        FUN_006f5870(param_3);
      }
      if (param_3 - param_2 == 1) {
        return;
      }
      puVar1 = *(undefined4 **)(param_1 + 8);
      iVar3 = (param_2 + param_3) / 2;
      puVar2 = (undefined4 *)FUN_006f9b70(iVar3);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      puVar1 = *(undefined4 **)(param_1 + 8);
      puVar2 = (undefined4 *)FUN_006f9b70(param_2);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      iVar4 = FUN_0070c4c0(0xffffffff);
      if (iVar4 == 0) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
        puVar1 = *(undefined4 **)(param_1 + 8);
        puVar2 = (undefined4 *)FUN_006f9b70(param_3);
        *puVar1 = *puVar2;
        puVar1[1] = puVar2[1];
        puVar1[2] = puVar2[2];
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        iVar4 = FUN_0070c4c0(0xfffffffe);
        if (iVar4 == 0) {
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x20;
        }
        else {
          FUN_006f5870(iVar3);
          FUN_006f5870(param_3);
        }
      }
      else {
        FUN_006f5870(iVar3);
        FUN_006f5870(param_2);
      }
      if (param_3 - param_2 == 2) {
        return;
      }
      puVar1 = *(undefined4 **)(param_1 + 8);
      puVar2 = (undefined4 *)FUN_006f9b70(iVar3);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      puVar1 = *(undefined4 **)(param_1 + 8);
      *puVar1 = puVar1[-4];
      puVar1[1] = puVar1[-3];
      puVar1[2] = puVar1[-2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      puVar1 = *(undefined4 **)(param_1 + 8);
      local_c = param_3 + -1;
      puVar2 = (undefined4 *)FUN_006f9b70(local_c);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      FUN_006f5870(iVar3);
      FUN_006f5870(local_c);
      local_10 = param_2;
      while( true ) {
        while( true ) {
          puVar1 = *(undefined4 **)(param_1 + 8);
          iVar3 = local_10 + 1;
          puVar2 = (undefined4 *)FUN_006f9b70(iVar3);
          *puVar1 = *puVar2;
          puVar1[1] = puVar2[1];
          puVar1[2] = puVar2[2];
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
          iVar4 = FUN_0070c4c0(0xfffffffe);
          if (iVar4 == 0) break;
          if (param_3 < iVar3) {
            FUN_006f5f30(param_1,"invalid order function for sorting");
          }
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
          local_10 = iVar3;
        }
        while( true ) {
          puVar1 = *(undefined4 **)(param_1 + 8);
          local_c = local_c + -1;
          puVar2 = (undefined4 *)FUN_006f9b70(local_c);
          *puVar1 = *puVar2;
          puVar1[1] = puVar2[1];
          puVar1[2] = puVar2[2];
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
          iVar4 = FUN_0070c4c0(0xffffffff);
          if (iVar4 == 0) break;
          if (local_c < param_2) {
            FUN_006f5f30(param_1,"invalid order function for sorting");
          }
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
        }
        if (local_c < iVar3) break;
        FUN_006f5870(iVar3);
        FUN_006f5870(local_c);
        local_10 = iVar3;
      }
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x30;
      puVar2 = (undefined4 *)FUN_006f9b70(param_3 + -1);
      puVar1 = *(undefined4 **)(param_1 + 8);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      puVar2 = (undefined4 *)FUN_006f9b70(iVar3);
      puVar1 = *(undefined4 **)(param_1 + 8);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      FUN_006f5870(param_3 + -1);
      FUN_006f5870(iVar3);
      if (iVar3 - param_2 < param_3 - iVar3) {
        iVar3 = param_2;
        param_2 = local_10 + 2;
      }
      else {
        iVar3 = local_10 + 2;
        iVar4 = local_10;
        local_10 = param_3;
        param_3 = iVar4;
      }
      FUN_0070c5d0(param_1,iVar3,local_10);
    } while (param_2 < param_3);
  }
  return;
}

