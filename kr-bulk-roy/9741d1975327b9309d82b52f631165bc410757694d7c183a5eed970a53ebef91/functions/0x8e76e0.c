
void FUN_008e76e0(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  size_t _Size;
  int iVar6;
  int iVar7;
  void *_Dst;
  int iVar8;
  byte *pbVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  size_t local_34;
  char *local_30;
  int local_2c;
  void *local_28;
  int local_24;
  int *local_20;
  char local_19;
  int local_18;
  int local_14;
  undefined4 *local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar8 = param_2[4];
  puVar4 = *(undefined4 **)(param_1 + 0x1e8);
  local_2c = param_1;
  local_30 = (char *)param_2[2];
  local_20 = param_2;
  local_24 = 0;
  local_19 = '\0';
  local_10 = puVar4;
  iVar6 = (*(code *)param_2[9])(param_2);
  if (iVar6 < 0) {
LAB_008e772f:
    param_2[3] = 3;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((iVar6 == 0) || (param_2[3] != 0)) goto LAB_008e7cc4;
  if (param_2[0x26] == 0) {
    local_28 = (void *)(iVar6 + 6);
    local_14 = (**(code **)*puVar4)(param_2 + 0x34,local_28,iVar8);
    iVar7 = local_14;
    if (((local_14 == 0) &&
        (local_14 = (**(code **)*puVar4)(param_2 + 0x27,local_28,iVar8), iVar7 = local_14,
        local_14 == 0)) &&
       (local_14 = (**(code **)*puVar4)(param_2 + 0x41,4,iVar8), iVar7 = local_14, local_14 == 0))
    goto LAB_008e77c2;
  }
  else {
LAB_008e77c2:
    local_18 = 0;
    (*(code *)param_2[7])(param_2);
    pcVar10 = (char *)*param_2;
    pcVar11 = local_30;
    if (pcVar10 < local_30) {
      do {
        if ((pcVar10 + 3 < pcVar11) &&
           (((((cVar2 = pcVar10[3], cVar2 == ' ' || (cVar2 == '\r')) ||
              ((cVar2 == '\n' || ((cVar2 == '\t' || (cVar2 == '\f')))))) ||
             (((cVar2 == '\0' ||
               ((((cVar2 == '/' || (cVar2 == '(')) || (cVar2 == ')')) ||
                ((cVar2 == '<' || (cVar2 == '>')))))) ||
              ((((cVar2 == '[' || ((cVar2 == ']' || (cVar2 == '{')))) || (cVar2 == '}')) ||
               (cVar2 == '%')))))) &&
            (((((*pcVar10 == 'd' && (pcVar10[1] == 'e')) && (pcVar10[2] == 'f')) && (local_18 != 0))
             || (((*pcVar10 == 'e' && (pcVar10[1] == 'n')) && (pcVar10[2] == 'd')))))))) break;
        (*(code *)param_2[8])(param_2);
        if (param_2[3] != 0) goto LAB_008e7cc4;
        if (*pcVar10 == '/') {
          pcVar10 = pcVar10 + 1;
          if (pcVar11 <= pcVar10) goto LAB_008e772f;
          iVar5 = *param_2;
          iVar7 = FUN_008e7060(&local_34,&local_28,*(int *)(*(int *)(local_2c + 0x80) + 0x30) != 0);
          piVar1 = local_20;
          if (iVar7 == 0) goto LAB_008e7cc4;
          param_2 = local_20;
          pcVar11 = local_30;
          if (local_20[0x26] == 0) {
            local_14 = (*(code *)local_20[0x32])
                                 (local_20 + 0x27,local_18,pcVar10,(iVar5 - (int)pcVar10) + 1);
            _Size = local_34;
            iVar7 = local_14;
            param_2 = local_20;
            if (local_14 != 0) goto LAB_008e7cc1;
            *(undefined1 *)((iVar5 - (int)pcVar10) + *(int *)(piVar1[0x2d] + local_18 * 4)) = 0;
            if (*pcVar10 == '.') {
              pbVar9 = *(byte **)(piVar1[0x2d] + local_18 * 4);
              pcVar10 = ".notdef";
              do {
                bVar3 = *pcVar10;
                bVar12 = bVar3 < *pbVar9;
                if (bVar3 != *pbVar9) {
LAB_008e7923:
                  iVar7 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                  goto LAB_008e7928;
                }
                if (bVar3 == 0) break;
                bVar3 = pcVar10[1];
                bVar12 = bVar3 < pbVar9[1];
                if (bVar3 != pbVar9[1]) goto LAB_008e7923;
                pcVar10 = pcVar10 + 2;
                pbVar9 = pbVar9 + 2;
              } while (bVar3 != 0);
              iVar7 = 0;
LAB_008e7928:
              if (iVar7 == 0) {
                local_24 = local_18;
                local_19 = '\x01';
              }
            }
            if ((*(int *)(local_2c + 0xac) < 0) || (iVar6 + 5 <= local_18)) {
              local_14 = (*(code *)local_20[0x3f])(local_20 + 0x34,local_18,local_28,local_34);
            }
            else {
              if ((int)local_34 <= *(int *)(local_2c + 0xac)) {
                iVar7 = 3;
                goto LAB_008e7cc1;
              }
              _Dst = (void *)FUN_008baee0(iVar8,local_34,&local_14);
              iVar7 = local_14;
              param_2 = local_20;
              if (local_14 != 0) goto LAB_008e7cc1;
              FID_conflict__memcpy(_Dst,local_28,_Size);
              (*(code *)local_10[4])(_Dst,_Size,0x10ea);
              local_34 = _Size - *(int *)(local_2c + 0xac);
              local_14 = (*(code *)local_20[0x3f])
                                   (local_20 + 0x34,local_18,*(int *)(local_2c + 0xac) + (int)_Dst,
                                    local_34);
              FUN_008b9f80(iVar8,_Dst);
            }
            iVar7 = local_14;
            param_2 = local_20;
            if (local_14 != 0) goto LAB_008e7cc1;
            local_18 = local_18 + 1;
            pcVar11 = local_30;
          }
        }
        (*(code *)param_2[7])(param_2);
        pcVar10 = (char *)*param_2;
      } while (pcVar10 < pcVar11);
    }
    param_2[0x26] = local_18;
    if (local_19 == '\0') {
      local_10 = (undefined4 *)0xde1f78b;
      local_c = 0xe;
      local_14 = (*(code *)param_2[0x4c])
                           (param_2 + 0x41,0,*(undefined4 *)param_2[0x2d],
                            *(undefined4 *)param_2[0x2e]);
      iVar7 = local_14;
      if (local_14 == 0) {
        local_14 = (*(code *)param_2[0x4c])
                             (param_2 + 0x41,1,*(undefined4 *)param_2[0x3a],
                              *(undefined4 *)param_2[0x3b]);
        iVar7 = local_14;
        if ((((local_14 == 0) &&
             (local_14 = (*(code *)param_2[0x32])(param_2 + 0x27,0,".notdef",8), iVar7 = local_14,
             local_14 == 0)) &&
            (local_14 = (*(code *)param_2[0x3f])(param_2 + 0x34,0,&local_10,5), iVar7 = local_14,
            local_14 == 0)) &&
           ((local_14 = (*(code *)param_2[0x32])
                                  (param_2 + 0x27,local_18,*(undefined4 *)param_2[0x47],
                                   *(undefined4 *)param_2[0x48]), iVar7 = local_14, local_14 == 0 &&
            (iVar7 = (*(code *)param_2[0x3f])
                               (param_2 + 0x34,local_18,*(undefined4 *)(param_2[0x47] + 4),
                                *(undefined4 *)(param_2[0x48] + 4)), iVar7 == 0)))) {
          param_2[0x26] = param_2[0x26] + 1;
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
    else {
      pcVar10 = ".notdef";
      pbVar9 = *(byte **)param_2[0x2d];
      do {
        bVar3 = *pcVar10;
        bVar12 = bVar3 < *pbVar9;
        if (bVar3 != *pbVar9) {
LAB_008e7a50:
          iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_008e7a55;
        }
        if (bVar3 == 0) break;
        bVar3 = pcVar10[1];
        bVar12 = bVar3 < pbVar9[1];
        if (bVar3 != pbVar9[1]) goto LAB_008e7a50;
        pcVar10 = pcVar10 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar3 != 0);
      iVar8 = 0;
LAB_008e7a55:
      if (iVar8 == 0) goto LAB_008e7cc4;
      piVar1 = param_2 + 0x41;
      local_14 = (*(code *)param_2[0x4c])
                           (piVar1,0,*(byte **)param_2[0x2d],*(undefined4 *)param_2[0x2e]);
      iVar7 = local_14;
      if (local_14 == 0) {
        local_14 = (*(code *)param_2[0x4c])
                             (piVar1,1,*(undefined4 *)param_2[0x3a],*(undefined4 *)param_2[0x3b]);
        iVar7 = local_14;
        if ((((local_14 == 0) &&
             (local_14 = (*(code *)param_2[0x4c])
                                   (piVar1,2,*(undefined4 *)(param_2[0x2d] + local_24 * 4),
                                    *(undefined4 *)(param_2[0x2e] + local_24 * 4)), iVar7 = local_14
             , local_14 == 0)) &&
            ((local_14 = (*(code *)param_2[0x4c])
                                   (piVar1,3,*(undefined4 *)(param_2[0x3a] + local_24 * 4),
                                    *(undefined4 *)(param_2[0x3b] + local_24 * 4)), iVar7 = local_14
             , local_14 == 0 &&
             (((local_14 = (*(code *)param_2[0x32])
                                     (param_2 + 0x27,local_24,*(undefined4 *)param_2[0x47],
                                      *(undefined4 *)param_2[0x48]), iVar7 = local_14, local_14 == 0
               && (local_14 = (*(code *)param_2[0x3f])
                                        (param_2 + 0x34,local_24,*(undefined4 *)(param_2[0x47] + 4),
                                         *(undefined4 *)(param_2[0x48] + 4)), iVar7 = local_14,
                  local_14 == 0)) &&
              (local_14 = (*(code *)param_2[0x32])
                                    (param_2 + 0x27,0,*(undefined4 *)(param_2[0x47] + 8),
                                     *(undefined4 *)(param_2[0x48] + 8)), iVar7 = local_14,
              local_14 == 0)))))) &&
           (iVar7 = (*(code *)param_2[0x3f])
                              (param_2 + 0x34,0,*(undefined4 *)(param_2[0x47] + 0xc),
                               *(undefined4 *)(param_2[0x48] + 0xc)), iVar7 == 0)) {
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
  }
LAB_008e7cc1:
  param_2[3] = iVar7;
LAB_008e7cc4:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

