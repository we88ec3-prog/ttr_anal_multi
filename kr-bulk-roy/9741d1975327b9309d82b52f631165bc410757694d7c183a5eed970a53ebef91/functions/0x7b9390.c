
void FUN_007b9390(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  LPCSTR lpCaption;
  char *pcVar5;
  int iVar6;
  int in_ECX;
  char *_Str1;
  undefined4 *_Src;
  undefined4 *_Src_00;
  uint uVar7;
  undefined4 *_Dst;
  int local_48;
  int local_44;
  undefined4 *local_40;
  char *local_3c;
  int *local_38;
  undefined4 *local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938076;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x3c) == 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(local_14);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    if ((DAT_00fb76a8 != 0) && (*(int *)(in_ECX + 0x40) != 0)) {
      FUN_007e5610();
      FUN_007b8970();
      FUN_007dddc0();
      uVar2 = FUN_00434740();
      piVar3 = (int *)FUN_0079a5f0(uVar2);
      (**(code **)(*piVar3 + 0xec))(piVar3,1,&local_38);
      (**(code **)(*local_38 + 0x10))(local_38);
      FUN_007e26d0();
      (**(code **)(*local_38 + 0x14))(local_38);
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 8))(local_38);
        local_38 = (int *)0x0;
      }
      local_34 = *(undefined4 **)(in_ECX + 0x7c);
      if (local_34 != *(undefined4 **)(in_ECX + 0x80)) {
        _Src_00 = local_34 + 1;
        local_40 = _Src_00;
        do {
          local_3c = (char *)*local_34;
          pcVar5 = local_3c;
          if (0xf < *(uint *)(local_3c + 0x14)) {
            pcVar5 = *(char **)local_3c;
          }
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = local_30[0] & 0xffffff00;
          pcVar4 = pcVar5;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar5,(int)pcVar4 - (int)(pcVar5 + 1));
          local_8 = 1;
          local_48 = FUN_007b6f30(local_30);
          if ((local_48 == *(int *)(in_ECX + 0x70)) || (cVar1 = FUN_0049ae30(), cVar1 != '\0')) {
            local_44 = *(int *)(in_ECX + 0x70);
            piVar3 = &local_44;
          }
          else {
            piVar3 = &local_48;
          }
          iVar6 = *piVar3;
          local_8 = 0xffffffff;
          if (0xf < local_1c) {
            FUN_0089120c(local_30[0]);
          }
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = local_30[0] & 0xffffff00;
          if (iVar6 == *(int *)(in_ECX + 0x70)) {
            lpCaption = local_3c;
            if (0xf < *(uint *)(local_3c + 0x14)) {
              lpCaption = *(LPCSTR *)local_3c;
            }
            MessageBoxA((HWND)0x0,&DAT_00c4fbc0,lpCaption,0);
            if (_Src_00 != *(undefined4 **)(in_ECX + 0x80)) {
              _Src = _Src_00 + 1;
              _Dst = _Src_00;
              do {
                pcVar5 = (char *)FUN_007e4440();
                iVar6 = __stricmp(_Str1,pcVar5);
                if (iVar6 == 0) {
                  FID_conflict__memcpy(_Dst,_Src,(*(int *)(in_ECX + 0x80) - (int)_Src >> 2) * 4);
                  *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + -4;
                }
                else {
                  _Dst = _Dst + 1;
                  _Src = _Src + 1;
                }
                _Src_00 = local_40;
              } while (_Dst != *(undefined4 **)(in_ECX + 0x80));
            }
            FID_conflict__memcpy(local_34,_Src_00,(*(int *)(in_ECX + 0x80) - (int)_Src_00 >> 2) * 4)
            ;
            *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + -4;
          }
          else {
            FUN_007e34f0(&local_3c);
            local_3c[0x4c] = '\x01';
            local_3c[0x4d] = '\0';
            local_3c[0x4e] = '\0';
            local_3c[0x4f] = '\0';
            local_3c[0x50] = '\x01';
            local_3c[0x51] = '\0';
            local_3c[0x52] = '\0';
            local_3c[0x53] = '\0';
            FUN_007e46c0();
            local_34 = local_34 + 1;
            _Src_00 = _Src_00 + 1;
            local_40 = _Src_00;
          }
        } while (local_34 != *(undefined4 **)(in_ECX + 0x80));
      }
      FUN_007e0ab0();
      uVar7 = 0;
      if (*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2 != 0) {
        do {
          FUN_007e4680(in_ECX);
          uVar7 = uVar7 + 1;
        } while (uVar7 < (uint)(*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2));
      }
      FUN_007e2e40(in_ECX + 0x90);
      uVar7 = 0;
      if (*(int *)(in_ECX + 0xa8) - *(int *)(in_ECX + 0xa4) >> 2 != 0) {
        do {
          iVar6 = *(int *)(*(int *)(in_ECX + 0xa4) + uVar7 * 4);
          uVar2 = FUN_007bad20(DAT_00fba838,iVar6,*(undefined4 *)(iVar6 + 0xc),
                               *(undefined4 *)(iVar6 + 0x30));
          *(undefined4 *)(iVar6 + 0x34) = uVar2;
          uVar7 = uVar7 + 1;
        } while (uVar7 < (uint)(*(int *)(in_ECX + 0xa8) - *(int *)(in_ECX + 0xa4) >> 2));
      }
      FUN_007baf50();
      *(undefined4 *)(in_ECX + 0x3c) = 1;
      goto LAB_007b96b7;
    }
  }
  local_8 = 0xffffffff;
LAB_007b96b7:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

