
undefined4
FUN_0082e360(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,uint param_7,
            uint param_8,int param_9,int param_10)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined **ppuVar9;
  int *piVar10;
  float10 fVar11;
  int local_84;
  char *local_80;
  int local_7c;
  undefined4 *local_78;
  int *local_74;
  float local_70;
  undefined4 *local_6c;
  float local_68;
  int *local_64;
  char *local_60;
  char *local_5c;
  undefined **local_58;
  int local_54;
  int *local_4c;
  int local_48;
  undefined4 *local_40;
  int local_3c;
  undefined **local_34 [3];
  int *local_28;
  int local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00907078;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  local_48 = 0;
  piVar5 = (int *)FUN_00891268(0xc,uVar4);
  if (piVar5 == (int *)0x0) {
    local_60 = (char *)0x0;
    std::exception::exception((exception *)&local_58,&local_60);
    local_58 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_58,&DAT_00c857a8);
  }
  *piVar5 = (int)piVar5;
  piVar5[1] = (int)piVar5;
  local_c = 0;
  local_3c = 0;
  local_4c = piVar5;
  puVar6 = (undefined4 *)FUN_00891268(0xc,uVar4);
  local_78 = puVar6;
  if (puVar6 == (undefined4 *)0x0) {
    local_5c = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_5c);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  *puVar6 = puVar6;
  puVar6[1] = puVar6;
  local_c = CONCAT31(local_c._1_3_,1);
  local_40 = puVar6;
  if ((*(int *)(*(int *)(param_1 + 0x20) + 0x10 + (*(int *)(param_1 + 8) * param_4 + param_3) * 0x18
               ) != 0) &&
     (*(int *)(*(int *)(param_1 + 0x20) + 0x10 + (*(int *)(param_1 + 8) * param_6 + param_5) * 0x18)
      != 0)) {
    puVar6 = (undefined4 *)FUN_00891268(0x14,uVar4);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      local_6c = (undefined4 *)
                 (float)((param_6 - param_4) * (param_6 - param_4) +
                        (param_5 - param_3) * (param_5 - param_3));
      fVar11 = (float10)FUN_008ff870();
      *puVar6 = 0;
      puVar6[1] = param_3;
      puVar6[3] = 0;
      puVar6[2] = param_4;
      puVar6[4] = (float)fVar11;
    }
    local_6c = puVar6;
    iVar7 = FUN_0074d700(piVar5,piVar5[1],&local_6c);
    piVar5[1] = iVar7;
    **(int **)(iVar7 + 4) = iVar7;
    local_48 = 1;
    if (*(int *)(param_1 + 8) < param_9) {
      param_9 = *(int *)(param_1 + 8);
    }
    if (*(int *)(param_1 + 0xc) < param_10) {
      param_10 = *(int *)(param_1 + 0xc);
    }
    FUN_0082e290();
    local_6c = (undefined4 *)0xffffffff;
    local_74 = (int *)0x0;
    local_7c = 0;
    piVar5 = local_4c;
    do {
      piVar10 = local_74;
      if ((local_6c != (undefined4 *)0xffffffff) || (0xff < local_7c)) break;
      local_7c = local_7c + 1;
      local_84 = 0;
      FUN_0082e2f0(&local_4c,&local_84);
      iVar8 = FUN_0074d700(local_78,local_78[1],&local_84);
      iVar7 = local_84;
      if (local_3c == 0x3ffffffe) {
LAB_0082e879:
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("list<T> too long");
      }
      local_78[1] = iVar8;
      local_3c = local_3c + 1;
      **(int **)(iVar8 + 4) = iVar8;
      *(undefined4 *)
       (*(int *)(param_1 + 0x20) +
       (*(int *)(local_84 + 8) * *(int *)(param_1 + 8) + *(int *)(local_84 + 4)) * 0x18) = 1;
      local_28 = (int *)0x0;
      local_24 = 0;
      local_20 = 0;
      local_c = CONCAT31(local_c._1_3_,2);
      local_80 = (char *)0xffffffff;
      do {
        local_70 = -NAN;
        do {
          if ((local_80 != (char *)0x0) || (local_70 != 0.0)) {
            local_54 = *(int *)(iVar7 + 8) + (int)local_80;
            local_58 = (undefined **)(*(int *)(iVar7 + 4) + (int)local_70);
            if (((int)(((int)param_7 < 0) - 1 & param_7) <= (int)local_58) &&
               (((((int)local_58 < param_9 && ((int)(((int)param_8 < 0) - 1 & param_8) <= local_54))
                 && (local_54 < param_10)) &&
                ((ppuVar9 = (undefined **)(*(int *)(param_1 + 8) * local_54 + (int)local_58),
                 *(int *)(*(int *)(param_1 + 0x20) + 0x10 + (int)ppuVar9 * 0x18) != 0 &&
                 (*(int *)(*(int *)(param_1 + 0x20) + (int)ppuVar9 * 0x18) == 0)))))) {
              FUN_007d4560();
            }
          }
          local_70 = (float)((int)local_70 + 1);
        } while ((int)local_70 < 2);
        local_80 = (char *)((int)local_80 + 1);
      } while ((int)local_80 < 2);
      local_60 = (char *)(local_24 - (int)local_28 >> 3);
      local_80 = (char *)0x0;
      piVar5 = local_28;
      if (local_60 != (char *)0x0) {
        do {
          iVar7 = *piVar5;
          iVar8 = *(int *)(param_1 + 8) * piVar5[1] + iVar7;
          local_70 = *(float *)(*(int *)(param_1 + 0x20) + 0x14 + iVar8 * 0x18);
          if (*(int *)(*(int *)(param_1 + 0x20) + 4 + iVar8 * 0x18) == 0) {
            piVar10 = (int *)FUN_00891268(0x14);
            if (piVar10 == (int *)0x0) {
              piVar10 = (int *)0x0;
            }
            else {
              local_68 = (float)((param_5 - *piVar5) * (param_5 - *piVar5) +
                                (param_6 - piVar5[1]) * (param_6 - piVar5[1]));
              fVar11 = (float10)FUN_008ff870();
              local_68 = *(float *)(local_84 + 0xc);
              *piVar10 = local_84;
              local_68 = local_68 + local_70;
              piVar10[1] = *piVar5;
              piVar10[2] = piVar5[1];
              piVar10[3] = (int)local_68;
              piVar10[4] = (int)(float)fVar11;
            }
            *(undefined4 *)
             (*(int *)(param_1 + 0x20) + (*(int *)(param_1 + 8) * piVar10[2] + piVar10[1]) * 0x18 +
             4) = 1;
            local_64 = piVar10;
            iVar7 = FUN_0074d700(local_4c,local_4c[1],&local_64);
            if (local_48 == 0x3ffffffe) goto LAB_0082e879;
            local_4c[1] = iVar7;
            **(int **)(iVar7 + 4) = iVar7;
            local_48 = local_48 + 1;
            if ((piVar10[1] == param_5) && (piVar10[2] == param_6)) {
              local_6c = (undefined4 *)0x1;
              local_74 = piVar10;
              break;
            }
          }
          else {
            for (piVar10 = (int *)*local_4c; piVar10 != local_4c; piVar10 = (int *)*piVar10) {
              if ((*(int *)(piVar10[2] + 4) == iVar7) && (*(int *)(piVar10[2] + 8) == piVar5[1])) {
                local_68 = (float)((param_6 - piVar5[1]) * (param_6 - piVar5[1]) +
                                  (param_5 - iVar7) * (param_5 - iVar7));
                fVar11 = (float10)FUN_008ff870();
                local_68 = (float)fVar11;
                if (local_70 + local_68 + *(float *)(local_84 + 0xc) <
                    *(float *)(piVar10[2] + 0x10) + *(float *)(piVar10[2] + 0xc)) {
                  local_68 = local_70 + *(float *)(local_84 + 0xc);
                  *(float *)(piVar10[2] + 0xc) = local_68;
                  *(int *)piVar10[2] = local_84;
                }
                break;
              }
            }
          }
          local_80 = local_80 + 1;
          piVar5 = piVar5 + 2;
        } while (local_80 < local_60);
      }
      piVar5 = local_4c;
      local_c = CONCAT31(local_c._1_3_,1);
      if (local_28 != (int *)0x0) {
        FUN_0089120c(local_28);
      }
      local_28 = (int *)0x0;
      local_24 = 0;
      local_20 = 0;
      piVar10 = local_74;
    } while (local_48 != 0);
    do {
      if (piVar10 == (int *)0x0) goto LAB_0082e893;
      if (((int *)*piVar10 != (int *)0x0) && (*(int *)*piVar10 == 0)) {
        FUN_007b6e80(piVar10 + 1);
        piVar5 = local_4c;
        goto LAB_0082e893;
      }
      FUN_007b6e80(piVar10 + 1);
      piVar5 = local_4c;
      piVar10 = (int *)*piVar10;
    } while( true );
  }
  puVar1 = (undefined4 *)*puVar6;
  *puVar6 = puVar6;
  puVar6[1] = puVar6;
  while (puVar1 != puVar6) {
    puVar2 = (undefined4 *)*puVar1;
    FUN_0089120c(puVar1);
    puVar1 = puVar2;
  }
  FUN_0089120c(puVar6);
  piVar10 = (int *)*piVar5;
  *piVar5 = (int)piVar5;
  piVar5[1] = (int)piVar5;
  while (piVar10 != piVar5) {
    piVar3 = (int *)*piVar10;
    FUN_0089120c(piVar10);
    piVar10 = piVar3;
  }
LAB_0082e928:
  FUN_0089120c(piVar5);
  ExceptionList = local_14;
  return 0;
LAB_0082e893:
  puVar6 = local_78;
  for (piVar10 = (int *)*piVar5; local_78 = puVar6, piVar10 != piVar5; piVar10 = (int *)*piVar10) {
    FUN_0089120c(piVar10[2]);
    puVar6 = local_78;
  }
  for (puVar1 = (undefined4 *)*puVar6; puVar1 != puVar6; puVar1 = (undefined4 *)*puVar1) {
    FUN_0089120c(puVar1[2]);
  }
  puVar1 = (undefined4 *)*puVar6;
  if (local_74 == (int *)0x0) {
    *puVar6 = puVar6;
    puVar6[1] = puVar6;
    while (puVar1 != puVar6) {
      puVar2 = (undefined4 *)*puVar1;
      FUN_0089120c(puVar1);
      puVar1 = puVar2;
    }
    FUN_0089120c(puVar6);
    piVar10 = (int *)*piVar5;
    *piVar5 = (int)piVar5;
    piVar5[1] = (int)piVar5;
    while (piVar10 != piVar5) {
      piVar3 = (int *)*piVar10;
      FUN_0089120c(piVar10);
      piVar10 = piVar3;
    }
  }
  else {
    iVar7 = *(int *)(param_2 + 0x10);
    *puVar6 = puVar6;
    puVar6[1] = puVar6;
    if (iVar7 != 0) {
      while (puVar1 != puVar6) {
        puVar2 = (undefined4 *)*puVar1;
        FUN_0089120c(puVar1);
        puVar1 = puVar2;
      }
      FUN_0089120c(puVar6);
      piVar10 = (int *)*piVar5;
      *piVar5 = (int)piVar5;
      piVar5[1] = (int)piVar5;
      while (piVar10 != piVar5) {
        piVar3 = (int *)*piVar10;
        FUN_0089120c(piVar10);
        piVar10 = piVar3;
      }
      FUN_0089120c(piVar5);
      ExceptionList = local_14;
      return 2;
    }
    while (puVar1 != puVar6) {
      puVar2 = (undefined4 *)*puVar1;
      FUN_0089120c(puVar1);
      puVar1 = puVar2;
    }
    FUN_0089120c(puVar6);
    piVar10 = (int *)*piVar5;
    *piVar5 = (int)piVar5;
    piVar5[1] = (int)piVar5;
    while (piVar10 != piVar5) {
      piVar3 = (int *)*piVar10;
      FUN_0089120c(piVar10);
      piVar10 = piVar3;
    }
  }
  goto LAB_0082e928;
}

