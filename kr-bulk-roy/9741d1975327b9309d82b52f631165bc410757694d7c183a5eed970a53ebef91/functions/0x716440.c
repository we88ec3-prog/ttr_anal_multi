
void FUN_00716440(int param_1)

{
  char cVar1;
  void *pvVar2;
  FILE *_File;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int *unaff_FS_OFFSET;
  uint local_5c;
  uint local_58;
  char *pcStack_54;
  void *pvStack_50;
  FILE *local_4c;
  int iStack_48;
  int local_44;
  int iStack_40;
  int iStack_3c;
  uint auStack_38 [4];
  uint uStack_28;
  uint uStack_24;
  uint local_1c;
  int local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00917e58;
  local_14 = *unaff_FS_OFFSET;
  local_1c = DAT_00d61f20 ^ (uint)&local_5c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  *unaff_FS_OFFSET = (int)&local_14;
  local_44 = param_1;
  local_4c = _fopen("fcs.flu","rb");
  if (local_4c != (FILE *)0x0) {
    local_5c = 0;
    local_58 = 0;
    _fread(&local_5c,8,1,local_4c);
    uVar5 = local_5c;
    pvStack_50 = (void *)FUN_0087dc3d(-(uint)((int)((ulonglong)local_5c * 0x158 >> 0x20) != 0) |
                                      (uint)((ulonglong)local_5c * 0x158));
    if (pvStack_50 == (void *)0x0) {
      pvStack_50 = (void *)0x0;
    }
    else if (-1 < (int)(uVar5 - 1)) {
      _memset(pvStack_50,0,uVar5 * 0x158);
    }
    uVar5 = local_58;
    pcStack_54 = (char *)FUN_0087dc3d(-(uint)((int)((ulonglong)local_58 * 0x218 >> 0x20) != 0) |
                                      (uint)((ulonglong)local_58 * 0x218),uVar3);
    if (pcStack_54 == (char *)0x0) {
      pcStack_54 = (char *)0x0;
    }
    else if (-1 < (int)(uVar5 - 1)) {
      _memset(pcStack_54,0,uVar5 * 0x218);
    }
    _File = local_4c;
    pvVar2 = pvStack_50;
    _fread(pvStack_50,0x158,local_5c,local_4c);
    _fread(pcStack_54,0x218,local_58,_File);
    iVar8 = 0;
    if (0 < (int)local_5c) {
      iVar7 = (int)pvVar2 + 0x50;
      do {
        FUN_00716040(iVar7 + -0x50,iVar7 + -0x40,*(undefined4 *)(iVar7 + 0x104));
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 0x158;
      } while (iVar8 < (int)local_5c);
    }
    iStack_48 = 0;
    pcVar9 = pcStack_54;
    if (0 < (int)local_58) {
      do {
        uStack_24 = 0xf;
        uStack_28 = 0;
        auStack_38[0] = auStack_38[0] & 0xffffff00;
        pcVar4 = pcVar9;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar9,(int)pcVar4 - (int)(pcVar9 + 1));
        uStack_c = 0;
        iStack_3c = FUN_007b6f30(auStack_38);
        if (iStack_3c == *(int *)(param_1 + 4)) {
LAB_00716679:
          iStack_40 = *(int *)(param_1 + 4);
          piVar6 = &iStack_40;
        }
        else {
          uVar3 = *(uint *)(iStack_3c + 0x1c);
          uVar5 = uStack_28;
          if (uVar3 <= uStack_28) {
            uVar5 = uVar3;
          }
          uVar5 = FUN_00407e70(uVar5);
          if (uVar5 == 0) {
            if (uStack_28 < uVar3) {
              uVar5 = 0xffffffff;
            }
            else {
              uVar5 = (uint)(uStack_28 != uVar3);
            }
          }
          param_1 = local_44;
          if ((int)uVar5 < 0) goto LAB_00716679;
          piVar6 = &iStack_3c;
        }
        iVar8 = *piVar6;
        uStack_c = 0xffffffff;
        if (0xf < uStack_24) {
          FUN_0089120c(auStack_38[0]);
        }
        uStack_24 = 0xf;
        uStack_28 = 0;
        auStack_38[0] = auStack_38[0] & 0xffffff00;
        FUN_007198f0(*(int *)(iVar8 + 0x28) + 0x3c);
        iStack_48 = iStack_48 + 1;
        pcVar9 = pcVar9 + 0x218;
      } while (iStack_48 < (int)local_58);
    }
    FUN_00891d3d(pvStack_50);
    FUN_00891d3d(pcStack_54);
    _fclose(local_4c);
  }
  *unaff_FS_OFFSET = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_5c);
  return;
}

