
void FUN_007bca20(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int *unaff_EBX;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar8;
  int local_6c;
  uint local_68;
  undefined4 local_64;
  int *local_60;
  char *local_5c;
  undefined4 local_58;
  undefined **local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  undefined1 *local_48;
  undefined1 local_44 [8];
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined1 *local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00937f15;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_6c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff88;
  ExceptionList = &local_14;
  local_6c = param_1;
  if (DAT_00d63c68 != 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x40);
    do {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 0;
        FUN_00798de0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_c = 1;
          FUN_00798de0(uVar2);
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_c = 0xffffffff;
        }
      }
      EnterCriticalSection(lpCriticalSection);
      if (*(int *)(param_1 + 0x38) == 0) {
        LeaveCriticalSection(lpCriticalSection);
        WaitForSingleObject(*(HANDLE *)(param_1 + 100),10000);
      }
      else {
        local_60 = *(int **)(param_1 + 0x34);
        local_68 = 0;
        piVar8 = (int *)*local_60;
        if ((int *)*local_60 != local_60) {
          do {
            iVar3 = piVar8[4];
            if (piVar8[2] == 1) {
              if (iVar3 == 0) {
LAB_007bcb7f:
                iVar3 = FUN_007bd270();
                if (iVar3 != 0) {
                  *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) + -1;
                  goto LAB_007bced7;
                }
                piVar8[4] = 2;
                param_1 = local_6c;
              }
              else if (iVar3 == 2) {
                iVar3 = piVar8[3];
                if (iVar3 == 3) {
                  piVar8[3] = 2;
                }
                else if (iVar3 == 2) {
                  piVar8[3] = 1;
                }
                else {
                  if (iVar3 != 1) goto LAB_007bced7;
                  piVar8[3] = 0;
                }
                goto LAB_007bcb7f;
              }
LAB_007bcba0:
              piVar7 = (int *)*piVar8;
            }
            else {
              if (iVar3 == 0) {
                iVar3 = FUN_007bd270();
                piVar8[0x13] = iVar3;
                if (iVar3 == 0) {
                  puVar4 = (undefined1 *)FUN_00891268(0x28);
                  local_c = 2;
                  local_48 = puVar4;
                  if (puVar4 == (undefined1 *)0x0) {
                    puVar4 = (undefined1 *)0x0;
                  }
                  else {
                    piVar7 = piVar8 + 0xc;
                    if (0xf < (uint)piVar8[0x11]) {
                      piVar7 = (int *)*piVar7;
                    }
                    iVar3 = piVar8[3];
                    local_5c = (char *)((int)piVar7 + 1);
                    *(undefined4 *)(puVar4 + 0x14) = 0xf;
                    *(undefined4 *)(puVar4 + 0x10) = 0;
                    *puVar4 = 0;
                    piVar5 = piVar7;
                    do {
                      iVar1 = *piVar5;
                      piVar5 = (int *)((int)piVar5 + 1);
                    } while ((char)iVar1 != '\0');
                    FUN_00402a70(piVar7,(int)piVar5 - (int)local_5c);
                    *(int *)(puVar4 + 0x20) = iVar3;
                    *(undefined4 *)(puVar4 + 0x1c) = 0;
                    *(undefined4 *)(puVar4 + 0x24) = 0;
                  }
                  piVar7 = piVar8 + 5;
                  local_c = 0xffffffff;
                  if (0xf < (uint)piVar8[10]) {
                    piVar7 = (int *)*piVar7;
                  }
                  local_28 = 0xf;
                  local_2c = 0;
                  local_3c[0] = local_3c[0] & 0xffffff00;
                  piVar5 = piVar7;
                  do {
                    iVar3 = *piVar5;
                    piVar5 = (int *)((int)piVar5 + 1);
                  } while ((char)iVar3 != '\0');
                  FUN_00402a70(piVar7,(int)piVar5 - (int)((int)piVar7 + 1));
                  iVar3 = local_6c + 0x24;
                  local_c = 3;
                  local_20 = puVar4;
                  uVar6 = FUN_00552de0(local_3c);
                  FUN_007e2910(iVar3,local_44,uVar6);
                  local_c = 0xffffffff;
                  if (0xf < local_28) {
                    FUN_0089120c(local_3c[0]);
                  }
                  local_28 = 0xf;
                  local_2c = 0;
                  local_3c[0] = local_3c[0] & 0xffffff00;
                  piVar8[0x13] = (int)puVar4;
                }
                *(int *)(piVar8[0x13] + 0x24) = *(int *)(piVar8[0x13] + 0x24) + 1;
                piVar8[4] = 1;
LAB_007bcd33:
                param_1 = local_6c;
                if (3 < local_68) goto LAB_007bcba0;
                if (*(int *)(piVar8[0x13] + 0x1c) == 0) {
                  local_68 = local_68 + 1;
                  local_58 = 0;
                  local_64 = 0;
                  if ((DAT_00fb79e8 & 1) == 0) {
                    DAT_00fb79e8 = DAT_00fb79e8 | 1;
                    local_c = 4;
                    FUN_00798de0();
                    _atexit((_func_4879 *)&LAB_00bcd2e0);
                    local_c = 0xffffffff;
                  }
                  local_50 = FUN_0079a5f0(&DAT_00fb76a8);
                  local_4c = &local_64;
                  local_54 = `long___cdecl_Graphics::LoadTextureFromFile(IDirect3DDevice9*,char_const*,IDirect3DTexture9**)'
                             ::__l2::CreateTextureFromFileBox::vftable;
                  iVar3 = FUN_00737d40();
                  if (iVar3 == 0) {
                    if ((DAT_00fb79e8 & 1) == 0) {
                      DAT_00fb79e8 = DAT_00fb79e8 | 1;
                      local_c = 5;
                      FUN_00798de0();
                      _atexit((_func_4879 *)&LAB_00bcd2e0);
                      local_c = 0xffffffff;
                    }
                    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
                    if ((DAT_00fb79e8 & 1) == 0) {
                      DAT_00fb79e8 = DAT_00fb79e8 | 1;
                      local_c = 6;
                      FUN_00798de0();
                      _atexit((_func_4879 *)&LAB_00bcd2e0);
                      local_c = 0xffffffff;
                      if ((DAT_00fb79e8 & 1) == 0) {
                        DAT_00fb79e8 = DAT_00fb79e8 | 1;
                        local_c = 7;
                        FUN_00798de0();
                        _atexit((_func_4879 *)&LAB_00bcd2e0);
                        local_c = 0xffffffff;
                      }
                    }
                    piVar7 = piVar8 + 5;
                    if (0xf < (uint)piVar8[10]) {
                      piVar7 = (int *)*piVar7;
                    }
                    (**(code **)(*DAT_00fb76a8 + 0x50))(piVar7,local_64,&local_58);
                    (**(code **)(*unaff_EBX + 8))(unaff_EBX);
                    if ((DAT_00fb79e8 & 1) == 0) {
                      DAT_00fb79e8 = DAT_00fb79e8 | 1;
                      local_c = 8;
                      FUN_00798de0();
                      _atexit((_func_4879 *)&LAB_00bcd2e0);
                      local_c = 0xffffffff;
                    }
                    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
                  }
                  *(undefined4 *)(piVar8[0x13] + 0x1c) = 1;
                }
              }
              else {
                if (iVar3 != 1) goto LAB_007bcba0;
                iVar3 = FUN_007bd270();
                piVar8[0x13] = iVar3;
                if (iVar3 != 0) goto LAB_007bcd33;
              }
LAB_007bced7:
              param_1 = local_6c;
              piVar7 = (int *)*piVar8;
              if (piVar8 != *(int **)(local_6c + 0x34)) {
                *(int **)piVar8[1] = piVar7;
                *(int *)(*piVar8 + 4) = piVar8[1];
                if (0xf < (uint)piVar8[0x11]) {
                  FUN_0089120c(piVar8[0xc]);
                }
                piVar8[0x11] = 0xf;
                piVar8[0x10] = 0;
                *(undefined1 *)(piVar8 + 0xc) = 0;
                if (0xf < (uint)piVar8[10]) {
                  FUN_0089120c(piVar8[5]);
                }
                piVar8[10] = 0xf;
                piVar8[9] = 0;
                *(undefined1 *)(piVar8 + 5) = 0;
                FUN_0089120c(piVar8);
                *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
              }
              local_60 = *(int **)(param_1 + 0x34);
            }
            piVar8 = piVar7;
          } while (piVar7 != local_60);
          FUN_007bd340(param_1);
        }
        lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x40);
        LeaveCriticalSection(lpCriticalSection);
        Sleep(0x14);
      }
    } while (DAT_00d63c68 != 0);
  }
  SetEvent(DAT_00d63c6c);
  __endthread();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_6c);
  return;
}

