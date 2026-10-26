
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00743180(LPCWSTR param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  HANDLE hFile;
  DWORD dwMaximumSizeLow;
  HANDLE hFileMappingObject;
  int *lpBaseAddress;
  wchar_t *_Dst;
  uint uVar6;
  ushort uVar7;
  undefined4 in_ECX;
  int *piVar8;
  uint uVar9;
  ushort uVar10;
  int iVar11;
  undefined4 *puVar12;
  ushort uVar13;
  byte local_3064;
  char cStack_3062;
  byte local_3060;
  uint local_3058;
  int *local_3044;
  byte local_3040;
  byte bStack_303e;
  byte local_303c;
  byte bStack_303a;
  byte local_3038;
  undefined1 uStack_3036;
  uint local_3030;
  uint local_302c;
  UINT local_3028;
  int local_3024;
  undefined4 local_3020;
  undefined4 local_301c;
  uint local_3018;
  uint local_3014;
  WCHAR local_3010;
  undefined1 local_300e [8190];
  undefined2 local_1010;
  uint local_c;
  undefined4 uStack_8;
  
  uStack_8 = 0x74318d;
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  hFile = CreateFileW(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,4,0x8000080,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    dwMaximumSizeLow = GetFileSize(hFile,(LPDWORD)0x0);
    if ((dwMaximumSizeLow != 0xffffffff) &&
       (hFileMappingObject =
             CreateFileMappingW(hFile,(LPSECURITY_ATTRIBUTES)0x0,2,0,dwMaximumSizeLow,(LPCWSTR)0x0),
       hFileMappingObject != (HANDLE)0x0)) {
      lpBaseAddress = MapViewOfFile(hFileMappingObject,4,0,0,0);
      if (lpBaseAddress == (int *)0x0) {
        CloseHandle(hFileMappingObject);
        CloseHandle(hFile);
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
      piVar8 = (int *)0x0;
      if (*lpBaseAddress == 0x66637474) {
        piVar8 = lpBaseAddress;
      }
      local_302c = 1;
      local_3044 = (int *)0x0;
      if (piVar8 != (int *)0x0) {
        local_302c = (uint)CONCAT11((char)piVar8[2],*(undefined1 *)((int)piVar8 + 9)) << 0x10 |
                     (uint)*(byte *)((int)piVar8 + 10) << 8 | (uint)*(byte *)((int)piVar8 + 0xb);
        local_3044 = piVar8 + 3;
      }
      local_3030 = 0;
      if (local_302c == 0) {
LAB_0074385c:
        UnmapViewOfFile(lpBaseAddress);
        CloseHandle(hFileMappingObject);
        CloseHandle(hFile);
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
LAB_007432cc:
      iVar11 = 0;
      if (local_3044 != (int *)0x0) {
        iVar11 = CONCAT22(CONCAT11((char)local_3044[local_3030],
                                   *(undefined1 *)((int)local_3044 + local_3030 * 4 + 1)),
                          CONCAT11(*(undefined1 *)((int)local_3044 + local_3030 * 4 + 2),
                                   *(undefined1 *)((int)local_3044 + local_3030 * 4 + 3)));
      }
      uVar3 = *(undefined4 *)(iVar11 + 4 + (int)lpBaseAddress);
      uVar9 = *(uint *)(iVar11 + (int)lpBaseAddress);
      local_3060 = (byte)uVar3;
      local_3064 = (byte)uVar9;
      cStack_3062 = (char)(uVar9 >> 0x10);
      if (((ushort)((ushort)(uVar9 >> 8) & 0xff | (ushort)local_3064 << 8) == 1) &&
         ((uVar9 & 0xff000000) == 0 && cStack_3062 == '\0')) {
        _memset(&local_1010,0,0x1000);
        uVar9 = (uint)(ushort)((ushort)((uint)uVar3 >> 8) & 0xff | (ushort)local_3060 << 8);
        local_3024 = 0;
        if (uVar9 != 0) {
          puVar12 = (undefined4 *)(iVar11 + 0xc + (int)lpBaseAddress);
          while( true ) {
            local_301c = puVar12[1];
            local_3018 = puVar12[2];
            local_3020 = *puVar12;
            local_3014 = puVar12[3];
            puVar12 = puVar12 + 4;
            _strncpy_s((char *)&local_1010,0x1000,(char *)&local_3020,4);
            iVar11 = __stricmp((char *)&local_1010,"name");
            if (iVar11 == 0) break;
            if (((char)local_1010 == '\0') ||
               (local_3024 = local_3024 + 1, (int)uVar9 <= local_3024)) goto LAB_00743837;
          }
          local_3014 = ((uint)(ushort)((short)local_3014 << 8) | local_3014 >> 8 & 0xff) << 0x10 |
                       (uint)(ushort)((short)(local_3014 >> 0x10) << 8) | local_3014 >> 0x18;
          local_3018 = ((uint)(ushort)((short)local_3018 << 8) | local_3018 >> 8 & 0xff) << 0x10 |
                       (uint)(ushort)((short)(local_3018 >> 0x10) << 8) | local_3018 >> 0x18;
          uVar2 = *(ushort *)(local_3018 + 4 + (int)lpBaseAddress);
          local_3058 = (uint)(ushort)((ushort)(byte)((uint)*(undefined4 *)
                                                            (local_3018 + (int)lpBaseAddress) >>
                                                    0x18) |
                                     (short)((uint)*(undefined4 *)(local_3018 + (int)lpBaseAddress)
                                            >> 0x10) << 8);
          if (local_3058 != 0) {
            puVar12 = (undefined4 *)(local_3018 + 6 + (int)lpBaseAddress);
            goto LAB_007434f6;
          }
        }
        goto LAB_00743837;
      }
      goto LAB_007431de;
    }
    CloseHandle(hFile);
  }
LAB_007431de:
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
LAB_007434f6:
  do {
    uVar3 = *puVar12;
    uVar4 = puVar12[1];
    uVar5 = puVar12[2];
    local_3040 = (byte)uVar3;
    bStack_303e = (byte)((uint)uVar3 >> 0x10);
    puVar12 = puVar12 + 3;
    local_303c = (byte)uVar4;
    bStack_303a = (byte)((uint)uVar4 >> 0x10);
    uVar10 = (ushort)((uint)uVar3 >> 8) & 0xff | (ushort)local_3040 << 8;
    local_3038 = (byte)uVar5;
    uStack_3036 = (undefined1)((uint)uVar5 >> 0x10);
    uVar13 = (ushort)(CONCAT12(local_303c,(short)((uint)uVar3 >> 0x10)) >> 8) & 0xff |
             (ushort)bStack_303e << 8;
    uVar7 = (ushort)(CONCAT12(local_3038,(short)((uint)uVar4 >> 0x10)) >> 8) & 0xff |
            (ushort)bStack_303a << 8;
    if ((ushort)((ushort)((uint)uVar4 >> 8) & 0xff | (ushort)local_303c << 8) < 0x8000) {
      local_3028 = 0;
      if (uVar10 == 3) {
        if (uVar13 == 10) goto switchD_00743791_caseD_3;
        switch(uVar13) {
        case 2:
          local_3028 = 0x3a4;
          break;
        case 3:
          local_3028 = 0x3a8;
          break;
        case 4:
          local_3028 = 0x3b6;
          break;
        case 5:
          local_3028 = 0x3b5;
          break;
        case 6:
          local_3028 = 0x551;
        }
      }
      _Dst = (wchar_t *)FUN_007438c0(in_ECX);
      if ((((uVar7 == 0) || (uVar7 == 1)) || (uVar7 == 2)) || ((uVar7 == 4 || (uVar7 == 7)))) {
        _memset(&local_1010,0,0x1000);
        uVar9 = (uint)(ushort)((ushort)((uint)uVar5 >> 8) & 0xff | (ushort)local_3038 << 8);
        FID_conflict__memcpy
                  (&local_1010,
                   (void *)((uint)(ushort)(uVar2 >> 8 | uVar2 << 8) +
                            CONCAT11(uStack_3036,(char)((uint)uVar5 >> 0x18)) + local_3018 +
                           (int)lpBaseAddress),uVar9);
        local_3010 = L'\0';
        _memset(local_300e,0,0x1ffe);
        if ((uVar10 == 0) || ((uVar10 == 3 && (uVar13 == 1)))) {
          uVar6 = 0;
          if (uVar9 != 0) {
            do {
              if ((uVar6 & 1) == 0) {
                uVar1 = *(undefined1 *)((int)&local_1010 + uVar6);
                *(undefined1 *)((int)&local_1010 + uVar6) =
                     *(undefined1 *)((int)&local_1010 + uVar6 + 1);
                *(undefined1 *)((int)&local_1010 + uVar6 + 1) = uVar1;
              }
              uVar6 = uVar6 + 1;
            } while ((int)uVar6 < (int)uVar9);
          }
          _wcscpy_s(&local_3010,0x1000,&local_1010);
        }
        else {
          MultiByteToWideChar(local_3028,0,(LPCSTR)&local_1010,-1,&local_3010,0xfff);
        }
        if (local_3010 != L'\0') {
          switch(uVar7) {
          case 0:
            _Dst = _Dst + 0x400;
            break;
          case 1:
            _Dst = _Dst + 0xc00;
            break;
          case 2:
            _Dst = _Dst + 0x1000;
            break;
          default:
            goto switchD_00743791_caseD_3;
          case 4:
            break;
          case 7:
            _Dst = _Dst + 0x800;
          }
          _wcsncpy_s(_Dst,0x400,&local_3010,0x3ff);
        }
      }
    }
switchD_00743791_caseD_3:
    local_3058 = local_3058 - 1;
  } while (local_3058 != 0);
LAB_00743837:
  local_3030 = local_3030 + 1;
  if (local_302c <= local_3030) goto LAB_0074385c;
  goto LAB_007432cc;
}

