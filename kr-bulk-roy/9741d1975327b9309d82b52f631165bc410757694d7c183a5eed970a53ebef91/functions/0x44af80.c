
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044af80(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_EDX;
  byte *pbVar6;
  int *piVar7;
  int iVar8;
  undefined4 *local_84;
  byte *local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  byte *local_6c;
  uint local_68;
  undefined4 *local_64;
  undefined1 local_50 [16];
  undefined4 local_40 [2];
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090de59;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_84;
  ExceptionList = &local_14;
  local_70 = in_EDX;
  FUN_00823850(DAT_00d61f20 ^ (uint)&stack0xffffff70);
  pbVar6 = (byte *)(in_EDX + 3);
  local_74 = 0;
  if (*(char *)(in_EDX + 2) != '\0') {
    do {
      iVar8 = 0;
      local_6c = pbVar6;
      switch(*pbVar6) {
      case 1:
        puVar5 = (undefined4 *)FUN_00891268(2);
        if (puVar5 == (undefined4 *)0x0) {
LAB_0044b005:
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *(undefined1 *)puVar5 = 1;
        }
        goto LAB_0044b007;
      case 2:
        puVar5 = (undefined4 *)FUN_00891268(5);
        if (puVar5 == (undefined4 *)0x0) {
          _DAT_00000000 = *(undefined4 *)pbVar6;
          bRam00000004 = pbVar6[4];
          pbVar6 = pbVar6 + 5;
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *(undefined1 *)puVar5 = 2;
          *puVar5 = *(undefined4 *)pbVar6;
          *(byte *)(puVar5 + 1) = pbVar6[4];
          pbVar6 = pbVar6 + 5;
        }
        break;
      case 3:
        puVar5 = (undefined4 *)FUN_00891268(7);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *(undefined1 *)puVar5 = 3;
        }
        *puVar5 = *(undefined4 *)pbVar6;
        *(undefined2 *)(puVar5 + 1) = *(undefined2 *)(pbVar6 + 4);
        *(byte *)((int)puVar5 + 6) = pbVar6[6];
        pbVar6 = pbVar6 + 7;
        break;
      case 4:
        puVar5 = (undefined4 *)FUN_00891268(2);
        if (puVar5 == (undefined4 *)0x0) goto LAB_0044b005;
        *(undefined1 *)puVar5 = 4;
LAB_0044b007:
        *(undefined2 *)puVar5 = *(undefined2 *)pbVar6;
LAB_0044b00d:
        pbVar6 = pbVar6 + 2;
        break;
      case 5:
        local_80 = pbVar6;
        local_7c = FUN_00891268(0x14);
        local_c = 0;
        if (local_7c == 0) {
          local_84 = (undefined4 *)0x0;
        }
        else {
          local_84 = (undefined4 *)FUN_0044ac20();
        }
        local_c = 0xffffffff;
        pbVar6 = pbVar6 + 3;
        puVar5 = local_84;
        if (*(short *)(local_80 + 1) != 0) {
          do {
            local_7c = *(int *)pbVar6;
            uVar4 = FUN_006bde40(&local_7c);
            FUN_0044bbd0(local_84 + 1,uVar4);
            iVar8 = iVar8 + 1;
            pbVar6 = pbVar6 + 4;
            puVar5 = local_84;
          } while (iVar8 < (int)(uint)*(ushort *)(local_80 + 1));
        }
        break;
      case 6:
        local_80 = pbVar6;
        local_7c = FUN_00891268(0x14);
        local_c = 1;
        if (local_7c == 0) {
          local_84 = (undefined4 *)0x0;
        }
        else {
          local_84 = (undefined4 *)FUN_0044ac90();
        }
        local_c = 0xffffffff;
        pbVar6 = pbVar6 + 3;
        puVar5 = local_84;
        if (*(short *)(local_80 + 1) != 0) {
          do {
            local_7c = *(int *)pbVar6;
            uVar4 = FUN_006bde40(&local_7c);
            FUN_0044bbd0(local_84 + 1,uVar4);
            iVar8 = iVar8 + 1;
            pbVar6 = pbVar6 + 4;
            puVar5 = local_84;
          } while (iVar8 < (int)(uint)*(ushort *)(local_80 + 1));
        }
        break;
      case 7:
        puVar5 = (undefined4 *)FUN_00891268(3);
        if (puVar5 == (undefined4 *)0x0) {
LAB_0044b2b7:
          _DAT_00000000 = CONCAT13(DAT_00000000_2._1_1_,*(undefined3 *)pbVar6);
          pbVar6 = pbVar6 + 3;
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *(undefined1 *)puVar5 = 7;
          *(undefined2 *)puVar5 = *(undefined2 *)pbVar6;
          *(byte *)((int)puVar5 + 2) = pbVar6[2];
          pbVar6 = pbVar6 + 3;
        }
        break;
      default:
        FUN_006edb60("ContentsValve: Invalid RCT type");
        goto LAB_0044b03f;
      case 9:
        local_80 = pbVar6;
        local_7c = FUN_00891268(0x14);
        local_c = 2;
        if (local_7c == 0) {
          local_84 = (undefined4 *)0x0;
        }
        else {
          local_84 = (undefined4 *)FUN_0044ad00();
        }
        local_c = 0xffffffff;
        pbVar6 = pbVar6 + 3;
        puVar5 = local_84;
        if (*(short *)(local_80 + 1) != 0) {
          do {
            local_7c = *(int *)pbVar6;
            uVar4 = FUN_006bde40(&local_7c);
            FUN_0044bbd0(local_84 + 1,uVar4);
            iVar8 = iVar8 + 1;
            pbVar6 = pbVar6 + 4;
            puVar5 = local_84;
          } while (iVar8 < (int)(uint)*(ushort *)(local_80 + 1));
        }
        break;
      case 10:
        puVar5 = (undefined4 *)FUN_00891268(3);
        if (puVar5 == (undefined4 *)0x0) goto LAB_0044b2b7;
        *(undefined1 *)puVar5 = 10;
        *(undefined2 *)puVar5 = *(undefined2 *)pbVar6;
        *(byte *)((int)puVar5 + 2) = pbVar6[2];
        pbVar6 = pbVar6 + 3;
        break;
      case 0xb:
        puVar5 = (undefined4 *)FUN_00891268(3);
        if (puVar5 == (undefined4 *)0x0) goto LAB_0044b2b7;
        *(undefined1 *)puVar5 = 0xb;
        *(undefined2 *)puVar5 = *(undefined2 *)pbVar6;
        *(byte *)((int)puVar5 + 2) = pbVar6[2];
        pbVar6 = pbVar6 + 3;
        break;
      case 0xc:
        puVar5 = (undefined4 *)FUN_00891268(2);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
          _DAT_00000000 = CONCAT22(DAT_00000000_2,*(undefined2 *)pbVar6);
        }
        else {
          *(undefined1 *)puVar5 = 0xc;
          *(undefined2 *)puVar5 = *(undefined2 *)pbVar6;
        }
        goto LAB_0044b00d;
      }
      if (puVar5 != (undefined4 *)0x0) {
        local_68 = (uint)*local_6c;
        local_64 = puVar5;
        uVar4 = FUN_0057ef20();
        FUN_0044bca0(local_50,uVar4);
      }
LAB_0044b03f:
      local_74 = local_74 + 1;
    } while (local_74 < (int)(uint)*(byte *)(local_70 + 2));
  }
  piVar7 = (int *)**(int **)(local_78 + 0x14);
  if (piVar7 != *(int **)(local_78 + 0x14)) {
    do {
      local_40[0] = 0;
      local_24 = 7;
      local_28 = 0;
      local_38 = local_38 & 0xffff0000;
      local_c = 3;
      (*(code *)**(undefined4 **)piVar7[4])(piVar7[3],local_40);
      local_c = 0xffffffff;
      if (7 < local_24) {
        FUN_0089120c(local_38);
      }
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar2 = (int *)piVar7[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar7 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar7 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x15);
          piVar3 = (int *)piVar7[1];
          piVar2 = piVar7;
          while ((piVar7 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x15);
            piVar3 = (int *)piVar7[1];
            piVar2 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(local_78 + 0x14));
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_84);
  return;
}

