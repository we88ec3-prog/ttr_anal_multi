
/* Library Function - Single Match
    __cenvarg
   
   Library: Visual Studio 2010 Release */

int __cdecl __cenvarg(char **_Argv,char **_Env,char **_ArgBlk,char **_EnvBlk,char *_Name)

{
  bool bVar1;
  char *pcVar2;
  int *piVar3;
  ulong *puVar4;
  errno_t eVar5;
  size_t sVar6;
  size_t sVar7;
  int iVar8;
  char cVar9;
  char **ppcVar10;
  size_t local_44;
  rsize_t local_34;
  int local_2c;
  int local_20;
  char *local_18;
  uchar local_14 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  builtin_memcpy(local_14,"SystemRoot",0xb);
  pcVar2 = *_Argv;
  local_18 = (char *)0x0;
  bVar1 = false;
  sVar7 = 2;
  ppcVar10 = _Argv;
  while (pcVar2 != (char *)0x0) {
    sVar6 = _strlen(pcVar2);
    ppcVar10 = ppcVar10 + 1;
    sVar7 = sVar7 + 1 + sVar6;
    pcVar2 = *ppcVar10;
  }
  pcVar2 = __calloc_crt(sVar7,1);
  *_ArgBlk = pcVar2;
  if (pcVar2 == (char *)0x0) {
    *_EnvBlk = (char *)0x0;
    piVar3 = __errno();
    *piVar3 = 0xc;
    puVar4 = ___doserrno();
    *puVar4 = 8;
    goto LAB_008b464c;
  }
  eVar5 = __dupenv_s(&local_18,(size_t *)0x0,(char *)local_14);
  if (eVar5 == 0) {
    sVar6 = _strlen((char *)local_14);
    local_34 = sVar6 + 2;
    if (local_18 != (char *)0x0) {
      sVar6 = _strlen(local_18);
      local_34 = local_34 + sVar6;
    }
    if (_Env == (char **)0x0) {
      *_EnvBlk = (char *)0x0;
LAB_008b43fc:
      pcVar2 = *_ArgBlk;
      if (*_Argv != (char *)0x0) {
        eVar5 = _strcpy_s(pcVar2,sVar7,*_Argv);
        if (eVar5 == 0) {
          sVar6 = _strlen(*_Argv);
          pcVar2 = pcVar2 + sVar6 + 1;
          goto LAB_008b4553;
        }
LAB_008b4374:
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      pcVar2 = pcVar2 + 1;
      for (; *_Argv != (char *)0x0; _Argv = _Argv + 1) {
        eVar5 = _strcpy_s(pcVar2,(rsize_t)(*_ArgBlk + (sVar7 - (int)pcVar2)),*_Argv);
        if (eVar5 != 0) goto LAB_008b4374;
        sVar6 = _strlen(*_Argv);
        pcVar2[sVar6] = ' ';
        pcVar2 = pcVar2 + sVar6 + 1;
LAB_008b4553:
      }
      pcVar2[-0xffffffff00000001] = '\0';
      pcVar2[0] = '\0';
      pcVar2 = *_EnvBlk;
      if (_Env != (char **)0x0) {
        FID_conflict__memcpy(pcVar2,DAT_00f8cb18 + local_20,local_2c - local_20);
        pcVar2 = pcVar2 + (local_2c - local_20);
        for (; *_Env != (char *)0x0; _Env = _Env + 1) {
          eVar5 = _strcpy_s(pcVar2,(rsize_t)(*_EnvBlk + (local_44 - (int)pcVar2)),*_Env);
          if (eVar5 != 0) goto LAB_008b4374;
          sVar7 = _strlen(*_Env);
          pcVar2 = pcVar2 + sVar7 + 1;
        }
        if (!bVar1) {
          eVar5 = _strcpy_s(pcVar2,local_34,(char *)local_14);
          if (((eVar5 != 0) || (eVar5 = _strcat_s(pcVar2,local_34,"="), eVar5 != 0)) ||
             ((local_18 != (char *)0x0 && (eVar5 = _strcat_s(pcVar2,local_34,local_18), eVar5 != 0))
             )) goto LAB_008b4374;
          pcVar2 = pcVar2 + local_34;
        }
      }
      if (pcVar2 != (char *)0x0) {
        if (pcVar2 == *_EnvBlk) {
          *pcVar2 = '\0';
          pcVar2 = pcVar2 + 1;
        }
        *pcVar2 = '\0';
      }
    }
    else {
      iVar8 = 2;
      pcVar2 = *_Env;
      ppcVar10 = _Env;
      while (pcVar2 != (char *)0x0) {
        sVar6 = _strlen(pcVar2);
        ppcVar10 = ppcVar10 + 1;
        iVar8 = iVar8 + 1 + sVar6;
        pcVar2 = *ppcVar10;
      }
      if ((DAT_00f8cb18 == (char *)0x0) &&
         (DAT_00f8cb18 = ___crtGetEnvironmentStringsA(), DAT_00f8cb18 == (char *)0x0))
      goto LAB_008b43df;
      local_20 = 0;
      if (*DAT_00f8cb18 != '\0') {
        cVar9 = *DAT_00f8cb18;
        pcVar2 = DAT_00f8cb18;
        do {
          if (cVar9 == '=') break;
          sVar6 = _strlen(pcVar2);
          local_20 = local_20 + 1 + sVar6;
          pcVar2 = DAT_00f8cb18 + local_20;
          cVar9 = *pcVar2;
        } while (cVar9 != '\0');
      }
      local_2c = local_20;
      pcVar2 = DAT_00f8cb18 + local_20;
      while ((((*pcVar2 == '=' && (pcVar2[1] != '\0')) && (pcVar2[2] == ':')) && (pcVar2[3] == '='))
            ) {
        sVar6 = _strlen(pcVar2 + 4);
        local_2c = local_2c + 5 + sVar6;
        pcVar2 = DAT_00f8cb18 + local_2c;
      }
      local_44 = iVar8 + (local_2c - local_20);
      for (ppcVar10 = _Env; *ppcVar10 != (char *)0x0; ppcVar10 = ppcVar10 + 1) {
        sVar6 = _strlen((char *)local_14);
        iVar8 = __mbsnicmp((uchar *)*ppcVar10,local_14,sVar6);
        if (iVar8 == 0) {
          bVar1 = true;
          sVar6 = local_44;
          goto LAB_008b44b0;
        }
      }
      sVar6 = local_44 + local_34;
LAB_008b44b0:
      pcVar2 = __calloc_crt(sVar6,1);
      *_EnvBlk = pcVar2;
      if (pcVar2 != (char *)0x0) goto LAB_008b43fc;
      _free(*_ArgBlk);
      *_ArgBlk = (char *)0x0;
      piVar3 = __errno();
      *piVar3 = 0xc;
      puVar4 = ___doserrno();
      *puVar4 = 8;
    }
  }
  else {
    if (eVar5 == 0x16) goto LAB_008b4374;
LAB_008b43df:
    _free(*_ArgBlk);
    *_ArgBlk = (char *)0x0;
    *_EnvBlk = (char *)0x0;
  }
  if (DAT_00f8cb18 != (char *)0x0) {
    _free(DAT_00f8cb18);
  }
  DAT_00f8cb18 = (char *)0x0;
  if (local_18 != (char *)0x0) {
    _free(local_18);
  }
LAB_008b464c:
  iVar8 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar8;
}

