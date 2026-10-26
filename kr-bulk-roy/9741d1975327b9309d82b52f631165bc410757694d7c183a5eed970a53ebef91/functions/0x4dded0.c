
/* WARNING: Removing unreachable block (ram,0x004ddf03) */

undefined4 FUN_004dded0(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 < 2) {
    local_8 = 0;
  }
  else {
    local_8 = param_2 - 2 >> 2;
  }
  puVar1 = (uint *)(in_ECX + 0x5eb8);
  if (*puVar1 != *(uint *)(in_ECX + 0x5ebc)) {
    *(uint *)(in_ECX + 0x5ebc) = *puVar1;
  }
  if (local_8 != 0) {
    param_1 = (undefined4 *)((int)param_1 + 2);
    do {
      uVar2 = *param_1;
      local_1c = uVar2;
      iVar5 = FUN_0040f060();
      param_2 = 0;
      local_c = uVar2;
      FUN_008438c0(&local_c);
      if ((local_10 != *(int *)(iVar5 + 0x1c)) && (*(int *)(local_10 + 0x10) != 0)) {
        param_2 = *(undefined4 *)(*(int *)(local_10 + 0x10) + 4);
        FUN_0082ef00(&param_2);
        if (local_14 == *(int *)(iVar5 + 0xc)) {
          param_2 = 0;
        }
        else {
          param_2 = *(uint *)(local_14 + 0x10);
        }
      }
      puVar3 = *(undefined4 **)(in_ECX + 0x5ebc);
      local_18 = CONCAT22(local_18._2_2_,*(undefined2 *)(param_2 + 0x88));
      if ((&local_1c < puVar3) && ((undefined4 *)*puVar1 <= &local_1c)) {
        iVar5 = (int)&local_1c - (int)*puVar1 >> 3;
        if (puVar3 == *(undefined4 **)(in_ECX + 0x5ec0)) {
          FUN_00539180();
        }
        puVar3 = *(undefined4 **)(in_ECX + 0x5ebc);
        if (puVar3 != (undefined4 *)0x0) {
          uVar4 = *puVar1;
          *puVar3 = *(undefined4 *)(uVar4 + iVar5 * 8);
          puVar3[1] = *(undefined4 *)(uVar4 + 4 + iVar5 * 8);
        }
      }
      else {
        if (puVar3 == *(undefined4 **)(in_ECX + 0x5ec0)) {
          FUN_00539180();
        }
        puVar3 = *(undefined4 **)(in_ECX + 0x5ebc);
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = uVar2;
          puVar3[1] = local_18;
        }
      }
      *(int *)(in_ECX + 0x5ebc) = *(int *)(in_ECX + 0x5ebc) + 8;
      param_1 = param_1 + 1;
      local_8 = local_8 - 1;
    } while (local_8 != 0);
  }
  return 0;
}

