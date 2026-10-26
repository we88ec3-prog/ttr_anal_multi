
char * FUN_0089a5d4(localeinfo_struct *param_1)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  char *pcVar4;
  errno_t eVar5;
  int iVar6;
  int local_1c [2];
  int local_14;
  char local_10;
  char *local_c;
  uint local_8;
  
  iVar6 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_1c,param_1);
  iVar1 = *(int *)(local_1c[0] + 0xd4);
  local_8 = 0;
  do {
    uVar2 = local_8;
    local_c = (char *)_strlen(*(char **)(iVar1 + 0x1c + local_8 * 4));
    sVar3 = _strlen(*(char **)(iVar1 + uVar2 * 4));
    local_8 = local_8 + 1;
    iVar6 = sVar3 + iVar6 + 2 + (int)local_c;
  } while (local_8 < 7);
  pcVar4 = __malloc_crt(iVar6 + 1);
  local_c = pcVar4;
  if (pcVar4 != (char *)0x0) {
    local_8 = 0;
    do {
      *pcVar4 = ':';
      pcVar4 = pcVar4 + 1;
      eVar5 = _strcpy_s(pcVar4,(rsize_t)(local_c + iVar6 + (1 - (int)pcVar4)),
                        *(char **)(iVar1 + local_8 * 4));
      if (eVar5 != 0) {
LAB_0089a6af:
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      sVar3 = _strlen(pcVar4);
      pcVar4[sVar3] = ':';
      pcVar4 = pcVar4 + sVar3 + 1;
      eVar5 = _strcpy_s(pcVar4,(rsize_t)(local_c + iVar6 + (1 - (int)pcVar4)),
                        *(char **)(iVar1 + 0x1c + local_8 * 4));
      if (eVar5 != 0) goto LAB_0089a6af;
      sVar3 = _strlen(pcVar4);
      pcVar4 = pcVar4 + sVar3;
      local_8 = local_8 + 1;
    } while (local_8 < 7);
    *pcVar4 = '\0';
  }
  if (local_10 != '\0') {
    *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
  }
  return local_c;
}

