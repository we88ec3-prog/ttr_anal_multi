
/* Library Function - Single Match
    __spawnve
   
   Library: Visual Studio 2010 Release */

intptr_t __cdecl __spawnve(int _Mode,char *_Filename,char **_ArgList,char **_Env)

{
  int iVar1;
  int *piVar2;
  uchar *puVar3;
  uchar *puVar4;
  size_t sVar5;
  errno_t eVar6;
  char *_Dst;
  size_t sVar7;
  intptr_t local_10;
  undefined **local_c;
  char *local_8;
  
  local_8 = _Filename;
  if ((((_Filename == (char *)0x0) || (*_Filename == '\0')) || (_ArgList == (char **)0x0)) ||
     ((*_ArgList == (char *)0x0 || (**_ArgList == '\0')))) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00893343();
    return -1;
  }
  puVar3 = __mbsrchr((uchar *)_Filename,0x5c);
  puVar4 = __mbsrchr((uchar *)_Filename,0x2f);
  if (puVar4 == (uchar *)0x0) {
    if ((puVar3 != (uchar *)0x0) ||
       (puVar3 = __mbschr((uchar *)_Filename,0x3a), puVar3 != (uchar *)0x0)) goto LAB_008b01d3;
    sVar5 = _strlen(_Filename);
    sVar5 = sVar5 + 3;
    local_8 = __calloc_crt(sVar5,1);
    if (local_8 != (char *)0x0) {
      eVar6 = _strcpy_s(local_8,sVar5,".\\");
      if ((eVar6 != 0) || (eVar6 = _strcat_s(local_8,sVar5,_Filename), eVar6 != 0))
      goto LAB_008b01c4;
      puVar3 = (uchar *)(local_8 + 2);
      goto LAB_008b01d3;
    }
LAB_008b0233:
    local_10 = -1;
  }
  else {
    if ((puVar3 == (uchar *)0x0) || (puVar3 < puVar4)) {
      puVar3 = puVar4;
    }
LAB_008b01d3:
    local_10 = -1;
    puVar3 = __mbsrchr(puVar3,0x2e);
    if (puVar3 == (uchar *)0x0) {
      sVar5 = _strlen(local_8);
      sVar5 = sVar5 + 5;
      _Dst = __calloc_crt(sVar5,1);
      if (_Dst == (char *)0x0) goto LAB_008b0233;
      eVar6 = _strcpy_s(_Dst,sVar5,local_8);
      if (eVar6 != 0) {
LAB_008b01c4:
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      sVar7 = _strlen(local_8);
      piVar2 = __errno();
      iVar1 = *piVar2;
      local_c = &PTR_DAT_00d62ca8;
      do {
        eVar6 = _strcpy_s(_Dst + sVar7,(rsize_t)(_Dst + (sVar5 - (int)(_Dst + sVar7))),*local_c);
        if (eVar6 != 0) goto LAB_008b01c4;
        eVar6 = __access_s(_Dst,0);
        if (eVar6 == 0) {
          piVar2 = __errno();
          *piVar2 = iVar1;
          local_10 = FUN_008b0092(_Mode,_Dst,_ArgList,_Env);
          break;
        }
        local_c = local_c + -1;
      } while (0xd62c9b < (int)local_c);
      _free(_Dst);
    }
    else {
      eVar6 = __access_s(local_8,0);
      if (eVar6 == 0) {
        local_10 = FUN_008b0092(_Mode,local_8,_ArgList,_Env);
      }
    }
    if (local_8 != _Filename) {
      _free(local_8);
    }
  }
  return local_10;
}

