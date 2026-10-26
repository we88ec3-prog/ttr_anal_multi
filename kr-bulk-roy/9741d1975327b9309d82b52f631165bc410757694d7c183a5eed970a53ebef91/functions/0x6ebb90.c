
/* WARNING: Removing unreachable block (ram,0x006ec10f) */
/* WARNING: Removing unreachable block (ram,0x006ebcb1) */
/* WARNING: Removing unreachable block (ram,0x006ec017) */
/* WARNING: Removing unreachable block (ram,0x006ebffa) */

void FUN_006ebb90(int *param_1,undefined4 param_2,undefined4 param_3)

{
  WCHAR WVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  bool bVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  LPWSTR pWVar11;
  undefined4 *in_ECX;
  LPWSTR pWVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint local_134;
  uint local_130;
  uint local_128;
  int local_120;
  undefined1 local_110 [12];
  int local_104;
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  undefined4 local_f0 [4];
  WCHAR local_e0 [100];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f3ab;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 != (int *)0x0) || (param_1 = (int *)FUN_006dfb80(local_18), param_1 != (int *)0x0)) {
    *in_ECX = param_1;
    in_ECX[1] = param_2;
    in_ECX[2] = param_3;
    FUN_006ec800();
    local_8 = 0;
    local_f0[0] = 0x16;
    local_f0[1] = 0x18;
    local_f0[2] = 0x17;
    local_f0[3] = 0x23;
    uVar5 = (**(code **)(*param_1 + 0x10))(param_1);
    local_128 = 0;
    if (uVar5 != 0) {
      do {
        iVar15 = 0;
        puVar6 = (uint *)FUN_00891268(0x668);
        if (puVar6 == (uint *)0x0) goto LAB_006ec11a;
        puVar6[0x194] = 0;
        puVar6[0x195] = 0;
        puVar6[0x196] = 0;
        puVar6[0x197] = 0;
        puVar6[0x198] = 0;
        puVar6[0x199] = 0;
        *puVar6 = local_128;
        (**(code **)(*param_1 + 0x14))(param_1,local_128,0,puVar6 + 1);
        local_120 = 0;
        local_130 = 0;
        do {
          uVar2 = local_f0[local_130];
          uVar7 = (**(code **)(*param_1 + 0x18))(param_1,local_128,uVar2);
          local_134 = 0;
          if (uVar7 != 0) {
            do {
              (**(code **)(*param_1 + 0x1c))(param_1,local_128,uVar2,local_134,&local_100);
              if ((((((uint)in_ECX[0xe] <= local_100) && ((uint)in_ECX[0x10] <= local_fc)) &&
                   (local_100 <= (uint)in_ECX[0xf])) &&
                  ((local_fc <= (uint)in_ECX[0x11] && ((uint)in_ECX[0x12] <= local_f8)))) &&
                 (local_f8 <= (uint)in_ECX[0x13])) {
                iVar8 = FUN_006ed140();
                if (-1 < iVar8) {
                  puVar9 = (uint *)(puVar6[0x195] * 0x10 + puVar6[0x194]);
                  *puVar9 = local_100;
                  puVar9[1] = local_fc;
                  puVar9[2] = local_f8;
                  puVar9[3] = local_f4;
                  puVar6[0x195] = puVar6[0x195] + 1;
                }
                if (0 < iVar15) {
                  iVar8 = 0;
                  do {
                    if (local_f4 == *(uint *)(iVar8 * 4)) {
                      if (iVar8 != -1) goto LAB_006ebe36;
                      break;
                    }
                    iVar8 = iVar8 + 1;
                  } while (iVar8 < iVar15);
                }
                iVar8 = FUN_006ed1c0();
                iVar15 = local_120;
                if (-1 < iVar8) {
                  *(uint *)(local_120 * 4) = local_f4;
                  iVar15 = local_120 + 1;
                  local_120 = iVar15;
                }
              }
LAB_006ebe36:
              local_134 = local_134 + 1;
            } while (local_134 < uVar7);
          }
          local_130 = local_130 + 1;
        } while (local_130 < 4);
        (**(code **)(*param_1 + 0x20))(param_1,local_128,local_110);
        if (0 < iVar15) {
          iVar8 = 0;
          do {
            if (local_104 == *(int *)(iVar8 * 4)) {
              if (iVar8 != -1) goto LAB_006ebedb;
              break;
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar15);
        }
        iVar15 = FUN_006ed1c0();
        if (-1 < iVar15) {
          *(int *)(local_120 * 4) = local_104;
        }
LAB_006ebedb:
        _qsort((void *)puVar6[0x194],puVar6[0x195],0x10,FUN_006ec9e0);
        iVar15 = FUN_006ec140(in_ECX,puVar6);
        if ((iVar15 < 0) || ((int)puVar6[0x198] < 1)) {
          FUN_006eca30();
          FUN_0089120c(puVar6);
        }
        else {
          iVar15 = FUN_006ed1c0();
          if (iVar15 < 0) goto LAB_006ec11a;
          *(uint **)(in_ECX[0x15] + in_ECX[0x16] * 4) = puVar6;
          in_ECX[0x16] = in_ECX[0x16] + 1;
        }
        local_128 = local_128 + 1;
      } while (local_128 < uVar5);
    }
    iVar15 = 0;
    bVar4 = true;
    if (0 < (int)in_ECX[0x16]) {
      iVar8 = 1;
      do {
        iVar13 = *(int *)(in_ECX[0x15] + iVar15 * 4);
        if (iVar8 < (int)in_ECX[0x16]) {
          iVar14 = iVar8;
          do {
            iVar10 = __stricmp((char *)(iVar13 + 0x204),
                               (char *)(*(int *)(in_ECX[0x15] + iVar14 * 4) + 0x204));
            if (iVar10 == 0) {
              bVar4 = false;
              goto LAB_006ec034;
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 < (int)in_ECX[0x16]);
        }
        iVar15 = iVar15 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar15 < (int)in_ECX[0x16]);
    }
LAB_006ec034:
    iVar15 = 0;
    if (0 < (int)in_ECX[0x16]) {
LAB_006ec043:
      puVar3 = *(undefined4 **)(in_ECX[0x15] + iVar15 * 4);
      pWVar11 = (LPWSTR)(puVar3 + 0x114);
      MultiByteToWideChar(0,0,(LPCSTR)(puVar3 + 0x81),-1,pWVar11,100);
      *(undefined2 *)(puVar3 + 0x146) = 0;
      if (!bVar4) {
        FUN_006ead50(local_e0,L" (#%d)",*puVar3);
        iVar8 = 0x100;
        pWVar12 = pWVar11;
        do {
          if (*pWVar12 == L'\0') {
            if (iVar8 != 0) {
              iVar13 = 0x100 - (0x100 - iVar8);
              pWVar11 = pWVar11 + (0x100 - iVar8);
              if (iVar13 == 0) goto LAB_006ec0ed;
              iVar8 = 0x7fffffff;
              iVar14 = (int)local_e0 - (int)pWVar11;
              goto LAB_006ec0d0;
            }
            break;
          }
          pWVar12 = pWVar12 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      goto LAB_006ec0f5;
    }
  }
LAB_006ec11a:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
  while( true ) {
    *pWVar11 = WVar1;
    pWVar11 = pWVar11 + 1;
    iVar8 = iVar8 + -1;
    iVar13 = iVar13 + -1;
    if (iVar13 == 0) break;
LAB_006ec0d0:
    if ((iVar8 == 0) || (WVar1 = *(WCHAR *)(iVar14 + (int)pWVar11), WVar1 == L'\0')) {
      if (iVar13 != 0) goto LAB_006ec0f0;
      break;
    }
  }
LAB_006ec0ed:
  pWVar11 = pWVar11 + -1;
LAB_006ec0f0:
  *pWVar11 = L'\0';
LAB_006ec0f5:
  iVar15 = iVar15 + 1;
  if ((int)in_ECX[0x16] <= iVar15) goto LAB_006ec11a;
  goto LAB_006ec043;
}

