
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fdopen
   
   Library: Visual Studio 2010 Release */

FILE * __cdecl __fdopen(int _FileHandle,char *_Mode)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  FILE *pFVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (_Mode != (char *)0x0) {
    if (_FileHandle == -2) {
      piVar3 = __errno();
      *piVar3 = 9;
      return (FILE *)0x0;
    }
    if (((_FileHandle < 0) || (DAT_00fe7294 <= (uint)_FileHandle)) ||
       (uVar8 = 1,
       (*(byte *)((&DAT_00fe72a0)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 0x40) & 1) == 0))
    {
      piVar3 = __errno();
      *piVar3 = 9;
      goto LAB_0089c3aa;
    }
    for (; *_Mode == ' '; _Mode = _Mode + 1) {
    }
    cVar1 = *_Mode;
    if (cVar1 != 'a') {
      uVar6 = uVar8;
      if (cVar1 == 'r') goto LAB_0089c41b;
      if (cVar1 != 'w') goto LAB_0089c39f;
    }
    uVar6 = 2;
LAB_0089c41b:
    bVar2 = false;
    uVar6 = uVar6 | DAT_00f8d84c;
    uVar5 = 0;
    uVar7 = uVar8;
LAB_0089c48d:
    do {
      _Mode = _Mode + 1;
      cVar1 = *_Mode;
      if ((cVar1 == '\0') || (uVar7 == 0)) goto LAB_0089c497;
    } while (cVar1 == ' ');
    if (cVar1 == '+') {
      if (-1 < (char)uVar6) {
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_0089c48d;
      }
    }
    else if (cVar1 == 'b') {
LAB_0089c455:
      if (!bVar2) {
        bVar2 = true;
        goto LAB_0089c48d;
      }
    }
    else if (cVar1 == 'c') {
      if (uVar5 == 0) {
        uVar5 = 1;
        uVar6 = uVar6 | 0x4000;
        goto LAB_0089c48d;
      }
    }
    else {
      if (cVar1 != 'n') {
        if (cVar1 == 't') goto LAB_0089c455;
        goto LAB_0089c39f;
      }
      if (uVar5 == 0) {
        uVar6 = uVar6 & 0xffffbfff;
        uVar5 = uVar8;
        goto LAB_0089c48d;
      }
    }
    uVar7 = 0;
    goto LAB_0089c48d;
  }
  goto LAB_0089c39f;
LAB_0089c497:
  for (; *_Mode == ' '; _Mode = _Mode + 1) {
  }
  if (*_Mode == '\0') {
    pFVar4 = __getstream();
    if (pFVar4 == (FILE *)0x0) {
      piVar3 = __errno();
      *piVar3 = 0x18;
      return (FILE *)0x0;
    }
    _DAT_00f8cb14 = _DAT_00f8cb14 + 1;
    pFVar4->_flag = uVar6;
    pFVar4->_file = _FileHandle;
    FUN_0089c4f3();
    return pFVar4;
  }
LAB_0089c39f:
  piVar3 = __errno();
  *piVar3 = 0x16;
LAB_0089c3aa:
  FUN_00893343();
  return (FILE *)0x0;
}

