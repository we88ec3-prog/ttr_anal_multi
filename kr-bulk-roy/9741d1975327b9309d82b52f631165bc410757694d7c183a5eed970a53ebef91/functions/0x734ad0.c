
undefined4 FUN_00734ad0(uint *param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint in_EAX;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint in_ECX;
  int iVar9;
  int iVar10;
  char *pcVar11;
  uint *local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (((int)in_EAX < 0) || ((int)in_ECX < 0)) {
    return 0;
  }
  if ((param_1[4] < in_EAX) || (param_1[5] < in_ECX)) {
    return 0;
  }
  local_8 = ((*param_1 - 1) + in_EAX) / *param_1;
  local_14 = ((param_1[1] - 1) + in_ECX) / param_1[1];
  if (local_8 == 0) {
    local_8 = 1;
  }
  if (local_14 == 0) {
    local_14 = 1;
  }
  uVar2 = param_1[2];
  *param_2 = -1;
  param_2[1] = -1;
  uVar3 = param_1[3];
  iVar10 = 0;
  if (0 < (int)(uVar3 - local_14)) {
    local_18 = param_1 + 6;
    local_10 = 0;
    do {
      if ((int)local_8 <= (int)*local_18) {
        iVar7 = iVar10 + local_14;
        local_c = 0;
        if (0 < (int)(uVar2 - local_8)) {
          do {
            cVar1 = *(char *)((int)param_1 + local_c + local_10 + 0x118);
            if (cVar1 == '\0') {
              FID_conflict__wprintf("Err#1\n");
              break;
            }
            uVar5 = (uint)cVar1;
            if ((int)uVar5 < (int)local_8) {
              uVar5 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f);
            }
            else {
              uVar5 = param_1[2];
              bVar4 = true;
              if (iVar7 <= iVar10) goto LAB_00734c8f;
              pcVar11 = (char *)(local_10 + local_c + 0x118 + (int)param_1);
              iVar9 = iVar7 - iVar10;
              do {
                uVar6 = (uint)*pcVar11;
                if ((int)uVar6 < (int)local_8) {
                  uVar6 = (uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f);
                  bVar4 = false;
                  if ((int)uVar6 <= (int)uVar5) {
                    uVar5 = uVar6;
                  }
                }
                pcVar11 = pcVar11 + 0x20;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
              if (bVar4) {
                if (iVar10 < iVar7) {
                  iVar7 = iVar7 - iVar10;
                  iVar9 = iVar10 * 0x20 + local_c + 0x118 + (int)param_1;
                  do {
                    iVar8 = 0;
                    if (0 < (int)local_8) {
                      do {
                        *(char *)(iVar9 + iVar8) = (char)iVar8 - (char)local_8;
                        iVar8 = iVar8 + 1;
                      } while (iVar8 < (int)local_8);
                    }
                    iVar9 = iVar9 + 0x20;
                    iVar7 = iVar7 + -1;
                  } while (iVar7 != 0);
                }
LAB_00734c8f:
                FUN_00734a50(local_c,local_8,local_14);
                uVar2 = param_1[1];
                *param_2 = *param_1 * local_c;
                param_2[1] = uVar2 * iVar10;
                return 1;
              }
            }
            local_c = local_c + uVar5;
          } while (local_c < (int)(uVar2 - local_8));
        }
      }
      local_18 = local_18 + 1;
      local_10 = local_10 + 0x20;
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)(uVar3 - local_14));
  }
  return 0;
}

