
void FUN_0073e260(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  char ****ppppcVar10;
  int iVar11;
  uint uVar12;
  char *in_ECX;
  char ****ppppcVar13;
  int *piVar14;
  int *unaff_FS_OFFSET;
  wchar_t *local_e4;
  char local_dd;
  undefined2 local_dc [8];
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined2 local_bc;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined2 local_a0;
  undefined4 local_90;
  undefined4 local_8c;
  undefined2 local_84;
  undefined4 local_74;
  undefined4 local_70;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  char ***local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  uint local_20;
  uint local_1c;
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0091ccb3;
  local_10 = *unaff_FS_OFFSET;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_c8 = 7;
  local_a8 = 7;
  local_8c = 7;
  local_70 = 7;
  local_cc = 0;
  local_dc[0] = 0;
  local_c0 = 0;
  local_ac = 0;
  local_bc = 0;
  local_90 = 0;
  local_a0 = 0;
  local_74 = 0;
  local_84 = 0;
  local_8 = 0;
  local_dd = '\0';
  local_e4 = L"Bold";
  if (param_4 != 1) {
    local_e4 = L"Regular";
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (char ***)((uint)local_4c[0] & 0xffffff00);
  pcVar6 = in_ECX;
  do {
    cVar4 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar4 != '\0');
  local_14 = uVar5;
  FUN_00402a70(in_ECX,(int)pcVar6 - (int)(in_ECX + 1));
  local_8._0_1_ = 1;
  puVar7 = (undefined4 *)FUN_004028b0(local_4c,uVar5);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (7 < (uint)puVar7[5]) {
    puVar7 = (undefined4 *)*puVar7;
  }
  cVar4 = FUN_00741320(puVar7,local_e4,local_dc,&local_dd);
  if (7 < local_54) {
    FUN_0089120c(local_68);
  }
  local_8 = local_8 & 0xffffff00;
  local_54 = 7;
  local_58 = 0;
  local_68 = local_68 & 0xffff0000;
  if (0xf < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  if (cVar4 != '\0') {
    iVar8 = FUN_008fed10();
    iVar9 = FUN_008fed10();
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = (char ***)((uint)local_4c[0] & 0xffffff00);
    local_8._0_1_ = 3;
    FUN_00429710();
    local_8._0_1_ = 4;
    ppppcVar13 = (char ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppcVar13 = local_4c;
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30 = local_30 & 0xffffff00;
    ppppcVar10 = ppppcVar13;
    do {
      cVar4 = *(char *)ppppcVar10;
      ppppcVar10 = (char ****)((int)ppppcVar10 + 1);
    } while (cVar4 != '\0');
    FUN_00402a70(ppppcVar13,(int)ppppcVar10 - (int)((int)ppppcVar13 + 1));
    local_8 = CONCAT31(local_8._1_3_,6);
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    local_3c = 0;
    piVar14 = (int *)**(int **)(param_1 + 0x1c);
    local_38 = 0xf;
    local_4c[0] = (char ***)((uint)local_4c[0] & 0xffffff00);
    if (piVar14 != *(int **)(param_1 + 0x1c)) {
      do {
        iVar1 = piVar14[4];
        uVar5 = *(uint *)(iVar1 + 0x1c);
        uVar12 = local_20;
        if (uVar5 < local_20) {
          uVar12 = uVar5;
        }
        iVar11 = FUN_00407e70(uVar12);
        if ((((iVar11 == 0) && (local_20 <= uVar5)) && (uVar5 == local_20)) &&
           ((*(int *)(iVar1 + 0x5c) == iVar8 && (*(int *)(iVar1 + 0x60) == iVar9)))) {
          uVar12 = param_4;
          if ((bool)local_dd != (uVar5 != local_20)) {
            iVar11 = FUN_0044df20(0,L"Bold",4);
            uVar12 = (uint)(iVar11 == 0);
          }
          if (*(uint *)(iVar1 + 0x50) == uVar12) {
            if (0xf < local_1c) {
              FUN_0089120c(local_30);
            }
            local_1c = 0xf;
            local_20 = 0;
            local_30 = local_30 & 0xffffff00;
            FUN_0073e5e0();
            goto LAB_0073e589;
          }
        }
        if (*(char *)((int)piVar14 + 0x15) == '\0') {
          piVar2 = (int *)piVar14[2];
          if (*(char *)((int)piVar2 + 0x15) == '\0') {
            cVar4 = *(char *)(*piVar2 + 0x15);
            piVar14 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar4 == '\0') {
              cVar4 = *(char *)(*piVar2 + 0x15);
              piVar14 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar4 = *(char *)(piVar14[1] + 0x15);
            piVar3 = (int *)piVar14[1];
            piVar2 = piVar14;
            while ((piVar14 = piVar3, cVar4 == '\0' && (piVar2 == (int *)piVar14[2]))) {
              cVar4 = *(char *)(piVar14[1] + 0x15);
              piVar3 = (int *)piVar14[1];
              piVar2 = piVar14;
            }
          }
        }
      } while (piVar14 != *(int **)(param_1 + 0x1c));
    }
    if (0xf < local_1c) {
      FUN_0089120c(local_30);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30 = local_30 & 0xffffff00;
  }
  FUN_0073e5e0();
LAB_0073e589:
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

