
int FUN_008f4160(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  short *psVar1;
  short *_Dst;
  undefined4 uVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  int local_8;
  
  iVar3 = *(int *)(param_1 + 0x10);
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) < iVar3) {
LAB_008f41cc:
    psVar1 = *(short **)(param_1 + 0x14);
    psVar4 = psVar1 + *(int *)(param_1 + 0xc) * 0x18;
    _Dst = psVar4;
    while (psVar1 < _Dst) {
      psVar4 = psVar4 + -0x18;
      if ((*psVar4 < param_2) || ((*psVar4 == param_2 && (param_3 == *(int *)(param_1 + 0x18)))))
      break;
      psVar5 = _Dst + -0x18;
      psVar6 = psVar4;
      psVar8 = _Dst;
      for (iVar3 = 0xc; _Dst = psVar5, iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined4 *)psVar8 = *(undefined4 *)psVar6;
        psVar6 = psVar6 + 2;
        psVar8 = psVar8 + 2;
      }
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    _memset(_Dst,0,0x30);
    *_Dst = (short)param_2;
    *(undefined1 *)((int)_Dst + 0xd) = (undefined1)param_3;
    *param_5 = _Dst;
    return local_8;
  }
  if (iVar3 < 0x2aaaaaa) {
    iVar7 = (iVar3 >> 2) + 4 + iVar3;
    if ((iVar7 < iVar3) || (0x2aaaaaa < iVar7)) {
      iVar7 = 0x2aaaaaa;
    }
    uVar2 = FUN_008bc7d0(param_4,0x30,iVar3,iVar7,*(undefined4 *)(param_1 + 0x14),&local_8);
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    if (local_8 == 0) {
      *(int *)(param_1 + 0x10) = iVar7;
      goto LAB_008f41cc;
    }
  }
  else {
    local_8 = 0x40;
  }
  *param_5 = 0;
  return local_8;
}

