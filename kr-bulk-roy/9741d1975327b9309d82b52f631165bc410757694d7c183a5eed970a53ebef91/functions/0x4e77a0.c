
void FUN_004e77a0(int param_1)

{
  WCHAR WVar1;
  short *psVar2;
  HANDLE hFindFile;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  WCHAR *pWVar6;
  BOOL BVar7;
  undefined4 *in_ECX;
  uint uVar8;
  int local_26c;
  uint local_268;
  int local_264;
  _WIN32_FIND_DATAW local_260;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  hFindFile = FindFirstFileW(L"./Emblem/*_S.bmp",&local_260);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      local_26c = 0;
      local_268 = 0;
      local_264 = 0;
      iVar3 = FID_conflict__swscanf
                        (local_260.cFileName,L"%d_%d_%d_S.bmp",&local_26c,&local_268,&local_264);
      if ((iVar3 == 3) && (local_26c == param_1)) {
        puVar5 = (undefined4 *)*in_ECX;
        uVar4 = in_ECX[1] - (int)puVar5 >> 2;
        uVar8 = 0;
        if (uVar4 != 0) {
          do {
            psVar2 = (short *)*puVar5;
            if ((*psVar2 == (short)local_26c) && (*(uint *)(psVar2 + 2) == (local_268 & 0xffff))) {
              if (psVar2 != (short *)0x0) {
                if ((int)(uint)(ushort)psVar2[1] < local_264) {
                  psVar2[1] = (short)local_264;
                  FUN_00402160(L"./Emblem/",9);
                  pWVar6 = local_260.cFileName;
                  do {
                    WVar1 = *pWVar6;
                    pWVar6 = pWVar6 + 1;
                  } while (WVar1 != L'\0');
                  FUN_00404300(local_260.cFileName,(int)pWVar6 - (int)(local_260.cFileName + 1) >> 1
                              );
                  psVar2[0x14] = 1;
                  psVar2[0x15] = 0;
                }
                goto LAB_004e7984;
              }
              break;
            }
            uVar8 = uVar8 + 1;
            puVar5 = puVar5 + 1;
          } while (uVar8 < uVar4);
        }
        puVar5 = (undefined4 *)FUN_00891268(0x30);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[7] = 7;
          puVar5[6] = 0;
          *(undefined2 *)(puVar5 + 2) = 0;
          puVar5[9] = 0;
          puVar5[10] = 0;
          puVar5[0xb] = 0;
        }
        *(undefined2 *)puVar5 = (undefined2)local_26c;
        *(undefined2 *)((int)puVar5 + 2) = (undefined2)local_264;
        puVar5[1] = local_268;
        FUN_00402160(L"./Emblem/",9);
        pWVar6 = local_260.cFileName;
        do {
          WVar1 = *pWVar6;
          pWVar6 = pWVar6 + 1;
        } while (WVar1 != L'\0');
        FUN_00404300(local_260.cFileName,(int)pWVar6 - (int)(local_260.cFileName + 1) >> 1);
        puVar5[10] = 1;
        FUN_00443d10();
      }
LAB_004e7984:
      BVar7 = FindNextFileW(hFindFile,&local_260);
    } while (BVar7 != 0);
  }
  FindClose(hFindFile);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

