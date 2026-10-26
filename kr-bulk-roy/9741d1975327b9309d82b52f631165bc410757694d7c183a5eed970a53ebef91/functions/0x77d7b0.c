
void FUN_0077d7b0(void)

{
  LPCWSTR pWVar1;
  WCHAR WVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *****pppppuVar5;
  int iVar6;
  int *piVar7;
  void *pvVar8;
  LPCWSTR pWVar9;
  char *_Str1;
  int iVar10;
  int in_ECX;
  LPCWSTR name;
  char *****_Str2;
  void *local_5c;
  int local_58;
  undefined4 ****local_54 [4];
  undefined4 local_44;
  uint local_40;
  char ****appppcStack_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00921398;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_5c;
  ExceptionList = &local_14;
  local_58 = in_ECX;
  uVar4 = FUN_00764fb0(*(undefined4 *)(in_ECX + 8),DAT_00d61f20 ^ (uint)&stack0xffffff98);
  *(undefined4 *)(in_ECX + 8) = uVar4;
  FUN_004297b0();
  pppppuVar5 = (undefined4 *****)local_54[0];
  if (local_40 < 0x10) {
    pppppuVar5 = local_54;
  }
  iVar6 = FUN_0072e2e0(pppppuVar5);
  if (0xf < local_40) {
    FUN_0089120c(local_54[0]);
  }
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = (undefined4 ****)((uint)local_54[0] & 0xffffff00);
  while (iVar6 != 0) {
    local_5c = (void *)0x0;
    FUN_00429860(&local_5c);
    if (local_5c == (void *)0xf619) {
      local_5c = _malloc(0x84);
      uStack_c = 0;
      if (local_5c == (void *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)FUN_00772b20(local_5c);
      }
      uStack_c = 0xffffffff;
      if (piVar7 != (int *)0x0) {
        local_5c = (void *)0x0;
        FUN_00429860(&local_5c);
        pvVar8 = (void *)(**(code **)(*piVar7 + 4))();
        if ((local_5c != pvVar8) || (cVar3 = (**(code **)(*piVar7 + 0x14))(iVar6), cVar3 == '\0'))
        break;
        name = (LPCWSTR)(piVar7 + 0x10);
        pWVar9 = name;
        if (7 < (uint)piVar7[0x15]) {
          pWVar9 = *(LPCWSTR *)name;
        }
        pWVar1 = pWVar9 + 1;
        do {
          WVar2 = *pWVar9;
          pWVar9 = pWVar9 + 1;
        } while (WVar2 != L'\0');
        if ((int)pWVar9 - (int)pWVar1 >> 1 != 0) {
          if (7 < (uint)piVar7[0x15]) {
            name = *(LPCWSTR *)name;
          }
          AddFontResourceExW(name,0x10,(PVOID)0x0);
        }
        iVar10 = local_58;
        if (*(int *)(local_58 + 0x14) != 0) {
          local_5c = *(void **)(local_58 + 0x10);
          FUN_0053f8a0();
        }
        FUN_0077d6f0(iVar10,piVar7);
      }
    }
    FUN_004297b0();
    _Str2 = (char *****)appppcStack_38[0];
    if (uStack_24 < 0x10) {
      _Str2 = appppcStack_38;
    }
    for (iVar6 = *(int *)(iVar6 + 0x40); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x40)) {
      _Str1 = (char *)(iVar6 + 0x20);
      if (0xf < *(uint *)(iVar6 + 0x34)) {
        _Str1 = *(char **)_Str1;
      }
      iVar10 = __stricmp(_Str1,(char *)_Str2);
      if (iVar10 == 0) goto LAB_0077d9a2;
    }
    iVar6 = 0;
LAB_0077d9a2:
    if (0xf < uStack_24) {
      FUN_0089120c(appppcStack_38[0]);
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    appppcStack_38[0] = (char ****)((uint)appppcStack_38[0] & 0xffffff00);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_5c);
  return;
}

