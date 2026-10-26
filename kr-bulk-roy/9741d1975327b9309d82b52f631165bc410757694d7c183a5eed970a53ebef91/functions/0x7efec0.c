
void FUN_007efec0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int in_ECX;
  char *pcVar8;
  int iVar9;
  int *piVar10;
  int *local_ac;
  int *local_a8;
  int local_a4;
  undefined4 local_a0;
  undefined1 local_99;
  int local_98;
  int local_94;
  undefined4 local_90;
  undefined4 auStack_88 [4];
  undefined4 uStack_78;
  undefined4 uStack_68;
  uint uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  local_c = 0xff;
  uStack_b = 0xffffff;
  puStack_10 = &LAB_009349a1;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_ac;
  ExceptionList = &local_14;
  local_a4 = in_ECX;
  if (*(int *)(in_ECX + 0x128) == 0) {
    pcVar8 = (char *)(in_ECX + 0xb4);
    if (0xf < *(uint *)(in_ECX + 200)) {
      pcVar8 = *(char **)pcVar8;
    }
    local_24 = 0xf;
    local_28 = 0;
    local_38 = local_38 & 0xffffff00;
    pcVar4 = pcVar8;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar8,(int)pcVar4 - (int)(pcVar8 + 1));
    local_c = 0;
    uStack_b = 0;
    FUN_00401fc0("mesh/",5);
    pcVar8 = (char *)(in_ECX + 0x44);
    if (0xf < *(uint *)(in_ECX + 0x58)) {
      pcVar8 = *(char **)pcVar8;
    }
    pcVar4 = pcVar8;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(pcVar8,(int)pcVar4 - (int)(pcVar8 + 1));
    if ((DAT_00fe321c & 1) == 0) {
      DAT_00fe321c = DAT_00fe321c | 1;
      local_c = 1;
      FUN_007d0fb0(&local_99);
      _atexit((_func_4879 *)&LAB_00bd09c0);
      local_c = 0;
    }
    local_a8 = (int *)FUN_007d0920(0);
    if (local_a8 == (int *)0x0) {
      local_a8 = (int *)0x0;
    }
    else {
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      _local_c = CONCAT31(uStack_b,2);
      FUN_007c7dd0(local_a8,&local_98);
      local_ac = (int *)0x0;
      if (local_94 - local_98 >> 2 != 0) {
        do {
          iVar2 = *(int *)(local_98 + (int)local_ac * 4);
          if (*(uint *)(local_a4 + 0x74) < 0x10) {
            iVar9 = local_a4 + 0x60;
          }
          else {
            iVar9 = *(int *)(local_a4 + 0x60);
          }
          if ((DAT_00fb79e8 & 1) == 0) {
            DAT_00fb79e8 = DAT_00fb79e8 | 1;
            local_c = 3;
            FUN_00798de0();
            _atexit((_func_4879 *)&LAB_00bcd2e0);
            _local_c = CONCAT31(uStack_b,2);
          }
          FUN_0079be00(iVar9);
          uVar3 = local_a0;
          iVar9 = 0;
          if (0 < *(int *)(iVar2 + 0x178)) {
            do {
              iVar5 = FUN_00843ef0();
              iVar9 = iVar9 + 1;
              *(undefined4 *)(iVar5 + 0x24) = 0;
              *(undefined4 *)(iVar5 + 0xb8) = uVar3;
            } while (iVar9 < *(int *)(iVar2 + 0x178));
          }
          local_ac = (int *)((int)local_ac + 1);
        } while (local_ac < (int *)(local_94 - local_98 >> 2));
      }
      piVar10 = local_a8;
      iVar9 = (**(code **)(*local_a8 + 0xc))();
      iVar2 = local_a4;
      *(int **)(local_a4 + 0x11c) = piVar10;
      local_a8 = (int *)FUN_00891268(0xe8);
      local_c = 4;
      if (local_a8 == (int *)0x0) {
        local_ac = (int *)0x0;
      }
      else {
        local_ac = (int *)FUN_0077ebb0();
      }
      piVar10 = local_ac;
      pcVar8 = (char *)(iVar9 + 8);
      local_c = 2;
      if (0xf < *(uint *)(iVar9 + 0x1c)) {
        pcVar8 = *(char **)pcVar8;
      }
      pcVar4 = pcVar8;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar8,(int)pcVar4 - (int)(pcVar8 + 1));
      (**(code **)(*piVar10 + 0x40))(iVar9);
      FUN_0077f030(*(undefined4 *)(local_a4 + 4),*(undefined4 *)(local_a4 + 8),
                   *(undefined4 *)(local_a4 + 0xc));
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0x3f800000;
      local_a8 = *(int **)(local_a4 + 0x10);
      local_a0 = *(undefined4 *)(local_a4 + 0x14);
      local_a4 = *(int *)(local_a4 + 0x18);
      _memset(auStack_88,0,0x34);
      uStack_68 = 0x3f800000;
      uStack_78 = 0x3f800000;
      auStack_88[0] = 0x3f800000;
      FUN_00790dc0(local_a8);
      FUN_00790e90(local_a0);
      FUN_00790f60(local_a4);
      FUN_00780890();
      FUN_0077efc0();
      FUN_0077ef50(*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x20),
                   *(undefined4 *)(iVar2 + 0x24));
      if (*(uint *)(iVar9 + 0x1c) < 0x10) {
        pcVar8 = (char *)(iVar9 + 8);
      }
      else {
        pcVar8 = *(char **)(iVar9 + 8);
      }
      pcVar4 = pcVar8;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar8,(int)pcVar4 - (int)(pcVar8 + 1));
      if (*(int *)(iVar2 + 0xe0) != 0) {
        FUN_00403040(iVar2 + 0xd0,0,0xffffffff);
      }
      *(int *)(iVar2 + 0x120) = iVar9;
      *(int **)(iVar2 + 0x124) = local_ac;
      FUN_007c7030(local_ac,3);
      *(undefined4 *)(iVar2 + 0x128) = 1;
      piVar10 = (int *)**(int **)(iVar2 + 0x110);
      if (piVar10 != *(int **)(iVar2 + 0x110)) {
        do {
          pcVar8 = (char *)(iVar2 + 0xb4);
          if (0xf < *(uint *)(iVar2 + 200)) {
            pcVar8 = *(char **)pcVar8;
          }
          uStack_40 = 0xf;
          uStack_44 = 0;
          uStack_54 = uStack_54 & 0xffffff00;
          pcVar4 = pcVar8;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar8,(int)pcVar4 - (int)(pcVar8 + 1));
          local_c = 5;
          FUN_00401fc0(&DAT_00c4fe14,4);
          if ((uint)piVar10[9] < 0x10) {
            piVar7 = piVar10 + 4;
          }
          else {
            piVar7 = (int *)piVar10[4];
          }
          piVar6 = piVar7;
          do {
            iVar9 = *piVar6;
            piVar6 = (int *)((int)piVar6 + 1);
          } while ((char)iVar9 != '\0');
          FUN_00401fc0(piVar7,(int)piVar6 - (int)((int)piVar7 + 1));
          piVar10[0xb] = 0;
          iVar9 = piVar10[8];
          iVar5 = FUN_00407e70(0);
          if (iVar5 != 0 || CONCAT31((int3)((uint)iVar5 >> 8),iVar9 != 0) != 0) {
            piVar7 = (int *)FUN_00891268(0x2c);
            local_c = 6;
            local_a8 = piVar7;
            if (piVar7 == (int *)0x0) {
              piVar7 = (int *)0x0;
            }
            else {
              iVar9 = piVar10[3];
              *piVar7 = iVar9 * 3000;
              piVar7[2] = iVar9;
              piVar7[1] = 0;
              piVar7[3] = 0;
              piVar7[9] = 0xf;
              piVar7[8] = 0;
              *(undefined1 *)(piVar7 + 4) = 0;
              FUN_00403040(&uStack_54,0,0xffffffff);
            }
            if ((DAT_00fd94d8 & 1) == 0) {
              DAT_00fd94d8 = DAT_00fd94d8 | 1;
              local_c = 7;
              FUN_007b5430();
              _atexit((_func_4879 *)&LAB_00bce660);
            }
            local_c = 5;
            FUN_007b61d0(&DAT_00fd9420,piVar7,iVar2 + 0x40);
          }
          if (*(char *)((int)piVar10 + 0x31) == '\0') {
            piVar7 = (int *)piVar10[2];
            if (*(char *)((int)piVar7 + 0x31) == '\0') {
              cVar1 = *(char *)(*piVar7 + 0x31);
              piVar10 = piVar7;
              piVar7 = (int *)*piVar7;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar7 + 0x31);
                piVar10 = piVar7;
                piVar7 = (int *)*piVar7;
              }
            }
            else {
              cVar1 = *(char *)(piVar10[1] + 0x31);
              piVar6 = (int *)piVar10[1];
              piVar7 = piVar10;
              while ((piVar10 = piVar6, cVar1 == '\0' && (piVar7 == (int *)piVar10[2]))) {
                cVar1 = *(char *)(piVar10[1] + 0x31);
                piVar6 = (int *)piVar10[1];
                piVar7 = piVar10;
              }
            }
          }
          local_c = 2;
          if (0xf < uStack_40) {
            FUN_0089120c(uStack_54);
          }
        } while (piVar10 != *(int **)(iVar2 + 0x110));
      }
      if (local_98 != 0) {
        FUN_0089120c(local_98);
      }
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
    }
    if (0xf < local_24) {
      FUN_0089120c(local_38);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_ac);
  return;
}

