
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cfe80(int param_1)

{
  char cVar1;
  int *piVar2;
  float fVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  LONG LVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  float fVar12;
  uint uVar13;
  float10 fVar14;
  float10 fVar15;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  HWND pHVar16;
  UINT UVar17;
  undefined **local_50 [3];
  int local_44;
  tagPOINT local_40;
  tagPOINT local_38;
  char *local_30;
  char *local_2c;
  tagRECT local_28;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926955;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = param_1;
  local_18 = uVar7;
  if ((_DAT_00fc1a6c & 1) == 0) {
    _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
    _atexit((_func_4879 *)&DAT_00bce3b0);
  }
  FUN_006f3350(&local_28.top);
  GetCursorPos(&local_40);
  LVar8 = local_28.right;
  if ((local_28.top != 0) || (local_28.right != 0)) {
    fVar3 = (float)(local_28.right * local_28.right) + (float)(local_28.top * local_28.top);
    fVar12 = (float)(0x5f375a86 - ((int)fVar3 >> 1));
    fVar14 = (float10)((float)*(int *)(param_1 + 4) * fVar12 * (1.5 - fVar12 * fVar12 * fVar3 * 0.5)
                      );
    local_38.y = (LONG)(float)(fVar14 * (float10)local_28.top);
    fVar15 = (float10)local_28.right;
    local_2c = (char *)(float)(fVar15 * fVar14);
    fVar14 = (float10)0;
    if (0 < local_28.top) {
      if (fVar14 <= (float10)local_28.top - (float10)(float)local_38.y) {
        local_28.top = FUN_008fed10(uVar7);
        fVar14 = fVar15;
      }
      else {
        local_28.top = FUN_008fed10(uVar7);
        fVar14 = fVar15;
      }
    }
    if (local_28.top < 0) {
      local_28.top = FUN_008fed10(uVar7);
      fVar14 = extraout_ST1;
    }
    fVar15 = (float10)(float)local_2c;
    if (0 < LVar8) {
      LVar8 = FUN_008fed10();
      fVar15 = extraout_ST1_00;
      fVar14 = extraout_ST0;
      local_28.right = LVar8;
    }
    if (LVar8 < 0) {
      if (fVar15 + (float10)local_28.right <= fVar14) {
        local_28.right = FUN_008fed10();
      }
      else {
        local_28.right = FUN_008fed10();
      }
    }
  }
  fVar3 = (float)(0x8000 - *(int *)(param_1 + 4));
  local_38.y = (LONG)((float)local_28.top / fVar3);
  local_30 = (char *)((float)local_28.right / fVar3);
  uVar7 = local_38.y & 0x80000000;
  uVar13 = (uint)local_30 & 0x80000000;
  local_2c = local_30;
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 0;
    FUN_006ccd20();
    _atexit((_func_4879 *)&LAB_00bce3c0);
    local_8 = 0xffffffff;
  }
  fVar14 = (float10)FUN_006d06a0(local_38.y);
  local_38.y = (LONG)(float)fVar14;
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 1;
    FUN_006ccd20();
    _atexit((_func_4879 *)&LAB_00bce3c0);
    local_8 = 0xffffffff;
  }
  local_30 = (char *)local_38.y;
  local_38.y = local_38.y | uVar7;
  fVar14 = (float10)FUN_006d06a0(local_2c);
  pcVar4 = (char *)(float)_DAT_00f744c8;
  local_2c = (char *)(1.0 - (float)pcVar4);
  local_38.y = (LONG)((float)local_2c * (float)local_38.y);
  if ((float)local_38.y <= 0.0) {
    local_30 = local_2c;
    if ((float)local_38.y < 0.0) {
      local_38.y = (LONG)((float)pcVar4 + (float)local_38.y);
      local_30 = pcVar4;
    }
  }
  else {
    local_38.y = (LONG)((float)local_38.y - (float)pcVar4);
    local_30 = pcVar4;
  }
  local_2c = (char *)((float)((uint)(float)fVar14 | uVar13) * (float)local_2c);
  if ((float)local_2c <= 0.0) {
    if ((float)local_2c < 0.0) {
      local_2c = (char *)((float)pcVar4 + (float)local_2c);
      local_30 = pcVar4;
    }
  }
  else {
    local_2c = (char *)((float)local_2c - (float)pcVar4);
    local_30 = pcVar4;
  }
  if ((local_28.top != 0) || (local_28.right != 0)) {
    iVar9 = FUN_008fed10();
    iVar10 = FUN_008fed10();
    local_38.x = 0;
    local_38.y = 0;
    GetClientRect(*(HWND *)(DAT_00fb1318 + 0x10),&local_28);
    ClientToScreen(*(HWND *)(DAT_00fb1318 + 0x10),&local_38);
    iVar9 = (local_40.x - iVar9) - local_38.x;
    local_40.y = (local_40.y - iVar10) - local_38.y;
    if (iVar9 < 0) {
      iVar9 = 0;
    }
    if (local_28.right + -1 < iVar9) {
      iVar9 = local_28.right + -1;
    }
    if (local_40.y < 0) {
      local_40.y = 0;
    }
    if (local_28.bottom + -1 < local_40.y) {
      local_40.y = local_28.bottom + -1;
    }
    local_40.x = iVar9 + local_38.x;
    local_40.y = local_40.y + local_38.y;
    SetCursorPos(local_40.x,local_40.y);
  }
  iVar9 = 4;
  piVar11 = (int *)(local_44 + 0xc);
  do {
    if (0 < piVar11[-1]) {
      piVar11[-1] = piVar11[-1] + -1;
    }
    if (0 < *piVar11) {
      *piVar11 = *piVar11 + -1;
    }
    if (0 < piVar11[1]) {
      piVar11[1] = piVar11[1] + -1;
    }
    if (0 < piVar11[2]) {
      piVar11[2] = piVar11[2] + -1;
    }
    piVar11 = piVar11 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 2;
    DAT_00fc1730 = 0;
    iVar9 = FUN_00891268(0x30);
    if (iVar9 == 0) {
      local_30 = (char *)0x0;
      std::exception::exception((exception *)local_50,&local_30);
      local_50[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_50,&DAT_00c857a8);
    }
    DAT_00fc172c = iVar9;
    *(int *)iVar9 = iVar9;
    *(int *)(DAT_00fc172c + 4) = DAT_00fc172c;
    *(int *)(DAT_00fc172c + 8) = DAT_00fc172c;
    *(undefined1 *)(DAT_00fc172c + 0x2c) = 1;
    *(undefined1 *)(DAT_00fc172c + 0x2d) = 1;
    local_8._0_1_ = 3;
    FUN_006ccc00(&DAT_00fc173c);
    local_8._0_1_ = 4;
    FUN_006ccc00(&DAT_00fc17bc);
    local_8 = CONCAT31(local_8._1_3_,5);
    DAT_00fc1778 = 1;
    FUN_006cd0e0();
    _atexit((_func_4879 *)&LAB_00bce3c0);
    local_8 = 0xffffffff;
  }
  local_2c = DAT_00fc1738;
  if (DAT_00fc1738 == (undefined *)0x0) {
    local_2c = &DAT_00fc173c;
  }
  piVar11 = (int *)**(int **)(local_2c + 100);
  iVar9 = DAT_00fba80c;
  if (piVar11 != *(int **)(local_2c + 100)) {
    do {
      iVar10 = piVar11[4];
      if (piVar11[5] == 1) {
        if (iVar9 == 0) {
          iVar9 = FUN_00891268(0x57c);
          if (iVar9 == 0) {
            iVar9 = 0;
            DAT_00fba80c = iVar9;
          }
          else {
            iVar9 = FUN_006f1370();
            DAT_00fba80c = iVar9;
          }
        }
        iVar5 = DAT_00fb1318;
        if ((*(int *)(iVar9 + 0x20) != 0) && (iVar10 - 9U < 0x80)) {
          cVar1 = *(char *)(iVar10 + 0x3ef + iVar9);
          if (cVar1 == '\x01') {
            if (*(int *)(local_44 + 0xc) < 1) {
              *(undefined4 *)(local_44 + 0xc) = 10;
              pHVar16 = *(HWND *)(iVar5 + 0x10);
              UVar17 = 0x201;
            }
            else {
              *(undefined4 *)(local_44 + 0xc) = 0;
              pHVar16 = *(HWND *)(DAT_00fb1318 + 0x10);
              UVar17 = 0x203;
            }
            SendMessageW(pHVar16,UVar17,local_40.x,local_40.y);
            if (DAT_00fba80c == 0) {
              iVar9 = FUN_00891268(0x57c);
              if (iVar9 != 0) {
                iVar9 = FUN_006f1370();
                DAT_00fba80c = iVar9;
                *(undefined1 *)(iVar9 + 0x368) = 1;
                goto LAB_006d062e;
              }
              DAT_00fba80c = 0;
            }
            iVar9 = DAT_00fba80c;
            *(undefined1 *)(DAT_00fba80c + 0x368) = 1;
          }
          else if (cVar1 == '\x02') {
            *(undefined1 *)(iVar9 + 0x368) = 2;
          }
          else if (cVar1 == '\x03') {
            SendMessageW(*(HWND *)(DAT_00fb1318 + 0x10),0x202,local_40.x,local_40.y);
            if (DAT_00fba80c == 0) {
              iVar9 = FUN_00891268(0x57c);
              if (iVar9 != 0) {
                iVar9 = FUN_006f1370();
                DAT_00fba80c = iVar9;
                *(undefined1 *)(iVar9 + 0x368) = 3;
                goto LAB_006d062e;
              }
              DAT_00fba80c = 0;
            }
            iVar9 = DAT_00fba80c;
            *(undefined1 *)(DAT_00fba80c + 0x368) = 3;
          }
        }
      }
      else if (piVar11[5] == 2) {
        if (iVar9 == 0) {
          iVar9 = FUN_00891268(0x57c);
          if (iVar9 == 0) {
            iVar9 = 0;
            DAT_00fba80c = iVar9;
          }
          else {
            iVar9 = FUN_006f1370();
            DAT_00fba80c = iVar9;
          }
        }
        iVar5 = DAT_00fb1318;
        if ((*(int *)(iVar9 + 0x20) != 0) && (iVar10 - 9U < 0x80)) {
          cVar1 = *(char *)(iVar10 + 0x3ef + iVar9);
          if (cVar1 == '\x01') {
            if (*(int *)(local_44 + 0x10) < 1) {
              *(undefined4 *)(local_44 + 0x10) = 10;
              pHVar16 = *(HWND *)(iVar5 + 0x10);
              UVar17 = 0x204;
            }
            else {
              *(undefined4 *)(local_44 + 0x10) = 0;
              pHVar16 = *(HWND *)(DAT_00fb1318 + 0x10);
              UVar17 = 0x206;
            }
            SendMessageW(pHVar16,UVar17,local_40.x,local_40.y);
            if (DAT_00fba80c == 0) {
              iVar9 = FUN_00891268(0x57c);
              if (iVar9 != 0) {
                iVar9 = FUN_006f1370();
                DAT_00fba80c = iVar9;
                *(undefined1 *)(iVar9 + 0x369) = 1;
                goto LAB_006d062e;
              }
              DAT_00fba80c = 0;
            }
            iVar9 = DAT_00fba80c;
            *(undefined1 *)(DAT_00fba80c + 0x369) = 1;
          }
          else if (cVar1 == '\x02') {
            *(undefined1 *)(iVar9 + 0x369) = 2;
          }
          else if (cVar1 == '\x03') {
            SendMessageW(*(HWND *)(DAT_00fb1318 + 0x10),0x205,local_40.x,local_40.y);
            if (DAT_00fba80c == 0) {
              iVar9 = FUN_00891268(0x57c);
              if (iVar9 == 0) {
                DAT_00fba80c = 0;
              }
              else {
                DAT_00fba80c = FUN_006f1370();
              }
            }
            iVar9 = DAT_00fba80c;
            *(undefined1 *)(DAT_00fba80c + 0x369) = 3;
          }
        }
      }
LAB_006d062e:
      if (*(char *)((int)piVar11 + 0x19) == '\0') {
        piVar2 = (int *)piVar11[2];
        if (*(char *)((int)piVar2 + 0x19) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar11 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x19);
            piVar11 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar11[1] + 0x19);
          piVar6 = (int *)piVar11[1];
          piVar2 = piVar11;
          while ((piVar11 = piVar6, cVar1 == '\0' && (piVar2 == (int *)piVar11[2]))) {
            cVar1 = *(char *)(piVar11[1] + 0x19);
            piVar6 = (int *)piVar11[1];
            piVar2 = piVar11;
          }
        }
      }
    } while (piVar11 != *(int **)(local_2c + 100));
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

