
int FUN_006fdec0(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  double *pdVar5;
  undefined4 *puVar6;
  int local_30;
  int local_28;
  undefined4 *local_20;
  double local_18;
  undefined4 local_10;
  
  uVar4 = (uint)*(byte *)(in_EAX + 0x49);
  local_20 = (undefined4 *)0x0;
  if (param_2 < (int)uVar4) {
    iVar3 = uVar4 - param_2;
    param_2 = param_2 + iVar3;
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if ((*(byte *)(in_EAX + 0x4a) & 4) != 0) {
    iVar3 = param_2 - uVar4;
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    local_20 = (undefined4 *)FUN_00700880(param_1,0,0,0x20);
    iVar1 = *(int *)(param_1 + 0x10);
    *local_20 = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 **)(iVar1 + 0x1c) = local_20;
    *(byte *)((int)local_20 + 5) = *(byte *)(iVar1 + 0x14) & 3;
    local_20[2] = 0;
    local_20[3] = 0;
    local_20[7] = 0;
    *(undefined1 *)(local_20 + 1) = 5;
    *(undefined2 *)((int)local_20 + 6) = 0xff;
    local_20[4] = &DAT_00c0bfa8;
    FUN_006f9500();
    FUN_006f9560(param_1);
    if (0 < iVar3) {
      iVar1 = iVar3 * -0x10;
      local_30 = 1;
      local_28 = iVar3;
      do {
        puVar6 = (undefined4 *)(*(int *)(param_1 + 8) + iVar1);
        puVar2 = (undefined4 *)FUN_006f9b70(local_30);
        if (puVar2 == &DAT_00c0bfc8) {
          local_18 = (double)local_30;
          local_10 = 3;
          puVar2 = (undefined4 *)FUN_006f9a60(param_1,local_20,&local_18);
        }
        iVar1 = iVar1 + 0x10;
        *puVar2 = *puVar6;
        puVar2[1] = puVar6[1];
        puVar2[2] = puVar6[2];
        local_30 = local_30 + 1;
        local_28 = local_28 + -1;
      } while (local_28 != 0);
    }
    iVar1 = FUN_006fec70(param_1,&DAT_00c4271c,1);
    for (pdVar5 = (double *)
                  (((1 << (*(byte *)((int)local_20 + 7) & 0x1f)) - 1U & *(uint *)(iVar1 + 8)) * 0x20
                  + local_20[4]); pdVar5 != (double *)0x0; pdVar5 = *(double **)((int)pdVar5 + 0x1c)
        ) {
      if ((*(int *)(pdVar5 + 3) == 4) && (*(int *)(pdVar5 + 2) == iVar1)) {
        if (pdVar5 != (double *)&DAT_00c0bfc8) goto LAB_006fe057;
        break;
      }
    }
    local_18 = (double)CONCAT44(local_18._4_4_,iVar1);
    local_10 = 4;
    pdVar5 = (double *)FUN_006f9a60(param_1,local_20,&local_18);
LAB_006fe057:
    *(undefined4 *)(pdVar5 + 1) = 3;
    *pdVar5 = (double)iVar3;
  }
  iVar3 = *(int *)(param_1 + 8);
  if (uVar4 != 0) {
    puVar2 = (undefined4 *)(iVar3 + param_2 * -0x10 + 8);
    do {
      puVar6 = *(undefined4 **)(param_1 + 8);
      *(undefined4 **)(param_1 + 8) = puVar6 + 4;
      *puVar6 = puVar2[-2];
      puVar6[1] = puVar2[-1];
      puVar6[2] = *puVar2;
      *puVar2 = 0;
      puVar2 = puVar2 + 4;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (local_20 != (undefined4 *)0x0) {
    puVar2 = *(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = puVar2 + 4;
    *puVar2 = local_20;
    puVar2[2] = 5;
  }
  return iVar3;
}

