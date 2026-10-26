
int FUN_008f3840(int *param_1,int param_2,uint param_3,char param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  bool bVar9;
  uint local_1c;
  
  iVar1 = *(int *)(param_2 + 4);
  iVar2 = *(int *)(iVar1 + 0x68);
  local_1c = CONCAT31(local_1c._1_3_,(byte)param_3) & 0xffffff80;
  _memset(param_1,0,0xd0);
  if (((param_3 & 2) == 0) && (param_4 == '\0')) {
    if ((*(char *)(unaff_EBX + 0x12d) == '\0') && (iVar4 = FUN_008f3370(local_1c), iVar4 != 0)) {
      return iVar4;
    }
    if (*(char *)(unaff_EBX + 0x124) == '\0') {
      iVar4 = *(int *)(*(int *)(iVar1 + 0x60) + 0x1c);
    }
    else {
      iVar4 = *(int *)(unaff_EBX + 0x128);
    }
    if (iVar4 == 0) {
      return 0x99;
    }
    bVar9 = (param_3 & 0xf0000) != 0x20000;
    FUN_008ec000(iVar4,iVar1);
    if (bVar9 != (bool)*(char *)(iVar4 + 0x25c)) {
      *(bool *)(iVar4 + 0x25c) = bVar9;
      uVar6 = 0;
      if (*(int *)(unaff_EBX + 0xf0) != 0) {
        do {
          lVar3 = (longlong)(int)*(short *)(*(int *)(iVar1 + 0x288) + uVar6 * 2) *
                  (longlong)*(int *)(unaff_EBX + 0x58);
          lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
          *(uint *)(*(int *)(unaff_EBX + 0xf4) + uVar6 * 4) =
               ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)(unaff_EBX + 0xf0));
      }
      FUN_008f30a0();
    }
    if ((*(byte *)(iVar4 + 0x150) & 1) != 0) {
      param_3 = param_3 | 2;
    }
    if ((*(byte *)(iVar4 + 0x150) & 2) != 0) {
      puVar7 = &DAT_00bead40;
      puVar8 = (undefined4 *)(iVar4 + 0x11c);
      for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    *(byte *)(iVar4 + 0x231) = (byte)param_3 & 0x80;
    param_1[0x28] = iVar4;
    param_1[0x29] = *(int *)(iVar4 + 0x188);
  }
  if (*(int *)(*(int *)(iVar1 + 0x80) + 0x30) == 0) {
    iVar4 = (**(code **)(iVar1 + 0x1fc))(iVar1,0x676c7966,iVar2,0);
    if ((char)iVar4 == -0x72) {
      param_1[0x15] = 0;
    }
    else {
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = FUN_008b9850(iVar2);
      param_1[0x15] = iVar4;
    }
  }
  else {
    param_1[0x15] = 0;
  }
  if (param_4 == '\0') {
    iVar4 = **(int **)(param_2 + 0x9c);
    FUN_008b82d0(iVar4);
    param_1[3] = iVar4;
  }
  param_1[4] = param_3;
  *param_1 = iVar1;
  param_1[1] = unaff_EBX;
  param_1[2] = param_2;
  param_1[6] = iVar2;
  return 0;
}

