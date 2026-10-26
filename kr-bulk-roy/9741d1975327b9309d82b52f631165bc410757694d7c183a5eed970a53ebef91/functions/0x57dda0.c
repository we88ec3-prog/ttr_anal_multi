
void FUN_0057dda0(void)

{
  char cVar1;
  ushort uVar2;
  void *_Dst;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  float *pfVar6;
  float *pfVar7;
  undefined4 uVar8;
  char ******ppppppcVar9;
  char *_Str2;
  uint uVar10;
  int in_ECX;
  float *pfVar11;
  char ******ppppppcVar12;
  int iVar13;
  undefined1 auStack_bc [4];
  float fStack_b8;
  float *local_b4;
  int *local_b0;
  int *local_ac;
  float *local_a8;
  int local_a4;
  float *local_a0;
  float *local_9c;
  float local_98;
  undefined4 *local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  char *****local_78 [4];
  float *local_68;
  uint local_64;
  uint local_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  char *****local_38 [5];
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092e3fa;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_bc;
  ExceptionList = &local_14;
  local_a4 = in_ECX;
  if (*(int *)(in_ECX + 0x8c) == 0) {
    if ((DAT_00fe2878 & 1) == 0) {
      DAT_00fe2878 = DAT_00fe2878 | 1;
      local_c = 0;
      FUN_0052b6c0(DAT_00d61f20 ^ (uint)&stack0xffffff38);
      _atexit((_func_4879 *)&LAB_00bcf300);
    }
    local_c = 0xffffffff;
    local_ac = *(int **)(in_ECX + 0xc0);
    FUN_008438c0(&local_ac);
    if (local_b4 == (float *)DAT_00fe2884) goto LAB_0057e46b;
    iVar13 = (int)local_b4[4];
    local_ac = (int *)(iVar13 + 0xc);
    if (local_ac == (int *)0x0) goto LAB_0057e46b;
    *(undefined4 *)(in_ECX + 0x8c) = 1;
    local_b4 = (float *)0x0;
    local_a8 = (float *)(*(int *)(iVar13 + 0x10) - *local_ac >> 2);
    if (0 < (int)local_a8) {
      do {
        iVar13 = local_a4;
        pfVar6 = local_b4;
        if ((undefined4 *)(local_ac[1] - *local_ac >> 2) <= local_b4) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        pfVar11 = *(float **)(*local_ac + (int)local_b4 * 4);
        local_9c = pfVar11 + 3;
        FUN_008438c0(local_9c);
        if (local_b0 == *(int **)(iVar13 + 0x11c)) {
          puVar5 = (undefined4 *)FUN_00891268(0x10);
          if (puVar5 == (undefined4 *)0x0) {
            puVar5 = (undefined4 *)0x0;
          }
          else {
            *puVar5 = 0;
            puVar5[1] = 0;
            puVar5[2] = 0;
          }
          _Dst = (void *)*puVar5;
          if (_Dst != (void *)puVar5[1]) {
            local_a0 = (float *)0x0;
            FID_conflict__memcpy(_Dst,(void *)puVar5[1],0);
            puVar5[1] = (int)_Dst + (int)local_a0;
          }
          local_a0 = (float *)FUN_00891268(8);
          if (local_a0 == (float *)0x0) {
            local_a0 = (float *)0x0;
          }
          else {
            uVar2 = *(ushort *)(pfVar11 + 2);
            *local_a0 = *pfVar11;
            local_a0[1] = (float)(uint)uVar2;
          }
          FUN_00443d10();
          local_98 = *local_9c;
          iVar13 = local_a4 + 0x118;
          local_94 = puVar5;
          uVar8 = FUN_0057ef20();
          FUN_0057e850(iVar13,uVar8);
        }
        else {
          local_b4 = (float *)FUN_00891268(8);
          if (local_b4 == (float *)0x0) {
            local_b4 = (float *)0x0;
            FUN_00443d10();
            local_b4 = pfVar6;
          }
          else {
            uVar2 = *(ushort *)(pfVar11 + 2);
            *local_b4 = *pfVar11;
            local_b4[1] = (float)(uint)uVar2;
            FUN_00443d10();
            local_b4 = pfVar6;
          }
        }
        local_b4 = (float *)((int)local_b4 + 1);
        in_ECX = local_a4;
      } while ((int)local_b4 < (int)local_a8);
    }
  }
  if (*(int *)(in_ECX + 0x114) == 0) {
    *(undefined4 *)(in_ECX + 0x114) = 1;
    local_b0 = (int *)**(int **)(in_ECX + 0x11c);
    if (local_b0 != *(int **)(in_ECX + 0x11c)) {
      do {
        local_b4 = *(float **)local_b0[4];
        local_ac = (int *)0x0;
        if (local_b4 != (float *)*(undefined4 **)(local_b0[4] + 4)) {
          local_88 = 0;
          local_84 = 0;
          local_80 = 0x20;
          local_7c = 0x20;
          local_90 = 0x3f200000;
          local_8c = 0x3f200000;
          do {
            puVar5 = (undefined4 *)*local_b4;
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c = 1;
              FUN_0051c120();
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = 0xffffffff;
            }
            pfVar6 = (float *)FUN_0051d700(*puVar5);
            FUN_0057e820("Product_{0}_{1}_{2}",local_b0[3]);
            local_c = 2;
            FUN_00401cc0(local_54,"Data_",local_38);
            local_c._0_1_ = 3;
            if ((DAT_00f94394 & 1) == 0) {
              DAT_00f94394 = DAT_00f94394 | 1;
              local_c._0_1_ = 4;
              FUN_005c3de0();
              _atexit((_func_4879 *)&LAB_00bccc30);
              local_c._0_1_ = 3;
            }
            local_c._0_1_ = 3;
            if (DAT_00f943e4 != 0) {
              pfVar11 = (float *)(*(float **)(DAT_00f943e4 + 0xc))[1];
              cVar1 = *(char *)((int)pfVar11 + 0x15);
              local_a8 = *(float **)(DAT_00f943e4 + 0xc);
              while (cVar1 == '\0') {
                if ((uint)pfVar11[3] < (uint)*pfVar6) {
                  pfVar7 = (float *)pfVar11[2];
                  pfVar11 = local_a8;
                }
                else {
                  pfVar7 = (float *)*pfVar11;
                }
                local_a8 = pfVar11;
                pfVar11 = pfVar7;
                cVar1 = *(char *)((int)pfVar7 + 0x15);
              }
              if ((local_a8 == *(float **)(DAT_00f943e4 + 0xc)) ||
                 ((uint)*pfVar6 < (uint)local_a8[3])) {
                local_9c = *(float **)(DAT_00f943e4 + 0xc);
              }
            }
            uVar8 = FUN_00557de0();
            iVar13 = local_a4;
            local_c._0_1_ = 5;
            FUN_005752e0(*(undefined4 *)(local_a4 + 4),uVar8);
            local_c._0_1_ = 3;
            if (7 < local_64) {
              FUN_0089120c(local_78[0]);
            }
            ppppppcVar12 = (char ******)local_38[0];
            if (local_24 < 0x10) {
              ppppppcVar12 = local_38;
            }
            local_64 = 0xf;
            local_68 = (float *)0x0;
            local_78[0] = (char *****)((uint)local_78[0] & 0xffffff00);
            ppppppcVar9 = ppppppcVar12;
            do {
              cVar1 = *(char *)ppppppcVar9;
              ppppppcVar9 = (char ******)((int)ppppppcVar9 + 1);
            } while (cVar1 != '\0');
            FUN_0040b310(ppppppcVar12);
            piVar3 = *(int **)(iVar13 + 4);
            local_c = CONCAT31(local_c._1_3_,6);
            iVar13 = *piVar3;
            fStack_b8 = (float)FUN_00575df0(local_78);
            if (fStack_b8 == *(float *)(iVar13 + 4)) {
LAB_0057e292:
              local_98 = *(float *)(iVar13 + 4);
              pfVar6 = &local_98;
            }
            else {
              local_a0 = *(float **)((int)fStack_b8 + 0x1c);
              _Str2 = (char *)((int)fStack_b8 + 0xc);
              if (0xf < *(uint *)((int)fStack_b8 + 0x20)) {
                _Str2 = *(char **)_Str2;
              }
              local_a8 = local_68;
              pfVar6 = local_68;
              if (local_a0 <= local_68) {
                pfVar6 = local_a0;
              }
              ppppppcVar12 = (char ******)local_78[0];
              if (local_64 < 0x10) {
                ppppppcVar12 = local_78;
              }
              uVar10 = __strnicmp((char *)ppppppcVar12,_Str2,(size_t)pfVar6);
              if (uVar10 == 0) {
                if (local_a8 < local_a0) {
                  uVar10 = 0xffffffff;
                }
                else {
                  uVar10 = (uint)(local_a8 != local_a0);
                }
              }
              if ((int)uVar10 < 0) goto LAB_0057e292;
              pfVar6 = &fStack_b8;
            }
            if (*pfVar6 != *(float *)(*piVar3 + 4)) {
              *(undefined4 *)((int)*pfVar6 + 0x28) = 0;
            }
            piVar3[6] = piVar3[6] + 1;
            local_c = CONCAT31(local_c._1_3_,3);
            if (0xf < local_64) {
              FUN_0089120c(local_78[0]);
            }
            FUN_00573510(local_54,1);
            FUN_005736d0(local_54,0);
            FUN_00573320(local_54,&local_88);
            FUN_00573420(local_54,&local_90);
            piVar3 = local_ac;
            fStack_b8 = (float)(((int)local_ac % 5) * 0x16) + 842.0;
            FUN_00573230(fStack_b8,
                         (float)(local_b0[3] * 0x2f) + 163.0 + (float)(((int)local_ac / 5) * 0x15));
            local_ac = (int *)((int)piVar3 + 1);
            if (0xf < uStack_40) {
              FUN_0089120c(local_54[0]);
            }
            local_c = 0xffffffff;
            uStack_40 = 0xf;
            uStack_44 = 0;
            local_54[0] = local_54[0] & 0xffffff00;
            if (0xf < local_24) {
              FUN_0089120c(local_38[0]);
            }
            local_b4 = local_b4 + 1;
          } while (local_b4 != (float *)*(undefined4 **)(local_b0[4] + 4));
        }
        if (*(char *)((int)local_b0 + 0x15) == '\0') {
          piVar3 = (int *)local_b0[2];
          if (*(char *)((int)piVar3 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            local_b0 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x15);
              local_b0 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(local_b0[1] + 0x15);
            piVar4 = (int *)local_b0[1];
            piVar3 = local_b0;
            while ((local_b0 = piVar4, cVar1 == '\0' && (piVar3 == (int *)local_b0[2]))) {
              cVar1 = *(char *)(local_b0[1] + 0x15);
              piVar4 = (int *)local_b0[1];
              piVar3 = local_b0;
            }
          }
        }
      } while (local_b0 != *(int **)(local_a4 + 0x11c));
    }
  }
LAB_0057e46b:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_bc);
  return;
}

