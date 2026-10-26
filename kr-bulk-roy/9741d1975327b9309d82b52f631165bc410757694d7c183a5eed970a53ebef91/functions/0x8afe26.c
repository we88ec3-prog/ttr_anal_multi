
/* Library Function - Single Match
    __spawnvpe
   
   Library: Visual Studio 2010 Release */

intptr_t __cdecl __spawnvpe(int _Mode,char *_Filename,char **_ArgList,char **_Env)

{
  uchar uVar1;
  int iVar2;
  int *piVar3;
  uchar *puVar4;
  errno_t eVar5;
  char *_Src;
  size_t sVar6;
  size_t sVar7;
  ulong *puVar8;
  uchar *puVar9;
  uchar *_Str;
  intptr_t local_10;
  char *local_8;
  
  _Str = (uchar *)0x0;
  local_8 = (char *)0x0;
  if ((_Filename == (char *)0x0) || (*_Filename == '\0')) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_00893343();
    local_10 = -1;
  }
  else if (((_ArgList == (char **)0x0) || (*_ArgList == (char *)0x0)) || (**_ArgList == '\0')) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_00893343();
    local_10 = -1;
  }
  else {
    piVar3 = __errno();
    iVar2 = *piVar3;
    piVar3 = __errno();
    *piVar3 = 0;
    local_10 = __spawnve(_Mode,_Filename,_ArgList,_Env);
    if (((local_10 == -1) && (piVar3 = __errno(), *piVar3 == 2)) &&
       (puVar4 = __mbschr((uchar *)_Filename,0x2f), puVar4 == (uchar *)0x0)) {
      eVar5 = __dupenv_s(&local_8,(size_t *)0x0,"PATH");
      if (eVar5 == 0) {
        if ((local_8 != (char *)0x0) && (_Str = __calloc_crt(0x104,1), _Str != (uchar *)0x0)) {
          _Src = __getpath(local_8,(char *)_Str,0x103);
          while ((_Src != (char *)0x0 && (*_Str != '\0'))) {
            sVar6 = _strlen((char *)_Str);
            uVar1 = _Str[sVar6 - 1];
            if (uVar1 == '\\') {
              puVar4 = __mbsrchr(_Str,0x5c);
              if (_Str + (sVar6 - 1) != puVar4) {
                _strcat_s((char *)_Str,0x104,"\\");
              }
            }
            else if ((uVar1 != '/') && (eVar5 = _strcat_s((char *)_Str,0x104,"\\"), eVar5 != 0))
            goto LAB_008afefb;
            sVar6 = _strlen((char *)_Str);
            sVar7 = _strlen(_Filename);
            if (0x103 < sVar6 + sVar7) break;
            eVar5 = _strcat_s((char *)_Str,0x104,_Filename);
            if (eVar5 != 0) goto LAB_008afefb;
            piVar3 = __errno();
            *piVar3 = 0;
            local_10 = __spawnve(_Mode,(char *)_Str,_ArgList,_Env);
            if (local_10 != -1) break;
            piVar3 = __errno();
            if ((*piVar3 != 2) && (puVar8 = ___doserrno(), *puVar8 != 0x15)) {
              puVar4 = __mbschr(_Str,0x5c);
              if ((_Str != puVar4) && (puVar4 = __mbschr(_Str,0x2f), _Str != puVar4)) break;
              puVar4 = _Str + 1;
              puVar9 = __mbschr(puVar4,0x5c);
              if ((puVar4 != puVar9) && (puVar9 = __mbschr(puVar4,0x2f), puVar4 != puVar9)) break;
            }
            _Src = __getpath(_Src,(char *)_Str,0x103);
          }
        }
      }
      else if (eVar5 == 0x16) {
LAB_008afefb:
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
    }
    piVar3 = __errno();
    if (*piVar3 == 0) {
      piVar3 = __errno();
      *piVar3 = iVar2;
    }
    if (_Str != (uchar *)0x0) {
      _free(_Str);
    }
    if (local_8 != (char *)0x0) {
      _free(local_8);
    }
  }
  return local_10;
}

