
void FUN_00837be0(undefined4 *param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  void *_Dst;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  size_t _Size;
  int iVar10;
  bool bVar11;
  int local_8;
  
  iVar1 = param_2;
  if (param_1[2] != 0) {
    FUN_00891d3d(param_1[2]);
    param_1[2] = 0;
  }
  iVar3 = *(int *)(iVar1 + 0x14);
  local_8 = 0;
  if (iVar3 != 0) {
    local_8 = iVar3;
  }
  param_2 = 0;
  iVar3 = FUN_008334a0(&param_2);
  if (iVar3 == 0) {
    iVar3 = in_EAX[2];
    iVar10 = *in_EAX;
    iVar9 = in_EAX[3];
    iVar4 = in_EAX[1];
    iVar1 = **(int **)(iVar1 + 0x18);
    param_1[3] = iVar3 - iVar10;
    lVar2 = (ulonglong)(uint)((iVar9 - iVar4) * (iVar3 - iVar10)) * 4;
    iVar3 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    param_2 = in_EAX[1];
    uVar6 = 0;
    if (param_2 < in_EAX[3]) {
      iVar10 = in_EAX[2];
      iVar9 = param_2 * iVar1;
      do {
        iVar4 = *in_EAX;
        if (iVar4 < iVar10) {
          puVar8 = (undefined4 *)(local_8 + (iVar9 + iVar4) * 4);
          do {
            *(undefined4 *)(iVar3 + uVar6 * 4) = *puVar8;
            iVar10 = in_EAX[2];
            iVar4 = iVar4 + 1;
            uVar6 = uVar6 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar4 < iVar10);
        }
        iVar9 = iVar9 + iVar1;
        param_2 = param_2 + 1;
      } while (param_2 < in_EAX[3]);
    }
    param_1[1] = uVar6;
    _Size = (int)(((int)uVar6 >> 0x1f & 7U) + uVar6) >> 3;
    uVar6 = uVar6 & 0x80000007;
    bVar11 = uVar6 == 0;
    if ((int)uVar6 < 0) {
      bVar11 = (uVar6 - 1 | 0xfffffff8) == 0xffffffff;
    }
    if (!bVar11) {
      _Size = _Size + 1;
    }
    _Dst = (void *)FUN_0087dc3d(_Size);
    param_1[2] = _Dst;
    _memset(_Dst,0,_Size);
    uVar6 = 0;
    if (0 < (int)param_1[1]) {
      do {
        if (*(int *)(iVar3 + uVar6 * 4) != 0) {
          pbVar5 = (byte *)(((int)(uVar6 + ((int)uVar6 >> 0x1f & 7U)) >> 3) + param_1[2]);
          uVar7 = uVar6 & 0x80000007;
          if ((int)uVar7 < 0) {
            uVar7 = (uVar7 - 1 | 0xfffffff8) + 1;
          }
          *pbVar5 = *pbVar5 | '\x01' << ((byte)uVar7 & 0x1f);
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < (int)param_1[1]);
    }
    FUN_00891d3d(iVar3);
    return;
  }
  param_1[1] = param_2;
  *param_1 = 1;
  return;
}

