
uint FUN_008d3350(undefined4 *param_1,uint param_2)

{
  char *_Str1;
  void *_Dst;
  int in_ECX;
  int *piVar1;
  int iVar2;
  size_t _Size;
  undefined8 uVar3;
  int local_14;
  undefined4 local_10;
  uint local_c;
  char *local_8;
  
  local_10 = param_1[1];
  if (5 < param_2) {
    return 0;
  }
  local_c = 0;
  if (param_2 != 0) {
    piVar1 = (int *)(in_ECX + 4);
    do {
      if (piVar1[-1] == 0) {
        uVar3 = FUN_008d11c0();
      }
      else {
        uVar3 = FUN_008d1150();
      }
      _Str1 = (char *)uVar3;
      if (_Str1 == (char *)0x0) {
        return local_c;
      }
      iVar2 = *(int *)((ulonglong)uVar3 >> 0x20) - (int)_Str1;
      _Size = iVar2 - 1;
      local_8 = _Str1;
      switch(piVar1[-1]) {
      case 0:
      case 1:
        _Dst = (void *)FUN_008b9f30(*param_1,iVar2,&local_14);
        *piVar1 = (int)_Dst;
        if (local_14 == 0) {
          FID_conflict__memcpy(_Dst,_Str1,_Size);
          *(undefined1 *)(_Size + *piVar1) = 0;
        }
        break;
      case 2:
        iVar2 = FUN_008d1540(&local_8,_Str1 + _Size,0);
        *piVar1 = iVar2;
        break;
      case 3:
        iVar2 = FUN_008d14e0();
        *piVar1 = iVar2;
        break;
      case 4:
        if ((_Size == 4) && (iVar2 = _strncmp(_Str1,"true",4), iVar2 == 0)) {
          *(undefined1 *)piVar1 = 1;
        }
        else {
          *(undefined1 *)piVar1 = 0;
        }
        break;
      case 5:
        if ((code *)param_1[3] == (code *)0x0) {
          *piVar1 = 0;
        }
        else {
          iVar2 = (*(code *)param_1[3])(_Str1,_Size,param_1[4]);
          *piVar1 = iVar2;
        }
      }
      local_c = local_c + 1;
      piVar1 = piVar1 + 2;
    } while (local_c < param_2);
  }
  return local_c;
}

