
/* WARNING: Removing unreachable block (ram,0x004bc072) */

undefined4 FUN_004bc050(int param_1,uint param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint local_14;
  uint local_10 [3];
  
  iVar6 = DAT_00fe1a88;
  if (*(int *)(DAT_00fe1a88 + 8) != *(int *)(DAT_00fe1a88 + 0xc)) {
    *(int *)(DAT_00fe1a88 + 0xc) = *(int *)(DAT_00fe1a88 + 8);
  }
  *(uint *)(iVar6 + 0x18) = (uint)*(byte *)(param_1 + 2);
  if (param_2 < 3) {
    local_14 = 0;
  }
  else {
    local_14 = param_2 - 3 >> 1;
  }
  if (local_14 != 0) {
    pbVar4 = (byte *)(param_1 + 3);
    do {
      uVar7 = (uint)*pbVar4;
      uVar5 = (uint)pbVar4[1];
      puVar1 = *(uint **)(iVar6 + 0xc);
      local_10[0] = uVar7;
      local_10[1] = uVar5;
      if (local_10 < puVar1) {
        if (local_10 < *(uint **)(iVar6 + 8)) goto LAB_004bc117;
        iVar8 = (int)local_10 - (int)*(uint **)(iVar6 + 8) >> 3;
        if (puVar1 == *(uint **)(iVar6 + 0x10)) {
          FUN_00539180();
        }
        puVar2 = *(undefined4 **)(iVar6 + 0xc);
        if (puVar2 != (undefined4 *)0x0) {
          iVar3 = *(int *)(iVar6 + 8);
          *puVar2 = *(undefined4 *)(iVar3 + iVar8 * 8);
          puVar2[1] = *(undefined4 *)(iVar3 + 4 + iVar8 * 8);
        }
      }
      else {
LAB_004bc117:
        if (puVar1 == *(uint **)(iVar6 + 0x10)) {
          FUN_00539180();
        }
        puVar1 = *(uint **)(iVar6 + 0xc);
        if (puVar1 != (uint *)0x0) {
          *puVar1 = uVar7;
          puVar1[1] = uVar5;
        }
      }
      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 8;
      pbVar4 = pbVar4 + 2;
      local_14 = local_14 - 1;
      iVar6 = DAT_00fe1a88;
    } while (local_14 != 0);
  }
  FUN_0058aad0(0xf424a);
  return 0;
}

