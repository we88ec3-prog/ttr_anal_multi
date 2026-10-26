
void FUN_008f58b0(int param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  int *piVar7;
  uint local_28;
  int *local_18;
  int local_10;
  int local_c;
  
  psVar5 = *(short **)(param_1 + 0x5c);
  iVar1 = *(int *)(param_2 + 0x458);
  psVar6 = psVar5 + *(int *)(param_1 + 0x54) * 0x18;
  for (; psVar5 < psVar6; psVar5 = psVar5 + 0x18) {
    local_18 = (int *)0x0;
    lVar2 = (longlong)(int)(*(uint *)(param_2 + 0x28) / 0x28) * (longlong)iVar1;
    lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
    local_10 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
    if (0x20 < local_10) {
      local_10 = 0x20;
    }
    local_28 = 0;
    if (*(int *)(param_2 + 0x530) != 0) {
      piVar7 = (int *)(param_2 + 0x540);
      do {
        if (((piVar7[3] & 1U) != 0) &&
           (bVar3 = (bool)((byte)((uint)piVar7[3] >> 1) & 1),
           ((int)*(char *)((int)psVar5 + 0xd) == *(int *)(param_1 + 0x60)) != bVar3)) {
          local_c = (int)*psVar5 - piVar7[-3];
          if (local_c < 0) {
            local_c = -local_c;
          }
          lVar2 = (longlong)local_c * (longlong)iVar1 +
                  (ulonglong)((int)((longlong)local_c * (longlong)iVar1 >> 0x3f) + 0x8000);
          iVar4 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
          if (iVar4 < local_10) {
            local_18 = piVar7 + -3;
            local_10 = iVar4;
          }
          if ((((*(byte *)(psVar5 + 6) & 1) != 0) && (iVar4 != 0)) &&
             ((int)*psVar5 < piVar7[-3] != bVar3)) {
            local_c = (int)*psVar5 - *piVar7;
            if (local_c < 0) {
              local_c = -local_c;
            }
            lVar2 = (longlong)local_c * (longlong)iVar1 +
                    (ulonglong)((int)((longlong)local_c * (longlong)iVar1 >> 0x3f) + 0x8000);
            iVar4 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
            if (iVar4 < local_10) {
              local_18 = piVar7;
              local_10 = iVar4;
            }
          }
        }
        local_28 = local_28 + 1;
        piVar7 = piVar7 + 7;
      } while (local_28 < *(uint *)(param_2 + 0x530));
      if (local_18 != (int *)0x0) {
        *(int **)(psVar5 + 10) = local_18;
      }
    }
  }
  return;
}

