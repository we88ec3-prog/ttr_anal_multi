
undefined1 * FUN_0071cc20(int *param_1)

{
  int *in_EAX;
  char *pcVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  char *_Str;
  int iVar5;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*in_EAX == 0) || (_Str = *(char **)(*in_EAX + 4), _Str == (char *)0x0)) {
    _Str = "";
  }
  pcVar1 = _strchr(_Str,0x3a);
  uVar4 = -(uint)(pcVar1 != (char *)0x0) & (uint)_Str;
  if (pcVar1 == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)pcVar1 - (int)_Str;
  }
  if ((uVar4 != 0) && (iVar5 = *param_1, iVar5 != 0)) {
    while (local_8 = iVar5, FUN_00722800(&local_c,uVar4,iVar2), local_c == 0) {
      if (iVar5 == 0) {
        local_14 = 0;
        piVar3 = &local_14;
      }
      else {
        local_10 = *(int *)(iVar5 + 4);
        piVar3 = &local_10;
      }
      iVar5 = *piVar3;
      if (iVar5 == 0) {
        return &DAT_00bf2375;
      }
    }
    if (*(undefined1 **)(local_c + 8) != (undefined1 *)0x0) {
      return *(undefined1 **)(local_c + 8);
    }
  }
  return &DAT_00bf2375;
}

