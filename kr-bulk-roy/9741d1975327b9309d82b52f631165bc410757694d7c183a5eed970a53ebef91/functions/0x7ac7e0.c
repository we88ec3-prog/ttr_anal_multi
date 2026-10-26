
void FUN_007ac7e0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *****pppppuVar8;
  int *_Str1;
  char *pcVar9;
  undefined **local_b0 [19];
  uint local_64;
  undefined4 local_54;
  uint local_50;
  undefined4 ****local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928713;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_b0);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 == '\0') {
    local_8 = 0xffffffff;
    local_b0[0] = TiXmlDocument::vftable;
    if (0xf < local_50) {
      FUN_0089120c(local_64,uVar2);
    }
    local_50 = 0xf;
    local_54 = 0;
    local_64 = local_64 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_0072e2e0(&DAT_00c4f83c);
    piVar3 = (int *)FUN_0072e2e0("Include");
    iVar4 = FUN_0072e2e0("ItemList");
    iVar5 = FUN_0072e2e0("EffectList");
    if (iVar4 != 0) {
      FUN_007aca80(param_1,0);
    }
    if (iVar5 != 0) {
      FUN_007aca80(param_1,1);
    }
    while (piVar3 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar3 + 0x14))();
      for (iVar4 = *(int *)(iVar5 + 0x94); iVar4 != iVar5 + 0x44; iVar4 = *(int *)(iVar4 + 0x50)) {
        pcVar9 = (char *)(iVar4 + 0x14);
        if (0xf < *(uint *)(iVar4 + 0x28)) {
          pcVar9 = *(char **)pcVar9;
        }
        iVar6 = __stricmp(pcVar9,"File");
        if (iVar6 == 0) {
          if (iVar4 != 0) {
            pcVar9 = (char *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              pcVar9 = *(char **)pcVar9;
            }
            goto LAB_007ac90d;
          }
          break;
        }
      }
      pcVar9 = (char *)0x0;
LAB_007ac90d:
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = (undefined4 ****)((uint)local_34[0] & 0xffffff00);
      pcVar7 = pcVar9;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar9,(int)pcVar7 - (int)(pcVar9 + 1));
      local_8 = CONCAT31(local_8._1_3_,1);
      pppppuVar8 = (undefined4 *****)local_34[0];
      if (local_20 < 0x10) {
        pppppuVar8 = local_34;
      }
      FUN_007ac7e0(pppppuVar8);
      for (piVar3 = (int *)piVar3[0x10]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
        _Str1 = piVar3 + 8;
        if (0xf < (uint)piVar3[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar4 = __stricmp((char *)_Str1,"Include");
        if (iVar4 == 0) goto LAB_007ac985;
      }
      piVar3 = (int *)0x0;
LAB_007ac985:
      local_8 = local_8 & 0xffffff00;
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = (undefined4 ****)((uint)local_34[0] & 0xffffff00);
    }
    local_8 = 0xffffffff;
    local_b0[0] = TiXmlDocument::vftable;
    if (0xf < local_50) {
      FUN_0089120c(local_64);
    }
    local_50 = 0xf;
    local_54 = 0;
    local_64 = local_64 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

