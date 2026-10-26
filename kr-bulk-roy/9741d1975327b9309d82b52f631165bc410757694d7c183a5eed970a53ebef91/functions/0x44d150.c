
void FUN_0044d150(undefined4 *param_1)

{
  uint *puVar1;
  DWORD DVar2;
  char *pcVar3;
  HANDLE hFile;
  SIZE_T SVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  uint uVar8;
  LPSTR pCVar9;
  CHAR *lpString2;
  int iVar10;
  undefined4 *puVar11;
  bool bVar12;
  uint uStack_770;
  _MEMORY_BASIC_INFORMATION local_760;
  undefined4 *local_744;
  int local_740;
  HANDLE local_73c;
  uint local_738;
  LPSTR local_734;
  undefined4 *local_730;
  int *local_72c;
  CHAR local_728;
  undefined1 local_727 [949];
  CHAR local_372 [50];
  CHAR local_340 [264];
  CHAR local_238 [264];
  char local_130 [268];
  uint local_24;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_00d61f20 ^ 0xc8b898;
  uStack_770 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&uStack_770;
  ExceptionList = &local_14;
  local_24 = uStack_770;
  puVar1 = &uStack_770;
  if (DAT_00fe4b58 == 0) {
    DAT_00fe4b58 = 1;
    builtin_strncpy(local_130,"Unknown",8);
    _memset(local_130 + 8,0,0xfc);
    DVar2 = GetModuleFileNameA((HMODULE)0x0,local_238,0x104);
    if (DVar2 == 0) {
      local_238[0] = '\0';
    }
    pcVar3 = _strrchr(local_238,0x5c);
    if (pcVar3 == (char *)0x0) {
      lpString2 = local_238;
    }
    else {
      lpString2 = pcVar3 + 1;
    }
    lstrcpyA(local_130,lpString2);
    pcVar3 = _strrchr(local_130,0x2e);
    if (pcVar3 != (char *)0x0) {
      *pcVar3 = '\0';
    }
    lstrcpyA(lpString2,"Tartaros.log");
    hFile = CreateFileA(local_238,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80000080,(HANDLE)0x0);
    local_73c = hFile;
    if (hFile != (HANDLE)0xffffffff) {
      SetFilePointer(hFile,0,(PLONG)0x0,2);
      FUN_0044c9e0("\r\n\r\n****** Exception Log Start ******\r\n\r\n");
      local_72c = (int *)*param_1;
      iVar6 = param_1[1];
      pcVar3 = "Unknown";
      local_730 = (undefined4 *)iVar6;
      SVar4 = VirtualQuery(*(LPCVOID *)(iVar6 + 0xb8),&local_760,0x1c);
      uVar5 = extraout_ECX;
      if ((SVar4 != 0) &&
         (DVar2 = GetModuleFileNameA(local_760.AllocationBase,local_340,0x104),
         uVar5 = extraout_ECX_00, DVar2 != 0)) {
        pcVar3 = _strrchr(local_340,0x5c);
        uVar5 = extraout_ECX_01;
        if (pcVar3 == (char *)0x0) {
          pcVar3 = local_340;
        }
        else {
          pcVar3 = pcVar3 + 1;
        }
      }
      uVar5 = FUN_0044cf70(uVar5,pcVar3,*(undefined4 *)(iVar6 + 0xbc),*(undefined4 *)(iVar6 + 0xb8))
      ;
      FUN_0044c9e0("%s caused %s in module %s at %04x:%08x.\r\n",local_130,uVar5);
      FUN_0044cd00();
      if ((*local_72c == -0x3ffffffb) && (1 < (uint)local_72c[4])) {
        pcVar3 = "Read from";
        if (local_72c[5] != 0) {
          pcVar3 = "Write to";
        }
        wsprintfA(&local_728,"%s location %08x caused an access violation.\r\n",pcVar3,local_72c[6])
        ;
        FUN_0044c9e0(&DAT_00bfc638,&local_728);
      }
      FUN_0044c9e0(&DAT_00bfc63c);
      FUN_0044c9e0("Registers:\r\n");
      FUN_0044c9e0("EAX=%08x CS=%04x EIP=%08x EFLGS=%08x\r\n",*(undefined4 *)(iVar6 + 0xb0),
                   *(undefined4 *)(iVar6 + 0xbc),*(undefined4 *)(iVar6 + 0xb8),
                   *(undefined4 *)(iVar6 + 0xc0));
      FUN_0044c9e0("EBX=%08x SS=%04x ESP=%08x EBP=%08x\r\n",*(undefined4 *)(iVar6 + 0xa4),
                   *(undefined4 *)(iVar6 + 200),*(undefined4 *)(iVar6 + 0xc4),
                   *(undefined4 *)(iVar6 + 0xb4));
      FUN_0044c9e0("ECX=%08x DS=%04x ESI=%08x FS=%04x\r\n",*(undefined4 *)(iVar6 + 0xac),
                   *(undefined4 *)(iVar6 + 0x98),*(undefined4 *)(iVar6 + 0xa0),
                   *(undefined4 *)(iVar6 + 0x90));
      FUN_0044c9e0("EDX=%08x ES=%04x EDI=%08x GS=%04x\r\n",*(undefined4 *)(iVar6 + 0xa8),
                   *(undefined4 *)(iVar6 + 0x94),*(undefined4 *)(iVar6 + 0x9c),
                   *(undefined4 *)(iVar6 + 0x8c));
      FUN_0044c9e0("Bytes at CS:EIP:\r\n");
      local_740 = *(int *)(iVar6 + 0xb8);
      for (iVar10 = 0; local_72c = (int *)iVar10, iVar10 < 0x10; iVar10 = iVar10 + 1) {
        local_8 = 0;
        FUN_0044c9e0("%02x ",*(undefined1 *)(iVar10 + local_740));
        local_8 = 0xfffffffe;
      }
      FUN_0044c9e0("\r\nStack dump:\r\n");
      local_8 = 1;
      puVar11 = *(undefined4 **)(iVar6 + 0xc4);
      local_72c = StackBase;
      if (puVar11 + 0x800 < StackBase) {
        local_72c = puVar11 + 0x800;
      }
      local_738 = 0;
      local_728 = '\0';
      local_744 = puVar11;
      _memset(local_727,0,999);
      do {
        pCVar9 = &local_728;
        do {
          local_730 = puVar11 + 1;
          local_734 = pCVar9;
          if (local_72c < local_730) {
            FUN_0044c9e0(&DAT_00bfc638,&local_728);
            local_8 = 0xfffffffe;
            FUN_0044cc60(hFile);
            FUN_0044c9e0("\r\n\r\n****** Game Log Start ******\r\n\r\n");
            CloseHandle(hFile);
            puVar1 = (uint *)local_1c;
            goto LAB_0044d65e;
          }
          uVar8 = local_738 & 0x80000007;
          bVar12 = uVar8 == 0;
          if ((int)uVar8 < 0) {
            bVar12 = (uVar8 - 1 | 0xfffffff8) == 0xffffffff;
          }
          if (bVar12) {
            iVar6 = wsprintfA(pCVar9,"%08x: ",puVar11);
            local_734 = pCVar9 + iVar6;
          }
          pCVar9 = local_734;
          puVar7 = &DAT_00bfafb8;
          local_738 = local_738 + 1;
          uVar8 = local_738 & 0x80000007;
          bVar12 = uVar8 == 0;
          if ((int)uVar8 < 0) {
            bVar12 = (uVar8 - 1 | 0xfffffff8) == 0xffffffff;
          }
          if ((bVar12) || (local_72c < puVar11 + 2)) {
            puVar7 = &DAT_00bfc63c;
          }
          iVar6 = wsprintfA(local_734,"%08x%s",*puVar11,puVar7);
          puVar11 = local_730;
          pCVar9 = pCVar9 + iVar6;
          local_744 = local_730;
        } while (pCVar9 <= local_372);
        local_734 = pCVar9;
        FUN_0044c9e0(&DAT_00bfc638,&local_728);
        local_728 = '\0';
      } while( true );
    }
    OutputDebugStringA("Error creating exception report");
    puVar1 = (uint *)local_1c;
  }
LAB_0044d65e:
  local_1c = (undefined1 *)puVar1;
  ExceptionList = local_14;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffffc);
  return;
}

