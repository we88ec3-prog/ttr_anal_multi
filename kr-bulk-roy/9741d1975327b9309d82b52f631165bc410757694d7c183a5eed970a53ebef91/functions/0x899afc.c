
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __popen
   
   Library: Visual Studio 2010 Release */

FILE * __cdecl __popen(char *_Command,char *_Mode)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  int *piVar4;
  byte *pbVar5;
  int iVar6;
  HANDLE hSourceProcessHandle;
  BOOL BVar7;
  errno_t eVar8;
  size_t sVar9;
  size_t sVar10;
  size_t sVar11;
  uchar *_Str;
  char *_Src;
  uchar *puVar12;
  uint uVar13;
  bool bVar14;
  _STARTUPINFOA local_b8;
  _PROCESS_INFORMATION local_74;
  char *local_64;
  uchar *local_60;
  int local_5c [2];
  undefined4 *local_54;
  uint local_50 [3];
  HANDLE local_44;
  uchar *local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  FILE *local_30;
  char *local_2c;
  char *local_28;
  undefined2 local_24;
  undefined1 local_22;
  char *local_20;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00c850a0;
  uStack_c = 0x899b0b;
  uVar13 = 0;
  local_30 = (FILE *)0x0;
  local_2c = (char *)0x0;
  local_24 = 0;
  local_22 = 0;
  local_50[2] = 0;
  if ((_Command == (char *)0x0) || (pbVar5 = (byte *)_Mode, _Mode == (char *)0x0)) {
LAB_00899b2b:
    piVar4 = __errno();
    *piVar4 = 0x16;
    FUN_00893343();
    return (FILE *)0x0;
  }
  for (; *pbVar5 == 0x20; pbVar5 = pbVar5 + 1) {
  }
  bVar2 = *pbVar5;
  if ((bVar2 != 0x77) && (bVar2 != 0x72)) goto LAB_00899b2b;
  local_24 = (ushort)bVar2;
  do {
    pbVar5 = pbVar5 + 1;
  } while (*pbVar5 == 0x20);
  bVar3 = *pbVar5;
  if (((bVar3 != 0) && (bVar3 != 0x74)) && (bVar3 != 0x62)) goto LAB_00899b2b;
  local_24 = CONCAT11(bVar3,bVar2);
  if (bVar3 == 0x74) {
    uVar13 = 0x4000;
  }
  else if (bVar3 == 0x62) {
    uVar13 = 0x8000;
  }
  iVar6 = __pipe((int *)local_50,0x400,uVar13 | 0x80);
  if (iVar6 == -1) {
    return local_30;
  }
  bVar14 = (char)local_24 != 'w';
  local_20 = (char *)(uint)bVar14;
  local_34 = (uint)bVar14;
  local_38 = (uint)!bVar14;
  iVar6 = __mtinitlocknum(9);
  if (iVar6 == 0) {
    __close(local_50[0]);
    __close(local_50[1]);
    return (FILE *)0x0;
  }
  __lock(9);
  local_8 = (undefined *)0x0;
  local_5c[1] = 1;
  local_5c[0] = 1;
  hSourceProcessHandle = GetCurrentProcess();
  puVar1 = local_50 + local_34;
  uVar13 = *puVar1;
  BVar7 = DuplicateHandle(hSourceProcessHandle,
                          *(HANDLE *)
                           ((int)(&DAT_00fe72a0)[(int)uVar13 >> 5] + (uVar13 & 0x1f) * 0x40),
                          hSourceProcessHandle,&local_44,0,1,2);
  if (BVar7 != 0) {
    __close(*puVar1);
    local_5c[local_34] = 0;
    local_30 = __fdopen(local_50[local_38],(char *)&local_24);
    if (local_30 != (FILE *)0x0) {
      local_54 = (undefined4 *)idtab();
      if (local_54 != (undefined4 *)0x0) {
        eVar8 = __dupenv_s(&local_2c,(size_t *)0x0,"COMSPEC");
        if (eVar8 == 0) {
LAB_00899ca7:
          local_28 = local_2c;
          if (local_2c == (char *)0x0) goto LAB_00899cb1;
        }
        else {
          if (eVar8 == 0x16) goto LAB_00899c9a;
          if (eVar8 == 0) goto LAB_00899ca7;
LAB_00899cb1:
          local_28 = "cmd.exe";
        }
        _memset(&local_b8,0,0x44);
        local_b8.cb = 0x44;
        local_b8.dwFlags = 0x100;
        local_b8.hStdInput = local_44;
        if (local_20 != (char *)0x0) {
          local_b8.hStdInput = (HANDLE)*DAT_00fe72a0;
        }
        local_b8.hStdOutput = local_44;
        if (local_20 != (char *)0x1) {
          local_b8.hStdOutput = (HANDLE)DAT_00fe72a0[0x10];
        }
        local_b8.hStdError = (HANDLE)DAT_00fe72a0[0x20];
        sVar9 = _strlen(local_28);
        sVar10 = _strlen(_Command);
        sVar11 = _strlen(" /c ");
        sVar9 = sVar11 + 1 + sVar9 + sVar10;
        local_20 = __calloc_crt(sVar9,1);
        if (local_20 != (char *)0x0) {
          eVar8 = _strcpy_s(local_20,sVar9,local_28);
          if (((eVar8 != 0) || (eVar8 = _strcat_s(local_20,sVar9," /c "), eVar8 != 0)) ||
             (eVar8 = _strcat_s(local_20,sVar9,_Command), eVar8 != 0)) {
LAB_00899c9a:
                    /* WARNING: Subroutine does not return */
            __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          piVar4 = __errno();
          local_3c = *piVar4;
          eVar8 = __access_s(local_28,0);
          if (eVar8 == 0) {
            local_50[2] = CreateProcessA(local_28,local_20,(LPSECURITY_ATTRIBUTES)0x0,
                                         (LPSECURITY_ATTRIBUTES)0x0,1,0,(LPVOID)0x0,(LPCSTR)0x0,
                                         &local_b8,&local_74);
          }
          else {
            _Command = (char *)0x0;
            _Str = __calloc_crt(0x104,1);
            local_60 = _Str;
            if (_Str == (uchar *)0x0) {
              _free((void *)0x0);
              _free(local_20);
              _free(local_2c);
LAB_00899df3:
              piVar4 = __errno();
              *piVar4 = local_3c;
              goto LAB_00899f6d;
            }
            eVar8 = __dupenv_s(&_Command,(size_t *)0x0,"PATH");
            _Src = _Command;
            if (eVar8 != 0) {
              if (eVar8 == 0x16) goto LAB_00899c9a;
              if (eVar8 != 0) {
                _free(_Command);
                _free(_Str);
                _free(local_20);
                _free(local_2c);
                goto LAB_00899df3;
              }
            }
            do {
              local_64 = __getpath(_Src,(char *)_Str,0x103);
              if ((local_64 == (char *)0x0) || (*_Str == '\0')) goto LAB_00899f0b;
              sVar9 = _strlen((char *)_Str);
              local_40 = _Str + (sVar9 - 1);
              if (*local_40 == '\\') {
                puVar12 = __mbsrchr(_Str,0x5c);
                bVar14 = local_40 == puVar12;
              }
              else {
                bVar14 = *local_40 == '/';
              }
              if ((!bVar14) && (eVar8 = _strcat_s((char *)_Str,0x104,"\\"), eVar8 != 0))
              goto LAB_00899c9a;
              local_40 = (uchar *)_strlen(local_28);
              sVar9 = _strlen((char *)_Str);
              _Str = local_60;
              if ((uchar *)0x103 < local_40 + sVar9) goto LAB_00899f0b;
              eVar8 = _strcat_s((char *)local_60,0x104,local_28);
              if (eVar8 != 0) goto LAB_00899c9a;
              eVar8 = __access_s((char *)_Str,0);
              _Src = local_64;
            } while (eVar8 != 0);
            local_50[2] = CreateProcessA((LPCSTR)_Str,local_20,(LPSECURITY_ATTRIBUTES)0x0,
                                         (LPSECURITY_ATTRIBUTES)0x0,1,0,(LPVOID)0x0,(LPCSTR)0x0,
                                         &local_b8,&local_74);
LAB_00899f0b:
            _free(_Command);
            _free(_Str);
          }
          _free(local_20);
          _free(local_2c);
          CloseHandle(local_44);
          CloseHandle(local_74.hThread);
          piVar4 = __errno();
          *piVar4 = local_3c;
          if (local_50[2] != 0) {
            local_54[1] = local_74.hProcess;
            *local_54 = local_30;
            goto LAB_00899fa6;
          }
          *local_54 = 0;
        }
      }
LAB_00899f6d:
      _fclose(local_30);
      local_5c[local_38] = 0;
      local_30 = (FILE *)0x0;
    }
  }
  if (local_5c[local_34] != 0) {
    __close(local_50[local_34]);
  }
  if (local_5c[local_38] != 0) {
    __close(local_50[local_38]);
  }
LAB_00899fa6:
  local_8 = (undefined *)0xfffffffe;
  FUN_00899fbb();
  return local_30;
}

