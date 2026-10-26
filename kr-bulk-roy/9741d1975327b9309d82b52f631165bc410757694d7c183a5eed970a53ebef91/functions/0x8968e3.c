
/* Library Function - Single Match
    __splitpath_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl
__splitpath_s(char *_FullPath,char *_Drive,size_t _DriveSize,char *_Dir,size_t _DirSize,
             char *_Filename,size_t _FilenameSize,char *_Ext,size_t _ExtSize)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  char *_Src;
  char *pcVar5;
  char *pcVar6;
  errno_t eVar7;
  
  bVar2 = false;
  if (_FullPath != (char *)0x0) {
    if (_Drive == (char *)0x0) {
      if (_DriveSize == 0) {
LAB_0089690d:
        if (_Dir == (char *)0x0) {
          if (_DirSize == 0) {
LAB_0089691e:
            if (_Filename == (char *)0x0) {
              if (_FilenameSize == 0) {
LAB_0089692f:
                if (_Ext == (char *)0x0) {
                  if (_ExtSize == 0) {
LAB_00896939:
                    iVar3 = 1;
                    pcVar5 = _FullPath;
                    do {
                      if (*pcVar5 == '\0') break;
                      iVar3 = iVar3 + -1;
                      pcVar5 = pcVar5 + 1;
                    } while (iVar3 != 0);
                    if (*pcVar5 == ':') {
                      if (_Drive != (char *)0x0) {
                        if (_DriveSize < 3) goto LAB_00896a7e;
                        _strncpy_s(_Drive,_DriveSize,_FullPath,2);
                      }
                      _FullPath = pcVar5 + 1;
                    }
                    else if (_Drive != (char *)0x0) {
                      *_Drive = '\0';
                    }
                    pcVar5 = (char *)0x0;
                    _Src = (char *)0x0;
                    pcVar6 = _FullPath;
                    if (*_FullPath == '\0') {
LAB_008969f6:
                      pcVar5 = _FullPath;
                      if (_Dir != (char *)0x0) {
                        *_Dir = '\0';
                      }
                    }
                    else {
                      do {
                        iVar3 = __ismbblead((int)*pcVar6);
                        if (iVar3 == 0) {
                          cVar1 = *pcVar6;
                          if ((cVar1 == '/') || (cVar1 == '\\')) {
                            pcVar5 = pcVar6 + 1;
                          }
                          else if (cVar1 == '.') {
                            _Src = pcVar6;
                          }
                        }
                        else {
                          pcVar6 = pcVar6 + 1;
                        }
                        pcVar6 = pcVar6 + 1;
                      } while (*pcVar6 != '\0');
                      if (pcVar5 == (char *)0x0) goto LAB_008969f6;
                      if (_Dir != (char *)0x0) {
                        if (_DirSize <= (uint)((int)pcVar5 - (int)_FullPath)) goto LAB_00896a7e;
                        _strncpy_s(_Dir,_DirSize,_FullPath,(int)pcVar5 - (int)_FullPath);
                      }
                    }
                    _FullPath = pcVar5;
                    if ((_Src == (char *)0x0) || (_Src < _FullPath)) {
                      if (_Filename != (char *)0x0) {
                        if (_FilenameSize <= (uint)((int)pcVar6 - (int)_FullPath))
                        goto LAB_00896a7e;
                        _strncpy_s(_Filename,_FilenameSize,_FullPath,(int)pcVar6 - (int)_FullPath);
                      }
                      if (_Ext != (char *)0x0) {
                        *_Ext = '\0';
                      }
                      return 0;
                    }
                    if (_Filename != (char *)0x0) {
                      if (_FilenameSize <= (uint)((int)_Src - (int)_FullPath)) goto LAB_00896a7e;
                      _strncpy_s(_Filename,_FilenameSize,_FullPath,(int)_Src - (int)_FullPath);
                    }
                    if (_Ext == (char *)0x0) {
                      return 0;
                    }
                    if ((uint)((int)pcVar6 - (int)_Src) < _ExtSize) {
                      _strncpy_s(_Ext,_ExtSize,_Src,(int)pcVar6 - (int)_Src);
                      return 0;
                    }
                    goto LAB_00896a7e;
                  }
                }
                else if (_ExtSize != 0) goto LAB_00896939;
              }
            }
            else if (_FilenameSize != 0) goto LAB_0089692f;
          }
        }
        else if (_DirSize != 0) goto LAB_0089691e;
      }
    }
    else if (_DriveSize != 0) goto LAB_0089690d;
  }
  bVar2 = true;
LAB_00896a7e:
  if ((_Drive != (char *)0x0) && (_DriveSize != 0)) {
    *_Drive = '\0';
  }
  if ((_Dir != (char *)0x0) && (_DirSize != 0)) {
    *_Dir = '\0';
  }
  if ((_Filename != (char *)0x0) && (_FilenameSize != 0)) {
    *_Filename = '\0';
  }
  if ((_Ext != (char *)0x0) && (_ExtSize != 0)) {
    *_Ext = '\0';
  }
  piVar4 = __errno();
  if ((_FullPath == (char *)0x0) || (bVar2)) {
    eVar7 = 0x16;
    *piVar4 = 0x16;
    FUN_00893343();
  }
  else {
    eVar7 = 0x22;
    *piVar4 = 0x22;
  }
  return eVar7;
}

