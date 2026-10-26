
int FUN_006f2560(void *param_1)

{
  char cVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  uint in_ECX;
  short *_Src;
  int *in_EDX;
  char *pcVar5;
  
  iVar4 = *in_EDX;
  if ((iVar4 == in_EDX[1]) || (*(uint *)(iVar4 + 8) <= in_ECX)) {
    return 0;
  }
  if ((char)in_EDX[0x1f] == '\0') {
    pcVar5 = (char *)(*(int *)(iVar4 + 0x18 + in_ECX * 4) + iVar4);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar4 = FUN_006f1fa0((short)in_EDX[0x1c],param_1);
    return iVar4;
  }
  _Src = (short *)(*(int *)(iVar4 + 0x18 + in_ECX * 4) + iVar4);
  if (param_1 == (void *)0x0) {
    psVar3 = _Src + 1;
    do {
      sVar2 = *_Src;
      _Src = _Src + 1;
    } while (sVar2 != 0);
    return (int)_Src - (int)psVar3 >> 1;
  }
  psVar3 = _Src;
  do {
    sVar2 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar2 != 0);
  iVar4 = (int)psVar3 - (int)(_Src + 1) >> 1;
  if (0x200 < iVar4) {
    return 0;
  }
  FID_conflict__memcpy(param_1,_Src,iVar4 * 2);
  return iVar4;
}

