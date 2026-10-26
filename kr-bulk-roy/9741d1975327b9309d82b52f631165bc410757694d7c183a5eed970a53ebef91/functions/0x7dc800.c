
void FUN_007dc800(int param_1)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  char *unaff_EDI;
  bool bVar9;
  undefined1 local_6c [4];
  undefined4 *local_68;
  uint local_64 [4];
  undefined4 local_54;
  uint local_50;
  undefined4 *local_48;
  uint local_44 [4];
  undefined4 local_34;
  uint local_30;
  byte local_28 [16];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914936;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30 = 0xf;
  local_34 = 0;
  local_44[0] = local_44[0] & 0xffffff00;
  pcVar4 = unaff_EDI;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_18 = uVar3;
  FUN_00402a70(unaff_EDI,(int)pcVar4 - (int)(unaff_EDI + 1));
  local_8 = 0;
  FUN_007b86f0(&local_68,local_44);
  local_8 = 0xffffffff;
  if (0xf < local_30) {
    FUN_0089120c(local_44[0],uVar3);
  }
  if (local_68 == *(undefined4 **)(param_1 + 4)) {
    __splitpath(unaff_EDI,(char *)0x0,(char *)0x0,(char *)0x0,(char *)local_28);
    pbVar5 = local_28;
    pbVar8 = &DAT_00c40f60;
    do {
      bVar2 = *pbVar5;
      bVar9 = bVar2 < *pbVar8;
      if (bVar2 != *pbVar8) {
LAB_007dc8d0:
        iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_007dc8d5;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar9 = bVar2 < pbVar8[1];
      if (bVar2 != pbVar8[1]) goto LAB_007dc8d0;
      pbVar5 = pbVar5 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar2 != 0);
    iVar6 = 0;
LAB_007dc8d5:
    if (iVar6 == 0) {
      local_68 = (undefined4 *)FUN_00891268(0xb4);
      local_8 = 1;
      if (local_68 == (undefined4 *)0x0) {
        local_48 = (undefined4 *)0x0;
      }
      else {
        local_48 = (undefined4 *)FUN_007f15b0(1);
      }
    }
    else {
      local_48 = (undefined4 *)FUN_00891268(0x88);
      local_8 = 2;
      local_68 = local_48;
      if (local_48 == (undefined4 *)0x0) {
        local_48 = (undefined4 *)0x0;
      }
      else {
        FUN_007e9bf0(unaff_EDI);
        *local_48 = IS3D::CEffectElementParticle::vftable;
        local_48[0x21] = 0;
      }
    }
    local_8 = 0xffffffff;
    local_50 = 0xf;
    local_54 = 0;
    local_64[0] = local_64[0] & 0xffffff00;
    pcVar4 = unaff_EDI;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(unaff_EDI,(int)pcVar4 - (int)(unaff_EDI + 1));
    local_8 = 3;
    iVar6 = **(int **)(param_1 + 4);
    iVar7 = FUN_00719b90(iVar6,*(undefined4 *)(iVar6 + 4),local_64);
    if (*(int *)(param_1 + 8) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(int *)(iVar6 + 4) = iVar7;
    **(int **)(iVar7 + 4) = iVar7;
    FUN_007d1080(local_6c,**(int **)(param_1 + 4) + 8,**(int **)(param_1 + 4));
    if (0xf < local_50) {
      FUN_0089120c(local_64[0]);
    }
  }
  else {
    *(int *)(local_68[9] + 8) = *(int *)(local_68[9] + 8) + 1;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

