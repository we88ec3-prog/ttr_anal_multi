
undefined4 FUN_007403e0(int param_1)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint *puVar6;
  byte *pbVar7;
  int local_14;
  uint *local_8;
  
  pbVar7 = *(byte **)(param_1 + 0x14);
  if ((pbVar7 != (byte *)0x0) && (local_8 = (uint *)*in_EAX, local_8 != (uint *)0x0)) {
    local_14 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      iVar1 = in_EAX[3];
      iVar2 = *(int *)(param_1 + 0xc);
      do {
        uVar4 = 0;
        if (*(char *)(param_1 + 0x1a) == '\x01') {
          pbVar5 = pbVar7;
          puVar6 = local_8;
          if (0 < iVar2) {
            do {
              uVar3 = (uint)((*pbVar5 & (byte)(0x80 >> (sbyte)(uVar4 & 7))) != 0);
              pbVar5 = pbVar5 + ((int)((uVar4 & 7) + 1) >> 3);
              uVar4 = uVar4 + 1;
              uVar3 = uVar3 | uVar3 * 2;
              uVar3 = uVar3 | uVar3 * 4;
              uVar3 = uVar3 | uVar3 << 4;
              uVar3 = uVar3 | uVar3 << 8;
              *puVar6 = (uVar3 | 0xffffff00) << 0x10 | uVar3;
              iVar2 = *(int *)(param_1 + 0xc);
              puVar6 = puVar6 + 1;
            } while ((int)uVar4 < iVar2);
          }
        }
        else {
          pbVar5 = pbVar7;
          puVar6 = local_8;
          if (0 < iVar2) {
            do {
              uVar3 = (uint)CONCAT11(*pbVar5,*pbVar5);
              *puVar6 = (uVar3 | 0xffffff00) << 0x10 | uVar3;
              iVar2 = *(int *)(param_1 + 0xc);
              uVar4 = uVar4 + 1;
              pbVar5 = pbVar5 + 1;
              puVar6 = puVar6 + 1;
            } while ((int)uVar4 < iVar2);
          }
        }
        pbVar7 = pbVar7 + *(int *)(param_1 + 0x10);
        local_8 = local_8 + (iVar1 >> 2);
        local_14 = local_14 + 1;
      } while (local_14 < *(int *)(param_1 + 8));
    }
    return 1;
  }
  return 0;
}

