
/* WARNING: Removing unreachable block (ram,0x008c2a25) */

void FUN_008c26b0(int param_1,int *param_2,int param_3)

{
  uint *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  int in_ECX;
  int iVar8;
  int in_EDX;
  size_t sVar9;
  int iVar10;
  int iVar11;
  void *_Src;
  size_t sVar12;
  size_t _Size;
  int iVar13;
  int iVar14;
  void *pvVar15;
  int local_5c;
  size_t local_58;
  int local_50;
  char local_4a;
  char local_49;
  int *local_48;
  int local_44;
  undefined4 local_40;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar3 = *(undefined4 *)(in_ECX + 8);
  local_4a = 0;
  local_49 = '\0';
  if (*(int *)(in_EDX + 0x48) != *(int *)(in_ECX + 0x10)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (param_1 == param_3) {
    if (param_2 != (int *)0x0) {
      FUN_008b94d0(in_EDX + 0x6c,*param_2,param_2[1]);
    }
    local_4a = param_2 != (int *)0x0;
    FUN_008b9440(in_EDX + 0x6c,&local_18);
    local_18 = local_18 & 0xffffffc0;
    local_14 = local_14 & 0xffffffc0;
    local_10 = local_10 + 0x3f & 0xffffffc0;
    local_c = local_c + 0x3f & 0xffffffc0;
    if (((int)local_18 < 0) && ((int)(local_18 + 0x7fffffff) < (int)local_10)) {
      local_50 = 0x62;
    }
    else {
      sVar12 = (int)(local_10 - local_18) >> 6;
      if (((int)local_14 < 0) && ((int)(local_14 + 0x7fffffff) < (int)local_c)) {
        local_50 = 0x62;
      }
      else {
        iVar13 = (int)(local_c - local_14) >> 6;
        if ((*(byte *)(*(int *)(in_EDX + 0x9c) + 4) & 1) != 0) {
          FUN_008b9f80(uVar3,*(undefined4 *)(in_EDX + 0x58));
          *(undefined4 *)(in_EDX + 0x58) = 0;
          puVar1 = (uint *)(*(int *)(in_EDX + 0x9c) + 4);
          *puVar1 = *puVar1 & 0xfffffffe;
        }
        uVar5 = local_14;
        uVar4 = local_18;
        _Size = sVar12;
        local_58 = sVar12;
        if (param_1 == 3) {
          local_58 = sVar12 * 3;
          _Size = local_58 + 3 & 0xfffffffc;
        }
        iVar14 = iVar13;
        if (param_1 == 4) {
          iVar14 = iVar13 * 3;
        }
        iVar10 = (int)local_18 >> 6;
        iVar8 = (int)local_c >> 6;
        if (((int)local_58 < 0x8000) && (iVar14 < 0x8000)) {
          *(undefined2 *)(in_EDX + 0x5c) = 0x100;
          *(undefined1 *)(in_EDX + 0x5e) = 2;
          *(size_t *)(in_EDX + 0x50) = local_58;
          *(int *)(in_EDX + 0x4c) = iVar14;
          *(size_t *)(in_EDX + 0x54) = _Size;
          FUN_008b94d0(in_EDX + 0x6c,-local_18,-local_14);
          uVar6 = FUN_008baee0(uVar3,_Size * iVar14,&local_50);
          *(undefined4 *)(in_EDX + 0x58) = uVar6;
          if (local_50 == 0) {
            puVar1 = (uint *)(*(int *)(in_EDX + 0x9c) + 4);
            *puVar1 = *puVar1 | 1;
            local_44 = in_EDX + 0x6c;
            local_40 = 1;
            local_49 = '\x01';
            local_48 = (int *)(in_EDX + 0x4c);
            local_50 = (**(code **)(in_ECX + 0x38))(*(undefined4 *)(in_ECX + 0x34),&local_48);
            if (local_50 == 0) {
              if ((param_1 == 3) && (iVar13 != 0)) {
                iVar11 = *(int *)(in_EDX + 0x58) + -1;
                local_5c = iVar13;
                do {
                  if (sVar12 != 0) {
                    puVar7 = (undefined1 *)((local_58 - 1) + iVar11);
                    sVar9 = sVar12;
                    do {
                      uVar2 = *(undefined1 *)(iVar11 + sVar9);
                      puVar7[-1] = uVar2;
                      *puVar7 = uVar2;
                      puVar7[1] = uVar2;
                      puVar7 = puVar7 + -3;
                      sVar9 = sVar9 - 1;
                    } while (sVar9 != 0);
                  }
                  local_5c = local_5c + -1;
                  iVar11 = iVar11 + _Size;
                } while (local_5c != 0);
              }
              if (param_1 == 4) {
                pvVar15 = *(void **)(in_EDX + 0x58);
                _Src = (void *)((int)pvVar15 + (iVar14 - iVar13) * _Size);
                local_50 = 0;
                for (; iVar13 != 0; iVar13 = iVar13 + -1) {
                  FID_conflict__memcpy(pvVar15,_Src,_Size);
                  FID_conflict__memcpy((void *)((int)pvVar15 + _Size),_Src,_Size);
                  pvVar15 = (void *)((int)((int)pvVar15 + _Size) + _Size);
                  FID_conflict__memcpy(pvVar15,_Src,_Size);
                  pvVar15 = (void *)((int)pvVar15 + _Size);
                  _Src = (void *)((int)_Src + _Size);
                }
              }
              *(undefined4 *)(in_EDX + 0x48) = 0x62697473;
              *(int *)(in_EDX + 100) = iVar10;
              *(int *)(in_EDX + 0x68) = iVar8;
              local_49 = '\0';
              local_50 = 0;
            }
          }
          FUN_008b94d0(in_EDX + 0x6c,uVar4,uVar5);
        }
        else {
          local_50 = 0x62;
        }
      }
    }
    if (local_4a != '\0') {
      FUN_008b94d0(in_EDX + 0x6c,-*param_2,-param_2[1]);
    }
    if (local_49 != '\0') {
      FUN_008b9f80(uVar3,*(undefined4 *)(in_EDX + 0x58));
      *(undefined4 *)(in_EDX + 0x58) = 0;
      puVar1 = (uint *)(*(int *)(in_EDX + 0x9c) + 4);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

