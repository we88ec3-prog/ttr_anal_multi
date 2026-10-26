
/* WARNING: Removing unreachable block (ram,0x006f97a4) */

void FUN_006f9630(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined *puVar2;
  int in_EAX;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  uint local_34;
  int local_30;
  
  iVar8 = *(int *)(in_EAX + 0x1c);
  bVar1 = *(byte *)(in_EAX + 7);
  puVar2 = *(undefined **)(in_EAX + 0x10);
  if (iVar8 < param_2) {
    FUN_006f9500();
  }
  FUN_006f9560(param_1);
  if (param_2 < iVar8) {
    *(int *)(in_EAX + 0x1c) = param_2;
    iVar7 = iVar8 - param_2;
    local_34 = param_2 + 1U;
    local_30 = param_2 << 4;
    do {
      puVar5 = (undefined4 *)(local_30 + *(int *)(in_EAX + 0xc));
      if (puVar5[2] != 0) {
        puVar3 = (undefined4 *)FUN_006f9b70(local_34);
        if (puVar3 == &DAT_00c0bfc8) {
          puVar3 = (undefined4 *)FUN_006f9a60(param_1);
        }
        *puVar3 = *puVar5;
        puVar3[1] = puVar5[1];
        puVar3[2] = puVar5[2];
      }
      local_30 = local_30 + 0x10;
      local_34 = local_34 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (param_2 + 1U < 0x10000000) {
      uVar4 = FUN_00700880(param_1,*(undefined4 *)(in_EAX + 0xc),iVar8 << 4,param_2 << 4);
    }
    else {
      FUN_006f8b60(param_1,"memory allocation error: block too big");
      uVar4 = 0;
    }
    *(undefined4 *)(in_EAX + 0xc) = uVar4;
  }
  iVar7 = 1 << (bVar1 & 0x1f);
  iVar8 = iVar7 + -1;
  if (-1 < iVar8) {
    puVar6 = puVar2 + iVar8 * 0x20 + 0x10;
    do {
      if (*(int *)(puVar6 + -8) != 0) {
        puVar5 = (undefined4 *)FUN_006f9c50();
        *(undefined1 *)(in_EAX + 6) = 0;
        if (puVar5 == &DAT_00c0bfc8) {
          if (*(int *)(puVar6 + 8) == 0) {
            FUN_006f8b60(param_1,"table index is nil");
          }
          puVar5 = (undefined4 *)FUN_006f9a60(param_1);
        }
        *puVar5 = *(undefined4 *)(puVar6 + -0x10);
        puVar5[1] = *(undefined4 *)(puVar6 + -0xc);
        puVar5[2] = *(undefined4 *)(puVar6 + -8);
      }
      puVar6 = puVar6 + -0x20;
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
  }
  if (puVar2 != &DAT_00c0bfa8) {
    FUN_00700880(param_1,puVar2,iVar7 << 5,0);
  }
  return;
}

