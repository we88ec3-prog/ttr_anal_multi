
void FUN_008c2030(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  int iVar5;
  uint local_15c;
  int local_158;
  int local_154;
  int local_150;
  int *local_14c;
  int local_148;
  int local_144;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_008c12a0();
  iVar1 = *(int *)(unaff_ESI + 0x400);
  if ((((iVar1 < *(int *)(unaff_ESI + 0xc)) &&
       (*(int *)(unaff_ESI + 8) < *(int *)(unaff_ESI + 0x408))) &&
      (*(int *)(unaff_ESI + 0x404) < *(int *)(unaff_ESI + 0x14))) &&
     (*(int *)(unaff_ESI + 0x10) < *(int *)(unaff_ESI + 0x40c))) {
    if (*(int *)(unaff_ESI + 8) < iVar1) {
      *(int *)(unaff_ESI + 8) = iVar1;
    }
    if (*(int *)(unaff_ESI + 0x10) < *(int *)(unaff_ESI + 0x404)) {
      *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x404);
    }
    if (*(int *)(unaff_ESI + 0x408) < *(int *)(unaff_ESI + 0xc)) {
      *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0x408);
    }
    if (*(int *)(unaff_ESI + 0x40c) < *(int *)(unaff_ESI + 0x14)) {
      *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x40c);
    }
    *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0xc) - *(int *)(unaff_ESI + 8);
    local_150 = *(int *)(unaff_ESI + 0x14) - *(int *)(unaff_ESI + 0x10);
    *(int *)(unaff_ESI + 0x1c) = local_150;
    local_150 = local_150 / *(int *)(unaff_ESI + 0x4e0);
    if (local_150 == 0) {
      local_150 = 1;
    }
    if (0x26 < local_150) {
      local_150 = 0x27;
    }
    local_14c = *(int **)(unaff_ESI + 0x10);
    iVar1 = *(int *)(unaff_ESI + 0x14);
    *(undefined4 *)(unaff_ESI + 0x4e4) = 0;
    local_154 = 0;
    if (0 < local_150) {
      do {
        local_158 = (int)local_14c + *(int *)(unaff_ESI + 0x4e0);
        if ((local_154 == local_150 + -1) || (iVar1 < local_158)) {
          local_158 = iVar1;
        }
        local_148 = (int)local_14c;
        local_144 = local_158;
        local_14c = &local_148;
        do {
          iVar5 = local_14c[1] - *local_14c;
          *(undefined4 *)(unaff_ESI + 0x530) = *(undefined4 *)(unaff_ESI + 0x528);
          local_15c = iVar5 * 4;
          *(int *)(unaff_ESI + 0x534) = iVar5;
          if ((local_15c & 0xf) != 0) {
            local_15c = local_15c + (0x10 - (local_15c & 0xf));
          }
          uVar2 = (*(int *)(unaff_ESI + 0x528) - (*(uint *)(unaff_ESI + 0x52c) & 0xf)) +
                  *(uint *)(unaff_ESI + 0x52c);
          local_15c = local_15c + *(int *)(unaff_ESI + 0x528);
          *(uint *)(unaff_ESI + 0x2c) = local_15c;
          if ((local_15c < uVar2) &&
             (iVar3 = (int)(uVar2 - local_15c) >> 4, *(int *)(unaff_ESI + 0x30) = iVar3, 1 < iVar3))
          {
            iVar3 = 0;
            if (0 < iVar5) {
              do {
                *(undefined4 *)(*(int *)(unaff_ESI + 0x530) + iVar3 * 4) = 0;
                iVar3 = iVar3 + 1;
              } while (iVar3 < *(int *)(unaff_ESI + 0x534));
            }
            iVar5 = local_14c[1];
            *(int *)(unaff_ESI + 0x10) = *local_14c;
            *(int *)(unaff_ESI + 0x14) = iVar5;
            iVar5 = local_14c[1];
            iVar3 = *local_14c;
            *(undefined4 *)(unaff_ESI + 0x34) = 0;
            *(undefined4 *)(unaff_ESI + 0x28) = 1;
            *(int *)(unaff_ESI + 0x1c) = iVar5 - iVar3;
            iVar5 = FUN_008c1fd0();
            if (iVar5 != 0) {
              if (iVar5 != 0x40) goto LAB_008c237d;
              goto LAB_008c22b5;
            }
            FUN_008c1ed0();
            local_14c = local_14c + -2;
          }
          else {
LAB_008c22b5:
            iVar5 = *local_14c;
            iVar3 = local_14c[1];
            iVar4 = (iVar3 - iVar5 >> 1) + iVar5;
            if (iVar4 == iVar5) {
LAB_008c237d:
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
              return;
            }
            if (*(int *)(unaff_ESI + 0x4e0) <= iVar5 - iVar3) {
              *(int *)(unaff_ESI + 0x4e4) = *(int *)(unaff_ESI + 0x4e4) + 1;
            }
            local_14c[2] = iVar5;
            local_14c[3] = iVar4;
            *local_14c = iVar4;
            local_14c[1] = iVar3;
            local_14c = local_14c + 2;
          }
        } while (&local_148 <= local_14c);
        local_154 = local_154 + 1;
        local_14c = (int *)local_158;
      } while (local_154 < local_150);
    }
    if ((8 < *(int *)(unaff_ESI + 0x4e4)) && (0x10 < *(int *)(unaff_ESI + 0x4e0))) {
      *(int *)(unaff_ESI + 0x4e0) = *(int *)(unaff_ESI + 0x4e0) / 2;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

