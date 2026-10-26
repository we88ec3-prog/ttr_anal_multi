
void FUN_004c62b0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  int *_Str1;
  int iVar11;
  undefined **local_a8 [17];
  char local_64;
  uint local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_30 [6];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924d5b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar1;
  FUN_0072ee30(local_a8);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_64 == '\0') && (iVar2 = FUN_0072e2e0("EVENTOBJECTS"), iVar2 != 0)) {
    iVar2 = FUN_0072e2e0("OBJECTS");
    if (iVar2 != 0) {
      piVar3 = (int *)FUN_0072e2e0(&DAT_00c07520);
joined_r0x004c63bd:
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x14))();
        iVar2 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar2 != 0) {
          puVar4 = (undefined4 *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 != (undefined4 *)0x0) {
            FUN_008917b4(puVar4);
          }
        }
        piVar5 = (int *)FUN_0072e2e0("STATE");
joined_r0x004c6423:
        if (piVar5 != (int *)0x0) {
          iVar6 = (**(code **)(*piVar5 + 0x14))();
          iVar2 = iVar6 + 0x44;
          for (iVar11 = *(int *)(iVar6 + 0x94); iVar11 != iVar2; iVar11 = *(int *)(iVar11 + 0x50)) {
            pcVar10 = (char *)(iVar11 + 0x14);
            if (0xf < *(uint *)(iVar11 + 0x28)) {
              pcVar10 = *(char **)pcVar10;
            }
            iVar7 = __stricmp(pcVar10,"ID");
            if (iVar7 == 0) {
              if (iVar11 != 0) {
                puVar4 = (undefined4 *)(iVar11 + 0x30);
                if (0xf < *(uint *)(iVar11 + 0x44)) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                if (puVar4 != (undefined4 *)0x0) {
                  iVar11 = FUN_008917b4(puVar4);
                  goto LAB_004c647e;
                }
              }
              break;
            }
          }
          iVar11 = 0;
LAB_004c647e:
          for (iVar7 = *(int *)(iVar6 + 0x94); iVar7 != iVar2; iVar7 = *(int *)(iVar7 + 0x50)) {
            pcVar10 = (char *)(iVar7 + 0x14);
            if (0xf < *(uint *)(iVar7 + 0x28)) {
              pcVar10 = *(char **)pcVar10;
            }
            iVar8 = __stricmp(pcVar10,"AVATAR");
            if (iVar8 == 0) {
              if (iVar7 != 0) {
                puVar4 = (undefined4 *)(iVar7 + 0x30);
                if (0xf < *(uint *)(iVar7 + 0x44)) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                if (puVar4 != (undefined4 *)0x0) {
                  uVar9 = FUN_008917b4(puVar4);
                  goto LAB_004c64af;
                }
              }
              break;
            }
          }
          uVar9 = 0;
LAB_004c64af:
          iVar6 = *(int *)(iVar6 + 0x94);
          local_30[iVar11 * 2] = uVar9;
          for (; iVar6 != iVar2; iVar6 = *(int *)(iVar6 + 0x50)) {
            pcVar10 = (char *)(iVar6 + 0x14);
            if (0xf < *(uint *)(iVar6 + 0x28)) {
              pcVar10 = *(char **)pcVar10;
            }
            iVar7 = __stricmp(pcVar10,"MOTION");
            if (iVar7 == 0) {
              if (iVar6 != 0) {
                puVar4 = (undefined4 *)(iVar6 + 0x30);
                if (0xf < *(uint *)(iVar6 + 0x44)) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                if (puVar4 != (undefined4 *)0x0) {
                  uVar9 = FUN_008917b4(puVar4);
                  goto LAB_004c64ed;
                }
              }
              break;
            }
          }
          uVar9 = 0;
LAB_004c64ed:
          piVar5 = (int *)piVar5[0x10];
          local_30[iVar11 * 2 + 1] = uVar9;
          for (; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[0x10]) {
            _Str1 = piVar5 + 8;
            if (0xf < (uint)piVar5[0xd]) {
              _Str1 = (int *)*_Str1;
            }
            iVar2 = __stricmp((char *)_Str1,"STATE");
            if (iVar2 == 0) goto joined_r0x004c6423;
          }
          piVar5 = (int *)0x0;
          goto joined_r0x004c6423;
        }
        uVar9 = FUN_004c6dc0();
        FUN_004c6b80(param_1,uVar9);
        for (piVar3 = (int *)piVar3[0x10]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
          piVar5 = piVar3 + 8;
          if (0xf < (uint)piVar3[0xd]) {
            piVar5 = (int *)*piVar5;
          }
          iVar2 = __stricmp((char *)piVar5,"OBJ");
          if (iVar2 == 0) goto joined_r0x004c63bd;
        }
        piVar3 = (int *)0x0;
        goto joined_r0x004c63bd;
      }
    }
    local_8 = 0xffffffff;
    local_a8[0] = TiXmlDocument::vftable;
    if (0xf < local_48) {
      FUN_0089120c(local_5c);
    }
    local_48 = 0xf;
    local_4c = 0;
    local_5c = local_5c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    local_a8[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_48) {
      local_8 = 0xffffffff;
      local_a8[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_5c,uVar1);
    }
    local_48 = 0xf;
    local_4c = 0;
    local_5c = local_5c & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

