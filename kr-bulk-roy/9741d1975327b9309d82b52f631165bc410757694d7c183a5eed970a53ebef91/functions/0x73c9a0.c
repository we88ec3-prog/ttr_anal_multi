
undefined4 FUN_0073c9a0(int param_1,short *param_2,undefined4 param_3,int param_4,int *param_5)

{
  short sVar1;
  longlong lVar2;
  int iVar3;
  void *_Dst;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int local_18;
  int aiStack_14 [2];
  int iStack_c;
  
  psVar4 = param_2;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  iVar3 = (int)psVar4 - (int)(param_2 + 1) >> 1;
  lVar2 = (ulonglong)(iVar3 + 1) * 4;
  _Dst = (void *)FUN_0087dc3d(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  _memset(_Dst,0,iVar3 * 4 + 4);
  iVar3 = local_18;
  psVar4 = param_2;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  iStack_c = (int)psVar4 - (int)(param_2 + 1) >> 1;
  iVar9 = local_18 + 0xc;
  local_18 = param_1;
  FUN_008438c0(&local_18);
  if ((aiStack_14[0] != *(int *)(iVar3 + 0x3c)) && (*(int *)(aiStack_14[0] + 0x10) != 0)) {
    FUN_0073da10(iVar9,*(int *)(aiStack_14[0] + 0x10),param_2,iStack_c,(int)_Dst + 4,aiStack_14);
  }
  iVar3 = 1;
  if (1 < iStack_c) {
    do {
      if (param_4 <= *(int *)((int)_Dst + iVar3 * 4)) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iStack_c);
  }
  uVar5 = *(int *)((int)_Dst + iVar3 * 4) - param_4;
  uVar7 = (int)uVar5 >> 0x1f;
  uVar6 = *(int *)((int)_Dst + (iVar3 + -1) * 4) - param_4;
  uVar8 = (int)uVar6 >> 0x1f;
  iVar9 = iVar3 + -1;
  if ((int)((uVar5 ^ uVar7) - uVar7) <= (int)((uVar6 ^ uVar8) - uVar8)) {
    iVar9 = iVar3;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = iVar9;
  }
  FUN_00891d3d(_Dst);
  return 1;
}

