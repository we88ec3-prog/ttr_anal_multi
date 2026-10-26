
void FUN_004d74c0(int param_1)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  wchar_t *_Str2;
  int iVar5;
  uint uVar6;
  short *psVar7;
  undefined2 *in_ECX;
  short *in_EDX;
  uint uVar8;
  wchar_t ****_Str1;
  int iVar9;
  int *unaff_FS_OFFSET;
  int local_38;
  wchar_t ***local_34;
  wchar_t ***local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b538;
  local_10 = *unaff_FS_OFFSET;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_20 = 0;
  local_30[0] = (wchar_t ***)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  psVar7 = in_EDX;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  local_14 = uVar3;
  FUN_00402160(in_EDX,(int)psVar7 - (int)(in_EDX + 1) >> 1);
  local_8 = 0;
  _Str1 = (wchar_t ****)local_30[0];
  if (local_1c < 8) {
    _Str1 = local_30;
  }
  uVar2 = *(ushort *)_Str1;
  while (uVar2 != 0) {
    if (uVar2 - 0x41 < 0x1a) {
      uVar2 = uVar2 + 0x20;
    }
    local_38 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (local_38 != 0) {
      iVar9 = 0;
      local_34 = (wchar_t ***)_Str1;
      do {
        puVar4 = (ushort *)(*(int *)(param_1 + 4) + iVar9);
        if (7 < *(uint *)(puVar4 + 10)) {
          puVar4 = *(ushort **)puVar4;
        }
        if (uVar2 == *puVar4) {
          _Str2 = (wchar_t *)(*(int *)(param_1 + 4) + iVar9);
          if (7 < *(uint *)(_Str2 + 10)) {
            _Str2 = *(wchar_t **)_Str2;
          }
          iVar5 = __wcsnicmp((wchar_t *)_Str1,_Str2,
                             *(size_t *)(*(int *)(param_1 + 4) + 0x10 + iVar9));
          if (iVar5 == 0) {
            uVar8 = 0;
            if (*(int *)(iVar9 + 0x10 + *(int *)(param_1 + 4)) != 0) {
              do {
                uVar6 = FUN_0089289d();
                uVar6 = uVar6 & 0x80000001;
                if ((int)uVar6 < 0) {
                  uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
                }
                if (uVar6 == 0) {
                  *(ushort *)((int)local_34 + uVar8 * 2) = 0x25cb;
                }
                else if (uVar6 == 1) {
                  *(ushort *)((int)local_34 + uVar8 * 2) = 0x25cf;
                }
                uVar8 = uVar8 + 1;
              } while (uVar8 < *(uint *)(iVar9 + 0x10 + *(int *)(param_1 + 4)));
            }
            _Str1 = (wchar_t ****)
                    ((int)local_34 + (*(int *)(iVar9 + 0x10 + *(int *)(param_1 + 4)) + -1) * 2);
            local_34 = (wchar_t ***)_Str1;
          }
        }
        iVar9 = iVar9 + 0x1c;
        local_38 = local_38 + -1;
      } while (local_38 != 0);
    }
    puVar4 = (ushort *)((int)_Str1 + 2);
    _Str1 = (wchar_t ****)((int)_Str1 + 2);
    uVar2 = *puVar4;
  }
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  if (local_20 == 0) {
    *in_ECX = 0;
    psVar7 = in_EDX;
    do {
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar1 != 0);
    FUN_00402160(in_EDX,(int)psVar7 - (int)(in_EDX + 1) >> 1);
  }
  else {
    *in_ECX = 0;
    FUN_00402800(local_30);
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30[0],uVar3);
  }
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

