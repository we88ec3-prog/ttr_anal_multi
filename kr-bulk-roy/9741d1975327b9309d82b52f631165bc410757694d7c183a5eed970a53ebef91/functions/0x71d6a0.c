
void FUN_0071d6a0(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 in_EAX;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  char *_Str1;
  
  if (*param_3 != 0) {
    _Str1 = *(char **)(*param_3 + 4);
    if (_Str1 == (char *)0x0) {
      _Str1 = "";
    }
    pcVar2 = "xmlns";
    cVar1 = 'x';
    do {
      if ((_Str1 + -0xc44524)[(int)pcVar2] != cVar1) {
        if (*pcVar2 != '\0') goto LAB_0071d6f0;
        break;
      }
      cVar1 = pcVar2[1];
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if ((_Str1[5] != '\0') && (_Str1[5] != ':')) {
LAB_0071d6f0:
      switch(*(undefined1 *)(param_1 + 3)) {
      case 1:
        iVar3 = __stricmp(_Str1,*(char **)(param_1 + 0x10));
        if (iVar3 != 0) {
          return;
        }
        break;
      case 2:
      case 7:
        break;
      default:
        goto switchD_0071d6fd_caseD_3;
      case 8:
        cVar1 = FUN_0071c130();
        if (cVar1 == '\0') {
          return;
        }
      }
      uVar4 = FUN_007213d0(param_4);
      FUN_0071cf80(uVar4,in_EAX);
    }
  }
switchD_0071d6fd_caseD_3:
  return;
}

