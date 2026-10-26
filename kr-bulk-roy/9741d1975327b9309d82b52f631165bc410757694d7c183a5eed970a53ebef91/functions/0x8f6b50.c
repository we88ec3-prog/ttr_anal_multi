
void FUN_008f6b50(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  int in_EAX;
  int in_EDX;
  int iVar5;
  short *psVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  short *psVar10;
  int *local_24;
  uint local_20;
  int local_18;
  int local_10;
  int local_8;
  
  piVar1 = (int *)(in_EAX * 0x42c + 0x2c + in_EDX);
  iVar3 = *piVar1;
  iVar2 = param_1 + 0x2c + in_EAX * 0x1c;
  psVar10 = *(short **)(iVar2 + 0x14);
  psVar6 = psVar10 + *(int *)(iVar2 + 0xc) * 0x18;
  lVar4 = (longlong)(int)(*(uint *)(in_EDX + 0x28) / 0x28) * (longlong)iVar3;
  lVar4 = lVar4 + (ulonglong)((int)(lVar4 >> 0x3f) + 0x8000);
  local_8 = ((uint)lVar4 >> 0x10) + (int)((ulonglong)lVar4 >> 0x20) * 0x10000;
  if (0x20 < local_8) {
    local_8 = 0x20;
  }
  for (; psVar10 < psVar6; psVar10 = psVar10 + 0x18) {
    local_24 = (int *)0x0;
    local_18 = local_8;
    local_20 = 0;
    if (piVar1[0x36] != 0) {
      piVar7 = piVar1 + 0x3a;
      do {
        if (((*(byte *)(piVar7 + 3) & 1) != 0) &&
           (((int)*(char *)((int)psVar10 + 0xd) == *(int *)(iVar2 + 0x18)) !=
            (bool)(*(byte *)(piVar7 + 3) & 2))) {
          local_10 = (int)*psVar10;
          iVar5 = local_10 - piVar7[-3];
          if (iVar5 < 0) {
            iVar5 = piVar7[-3] - local_10;
          }
          iVar8 = local_10 - *piVar7;
          if (iVar8 < 0) {
            iVar8 = *piVar7 - local_10;
          }
          piVar9 = piVar7;
          if (iVar5 <= iVar8) {
            piVar9 = piVar7 + -3;
          }
          local_10 = local_10 - *piVar9;
          if (local_10 < 0) {
            local_10 = -local_10;
          }
          lVar4 = (longlong)local_10 * (longlong)iVar3;
          lVar4 = lVar4 + (ulonglong)((int)(lVar4 >> 0x3f) + 0x8000);
          iVar5 = ((uint)lVar4 >> 0x10) + (int)((ulonglong)lVar4 >> 0x20) * 0x10000;
          if (iVar5 < local_18) {
            local_24 = piVar9;
            local_18 = iVar5;
          }
        }
        local_20 = local_20 + 1;
        piVar7 = piVar7 + 7;
      } while (local_20 < (uint)piVar1[0x36]);
      if (local_24 != (int *)0x0) {
        *(int **)(psVar10 + 10) = local_24;
      }
    }
  }
  return;
}

