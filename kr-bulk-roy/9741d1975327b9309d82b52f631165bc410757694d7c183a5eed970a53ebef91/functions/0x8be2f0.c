
int FUN_008be2f0(int param_1,undefined4 param_2,int *param_3)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  size_t sVar4;
  bool bVar5;
  code *in_EAX;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *_Dst;
  size_t local_28;
  int local_24;
  code *local_20;
  size_t local_1c;
  size_t local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar3 = *(undefined4 *)(param_1 + 0x1c);
  iVar7 = 0;
  _Dst = (undefined1 *)0x0;
  local_8 = 0;
  if (in_EAX == (code *)0x0) {
LAB_008be30f:
    local_8 = 6;
  }
  else {
    local_18 = 0x400;
    _Dst = (undefined1 *)FUN_008bc7d0(uVar3,1,0,0x400,0,&local_8);
    if (local_8 == 0) {
      iVar6 = 0;
      local_14 = 1;
      *_Dst = 0;
      local_10 = 0;
      local_1c = 0;
      bVar5 = true;
      local_28 = 0;
      local_20 = in_EAX;
      do {
        local_24 = 0x100;
        local_c = iVar7;
LAB_008be370:
        sVar4 = local_1c;
        if (bVar5) {
          local_28 = FUN_008b98e0(param_1,_Dst + local_1c,local_18 - local_1c);
          iVar6 = local_28 + sVar4;
          local_1c = 0;
          bVar5 = false;
          local_10 = iVar6;
        }
        if (iVar6 <= iVar7) goto LAB_008be3da;
        pcVar1 = _Dst + iVar7;
        iVar8 = iVar7;
        if ((char)_Dst[iVar7] != local_24) goto LAB_008be3c0;
        iVar7 = iVar7 + 1;
      } while( true );
    }
  }
LAB_008be504:
  FUN_008b9f80(uVar3,_Dst);
  return local_8;
LAB_008be3c0:
  do {
    if ((_Dst[iVar8] == '\n') || (_Dst[iVar8] == '\r')) {
      if (iVar8 < iVar6) {
        cVar2 = _Dst[iVar8];
        _Dst[iVar8] = 0;
        if (((*pcVar1 != '#') && (*pcVar1 != '\x1a')) && (local_c < iVar8)) {
          iVar7 = iVar8 - local_c;
          local_8 = (*local_20)(pcVar1,iVar7,local_14,&local_20,param_2);
          if (local_8 == -1) {
            local_8 = (*local_20)(pcVar1,iVar7,local_14,&local_20,param_2);
          }
          if (local_8 != 0) goto LAB_008be4fc;
        }
        local_14 = local_14 + 1;
        _Dst[iVar8] = cVar2;
        iVar7 = iVar8 + 1;
        iVar6 = local_10;
        local_c = iVar7;
        if (cVar2 == '\n') {
          local_24 = 0xd;
        }
        else {
          local_24 = (-(uint)(cVar2 != '\r') & 0xf6) + 10;
        }
        goto LAB_008be370;
      }
      break;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < iVar6);
LAB_008be3da:
  if (local_28 == 0) {
LAB_008be4fc:
    *param_3 = local_14;
    goto LAB_008be504;
  }
  if (iVar7 == 0) {
    if (0xffff < local_18) goto LAB_008be30f;
    sVar4 = local_18 * 2;
    _Dst = (undefined1 *)FUN_008bc7d0(uVar3,1,local_18,sVar4,_Dst,&local_8);
    if (local_8 != 0) goto LAB_008be504;
    local_1c = local_18;
    bVar5 = true;
    iVar6 = local_10;
    local_18 = sVar4;
  }
  else {
    local_28 = iVar6 - iVar7;
    FID_conflict__memcpy(_Dst,_Dst + iVar7,local_28);
    local_10 = local_10 - local_28;
    local_c = 0;
    bVar5 = true;
    iVar6 = local_10;
    iVar7 = local_c;
    local_1c = local_28;
  }
  goto LAB_008be370;
}

