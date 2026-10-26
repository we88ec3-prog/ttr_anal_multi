
undefined4 FUN_004c21f0(int param_1,uint param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint local_c [2];
  
  *(uint *)(DAT_00fe1a88 + 0x18) = (uint)*(byte *)(param_1 + 2);
  if (param_2 < 3) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 - 3 >> 1;
  }
  if (param_2 != 0) {
    pbVar5 = (byte *)(param_1 + 3);
    do {
      iVar4 = DAT_00fe1a88;
      uVar7 = (uint)*pbVar5;
      uVar6 = (uint)pbVar5[1];
      puVar1 = *(uint **)(DAT_00fe1a88 + 0xc);
      local_c[0] = uVar7;
      local_c[1] = uVar6;
      if (local_c < puVar1) {
        if (local_c < *(uint **)(DAT_00fe1a88 + 8)) goto LAB_004c2283;
        iVar8 = (int)local_c - (int)*(uint **)(DAT_00fe1a88 + 8) >> 3;
        if (puVar1 == *(uint **)(DAT_00fe1a88 + 0x10)) {
          FUN_00539180();
        }
        puVar2 = *(undefined4 **)(iVar4 + 0xc);
        if (puVar2 != (undefined4 *)0x0) {
          iVar3 = *(int *)(iVar4 + 8);
          *puVar2 = *(undefined4 *)(iVar3 + iVar8 * 8);
          puVar2[1] = *(undefined4 *)(iVar3 + 4 + iVar8 * 8);
        }
      }
      else {
LAB_004c2283:
        if (puVar1 == *(uint **)(DAT_00fe1a88 + 0x10)) {
          FUN_00539180();
        }
        puVar1 = *(uint **)(iVar4 + 0xc);
        if (puVar1 != (uint *)0x0) {
          *puVar1 = uVar7;
          puVar1[1] = uVar6;
        }
      }
      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 8;
      pbVar5 = pbVar5 + 2;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return 0;
}

