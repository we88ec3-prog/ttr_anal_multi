
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0088f683(undefined1 *param_1,istreambuf_iterator<char,std::char_traits<char>_> *param_2,
                 istreambuf_iterator<char,struct_std::char_traits<char>_> *param_3,char param_4,
                 int param_5)

{
  char cVar1;
  moneypunct<char,1> *pmVar2;
  istreambuf_iterator<char,std::char_traits<char>_> iVar3;
  bool bVar4;
  locale *plVar5;
  undefined4 uVar6;
  int iVar7;
  istreambuf_iterator<char,std::char_traits<char>_> *piVar8;
  istreambuf_iterator<char,std::char_traits<char>_> *piVar9;
  undefined1 local_1a0 [4];
  undefined1 local_19c [4];
  undefined4 local_198;
  undefined1 local_194 [4];
  char local_190 [4];
  undefined4 local_18c;
  int local_188;
  int local_184;
  uint local_180;
  int local_17c;
  moneypunct<char,1> *local_178;
  char local_171;
  istreambuf_iterator<char,struct_std::char_traits<char>_> *local_170;
  uint local_16c;
  char local_166;
  char local_165;
  undefined1 local_164 [28];
  undefined1 local_148 [28];
  undefined1 local_12c [28];
  undefined1 local_110 [28];
  undefined1 local_f4 [28];
  undefined1 local_d8 [28];
  undefined1 local_bc [28];
  undefined1 local_a0 [28];
  istreambuf_iterator<char,std::char_traits<char>_> *local_84 [4];
  int local_74;
  uint local_70;
  undefined1 local_68 [16];
  int local_58;
  undefined4 local_54;
  istreambuf_iterator<char,std::char_traits<char>_> *local_4c [4];
  uint local_3c;
  uint local_38;
  istreambuf_iterator<char,std::char_traits<char>_> *local_30 [4];
  int local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x198;
  local_8 = 0x88f692;
  local_16c = 0;
  local_170 = param_3;
  local_188 = param_5;
  if (param_4 == '\0') {
    plVar5 = (locale *)FUN_004318d0(local_19c);
    local_8 = 1;
    local_178 = (moneypunct<char,1> *)std::use_facet<std::moneypunct<char,0>_>(plVar5);
  }
  else {
    plVar5 = (locale *)FUN_004318d0(local_1a0);
    local_8 = 0;
    local_178 = std::use_facet<std::moneypunct<char,1>_>(plVar5);
  }
  FUN_004327c0();
  local_3c = 0;
  local_165 = '\0';
  local_171 = '\0';
  local_38 = 0xf;
  local_4c[0] = (istreambuf_iterator<char,std::char_traits<char>_> *)
                ((uint)local_4c[0] & 0xffffff00);
  local_58 = 0;
  local_54 = 0xf;
  local_68[0] = 0;
  local_8 = 3;
  (**(code **)(*(int *)local_178 + 0x24))(local_190);
  local_180 = 0;
  do {
    pmVar2 = local_178;
    if (3 < local_180) break;
    cVar1 = local_190[local_180];
    if (cVar1 == ' ') {
LAB_0088f797:
      if (local_180 != 3) {
        uVar6 = FUN_004318d0(local_194);
        local_8._0_1_ = 0xd;
        iVar7 = FUN_006de510(uVar6);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004327c0();
        while (bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                                 (param_2,local_170), !bVar4) {
          if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
            std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
          }
          if ((*(byte *)(*(int *)(iVar7 + 0x10) + (uint)(byte)param_2[5] * 2) & 0x48) == 0) break;
          std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
        }
      }
      goto LAB_0088fecb;
    }
    if (cVar1 == '$') {
      curr_symbol(local_30);
      local_8._0_1_ = 4;
      if (((*(byte *)(param_5 + 0x14) & 8) != 0) ||
         (bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_170),
         bVar4)) {
LAB_0088fdd2:
        if ((local_180 == 3) && (local_3c < 2)) {
          bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_170);
          if (!bVar4) {
            if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
              std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
            }
            piVar9 = local_30[0];
            if (local_1c < 0x10) {
              piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
            }
            if (param_2[5] == *piVar9) goto LAB_0088fe1d;
          }
          goto LAB_0088fe11;
        }
      }
      else {
        if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
        }
        piVar9 = local_30[0];
        if (local_1c < 0x10) {
          piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
        }
        if (param_2[5] == *piVar9) goto LAB_0088fdd2;
LAB_0088fe11:
        FUN_00402c80(0,0xffffffff);
      }
LAB_0088fe1d:
      piVar9 = local_30[0];
      if (local_1c < 0x10) {
        piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
      }
      while (bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                               (param_2,local_170), !bVar4) {
        piVar8 = local_30[0];
        if (local_1c < 0x10) {
          piVar8 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
        }
        if (piVar9 == piVar8 + local_20) break;
        if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
        }
        if (param_2[5] != *piVar9) break;
        std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
        piVar9 = piVar9 + 1;
      }
      piVar8 = local_30[0];
      if (local_1c < 0x10) {
        piVar8 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
      }
      if (piVar9 != piVar8 + local_20) {
        local_165 = '\x01';
      }
LAB_0088fe8c:
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00402f30(1,0);
    }
    else {
      if (cVar1 != '+') {
        if (cVar1 != 'v') {
          if (cVar1 == 'x') goto LAB_0088f797;
          goto LAB_0088fecb;
        }
        local_17c = 0;
        local_184 = (**(code **)(*(int *)local_178 + 0x1c))();
        grouping(local_84);
        local_8._0_1_ = 0xb;
        if ((local_74 == 0) ||
           (iVar3 = (istreambuf_iterator<char,std::char_traits<char>_>)
                    (**(code **)(*(int *)pmVar2 + 8))(),
           iVar3 == (istreambuf_iterator<char,std::char_traits<char>_>)0x0)) {
LAB_0088fa0b:
          while (bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                                   (param_2,local_170), !bVar4) {
            if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
              std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
            }
            if ((char)param_2[5] < '0') break;
            if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
              std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
            }
            if ('9' < (char)param_2[5]) break;
            if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
              std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
            }
            local_18c = CONCAT31(local_18c._1_3_,param_2[5]);
            FUN_00429630(1,local_18c);
            std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
          }
LAB_0088fa1c:
          iVar3 = (istreambuf_iterator<char,std::char_traits<char>_>)
                  (**(code **)(*(int *)local_178 + 4))();
          bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_170);
          if ((!bVar4) && (iVar3 != (istreambuf_iterator<char,std::char_traits<char>_>)0x0)) {
            if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
              std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
            }
            if (param_2[5] == iVar3) {
              while( true ) {
                std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
                bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                                  (param_2,local_170);
                if (bVar4) break;
                if (local_184 <= local_17c) goto LAB_0088faea;
                if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
                  std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
                }
                if ((char)param_2[5] < '0') break;
                if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
                  std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
                }
                if ('9' < (char)param_2[5]) break;
                if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
                  std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
                }
                FUN_00429630(1,param_2[5]);
                local_17c = local_17c + 1;
              }
              if (local_17c < local_184) {
                local_165 = '\x01';
              }
            }
          }
LAB_0088faea:
          if (local_58 == 0) {
            local_165 = '\x01';
          }
          else if (local_17c < local_184) {
            iVar7 = local_184 - local_17c;
            do {
              FUN_00429630(1,0x30);
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
        }
        else {
          piVar9 = local_84[0];
          if (local_70 < 0x10) {
            piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_84;
          }
          if (0x7e < (byte)*piVar9) goto LAB_0088fa0b;
          local_20 = 0;
          local_30[0] = (istreambuf_iterator<char,std::char_traits<char>_> *)
                        ((uint)local_30[0] & 0xffffff00);
          local_1c = 0xf;
          FUN_0046e1b0(1,0);
          local_8._0_1_ = 0xc;
          iVar7 = 0;
          bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_170);
          if (!bVar4) {
            do {
              if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
                std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
              }
              if ((char)param_2[5] < '0') {
LAB_0088f8cd:
                piVar9 = local_30[0];
                if (local_1c < 0x10) {
                  piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
                }
                if (piVar9[iVar7] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) break;
                if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
                  std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
                }
                if (param_2[5] != iVar3) break;
                FUN_00429630(1,0);
                iVar7 = iVar7 + 1;
              }
              else {
                if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
                  std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
                }
                if ('9' < (char)param_2[5]) goto LAB_0088f8cd;
                if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
                  std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
                }
                local_198 = CONCAT31(local_198._1_3_,param_2[5]);
                FUN_00429630(1,local_198);
                piVar9 = local_30[0];
                if (local_1c < 0x10) {
                  piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
                }
                if (piVar9[iVar7] != (istreambuf_iterator<char,std::char_traits<char>_>)0x7f) {
                  piVar9 = local_30[0];
                  if (local_1c < 0x10) {
                    piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
                  }
                  piVar9[iVar7] =
                       (istreambuf_iterator<char,std::char_traits<char>_>)
                       ((char)piVar9[iVar7] + '\x01');
                }
              }
              std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
              bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                                (param_2,local_170);
            } while (!bVar4);
            if (iVar7 != 0) {
              piVar9 = local_30[0];
              if (local_1c < 0x10) {
                piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
              }
              if ((char)piVar9[iVar7] < '\x01') {
                local_165 = '\x01';
              }
              else {
                iVar7 = iVar7 + 1;
              }
            }
          }
          piVar9 = local_84[0];
          if (local_70 < 0x10) {
            piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_84;
          }
          if (local_165 == '\0') {
            while ((iVar7 != 0 &&
                   (iVar3 = *piVar9,
                   iVar3 != (istreambuf_iterator<char,std::char_traits<char>_>)0x7f))) {
              iVar7 = iVar7 + -1;
              if (iVar7 != 0) {
                piVar8 = local_30[0];
                if (local_1c < 0x10) {
                  piVar8 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
                }
                if (iVar3 == piVar8[iVar7]) goto LAB_0088f96e;
LAB_0088f98b:
                local_165 = '\x01';
                goto LAB_0088f992;
              }
LAB_0088f96e:
              if (iVar7 == 0) {
                piVar8 = local_30[0];
                if (local_1c < 0x10) {
                  piVar8 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_30;
                }
                if ((char)iVar3 < (char)*piVar8) goto LAB_0088f98b;
              }
              if ('\0' < (char)piVar9[1]) {
                piVar9 = piVar9 + 1;
              }
            }
            local_8._0_1_ = 0xb;
            FUN_00402f30(1,0);
            goto LAB_0088fa1c;
          }
LAB_0088f992:
          FUN_00402f30(1,0);
        }
        goto LAB_0088fe8c;
      }
      bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_170);
      if (!bVar4) {
        iVar7 = positive_sign(local_a0);
        local_16c = local_16c | 1;
        local_8 = CONCAT31(local_8._1_3_,5);
        if (*(int *)(iVar7 + 0x10) == 0) {
LAB_0088fba9:
          local_166 = '\0';
        }
        else {
          piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)positive_sign(local_148);
          local_16c = local_16c | 2;
          local_8 = 6;
          if (0xf < *(uint *)(piVar9 + 0x14)) {
            piVar9 = *(istreambuf_iterator<char,std::char_traits<char>_> **)piVar9;
          }
          if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
            std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
          }
          local_166 = '\x01';
          if (*piVar9 != param_2[5]) goto LAB_0088fba9;
        }
        if ((local_16c & 2) != 0) {
          local_16c = local_16c & 0xfffffffd;
          FUN_00402f30(1,0);
        }
        local_8 = 3;
        if ((local_16c & 1) != 0) {
          local_16c = local_16c & 0xfffffffe;
          FUN_00402f30(1,0);
        }
        if (local_166 != '\0') {
          std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
          uVar6 = positive_sign(local_bc);
          local_8._0_1_ = 7;
          FUN_00402bb0(uVar6);
          goto LAB_0088fe8c;
        }
        iVar7 = negative_sign(local_12c);
        local_16c = local_16c | 4;
        local_8 = CONCAT31(local_8._1_3_,8);
        if (*(int *)(iVar7 + 0x10) == 0) {
LAB_0088fc99:
          local_166 = '\0';
        }
        else {
          piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)negative_sign(local_f4);
          local_16c = local_16c | 8;
          local_8 = 9;
          if (0xf < *(uint *)(piVar9 + 0x14)) {
            piVar9 = *(istreambuf_iterator<char,std::char_traits<char>_> **)piVar9;
          }
          if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
            std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
          }
          local_166 = '\x01';
          if (*piVar9 != param_2[5]) goto LAB_0088fc99;
        }
        if ((local_16c & 8) != 0) {
          local_16c = local_16c & 0xfffffff7;
          FUN_00402f30(1,0);
        }
        local_8 = 3;
        if ((local_16c & 4) != 0) {
          local_16c = local_16c & 0xfffffffb;
          FUN_00402f30(1,0);
        }
        if (local_166 == '\0') {
          iVar7 = positive_sign(local_d8);
          iVar7 = *(int *)(iVar7 + 0x10);
          FUN_00402f30(1,0);
          if (iVar7 != 0) {
            iVar7 = negative_sign(local_110);
            iVar7 = *(int *)(iVar7 + 0x10);
            FUN_00402f30(1,0);
            if (iVar7 == 0) goto LAB_0088fd7d;
          }
        }
        else {
          std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
          uVar6 = negative_sign(local_164);
          local_8._0_1_ = 10;
          FUN_00402bb0(uVar6);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_00402f30(1,0);
LAB_0088fd7d:
          local_171 = '\x01';
        }
      }
    }
LAB_0088fecb:
    local_180 = local_180 + 1;
    param_5 = local_188;
  } while (local_165 == '\0');
  if (local_165 == '\0') {
    if (1 < local_3c) {
      piVar9 = local_4c[0];
      if (local_38 < 0x10) {
        piVar9 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_4c;
      }
      while( true ) {
        piVar8 = local_4c[0];
        if (local_38 < 0x10) {
          piVar8 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_4c;
        }
        piVar9 = piVar9 + 1;
        if ((piVar9 == piVar8 + local_3c) ||
           (bVar4 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal(param_2,local_170)
           , bVar4)) break;
        if (param_2[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
          std::istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_2);
        }
        if (param_2[5] != *piVar9) break;
        std::istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_2);
      }
      piVar8 = local_4c[0];
      if (local_38 < 0x10) {
        piVar8 = (istreambuf_iterator<char,std::char_traits<char>_> *)local_4c;
      }
      if (piVar9 != piVar8 + local_3c) goto LAB_0088ff56;
    }
    if (local_171 != '\0') {
      FUN_004329c0(0,1,0x2d);
    }
  }
  else {
LAB_0088ff56:
    FUN_00402c80(0,0xffffffff);
  }
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00402bb0(local_68);
  FUN_00402f30(1,0);
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

