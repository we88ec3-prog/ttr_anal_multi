
/* Library Function - Single Match
    __Gettnames_l
   
   Library: Visual Studio 2010 Release */

void * __Gettnames_l(localeinfo_struct *param_1)

{
  void *_Src;
  undefined4 *puVar1;
  uint uVar2;
  size_t sVar3;
  size_t sVar4;
  size_t sVar5;
  size_t sVar6;
  void *_Dst;
  errno_t eVar7;
  int iVar8;
  char *pcVar9;
  int local_28 [2];
  int local_20;
  char local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  size_t local_c;
  uint local_8;
  
  iVar8 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_28,param_1);
  _Src = *(void **)(local_28[0] + 0xd4);
  local_8 = 0;
  do {
    uVar2 = local_8;
    local_18 = (undefined4 *)_strlen(*(char **)((int)_Src + local_8 * 4 + 0x1c));
    sVar3 = _strlen(*(char **)((int)_Src + uVar2 * 4));
    local_8 = local_8 + 1;
    iVar8 = sVar3 + iVar8 + 2 + (int)local_18;
  } while (local_8 < 7);
  local_14 = (undefined4 *)((int)_Src + 0x38);
  local_18 = (undefined4 *)0xc;
  do {
    puVar1 = local_14;
    local_10 = (undefined4 *)_strlen((char *)local_14[0xc]);
    sVar3 = _strlen((char *)*puVar1);
    local_14 = local_14 + 1;
    local_18 = (undefined4 *)((int)local_18 + -1);
    iVar8 = sVar3 + iVar8 + 2 + (int)local_10;
  } while (local_18 != (undefined4 *)0x0);
  sVar3 = _strlen(*(char **)((int)_Src + 0x9c));
  sVar4 = _strlen(*(char **)((int)_Src + 0x98));
  sVar5 = _strlen(*(char **)((int)_Src + 0xa0));
  sVar6 = _strlen(*(char **)((int)_Src + 0xa4));
  local_c = _strlen(*(char **)((int)_Src + 0xa8));
  local_c = sVar4 + iVar8 + sVar3 + sVar5 + sVar6 + 0x169 + local_c;
  _Dst = __malloc_crt(local_c);
  if (_Dst != (void *)0x0) {
    pcVar9 = (char *)((int)_Dst + 0x164);
    FID_conflict__memcpy(_Dst,_Src,0x164);
    local_8 = 0;
    local_10 = (undefined4 *)((int)_Src + 0x1c);
    local_14 = (undefined4 *)((int)_Dst - (int)_Src);
    do {
      *(char **)((int)_Dst + local_8 * 4) = pcVar9;
      eVar7 = _strcpy_s(pcVar9,(int)_Dst + (local_c - (int)pcVar9),(char *)local_10[-7]);
      if (eVar7 != 0) goto LAB_0089a941;
      sVar3 = _strlen(pcVar9);
      pcVar9 = pcVar9 + sVar3 + 1;
      *(char **)((int)local_14 + (int)local_10) = pcVar9;
      eVar7 = _strcpy_s(pcVar9,(int)_Dst + (local_c - (int)pcVar9),(char *)*local_10);
      if (eVar7 != 0) goto LAB_0089a941;
      sVar3 = _strlen(pcVar9);
      local_8 = local_8 + 1;
      local_10 = local_10 + 1;
      pcVar9 = pcVar9 + sVar3 + 1;
    } while (local_8 < 7);
    local_8 = 0;
    local_18 = (undefined4 *)((int)_Dst + 0x68);
    local_10 = (undefined4 *)((int)_Src + 0x38);
    do {
      *(char **)((int)local_10 + (int)local_14) = pcVar9;
      eVar7 = _strcpy_s(pcVar9,(int)_Dst + (local_c - (int)pcVar9),(char *)*local_10);
      if (eVar7 != 0) goto LAB_0089a941;
      sVar3 = _strlen(pcVar9);
      pcVar9 = pcVar9 + sVar3 + 1;
      *local_18 = pcVar9;
      eVar7 = _strcpy_s(pcVar9,(int)_Dst + (local_c - (int)pcVar9),(char *)local_10[0xc]);
      if (eVar7 != 0) goto LAB_0089a941;
      sVar3 = _strlen(pcVar9);
      local_8 = local_8 + 1;
      local_10 = local_10 + 1;
      local_18 = local_18 + 1;
      pcVar9 = pcVar9 + sVar3 + 1;
    } while (local_8 < 0xc);
    *(char **)((int)_Dst + 0x98) = pcVar9;
    eVar7 = _strcpy_s(pcVar9,(int)_Dst + (local_c - (int)pcVar9),*(char **)((int)_Src + 0x98));
    if (eVar7 == 0) {
      sVar3 = _strlen(pcVar9);
      pcVar9 = pcVar9 + sVar3 + 1;
      *(char **)((int)_Dst + 0x9c) = pcVar9;
      eVar7 = _strcpy_s(pcVar9,(int)_Dst + (local_c - (int)pcVar9),*(char **)((int)_Src + 0x9c));
      if (eVar7 == 0) {
        sVar3 = _strlen(pcVar9);
        pcVar9 = pcVar9 + sVar3 + 1;
        *(char **)((int)_Dst + 0xa0) = pcVar9;
        eVar7 = _strcpy_s(pcVar9,(int)_Dst + (local_c - (int)pcVar9),*(char **)((int)_Src + 0xa0));
        if (eVar7 == 0) {
          sVar3 = _strlen(pcVar9);
          pcVar9 = pcVar9 + sVar3 + 1;
          *(char **)((int)_Dst + 0xa4) = pcVar9;
          eVar7 = _strcpy_s(pcVar9,(int)_Dst + (local_c - (int)pcVar9),*(char **)((int)_Src + 0xa4))
          ;
          if (eVar7 == 0) {
            sVar3 = _strlen(pcVar9);
            pcVar9 = pcVar9 + sVar3 + 1;
            *(char **)((int)_Dst + 0xa8) = pcVar9;
            eVar7 = _strcpy_s(pcVar9,(int)_Dst + (local_c - (int)pcVar9),
                              *(char **)((int)_Src + 0xa8));
            if (eVar7 == 0) goto LAB_0089aa94;
          }
        }
      }
    }
LAB_0089a941:
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
LAB_0089aa94:
  if (local_1c != '\0') {
    *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
  }
  return _Dst;
}

