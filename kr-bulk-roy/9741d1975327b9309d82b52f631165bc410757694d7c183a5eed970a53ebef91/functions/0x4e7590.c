
void FUN_004e7590(int param_1,int param_2)

{
  WCHAR WVar1;
  short *psVar2;
  HANDLE hFindFile;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  BOOL BVar6;
  WCHAR *pWVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint local_268;
  int local_264;
  int local_260;
  _WIN32_FIND_DATAW local_25c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  hFindFile = FindFirstFileW(L"./Emblem/*_B.bmp",&local_25c);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      local_260 = 0;
      local_268 = 0;
      local_264 = 0;
      iVar3 = FID_conflict__swscanf
                        (local_25c.cFileName,L"%d_%d_%d_B.bmp",&local_260,&local_268,&local_264);
      if ((iVar3 == 3) && (local_260 == param_2)) {
        uVar8 = 0;
        uVar4 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2;
        if (uVar4 != 0) {
          puVar9 = *(undefined4 **)(param_1 + 0x10);
          do {
            psVar2 = (short *)*puVar9;
            if ((*psVar2 == (short)local_260) && (*(uint *)(psVar2 + 2) == (local_268 & 0xffff))) {
              if (psVar2 != (short *)0x0) {
                if ((int)(uint)(ushort)psVar2[1] < local_264) {
                  psVar2[1] = (short)local_264;
                  FUN_00402160(L"./Emblem/",9);
                  pWVar7 = local_25c.cFileName;
                  do {
                    WVar1 = *pWVar7;
                    pWVar7 = pWVar7 + 1;
                  } while (WVar1 != L'\0');
                  FUN_00404300(local_25c.cFileName,(int)pWVar7 - (int)(local_25c.cFileName + 1) >> 1
                              );
                  psVar2[0x14] = 1;
                  psVar2[0x15] = 0;
                }
                goto LAB_004e7704;
              }
              break;
            }
            uVar8 = uVar8 + 1;
            puVar9 = puVar9 + 1;
          } while (uVar8 < uVar4);
        }
        puVar5 = (undefined4 *)FUN_00891268(0x30);
        puVar9 = (undefined4 *)0x0;
        if (puVar5 != (undefined4 *)0x0) {
          puVar5[1] = 0;
          *puVar5 = 0;
          puVar5[6] = 0;
          puVar5[7] = 7;
          *(undefined2 *)(puVar5 + 2) = 0;
          puVar5[9] = 0;
          puVar5[10] = 0;
          puVar5[0xb] = 0;
          puVar9 = puVar5;
        }
        *(short *)puVar9 = (short)local_260;
        *(undefined2 *)((int)puVar9 + 2) = (undefined2)local_264;
        puVar9[1] = local_268;
        FUN_00402160(L"./Emblem/",9);
        pWVar7 = local_25c.cFileName;
        do {
          WVar1 = *pWVar7;
          pWVar7 = pWVar7 + 1;
        } while (WVar1 != L'\0');
        FUN_00404300(local_25c.cFileName,(int)pWVar7 - (int)(local_25c.cFileName + 1) >> 1);
        puVar9[10] = 1;
        FUN_00443d10();
      }
LAB_004e7704:
      BVar6 = FindNextFileW(hFindFile,&local_25c);
    } while (BVar6 != 0);
  }
  FindClose(hFindFile);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

