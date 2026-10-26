
undefined1 * FUN_0071cb70(int *param_1)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  char *_Str;
  int iVar4;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*param_1 == 0) || (_Str = *(char **)(*param_1 + 8), _Str == (char *)0x0)) {
    _Str = "";
  }
  pcVar1 = _strchr(_Str,0x3a);
  if (pcVar1 == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)pcVar1 - (int)_Str;
  }
  iVar4 = *param_1;
  if (iVar4 != 0) {
    while (FUN_00722800(&local_8,-(uint)(pcVar1 != (char *)0x0) & (uint)_Str,iVar2), local_8 == 0) {
      if (iVar4 == 0) {
        local_10 = 0;
        piVar3 = &local_10;
      }
      else {
        local_c = *(int *)(iVar4 + 4);
        piVar3 = &local_c;
      }
      iVar4 = *piVar3;
      if (iVar4 == 0) {
        return &DAT_00bf2375;
      }
    }
    if (*(undefined1 **)(local_8 + 8) != (undefined1 *)0x0) {
      return *(undefined1 **)(local_8 + 8);
    }
  }
  return &DAT_00bf2375;
}

