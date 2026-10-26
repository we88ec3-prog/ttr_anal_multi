
void FUN_007a5c50(int param_1,float param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float fVar11;
  float fStack_c4;
  char *pcStack_c0;
  float fStack_bc;
  undefined **ppuStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 *puStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  float fStack_94;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined1 uStack_48;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 auStack_2c [16];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093a08e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&fStack_c4;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xffffff30;
  ExceptionList = &local_14;
  if (((*(char *)(param_1 + 0x28) != '\0') && (*(int *)(param_1 + 0x24) != 2)) &&
     (*(int *)(param_1 + 0x24) != 3)) {
    FUN_007a8e70(param_1);
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    local_a8 = *(undefined4 *)(param_1 + 0xb4);
    (**(code **)(*(int *)(param_1 + 4) + 8))(&local_50,uVar7);
    FUN_007a7b30(&uStack_54,0);
    if (*(int *)(param_1 + 0x13c) == 0) {
      iVar8 = 1;
    }
    else {
      iVar8 = 1;
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        puStack_10 = (undefined1 *)0x0;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        puStack_10 = (undefined1 *)0xffffffff;
      }
      fVar10 = (float10)FUN_007a7100();
      if (DAT_00fb76e4 != 0) {
        iVar8 = FUN_00838860(uStack_54,local_50,uStack_4c,(float)fVar10);
      }
    }
    *(int *)(param_1 + 0x124) = iVar8;
    if (iVar8 == 0) {
      *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x140) = 0;
    }
    if (param_3 != 0) {
      *(undefined4 *)(param_1 + 0x124) = 1;
    }
    FUN_007a86b0(param_1,*(float *)(param_1 + 0x104) * param_2);
    if (*(int *)(param_1 + 0xac) != 0) {
      FUN_007a87d0(param_1,param_2,uStack_ac);
    }
    if ((*(int *)(param_1 + 0x124) != 0) || (10 < *(uint *)(param_1 + 0x140))) {
      if (*(int *)(param_1 + 0x100) == 0) {
        FUN_007d3bd0(*(undefined4 *)(param_1 + 0x1c));
        *(undefined4 *)(param_1 + 0x140) = 0;
      }
      else {
        iVar8 = *(int *)(param_1 + 0x1c);
        *(undefined4 *)(iVar8 + 0x28) = *(undefined4 *)(param_1 + 0xec);
        *(undefined4 *)(iVar8 + 0x2c) = *(undefined4 *)(param_1 + 0xf0);
        *(undefined4 *)(iVar8 + 0x30) = *(undefined4 *)(param_1 + 0xf4);
        iVar8 = *(int *)(iVar8 + 0x10);
        *(undefined4 *)(iVar8 + 0x68) = *(undefined4 *)(param_1 + 0xec);
        *(undefined4 *)(iVar8 + 0x6c) = *(undefined4 *)(param_1 + 0xf0);
        *(undefined4 *)(iVar8 + 0x70) = *(undefined4 *)(param_1 + 0xf4);
        *(undefined4 *)(iVar8 + 0xc0) = 0;
        uStack_b0 = *(undefined4 *)(param_1 + 0xfc);
        ppuStack_b8 = (undefined **)0x0;
        uStack_b4 = 0;
        FUN_007d3030(&ppuStack_b8);
        FUN_007d30f0(*(undefined4 *)(param_1 + 0xf8));
        *(undefined4 *)(param_1 + 0x100) = 0;
        FUN_007d3bd0(*(undefined4 *)(param_1 + 0x1c));
        *(undefined4 *)(param_1 + 0x140) = 0;
      }
    }
    if (*(int *)(param_1 + 0xa0) != 0) {
      FUN_007d65a0(param_2);
    }
    if (*(int *)(param_1 + 0x14c) != *(int *)(param_1 + 0x150)) {
      fStack_bc = (float)(*(int *)(param_1 + 0x150) - *(int *)(param_1 + 0x14c) >> 3);
      fVar11 = 0.0;
      if (fStack_bc != 0.0) {
        do {
          uStack_34 = 0xf;
          uStack_38 = 0;
          uStack_48 = 0;
          puStack_10 = (undefined1 *)0x1;
          iVar8 = (int)fVar11 * 8;
          fStack_c4 = (float)(iVar8 + *(int *)(param_1 + 0x14c));
          if (*(int *)(iVar8 + *(int *)(param_1 + 0x14c)) < 0) {
            puVar9 = (undefined4 *)(**(code **)(*(int *)(param_1 + 4) + 8))(auStack_2c);
            uStack_60 = puVar9[1];
            uVar2 = puVar9[2];
            puVar3 = *(undefined4 **)((int)fVar11 + 4);
            *puVar3 = *puVar9;
            puVar3[1] = uStack_60;
            puVar3[2] = uVar2;
            fVar10 = (float10)(**(code **)(*(int *)(param_1 + 4) + 0x10))();
            fStack_94 = (float)fVar10;
            iVar4 = *(int *)(iVar8 + 4 + *(int *)(param_1 + 0x14c));
            uStack_9c = 0;
            uStack_98 = 0;
            *(undefined4 *)(iVar4 + 0xc) = 0;
            *(undefined4 *)(iVar4 + 0x10) = 0;
            *(float *)(iVar4 + 0x14) = fStack_94;
            fVar11 = (float)(*(int *)(param_1 + 0x14c) + iVar8);
            fVar10 = (float10)(**(code **)(*(int *)(param_1 + 4) + 0x18))();
            pcStack_c0 = (char *)(float)fVar10;
            *(char **)(*(int *)((int)fStack_c4 + 4) + 0x18) = pcStack_c0;
          }
          else {
            uStack_64 = 1;
            (**(code **)(*(int *)(param_1 + 4) + 0x18))();
            uStack_8c = 0;
            uStack_88 = 0;
            uStack_84 = 0;
            uStack_80 = 0;
            uStack_7c = 0;
            uStack_78 = 0;
            uStack_74 = 0x3f800000;
            uStack_70 = 0x3f800000;
            uStack_6c = 0x3f800000;
            uStack_68 = 0x3f800000;
            FUN_007d3340();
            FUN_007cc3a0(&uStack_b0,&ppuStack_b8,&uStack_b4);
            iVar4 = (int)fVar11 * 8;
            puVar3 = *(undefined4 **)(iVar4 + 4 + *(int *)(param_1 + 0x14c));
            *puVar3 = uStack_8c;
            puVar3[1] = uStack_88;
            puVar3[2] = uStack_84;
            iVar8 = *(int *)(iVar4 + 4 + *(int *)(param_1 + 0x14c));
            *(undefined ***)(iVar8 + 0xc) = ppuStack_b8;
            *(undefined4 *)(iVar8 + 0x10) = uStack_b4;
            *(undefined4 *)(iVar8 + 0x14) = uStack_b0;
            *(undefined4 *)(*(int *)(iVar4 + 4 + *(int *)(param_1 + 0x14c)) + 0x18) = uStack_70;
            FUN_007d8a50(*(undefined4 *)(iVar4 + 4 + *(int *)(param_1 + 0x14c)));
          }
          if (*(int **)(param_1 + 0xac) != (int *)0x0) {
            iVar8 = *(int *)(param_1 + 0x14c);
            fVar10 = (float10)(**(code **)(**(int **)(param_1 + 0xac) + 0x10))();
            pcStack_c0 = (char *)(float)((float10)*(float *)(param_1 + 0x104) * (float10)param_2 *
                                        fVar10);
            FUN_007d89b0(*(undefined4 *)(iVar8 + (int)fVar11 * 8 + 4),pcStack_c0);
          }
          iVar8 = *(int *)(*(int *)(param_1 + 0x14c) + 4 + (int)fVar11 * 8);
          pcStack_c0 = *(char **)(iVar8 + 0x6c);
          fStack_c4 = *(float *)(iVar8 + 0x70);
          if (fStack_c4 < (float)pcStack_c0) {
            iVar8 = *(int *)(*(int *)(param_1 + 0x14c) + 4 + (int)fVar11 * 8);
            uVar7 = 0;
            if (*(int *)(iVar8 + 0x60) - *(int *)(iVar8 + 0x5c) >> 2 != 0) {
              do {
                *(undefined4 *)(*(int *)(*(int *)(iVar8 + 0x5c) + uVar7 * 4) + 0x7c) = 0;
                uVar7 = uVar7 + 1;
              } while (uVar7 < (uint)(*(int *)(iVar8 + 0x60) - *(int *)(iVar8 + 0x5c) >> 2));
            }
            *(undefined4 *)(iVar8 + 0x6c) = 0;
          }
          fVar11 = (float)((int)fVar11 + 1);
          puStack_10 = (undefined1 *)0xffffffff;
        } while ((uint)fVar11 < (uint)fStack_bc);
      }
    }
    uStack_a0 = 0;
    puStack_a4 = (undefined4 *)FUN_00891268(0x5c);
    if (puStack_a4 == (undefined4 *)0x0) {
      pcStack_c0 = (char *)0x0;
      std::exception::exception((exception *)&ppuStack_b8,&pcStack_c0);
      ppuStack_b8 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&ppuStack_b8,&DAT_00c857a8);
    }
    *puStack_a4 = puStack_a4;
    puStack_a4[1] = puStack_a4;
    puStack_a4[2] = puStack_a4;
    *(undefined1 *)(puStack_a4 + 0x16) = 1;
    *(undefined1 *)((int)puStack_a4 + 0x59) = 1;
    puStack_10 = (undefined1 *)0x2;
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_007d4180(*(int *)(param_1 + 0x1c),&local_a8,0);
    }
    puVar3 = *(undefined4 **)(param_1 + 0x70);
    if (*(int *)(param_1 + 0xac) != 0) {
      puVar9 = (undefined4 *)*puVar3;
      while (puVar9 != puVar3) {
        fVar10 = (float10)(**(code **)(**(int **)(param_1 + 0xac) + 0x10))();
        fStack_bc = (float)((float10)*(float *)(param_1 + 0x104) * (float10)param_2 * fVar10);
        FUN_007d2d50(uStack_ac,fStack_bc);
        if (*(char *)((int)puVar9 + 0x21) == '\0') {
          puVar5 = (undefined4 *)puVar9[2];
          if (*(char *)((int)puVar5 + 0x21) == '\0') {
            cVar1 = *(char *)((int)*puVar5 + 0x21);
            puVar9 = puVar5;
            puVar5 = (undefined4 *)*puVar5;
            while (cVar1 == '\0') {
              cVar1 = *(char *)((int)*puVar5 + 0x21);
              puVar9 = puVar5;
              puVar5 = (undefined4 *)*puVar5;
            }
          }
          else {
            cVar1 = *(char *)((int)puVar9[1] + 0x21);
            puVar6 = (undefined4 *)puVar9[1];
            puVar5 = puVar9;
            while ((puVar9 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar9[2]))) {
              cVar1 = *(char *)((int)puVar9[1] + 0x21);
              puVar6 = (undefined4 *)puVar9[1];
              puVar5 = puVar9;
            }
          }
        }
      }
    }
    uVar7 = 0;
    do {
      puVar9 = (undefined4 *)**(undefined4 **)(param_1 + 0x70);
      while (puVar9 != puVar3) {
        FUN_007d2a70(uVar7);
        if (*(char *)((int)puVar9 + 0x21) == '\0') {
          puVar5 = (undefined4 *)puVar9[2];
          if (*(char *)((int)puVar5 + 0x21) == '\0') {
            cVar1 = *(char *)((int)*puVar5 + 0x21);
            puVar9 = puVar5;
            puVar5 = (undefined4 *)*puVar5;
            while (cVar1 == '\0') {
              cVar1 = *(char *)((int)*puVar5 + 0x21);
              puVar9 = puVar5;
              puVar5 = (undefined4 *)*puVar5;
            }
          }
          else {
            cVar1 = *(char *)((int)puVar9[1] + 0x21);
            puVar6 = (undefined4 *)puVar9[1];
            puVar5 = puVar9;
            while ((puVar9 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar9[2]))) {
              cVar1 = *(char *)((int)puVar9[1] + 0x21);
              puVar6 = (undefined4 *)puVar9[1];
              puVar5 = puVar9;
            }
          }
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 3);
    puStack_10 = (undefined1 *)0x3;
    FUN_007aa1e0(*puStack_a4,puStack_a4);
    FUN_0089120c(puStack_a4);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&fStack_c4);
  return;
}

