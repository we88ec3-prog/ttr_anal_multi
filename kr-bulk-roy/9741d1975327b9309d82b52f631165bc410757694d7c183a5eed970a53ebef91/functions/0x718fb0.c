
/* WARNING: Type propagation algorithm not settling */

void FUN_00718fb0(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  char *pcVar8;
  HANDLE pvVar9;
  int iVar10;
  char *pcVar11;
  CHAR *pCVar12;
  LPCSTR ******pppppppCVar13;
  int iVar14;
  BOOL BVar15;
  int in_ECX;
  byte *pbVar16;
  undefined4 *puVar17;
  int *unaff_FS_OFFSET;
  bool bVar18;
  undefined1 local_344 [8];
  undefined4 *local_33c;
  undefined4 *local_338;
  undefined4 local_334;
  int local_32c;
  char *local_328;
  int local_324;
  undefined1 *local_320;
  char *local_31c;
  int local_318;
  HANDLE local_314;
  _WIN32_FIND_DATAA local_310;
  _WIN32_FIND_DATAA local_1d0;
  LPCSTR ******local_8c [4];
  undefined4 local_7c;
  uint local_78;
  uint local_70;
  uint local_6c;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  undefined1 *local_54;
  uint local_50 [4];
  undefined4 local_40;
  uint local_3c;
  LPCSTR ******local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  int local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00928996;
  local_10 = *unaff_FS_OFFSET;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_328 = param_1;
  local_31c = param_2;
  local_33c = (undefined4 *)0x0;
  local_338 = (undefined4 *)0x0;
  local_334 = 0;
  local_8 = 0;
  local_324 = in_ECX;
  if (param_3 != 0) {
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (LPCSTR ******)((uint)local_34[0] & 0xffffff00);
    pcVar8 = param_2;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(param_2,(int)pcVar8 - (int)(param_2 + 1));
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00401fc0(&DAT_00c444b0,3);
    _memset(&local_1d0,0,0x140);
    pppppppCVar13 = local_34[0];
    if (local_20 < 0x10) {
      pppppppCVar13 = (LPCSTR ******)local_34;
    }
    pvVar9 = FindFirstFileA((LPCSTR)pppppppCVar13,&local_1d0);
    local_314 = pvVar9;
    if (pvVar9 == (HANDLE)0xffffffff) {
      FindClose((HANDLE)0xffffffff);
    }
    else {
      do {
        if ((((byte)local_1d0.dwFileAttributes & 0x10) != 0) &&
           (((byte)local_1d0.dwFileAttributes & 2) == 0)) {
          pbVar16 = &DAT_00c41190;
          pCVar12 = local_1d0.cFileName;
          do {
            bVar2 = *pCVar12;
            bVar18 = bVar2 < *pbVar16;
            if (bVar2 != *pbVar16) {
LAB_007190e1:
              iVar10 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
              goto LAB_007190e6;
            }
            if (bVar2 == 0) break;
            bVar2 = pCVar12[1];
            bVar18 = bVar2 < pbVar16[1];
            if (bVar2 != pbVar16[1]) goto LAB_007190e1;
            pCVar12 = pCVar12 + 2;
            pbVar16 = pbVar16 + 2;
          } while (bVar2 != 0);
          iVar10 = 0;
LAB_007190e6:
          if (iVar10 != 0) {
            pbVar16 = &DAT_00c42c80;
            pCVar12 = local_1d0.cFileName;
            do {
              bVar2 = *pCVar12;
              bVar18 = bVar2 < *pbVar16;
              if (bVar2 != *pbVar16) {
LAB_00719120:
                iVar10 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
                goto LAB_00719125;
              }
              if (bVar2 == 0) break;
              bVar2 = pCVar12[1];
              bVar18 = bVar2 < pbVar16[1];
              if (bVar2 != pbVar16[1]) goto LAB_00719120;
              pCVar12 = pCVar12 + 2;
              pbVar16 = pbVar16 + 2;
            } while (bVar2 != 0);
            iVar10 = 0;
LAB_00719125:
            if (iVar10 != 0) {
              pCVar12 = local_1d0.cFileName;
              local_3c = 0xf;
              local_40 = 0;
              local_50[0] = local_50[0] & 0xffffff00;
              do {
                cVar1 = *pCVar12;
                pCVar12 = pCVar12 + 1;
              } while (cVar1 != '\0');
              FUN_00402a70(local_1d0.cFileName,(int)pCVar12 - (int)(local_1d0.cFileName + 1));
              local_8._0_1_ = 2;
              FUN_00440c60();
              local_8 = CONCAT31(local_8._1_3_,1);
              if (0xf < local_3c) {
                FUN_0089120c(local_50[0]);
              }
            }
          }
        }
        pvVar9 = local_314;
        BVar15 = FindNextFileA(local_314,&local_1d0);
      } while (BVar15 != 0);
    }
    FindClose(pvVar9);
    local_8 = local_8 & 0xffffff00;
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
  }
  local_78 = 0xf;
  local_7c = 0;
  local_8c[0] = (LPCSTR ******)((uint)local_8c[0] & 0xffffff00);
  pcVar8 = param_2;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar8 - (int)(param_2 + 1));
  local_8 = CONCAT31(local_8._1_3_,3);
  pcVar8 = local_328;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_328,(int)pcVar8 - (int)(local_328 + 1));
  _memset(&local_310,0,0x140);
  pppppppCVar13 = local_8c[0];
  if (local_78 < 0x10) {
    pppppppCVar13 = (LPCSTR ******)local_8c;
  }
  local_314 = FindFirstFileA((LPCSTR)pppppppCVar13,&local_310);
  if (local_314 == (HANDLE)0xffffffff) {
    FindClose((HANDLE)0xffffffff);
  }
  else {
    do {
      if (((byte)local_310.dwFileAttributes & 0x12) == 0) {
        local_320 = (undefined1 *)FUN_00891268(0x38);
        if (local_320 == (undefined1 *)0x0) {
          local_320 = (undefined1 *)0x0;
        }
        else {
          *(undefined4 *)(local_320 + 0x14) = 0xf;
          *(undefined4 *)(local_320 + 0x10) = 0;
          *local_320 = 0;
          *(undefined4 *)(local_320 + 0x30) = 0xf;
          *(undefined4 *)(local_320 + 0x2c) = 0;
          local_320[0x1c] = 0;
        }
        pcVar8 = local_31c;
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(local_31c,(int)pcVar8 - (int)(local_31c + 1));
        pCVar12 = local_310.cFileName;
        do {
          cVar1 = *pCVar12;
          pCVar12 = pCVar12 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(local_310.cFileName,(int)pCVar12 - (int)(local_310.cFileName + 1));
        _strcpy_s(local_1d0.cFileName + 0xc,0x104,local_310.cFileName);
        FUN_007198b0(local_1d0.cFileName + 0xc);
        pCVar12 = local_1d0.cFileName + 0xc;
        local_3c = 0xf;
        local_40 = 0;
        local_50[0] = local_50[0] & 0xffffff00;
        do {
          cVar1 = *pCVar12;
          pCVar12 = pCVar12 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(local_1d0.cFileName + 0xc,(int)pCVar12 - (int)(local_1d0.cFileName + 0xd));
        iVar7 = local_324;
        local_8._0_1_ = 4;
        iVar10 = *(int *)(local_324 + 8);
        FUN_007b86f0(&local_318,local_50);
        bVar18 = local_318 == iVar10;
        local_8._0_1_ = 3;
        if (0xf < local_3c) {
          FUN_0089120c(local_50[0]);
        }
        pCVar12 = local_1d0.cFileName + 0xc;
        if (bVar18) {
          local_5c = 0xf;
          local_60 = 0;
          local_70 = local_70 & 0xffffff00;
          do {
            cVar1 = *pCVar12;
            pCVar12 = pCVar12 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(local_1d0.cFileName + 0xc,(int)pCVar12 - (int)(local_1d0.cFileName + 0xd));
          local_54 = local_320;
          local_8._0_1_ = 8;
          iVar10 = **(int **)(iVar7 + 8);
          iVar14 = FUN_00719b90(iVar10,*(undefined4 *)(iVar10 + 4),&local_70);
          if (*(int *)(iVar7 + 0xc) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("list<T> too long");
          }
          *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;
          *(int *)(iVar10 + 4) = iVar14;
          **(int **)(iVar14 + 4) = iVar14;
          FUN_007d1080(local_344,**(int **)(iVar7 + 8) + 8,**(int **)(iVar7 + 8));
          uVar3 = local_70;
          uVar5 = local_5c;
        }
        else {
          local_3c = 0xf;
          local_40 = 0;
          local_50[0] = local_50[0] & 0xffffff00;
          do {
            cVar1 = *pCVar12;
            pCVar12 = pCVar12 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(local_1d0.cFileName + 0xc,(int)pCVar12 - (int)(local_1d0.cFileName + 0xd));
          local_8._0_1_ = 5;
          FUN_007b86f0(&local_32c,local_50);
          local_8._0_1_ = 3;
          if (0xf < local_3c) {
            FUN_0089120c(local_50[0]);
          }
          iVar10 = local_32c;
          pcVar8 = *(char **)(local_32c + 0x24);
          if (0xf < *(uint *)(pcVar8 + 0x14)) {
            pcVar8 = *(char **)pcVar8;
          }
          local_5c = 0;
          local_58 = 0xf;
          local_6c = local_6c & 0xffffff00;
          pcVar11 = pcVar8;
          do {
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar8,(int)pcVar11 - (int)(pcVar8 + 1));
          local_8._0_1_ = 6;
          if (*(uint *)(iVar10 + 0x1c) < 0x10) {
            pcVar8 = (char *)(iVar10 + 8);
          }
          else {
            pcVar8 = *(char **)(iVar10 + 8);
          }
          pcVar11 = pcVar8;
          do {
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(pcVar8,(int)pcVar11 - (int)(pcVar8 + 1));
          local_20 = 0xf;
          local_24 = 0;
          local_34[0] = (LPCSTR ******)((uint)local_34[0] & 0xffffff00);
          FUN_00402a70("Conflict : ",0xb);
          local_8 = CONCAT31(local_8._1_3_,7);
          pcVar8 = *(char **)(local_32c + 0x24);
          if (0xf < *(uint *)(pcVar8 + 0x14)) {
            pcVar8 = *(char **)pcVar8;
          }
          pcVar11 = pcVar8;
          do {
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(pcVar8,(int)pcVar11 - (int)(pcVar8 + 1));
          if (*(uint *)(iVar10 + 0x1c) < 0x10) {
            pcVar8 = (char *)(iVar10 + 8);
          }
          else {
            pcVar8 = *(char **)(iVar10 + 8);
          }
          pcVar11 = pcVar8;
          do {
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(pcVar8,(int)pcVar11 - (int)(pcVar8 + 1));
          FUN_00401fc0(&DAT_00c444c0,2);
          pcVar8 = local_31c;
          do {
            cVar1 = *pcVar8;
            pcVar8 = pcVar8 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(local_31c,(int)pcVar8 - (int)(local_31c + 1));
          pCVar12 = local_310.cFileName;
          do {
            cVar1 = *pCVar12;
            pCVar12 = pCVar12 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(local_310.cFileName,(int)pCVar12 - (int)(local_310.cFileName + 1));
          FUN_00401fc0(&DAT_00c411c0,1);
          pppppppCVar13 = local_34[0];
          if (local_20 < 0x10) {
            pppppppCVar13 = (LPCSTR ******)local_34;
          }
          OutputDebugStringA((LPCSTR)pppppppCVar13);
          if (local_320 != (undefined1 *)0x0) {
            FUN_00718e80();
          }
          if (0xf < local_20) {
            FUN_0089120c(local_34[0]);
          }
          local_20 = 0xf;
          local_24 = 0;
          local_34[0] = (LPCSTR ******)((uint)local_34[0] & 0xffffff00);
          uVar3 = local_6c;
          uVar5 = local_58;
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        if (0xf < uVar5) {
          FUN_0089120c(uVar3);
        }
      }
      BVar15 = FindNextFileA(local_314,&local_310);
    } while (BVar15 != 0);
  }
  FindClose(local_314);
  pcVar8 = local_31c;
  pvVar9 = (HANDLE)(((int)local_338 - (int)local_33c) / 0x1c);
  puVar17 = local_33c;
  if (pvVar9 != (HANDLE)0x0) {
    do {
      local_314 = pvVar9;
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = (LPCSTR ******)((uint)local_34[0] & 0xffffff00);
      pcVar11 = pcVar8;
      do {
        cVar1 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar8,(int)pcVar11 - (int)(pcVar8 + 1));
      local_8._0_1_ = 9;
      FUN_00401ed0(puVar17,0,0xffffffff);
      FUN_00401fc0(&DAT_00c420d4,1);
      pppppppCVar13 = local_34[0];
      if (local_20 < 0x10) {
        pppppppCVar13 = (LPCSTR ******)local_34;
      }
      FUN_00718fb0(local_328,pppppppCVar13,param_3);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      puVar17 = puVar17 + 7;
      pvVar9 = (HANDLE)((int)local_314 + -1);
    } while ((int)local_314 + -1 != 0);
    local_314 = (HANDLE)0x0;
  }
  puVar17 = local_33c;
  local_318 = *(int *)(local_324 + 0xc);
  if (0xf < local_78) {
    FUN_0089120c(local_8c[0]);
  }
  puVar6 = local_338;
  local_78 = 0xf;
  local_7c = 0;
  local_8c[0] = (LPCSTR ******)((uint)local_8c[0] & 0xffffff00);
  puVar4 = local_33c;
  if (puVar17 != (undefined4 *)0x0) {
    for (; puVar4 != puVar6; puVar4 = puVar4 + 7) {
      if (0xf < (uint)puVar4[5]) {
        FUN_0089120c(*puVar4);
      }
      puVar4[5] = 0xf;
      puVar4[4] = 0;
      *(undefined1 *)puVar4 = 0;
    }
    FUN_0089120c(local_33c);
  }
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

