
int FUN_008ccd50(int *param_1,int param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int in_EAX;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  undefined4 *_Dst;
  byte *pbVar11;
  
  iVar7 = in_EAX;
  if (param_2 < in_EAX) {
    iVar7 = param_2;
    param_2 = in_EAX;
  }
  if (((iVar7 < param_2) && (-1 < iVar7)) && (param_2 < *param_1)) {
    iVar2 = param_1[2];
    uVar10 = *(uint *)(param_2 * 0x10 + iVar2);
    _Dst = (undefined4 *)(param_2 * 0x10 + iVar2);
    puVar1 = (uint *)(iVar2 + iVar7 * 0x10);
    uVar8 = *puVar1;
    if (uVar10 != 0) {
      if (uVar8 < uVar10) {
        iVar7 = FUN_008cca60(param_3);
        if (iVar7 != 0) {
          return iVar7;
        }
        for (; uVar8 < uVar10; uVar8 = uVar8 + 1) {
          FUN_008ccae0();
        }
      }
      pbVar9 = (byte *)_Dst[2];
      pbVar11 = (byte *)puVar1[2];
      for (uVar10 = uVar10 + 7 >> 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pbVar11 = *pbVar11 | *pbVar9;
        pbVar11 = pbVar11 + 1;
        pbVar9 = pbVar9 + 1;
      }
    }
    *_Dst = 0;
    _Dst[3] = 0;
    iVar7 = (*param_1 - param_2) + -1;
    if (0 < iVar7) {
      uVar3 = _Dst[1];
      uVar4 = _Dst[2];
      uVar5 = *_Dst;
      uVar6 = _Dst[3];
      FID_conflict__memcpy(_Dst,_Dst + 4,iVar7 * 0x10);
      _Dst[iVar7 * 4] = uVar5;
      _Dst[iVar7 * 4 + 1] = uVar3;
      _Dst[iVar7 * 4 + 2] = uVar4;
      _Dst[iVar7 * 4 + 3] = uVar6;
    }
    *param_1 = *param_1 + -1;
  }
  return 0;
}

