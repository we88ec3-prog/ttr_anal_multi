
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __pipe
   
   Library: Visual Studio 2010 Release */

int __cdecl __pipe(int *_PtHandles,uint _PipeSize,int _TextMode)

{
  byte *pbVar1;
  ulong *puVar2;
  int *piVar3;
  BOOL BVar4;
  DWORD DVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  errno_t eVar11;
  _SECURITY_ATTRIBUTES local_40;
  HANDLE local_34;
  HANDLE local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  int local_20;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00c85700;
  uStack_c = 0x8afafb;
  local_20 = 0;
  if (_PtHandles == (int *)0x0) {
    puVar2 = ___doserrno();
    *puVar2 = 0;
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_00893343();
    return -1;
  }
  _PtHandles[1] = -1;
  *_PtHandles = -1;
  if (((_TextMode & 0xffff3f7fU) != 0) || ((_TextMode & 0xc000U) == 0xc000)) {
    puVar2 = ___doserrno();
    *puVar2 = 0;
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_00893343();
    return -1;
  }
  local_40.nLength = 0xc;
  local_40.lpSecurityDescriptor = (LPVOID)0x0;
  local_40.bInheritHandle = (BOOL)((_TextMode & 0x80U) == 0);
  BVar4 = CreatePipe(&local_30,&local_34,&local_40,_PipeSize);
  if (BVar4 == 0) {
    DVar5 = GetLastError();
    __dosmaperr(DVar5);
    return -1;
  }
  uVar6 = __alloc_osfhnd();
  local_24 = uVar6;
  if (uVar6 != 0xffffffff) {
    iVar7 = (int)uVar6 >> 5;
    piVar3 = &DAT_00fe72a0 + iVar7;
    iVar8 = (uVar6 & 0x1f) * 0x40;
    *(undefined1 *)(*piVar3 + 4 + iVar8) = 0x89;
    pbVar1 = (byte *)(*piVar3 + 0x24 + iVar8);
    *pbVar1 = *pbVar1 & 0x80;
    pbVar1 = (byte *)(*piVar3 + 0x24 + iVar8);
    *pbVar1 = *pbVar1 & 0x7f;
    local_8 = (undefined *)0xfffffffe;
    FUN_008afd0e();
    uVar9 = __alloc_osfhnd();
    local_2c = uVar9;
    if (uVar9 != 0xffffffff) {
      local_28 = 0;
      iVar8 = (int)uVar9 >> 5;
      piVar3 = &DAT_00fe72a0 + iVar8;
      iVar10 = (uVar9 & 0x1f) * 0x40;
      *(undefined1 *)(iVar10 + 4 + *piVar3) = 0x89;
      pbVar1 = (byte *)(iVar10 + 0x24 + *piVar3);
      *pbVar1 = *pbVar1 & 0x80;
      pbVar1 = (byte *)(iVar10 + 0x24 + *piVar3);
      *pbVar1 = *pbVar1 & 0x7f;
      local_8 = (undefined *)0xfffffffe;
      FUN_008afd1e();
      eVar11 = __get_fmode(&local_28);
      if (eVar11 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      if (((_TextMode & 0x8000U) != 0) || (((_TextMode & 0x4000U) == 0 && (local_28 == 0x8000)))) {
        pbVar1 = (byte *)((&DAT_00fe72a0)[iVar7] + 4 + (uVar6 & 0x1f) * 0x40);
        *pbVar1 = *pbVar1 & 0x7f;
        pbVar1 = (byte *)((&DAT_00fe72a0)[iVar8] + 4 + (uVar9 & 0x1f) * 0x40);
        *pbVar1 = *pbVar1 & 0x7f;
      }
      if ((_TextMode & 0x80U) != 0) {
        pbVar1 = (byte *)((&DAT_00fe72a0)[iVar7] + 4 + (uVar6 & 0x1f) * 0x40);
        *pbVar1 = *pbVar1 | 0x10;
        pbVar1 = (byte *)((&DAT_00fe72a0)[iVar8] + 4 + (uVar9 & 0x1f) * 0x40);
        *pbVar1 = *pbVar1 | 0x10;
      }
      __set_osfhnd(uVar6,(intptr_t)local_30);
      __set_osfhnd(uVar9,(intptr_t)local_34);
      goto LAB_008afd59;
    }
    *(undefined1 *)((&DAT_00fe72a0)[iVar7] + 4 + (uVar6 & 0x1f) * 0x40) = 0;
  }
  local_20 = 1;
  uVar9 = local_2c;
LAB_008afd59:
  if (local_20 != 0) {
    piVar3 = __errno();
    *piVar3 = 0x18;
    CloseHandle(local_30);
    CloseHandle(local_34);
    puVar2 = ___doserrno();
    *puVar2 = 0;
    return -1;
  }
  *_PtHandles = uVar6;
  _PtHandles[1] = uVar9;
  return 0;
}

