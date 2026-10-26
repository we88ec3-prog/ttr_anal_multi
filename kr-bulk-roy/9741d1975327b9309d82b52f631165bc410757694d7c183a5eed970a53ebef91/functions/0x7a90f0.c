
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a90f0(char *param_1,char *param_2,int *param_3)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *****pppppuVar9;
  int iVar10;
  char *pcVar11;
  DWORD DVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  undefined **local_e0 [4];
  LPCRITICAL_SECTION local_d0;
  undefined **local_c8 [3];
  undefined **local_bc [3];
  undefined4 local_b0;
  undefined4 *local_ac;
  int local_a0;
  int local_9c;
  undefined4 local_98;
  undefined4 *local_94;
  undefined4 local_88;
  undefined4 *local_84;
  char *local_78;
  DWORD local_74;
  undefined4 *local_70;
  int local_6c [3];
  undefined4 *local_60;
  int *local_5c;
  char *local_54;
  undefined4 *local_50;
  int *local_4c;
  int local_48;
  char *local_44;
  int local_40;
  int *local_3c;
  char *local_38;
  undefined4 ****local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00918d64;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = param_1;
  local_8 = 0;
  local_18 = uVar6;
  if (*param_2 == '\0') {
    local_8 = 0xffffffff;
    param_1[0x24] = '\x03';
    param_1[0x25] = '\0';
    param_1[0x26] = '\0';
    param_1[0x27] = '\0';
    param_1[0x1c] = '\0';
    param_1[0x1d] = '\0';
    param_1[0x1e] = '\0';
    param_1[0x1f] = '\0';
    param_1[0xa0] = '\0';
    param_1[0xa1] = '\0';
    param_1[0xa2] = '\0';
    param_1[0xa3] = '\0';
    if (param_3 == (int *)0x0) goto LAB_007a9a47;
    LOCK();
    iVar8 = param_3[1] + -1;
    param_3[1] = iVar8;
    UNLOCK();
  }
  else {
    local_74 = timeGetTime();
    local_6c[2] = *(int *)(param_1 + 0x1c);
    FUN_007a9e50(&local_98,param_1 + 0x2c);
    local_8._0_1_ = 1;
    FUN_007a9f20(&local_88,param_1 + 0x3c);
    local_8._0_1_ = 2;
    FUN_007a9ff0(&local_b0,param_1 + 0x6c);
    local_8._0_1_ = 3;
    local_48 = *(int *)(param_2 + 4);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x10);
    FUN_007a5730(*(int *)(param_2 + 8) + 0x48);
    local_38 = param_2 + 0x18;
    if (param_1 + 0x6c != local_38) {
      FUN_006d7120(**(undefined4 **)(param_1 + 0x70),*(undefined4 **)(param_1 + 0x70));
      FUN_007aa150(local_38);
    }
    (**(code **)(*(int *)(param_1 + 4) + 4))(param_1 + 0xec);
    (**(code **)(*(int *)(param_1 + 4) + 0x14))(*(undefined4 *)(param_1 + 0xf8));
    (**(code **)(*(int *)(param_1 + 4) + 0xc))(*(undefined4 *)(param_1 + 0xfc));
    FUN_00823850();
    local_40 = *(int *)(param_2 + 8);
    piVar14 = (int *)**(int **)(local_40 + 0x3c);
    if (piVar14 != *(int **)(local_40 + 0x3c)) {
      do {
        if ((DAT_00fe1bc0 & 1) == 0) {
          DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
          local_8._0_1_ = 4;
          FUN_007bef00();
          _atexit((_func_4879 *)&LAB_00bcec50);
          local_8._0_1_ = 3;
        }
        local_a0 = piVar14[6];
        local_9c = piVar14[7];
        FUN_004dd400(&DAT_00fe1b60,&local_38,&local_a0);
        if ((local_38 != DAT_00fe1b64) && (*(int *)(local_38 + 0x18) != 0)) {
          FUN_007d5cd0(local_48,param_1 + 0x7c);
        }
        if (*(char *)((int)piVar14 + 0x21) == '\0') {
          piVar3 = (int *)piVar14[2];
          if (*(char *)((int)piVar3 + 0x21) == '\0') {
            cVar2 = *(char *)(*piVar3 + 0x21);
            piVar14 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar2 == '\0') {
              cVar2 = *(char *)(*piVar3 + 0x21);
              piVar14 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar2 = *(char *)(piVar14[1] + 0x21);
            piVar5 = (int *)piVar14[1];
            piVar3 = piVar14;
            while ((piVar14 = piVar5, cVar2 == '\0' && (piVar3 == (int *)piVar14[2]))) {
              cVar2 = *(char *)(piVar14[1] + 0x21);
              piVar5 = (int *)piVar14[1];
              piVar3 = piVar14;
            }
          }
        }
      } while (piVar14 != *(int **)(local_40 + 0x3c));
    }
    uVar7 = FUN_007a7800(*(undefined4 *)(param_1 + 0xa8));
    local_38 = *(char **)(param_1 + 0xb4);
    *(undefined4 *)(param_1 + 0xac) = uVar7;
    FUN_007a6830(0);
    FUN_007a6830(local_38);
    local_3c = (int *)**(int **)(param_1 + 0x70);
    if (local_3c != *(int **)(param_1 + 0x70)) {
      do {
        iVar8 = local_3c[6];
        local_38 = *(char **)(param_1 + 0xa8);
        uVar15 = 0;
        if (*(int *)(iVar8 + 0x1c) - *(int *)(iVar8 + 0x18) >> 2 != 0) {
          do {
            (**(code **)(**(int **)(*(int *)(iVar8 + 0x18) + uVar15 * 4) + 8))(local_38);
            uVar15 = uVar15 + 1;
          } while (uVar15 < (uint)(*(int *)(iVar8 + 0x1c) - *(int *)(iVar8 + 0x18) >> 2));
        }
        if (*(char *)((int)local_3c + 0x21) == '\0') {
          piVar14 = (int *)local_3c[2];
          if (*(char *)((int)piVar14 + 0x21) == '\0') {
            cVar2 = *(char *)(*piVar14 + 0x21);
            local_3c = piVar14;
            piVar14 = (int *)*piVar14;
            while (cVar2 == '\0') {
              cVar2 = *(char *)(*piVar14 + 0x21);
              local_3c = piVar14;
              piVar14 = (int *)*piVar14;
            }
          }
          else {
            cVar2 = *(char *)(local_3c[1] + 0x21);
            piVar3 = (int *)local_3c[1];
            piVar14 = local_3c;
            while ((local_3c = piVar3, cVar2 == '\0' && (piVar14 == (int *)local_3c[2]))) {
              cVar2 = *(char *)(local_3c[1] + 0x21);
              piVar3 = (int *)local_3c[1];
              piVar14 = local_3c;
            }
          }
        }
      } while (local_3c != *(int **)(param_1 + 0x70));
    }
    piVar14 = *(int **)(param_1 + 0xa0);
    if (piVar14 != (int *)0x0) {
      *(int *)(*piVar14 + 0x2c) = *(int *)(*piVar14 + 0x2c) + -1;
      FUN_0089120c(piVar14);
      param_1[0xa0] = '\0';
      param_1[0xa1] = '\0';
      param_1[0xa2] = '\0';
      param_1[0xa3] = '\0';
    }
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0x14);
    iVar13 = *(int *)(local_48 + 200) - *(int *)(local_48 + 0xc4);
    iVar8 = iVar13 >> 0x1f;
    iVar13 = iVar13 / 0x38 + iVar8;
    if ((iVar13 != iVar8) && (local_38 = (char *)0x0, iVar13 != iVar8)) {
      local_3c = (int *)0x0;
      do {
        local_40 = -1;
        if ((DAT_00fe324c & 1) == 0) {
          DAT_00fe324c = DAT_00fe324c | 1;
          local_8._0_1_ = 5;
          _DAT_00fe3258 = 0;
          iVar8 = FUN_00891268(0x34);
          if (iVar8 == 0) {
            local_54 = (char *)0x0;
            std::exception::exception((exception *)local_bc,&local_54);
            local_bc[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_bc,&DAT_00c857a8);
          }
          DAT_00fe3254 = iVar8;
          *(int *)iVar8 = iVar8;
          *(int *)(DAT_00fe3254 + 4) = DAT_00fe3254;
          *(int *)(DAT_00fe3254 + 8) = DAT_00fe3254;
          *(undefined1 *)(DAT_00fe3254 + 0x30) = 1;
          *(undefined1 *)(DAT_00fe3254 + 0x31) = 1;
          local_8._0_1_ = 6;
          _DAT_00fe3268 = 0;
          iVar8 = FUN_00891268(0x30);
          if (iVar8 == 0) {
            local_78 = (char *)0x0;
            std::exception::exception((exception *)local_e0,&local_78);
            local_e0[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_e0,&DAT_00c857a8);
          }
          DAT_00fe3264 = iVar8;
          *(int *)iVar8 = iVar8;
          *(int *)(DAT_00fe3264 + 4) = DAT_00fe3264;
          *(int *)(DAT_00fe3264 + 8) = DAT_00fe3264;
          *(undefined1 *)(DAT_00fe3264 + 0x2c) = 1;
          *(undefined1 *)(DAT_00fe3264 + 0x2d) = 1;
          DAT_00fe3270 = 0;
          _DAT_00fe3274 = 0;
          _DAT_00fe3278 = 0;
          _DAT_00fe3280 = 0;
          _atexit((_func_4879 *)&LAB_00bd09b0);
          local_8._0_1_ = 3;
        }
        iVar8 = FUN_007cf850();
        local_20 = 0xf;
        local_24 = 0;
        local_34[0] = (undefined4 ****)((uint)local_34[0] & 0xffffff00);
        puVar1 = (undefined4 *)(iVar8 + 0x7c);
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_00403040(puVar1,0,0xffffffff);
        if (*(int *)(iVar8 + 0x78) == 0) {
LAB_007a963c:
          local_8 = CONCAT31(local_8._1_3_,9);
          local_40 = iVar8;
          FUN_007d8920();
          if (0xf < *(uint *)(iVar8 + 0x90)) {
            FUN_0089120c(*puVar1);
          }
          *(undefined4 *)(iVar8 + 0x90) = 0xf;
          *(undefined4 *)(iVar8 + 0x8c) = 0;
          *(undefined1 *)puVar1 = 0;
          if (*(int *)(iVar8 + 0x5c) != 0) {
            FUN_0089120c(*(int *)(iVar8 + 0x5c));
          }
          *(undefined4 *)(iVar8 + 0x5c) = 0;
          *(undefined4 *)(iVar8 + 0x60) = 0;
          *(undefined4 *)(iVar8 + 100) = 0;
          FUN_0089120c(iVar8);
        }
        else {
          pppppuVar9 = (undefined4 *****)local_34[0];
          if (local_20 < 0x10) {
            pppppuVar9 = local_34;
          }
          if (((*(int *)(local_44 + 0x1c) == 0) ||
              (iVar10 = FUN_007d32d0(&local_40,pppppuVar9), iVar13 = local_40, pcVar11 = local_44,
              iVar10 == 0)) || (local_40 < 0)) goto LAB_007a963c;
          piVar14 = *(int **)(local_44 + 0x150);
          local_6c[0] = local_40;
          local_6c[1] = iVar8;
          if (local_6c < piVar14) {
            piVar3 = *(int **)(local_44 + 0x14c);
            if (local_6c < piVar3) goto LAB_007a9611;
            if (piVar14 == *(int **)(local_44 + 0x154)) {
              FUN_007cddf0();
            }
            puVar1 = (undefined4 *)
                     (*(int *)(pcVar11 + 0x14c) + ((int)local_6c - (int)piVar3 >> 3) * 8);
            puVar4 = *(undefined4 **)(pcVar11 + 0x150);
            if (puVar4 != (undefined4 *)0x0) {
              *puVar4 = *puVar1;
              puVar4[1] = puVar1[1];
            }
            *(int *)(pcVar11 + 0x150) = *(int *)(pcVar11 + 0x150) + 8;
          }
          else {
LAB_007a9611:
            if (piVar14 == *(int **)(local_44 + 0x154)) {
              FUN_007cddf0();
            }
            piVar14 = *(int **)(pcVar11 + 0x150);
            if (piVar14 != (int *)0x0) {
              *piVar14 = iVar13;
              piVar14[1] = iVar8;
            }
            *(int *)(pcVar11 + 0x150) = *(int *)(pcVar11 + 0x150) + 8;
          }
        }
        local_8._0_1_ = 3;
        if (0xf < local_20) {
          FUN_0089120c(local_34[0]);
        }
        local_3c = local_3c + 0xe;
        local_38 = local_38 + 1;
        param_1 = local_44;
      } while (local_38 < (char *)((*(int *)(local_48 + 200) - *(int *)(local_48 + 0xc4)) / 0x38));
    }
    if (*(char *)(*(int *)(param_2 + 8) + 4) == '\0') {
      pcVar11 = (char *)FUN_00891268(0x38);
      local_8._0_1_ = 10;
      local_54 = pcVar11;
      if (pcVar11 == (char *)0x0) {
        pcVar11 = (char *)0x0;
      }
      else {
        FUN_007a5020(pcVar11 + 8);
        local_8._0_1_ = 0xb;
        pcVar11[0x30] = '\0';
        pcVar11[0x31] = '\0';
        pcVar11[0x32] = '\0';
        pcVar11[0x33] = '\0';
        iVar8 = FUN_00891268(0x28);
        if (iVar8 == 0) {
          local_44 = (char *)0x0;
          std::exception::exception((exception *)local_c8,&local_44);
          local_c8[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_c8,&DAT_00c857a8);
        }
        *(int *)(pcVar11 + 0x2c) = iVar8;
        *(int *)iVar8 = iVar8;
        *(int *)(*(int *)(pcVar11 + 0x2c) + 4) = *(int *)(pcVar11 + 0x2c);
        *(int *)(*(int *)(pcVar11 + 0x2c) + 8) = *(int *)(pcVar11 + 0x2c);
        *(undefined1 *)(*(int *)(pcVar11 + 0x2c) + 0x20) = 1;
        *(undefined1 *)(*(int *)(pcVar11 + 0x2c) + 0x21) = 1;
      }
      local_8._0_1_ = 3;
      local_50 = (undefined4 *)0x0;
      local_4c = (int *)0x0;
      FUN_007aa780(&local_50,pcVar11);
      puVar1 = local_50;
      local_8 = CONCAT31(local_8._1_3_,0xc);
      *local_50 = *(undefined4 *)(param_1 + 0x18);
      if (local_50 + 2 != &local_98) {
        FUN_004ca160(*(undefined4 *)local_50[3],(undefined4 *)local_50[3]);
        FUN_007a1540(&local_98);
      }
      if (puVar1 + 6 != &local_88) {
        puVar1 = (undefined4 *)puVar1[7];
        FUN_006d7120(*puVar1,puVar1);
        FUN_007a1660(&local_88);
      }
      local_50[1] = local_6c[2];
      if (local_50 + 10 != &local_b0) {
        FUN_006d7120(*(undefined4 *)local_50[0xb],(undefined4 *)local_50[0xb]);
        FUN_007aa150(&local_b0);
      }
      local_60 = (undefined4 *)0x0;
      local_5c = (int *)0x0;
      if (local_4c != (int *)0x0) {
        iVar8 = local_4c[1];
        while (iVar8 != 0) {
          LOCK();
          iVar13 = local_4c[1];
          if (iVar8 == iVar13) {
            local_4c[1] = iVar8 + 1;
            iVar13 = iVar8;
          }
          UNLOCK();
          if (iVar13 == iVar8) {
            local_5c = local_4c;
            local_60 = local_50;
            break;
          }
          iVar8 = local_4c[1];
        }
      }
      local_8._0_1_ = 0xd;
      iVar8 = FUN_0047c290();
      lpCriticalSection = (LPCRITICAL_SECTION)(iVar8 + 0x70);
      local_d0 = lpCriticalSection;
      EnterCriticalSection(lpCriticalSection);
      local_8._0_1_ = 0xf;
      FUN_007a0f60(iVar8 + 0x38);
      LeaveCriticalSection(lpCriticalSection);
      piVar14 = local_5c;
      local_8._0_1_ = 0xc;
      if (local_5c != (int *)0x0) {
        LOCK();
        iVar8 = local_5c[1] + -1;
        local_5c[1] = iVar8;
        UNLOCK();
        if (iVar8 == 0) {
          (**(code **)*local_5c)();
          piVar3 = piVar14 + 2;
          LOCK();
          iVar8 = *piVar3 + -1;
          *piVar3 = iVar8;
          UNLOCK();
          if (iVar8 == 0) {
            (**(code **)(*piVar14 + 4))();
          }
        }
      }
      piVar14 = local_4c;
      local_8._0_1_ = 3;
      if (local_4c != (int *)0x0) {
        LOCK();
        iVar8 = local_4c[1] + -1;
        local_4c[1] = iVar8;
        UNLOCK();
        if (iVar8 == 0) {
          (**(code **)*local_4c)();
          piVar3 = piVar14 + 2;
          LOCK();
          iVar8 = *piVar3 + -1;
          *piVar3 = iVar8;
          UNLOCK();
          if (iVar8 == 0) {
            (**(code **)(*piVar14 + 4))();
          }
        }
      }
    }
    param_1[0x24] = '\x01';
    param_1[0x25] = '\0';
    param_1[0x26] = '\0';
    param_1[0x27] = '\0';
    param_1[0x118] = '\x01';
    param_1[0x119] = '\0';
    param_1[0x11a] = '\0';
    param_1[0x11b] = '\0';
    DVar12 = timeGetTime();
    FID_conflict__wprintf("ApplyTime: %d\n",DVar12 - local_74);
    local_8._0_1_ = 0x10;
    FUN_006d7120(*local_ac,local_ac);
    FUN_0089120c(local_ac);
    local_70 = &local_88;
    local_8._0_1_ = 0x12;
    FUN_006d7120(*local_84,local_84);
    FUN_0089120c(local_84);
    local_8 = CONCAT31(local_8._1_3_,0x13);
    FUN_004ca160(*local_94,local_94);
    FUN_0089120c(local_94);
    local_8 = 0xffffffff;
    if (param_3 == (int *)0x0) goto LAB_007a9a47;
    LOCK();
    iVar8 = param_3[1] + -1;
    param_3[1] = iVar8;
    UNLOCK();
  }
  local_8 = 0xffffffff;
  if (iVar8 == 0) {
    (**(code **)*param_3)(uVar6);
    LOCK();
    iVar8 = param_3[2] + -1;
    param_3[2] = iVar8;
    UNLOCK();
    if (iVar8 == 0) {
      (**(code **)(*param_3 + 4))();
    }
  }
LAB_007a9a47:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

