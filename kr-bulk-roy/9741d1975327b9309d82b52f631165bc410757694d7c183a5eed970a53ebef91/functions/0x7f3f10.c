
undefined4 * FUN_007f3f10(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_74 [26];
  uint local_c;
  undefined4 *local_8;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    local_8 = (undefined4 *)FUN_00891268(0x80);
    if (local_8 == (undefined4 *)0x0) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      local_8[0x1a] = 1;
      local_8[0x1b] = 1;
      local_8[0x1c] = 1;
      local_8[0x1d] = 1;
      _memset(local_74,0,0x68);
      puVar2 = local_74;
      puVar4 = local_8;
      for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar4 = puVar4 + 1;
      }
      local_8[0x1e] = 1;
      local_8[0x1f] = 0;
    }
    puVar2 = local_8;
    *local_8 = param_2;
    param_2 = local_8;
    FUN_007bb350();
    local_c = 0;
    if (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2 != 0) {
      do {
        puVar2 = (undefined4 *)FUN_00891268(0x80);
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          puVar2[0x1a] = 1;
          puVar2[0x1b] = 1;
          puVar2[0x1c] = 1;
          puVar2[0x1d] = 1;
          _memset(local_74,0,0x68);
          puVar4 = local_74;
          puVar5 = puVar2;
          for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          puVar2[0x1e] = 1;
          puVar2[0x1f] = 0;
        }
        uVar1 = local_c;
        puVar4 = local_8;
        puVar5 = puVar2;
        for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        puVar2[0x1f] = local_8[0x1f];
        puVar2[0x1e] = local_8[0x1e];
        iVar3 = *(int *)(*(int *)(param_1 + 0x14) + local_c * 4);
        puVar4 = *(undefined4 **)(iVar3 + 0x28);
        param_2 = puVar2;
        if ((&param_2 < puVar4) && (puVar5 = *(undefined4 **)(iVar3 + 0x24), puVar5 <= &param_2)) {
          if (puVar4 == *(undefined4 **)(iVar3 + 0x2c)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(iVar3 + 0x28) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar3 + 0x28) =
                 *(undefined4 *)(*(int *)(iVar3 + 0x24) + ((int)&param_2 - (int)puVar5 >> 2) * 4);
          }
        }
        else {
          if (puVar4 == *(undefined4 **)(iVar3 + 0x2c)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(iVar3 + 0x28) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar3 + 0x28) = puVar2;
          }
        }
        *(int *)(iVar3 + 0x28) = *(int *)(iVar3 + 0x28) + 4;
        local_c = uVar1 + 1;
        puVar2 = local_8;
      } while (local_c < (uint)(*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2));
    }
    return puVar2;
  }
  return (undefined4 *)0x0;
}

