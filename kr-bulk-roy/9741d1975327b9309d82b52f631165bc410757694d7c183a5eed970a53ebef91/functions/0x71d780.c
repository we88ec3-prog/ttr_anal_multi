
void FUN_0071d780(undefined4 param_1,int *param_2)

{
  char cVar1;
  undefined4 in_EAX;
  char *_Str1;
  int iVar2;
  int in_ECX;
  char *_Str2;
  bool bVar3;
  uint *local_c;
  undefined4 local_8;
  
  local_c = (uint *)*param_2;
  if (local_c == (uint *)0x0) {
    return;
  }
  switch(*(undefined1 *)(in_ECX + 3)) {
  case 1:
    bVar3 = (*local_c & 7) == 1;
    goto LAB_0071d7b8;
  case 2:
switchD_0071d7a8_caseD_2:
    local_8 = 0;
    FUN_0071cf80(&local_c,in_EAX);
    return;
  case 3:
    bVar3 = (*local_c & 7) == 4;
    goto LAB_0071d7f2;
  case 4:
    bVar3 = (*local_c & 7) == 5;
LAB_0071d7f2:
    if (bVar3) {
      local_8 = 0;
      FUN_0071cf80(&local_c,in_EAX);
      return;
    }
    break;
  case 5:
    if (((*local_c & 7) == 2) || ((*local_c & 7) == 3)) goto switchD_0071d7a8_caseD_2;
    break;
  case 6:
    bVar3 = (*local_c & 7) == 5;
LAB_0071d7b8:
    if (bVar3) {
      _Str1 = (char *)FUN_0071ba20();
      iVar2 = __stricmp(_Str1,_Str2);
      if (iVar2 == 0) {
        local_c = (uint *)*param_2;
LAB_0071d8ac:
        local_8 = 0;
        FUN_0071cf80(&local_c,in_EAX);
      }
    }
    break;
  case 7:
    if ((*local_c & 7) == 1) {
      local_8 = 0;
      FUN_0071cf80(&local_c,in_EAX);
      return;
    }
    break;
  case 8:
    if ((*local_c & 7) != 1) {
      return;
    }
    FUN_0071ba20();
    cVar1 = FUN_0071c130();
    if (cVar1 == '\0') {
      return;
    }
    goto LAB_0071d8ac;
  }
  return;
}

