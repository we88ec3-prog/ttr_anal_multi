
uint FUN_006fbda0(void)

{
  char cVar1;
  int in_EAX;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  char *_Str1;
  char *_Str2;
  int local_8;
  
  iVar5 = *(int *)(in_EAX + 0xc);
  _Str2 = (char *)(in_EAX + 0x10);
  _Str1 = (char *)(in_ECX + 0x10);
  local_8 = *(int *)(in_ECX + 0xc);
  uVar2 = _strcoll(_Str1,_Str2);
  if (uVar2 == 0) {
    while( true ) {
      pcVar3 = _Str1;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      iVar4 = (int)pcVar3 - (int)(_Str1 + 1);
      if (iVar4 == iVar5) {
        return (uint)(iVar4 != local_8);
      }
      if (iVar4 == local_8) break;
      iVar4 = iVar4 + 1;
      local_8 = local_8 - iVar4;
      _Str2 = _Str2 + iVar4;
      _Str1 = _Str1 + iVar4;
      iVar5 = iVar5 - iVar4;
      uVar2 = _strcoll(_Str1,_Str2);
      if (uVar2 != 0) {
        return uVar2;
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

