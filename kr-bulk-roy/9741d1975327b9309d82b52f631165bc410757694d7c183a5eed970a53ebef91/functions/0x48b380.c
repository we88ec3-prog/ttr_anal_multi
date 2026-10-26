
void FUN_0048b380(int param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined1 uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 ****ppppuVar8;
  uint *puVar9;
  uint uVar10;
  char *pcVar11;
  undefined1 *puVar12;
  undefined1 local_78 [8];
  undefined1 local_70 [4];
  undefined1 local_6c [4];
  undefined4 ***local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  uint *local_4c;
  char *local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009177d0;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_48 = param_2;
  if (param_1 != 0) {
    FUN_00719da0(&local_44);
    while (local_44 != 0) {
      FUN_0071baa0(&DAT_00bed1d4);
      if (local_54 == 0) {
        pcVar11 = (char *)0x0;
      }
      else {
        pcVar11 = *(char **)(local_54 + 8);
        if (pcVar11 == (char *)0x0) {
          pcVar11 = "";
        }
      }
      FUN_0071baa0("Checksum");
      if (local_4c == (uint *)0x0) {
        pcVar4 = (char *)0x0;
      }
      else {
        pcVar4 = (char *)local_4c[2];
        if (pcVar4 == (char *)0x0) {
          pcVar4 = "";
        }
      }
      if ((pcVar11 == (char *)0x0) || (pcVar4 == (char *)0x0)) {
LAB_0048b587:
        puVar12 = local_70;
      }
      else {
        pcVar1 = pcVar4 + 1;
        do {
          cVar2 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        if ((int)pcVar4 - (int)pcVar1 != 0x20) goto LAB_0048b587;
        pcVar4 = pcVar11;
        do {
          cVar2 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        pcVar1 = pcVar11;
        if ((uint)((int)pcVar4 - (int)(pcVar11 + 1)) < 5) {
LAB_0048b4a8:
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
          pcVar4 = local_48;
          do {
            cVar2 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar2 != '\0');
          FUN_00402a70(local_48,(int)pcVar4 - (int)(local_48 + 1));
          local_8 = 0;
          pcVar4 = pcVar11;
          do {
            cVar2 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar2 != '\0');
          FUN_00401fc0(pcVar11,(int)pcVar4 - (int)(pcVar11 + 1));
          FUN_0048b8c0(local_30);
          iVar5 = 0;
          do {
            uVar3 = FUN_0049b1b0();
            *(undefined1 *)((int)&local_40 + iVar5) = uVar3;
            iVar5 = iVar5 + 1;
          } while (iVar5 < 0x10);
          local_68 = local_30[0];
          if (local_1c < 0x10) {
            local_68 = local_30;
          }
          local_60 = local_3c;
          local_64 = local_40;
          iVar5 = local_50 + 8;
          local_5c = local_38;
          local_58 = local_34;
          uVar6 = FUN_004992a0(&local_68);
          FUN_00498f80(iVar5,local_78,uVar6);
          local_8 = 0xffffffff;
          if (0xf < local_1c) {
            FUN_0089120c(local_30[0]);
          }
          goto LAB_0048b587;
        }
        do {
          pcVar4 = pcVar1;
          pcVar1 = pcVar4 + 1;
        } while (*pcVar4 != '\0');
        iVar5 = __stricmp(pcVar4 + -4,".stp");
        if (iVar5 != 0) goto LAB_0048b4a8;
        puVar12 = local_6c;
      }
      piVar7 = (int *)FUN_00719e00(puVar12);
      local_44 = *piVar7;
    }
    FUN_00719da0(&local_4c);
    puVar9 = local_4c;
    if (local_4c != (uint *)0x0) {
LAB_0048b5c1:
      if (puVar9 != (uint *)0x0) {
        uVar10 = puVar9[7];
        if (uVar10 != 0) {
LAB_0048b5d4:
          if ((*(char **)(uVar10 + 4) == (char *)0x0) ||
             (iVar5 = __stricmp("name",*(char **)(uVar10 + 4)), iVar5 != 0)) goto LAB_0048b5ed;
          pcVar11 = *(char **)(uVar10 + 8);
          if (pcVar11 == (char *)0x0) {
            pcVar11 = "";
          }
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
          pcVar4 = local_48;
          do {
            cVar2 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar2 != '\0');
          FUN_00402a70(local_48,(int)pcVar4 - (int)(local_48 + 1));
          local_8 = 1;
          pcVar4 = pcVar11;
          do {
            cVar2 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar2 != '\0');
          FUN_00401fc0(pcVar11,(int)pcVar4 - (int)(pcVar11 + 1));
          FUN_00401fc0(&DAT_00bed1e4,1);
          ppppuVar8 = (undefined4 ****)local_30[0];
          if (local_1c < 0x10) {
            ppppuVar8 = local_30;
          }
          FUN_0048b380(puVar9,ppppuVar8);
          local_8 = 0xffffffff;
          if (0xf < local_1c) {
            FUN_0089120c(local_30[0]);
          }
        }
LAB_0048b691:
        for (puVar9 = (uint *)puVar9[6]; puVar9 != (uint *)0x0; puVar9 = (uint *)puVar9[6]) {
          if (((char *)puVar9[2] != (char *)0x0) &&
             (iVar5 = __stricmp("FOLDER",(char *)puVar9[2]), iVar5 == 0)) {
            if (puVar9 == (uint *)0x0) goto LAB_0048b6f2;
            goto LAB_0048b6c0;
          }
        }
      }
      goto LAB_0048b6f8;
    }
  }
LAB_0048b704:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_0048b5ed:
  uVar10 = *(uint *)(uVar10 + 0x10);
  if (uVar10 == 0) goto LAB_0048b691;
  goto LAB_0048b5d4;
LAB_0048b6c0:
  do {
    if ((*puVar9 & 7) == 1) goto LAB_0048b6fa;
    for (puVar9 = (uint *)puVar9[6]; puVar9 != (uint *)0x0; puVar9 = (uint *)puVar9[6]) {
      if (((char *)puVar9[2] != (char *)0x0) &&
         (iVar5 = __stricmp("FOLDER",(char *)puVar9[2]), iVar5 == 0)) goto LAB_0048b6f4;
    }
LAB_0048b6f2:
    puVar9 = (uint *)0x0;
LAB_0048b6f4:
  } while (puVar9 != (uint *)0x0);
LAB_0048b6f8:
  puVar9 = (uint *)0x0;
LAB_0048b6fa:
  if (puVar9 == (uint *)0x0) goto LAB_0048b704;
  goto LAB_0048b5c1;
}

