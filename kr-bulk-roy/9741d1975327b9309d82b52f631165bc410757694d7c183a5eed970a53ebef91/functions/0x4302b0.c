
wchar_t * FUN_004302b0(char *param_1,undefined4 param_2,_Cvtvec *param_3)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  wchar_t *pwVar10;
  mbstate_t local_10;
  mbstate_t local_c;
  wchar_t local_8 [2];
  
  iVar7 = 0;
  local_c = 0;
  pcVar1 = param_1 + 1;
  pcVar3 = param_1;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  pcVar9 = pcVar3 + (1 - (int)pcVar1);
  pcVar6 = param_1;
  while ((pcVar9 != (char *)0x0 &&
         (iVar4 = __Mbrtowc(local_8,pcVar6,(size_t)pcVar9,&local_c,param_3), 0 < iVar4))) {
    pcVar6 = pcVar6 + iVar4;
    iVar7 = iVar7 + 1;
    pcVar9 = pcVar9 + -iVar4;
  }
  uVar8 = iVar7 + 1;
  pwVar5 = (wchar_t *)
           FUN_0087dc3d(-(uint)((int)((ulonglong)uVar8 * 2 >> 0x20) != 0) |
                        (uint)((ulonglong)uVar8 * 2));
  local_10 = 0;
  pwVar10 = pwVar5;
  while ((uVar8 != 0 &&
         (iVar7 = __Mbrtowc(pwVar10,param_1,(size_t)(pcVar3 + (1 - (int)pcVar1)),&local_10,param_3),
         0 < iVar7))) {
    param_1 = param_1 + iVar7;
    pwVar10 = pwVar10 + 1;
    uVar8 = uVar8 - 1;
  }
  *pwVar10 = L'\0';
  return pwVar5;
}

