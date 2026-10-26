
void FUN_008242a0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  int local_98 [3];
  undefined **local_8c [6];
  undefined4 *local_74;
  undefined4 local_6c;
  uint local_58;
  char local_48;
  uint local_40;
  undefined4 local_30;
  uint local_2c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925e8e;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  FUN_0072ee30(local_8c);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_48 == '\0') && (local_98[2] = FUN_0072e360(uVar4), local_98[2] != 0)) {
    iVar5 = FUN_0072e360(uVar4);
    if (iVar5 != 0) {
      iVar5 = FUN_0072e360(uVar4);
      while (iVar5 != 0) {
        iVar5 = FUN_007300a0("product");
        if (iVar5 == 0) {
LAB_008243d0:
          iVar5 = 0;
        }
        else {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_008243d0;
          iVar5 = FUN_008917b4(puVar6);
        }
        iVar7 = FUN_007300a0("open_slot_count");
        if (iVar7 == 0) {
LAB_008243fa:
          local_98[1] = 0;
        }
        else {
          puVar6 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_008243fa;
          local_98[1] = FUN_008917b4(puVar6);
        }
        local_98[0] = iVar5;
        uVar8 = FUN_0057ef20();
        FUN_0057e850(&DAT_00fc0c84,uVar8);
        iVar5 = FUN_0072e3c0();
      }
    }
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      iVar5 = FUN_0072e360();
      while (iVar5 != 0) {
        iVar5 = FUN_007300a0("product");
        if (iVar5 == 0) {
LAB_0082449d:
          iVar5 = 0;
        }
        else {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_0082449d;
          iVar5 = FUN_008917b4(puVar6);
        }
        iVar7 = FUN_007300a0("point");
        if (iVar7 == 0) {
LAB_008244c7:
          local_98[1] = 0;
        }
        else {
          puVar6 = (undefined4 *)(iVar7 + 0x30);
          if (0xf < *(uint *)(iVar7 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_008244c7;
          local_98[1] = FUN_008917b4(puVar6);
        }
        local_98[0] = iVar5;
        uVar8 = FUN_0057ef20();
        FUN_0057e850(&DAT_00fc0c94,uVar8);
        iVar5 = FUN_0072e3c0();
      }
    }
    iVar5 = FUN_0072e360();
    if (iVar5 != 0) {
      iVar5 = FUN_0072e360();
      while (local_98[2] = iVar5, iVar5 != 0) {
        for (iVar7 = *(int *)(iVar5 + 0x94); iVar7 != iVar5 + 0x44; iVar7 = *(int *)(iVar7 + 0x50))
        {
          pcVar10 = (char *)(iVar7 + 0x14);
          if (0xf < *(uint *)(iVar7 + 0x28)) {
            pcVar10 = *(char **)pcVar10;
          }
          iVar9 = __stricmp(pcVar10,"index");
          if (iVar9 == 0) {
            if (iVar7 != 0) {
              puVar6 = (undefined4 *)(iVar7 + 0x30);
              if (0xf < *(uint *)(iVar7 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                iVar7 = FUN_008917b4(puVar6);
                goto LAB_00824581;
              }
            }
            break;
          }
        }
        iVar7 = 0;
LAB_00824581:
        local_98[0] = iVar7;
        for (iVar9 = *(int *)(iVar5 + 0x94); iVar9 != iVar5 + 0x44; iVar9 = *(int *)(iVar9 + 0x50))
        {
          pcVar10 = (char *)(iVar9 + 0x14);
          if (0xf < *(uint *)(iVar9 + 0x28)) {
            pcVar10 = *(char **)pcVar10;
          }
          iVar11 = __stricmp(pcVar10,"range");
          if (iVar11 == 0) {
            if (iVar9 != 0) {
              puVar6 = (undefined4 *)(iVar9 + 0x30);
              if (0xf < *(uint *)(iVar9 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                iVar5 = FUN_008917b4(puVar6);
                goto LAB_008245ba;
              }
            }
            break;
          }
        }
        iVar5 = 0;
LAB_008245ba:
        local_98[1] = iVar5;
        if ((local_98 < DAT_00fc0ca8) && (DAT_00fc0ca4 <= local_98)) {
          iVar5 = (int)local_98 - (int)DAT_00fc0ca4;
          if (DAT_00fc0ca8 == DAT_00fc0cac) {
            uVar4 = (int)DAT_00fc0ca8 - (int)DAT_00fc0ca4 >> 3;
            if (0x1ffffffe < uVar4) {
LAB_008247c2:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar4 = uVar4 + 1;
            uVar12 = (int)DAT_00fc0cac - (int)DAT_00fc0ca4 >> 3;
            if (uVar12 < uVar4) {
              if (0x1fffffff - (uVar12 >> 1) < uVar12) {
                uVar12 = 0;
              }
              else {
                uVar12 = uVar12 + (uVar12 >> 1);
              }
              if (uVar12 < uVar4) {
                uVar12 = uVar4;
              }
              FUN_004e7330(uVar12);
            }
          }
          piVar3 = DAT_00fc0ca8;
          piVar1 = DAT_00fc0ca4 + (iVar5 >> 3) * 2;
          if (DAT_00fc0ca8 != (int *)0x0) {
            *DAT_00fc0ca8 = *piVar1;
            piVar3[1] = piVar1[1];
          }
        }
        else {
          if (DAT_00fc0ca8 == DAT_00fc0cac) {
            uVar4 = (int)DAT_00fc0ca8 - (int)DAT_00fc0ca4 >> 3;
            if (0x1ffffffe < uVar4) goto LAB_008247c2;
            uVar4 = uVar4 + 1;
            uVar12 = (int)DAT_00fc0cac - (int)DAT_00fc0ca4 >> 3;
            if (uVar12 < uVar4) {
              if (0x1fffffff - (uVar12 >> 1) < uVar12) {
                uVar12 = 0;
              }
              else {
                uVar12 = uVar12 + (uVar12 >> 1);
              }
              if (uVar12 < uVar4) {
                uVar12 = uVar4;
              }
              FUN_004e7330(uVar12);
            }
          }
          piVar1 = DAT_00fc0ca8;
          if (DAT_00fc0ca8 != (int *)0x0) {
            *DAT_00fc0ca8 = iVar7;
            piVar1[1] = iVar5;
          }
        }
        DAT_00fc0ca8 = DAT_00fc0ca8 + 2;
        iVar5 = FUN_0072e3c0();
      }
    }
    local_8c[0] = TiXmlDocument::vftable;
    if (0xf < local_2c) {
      FUN_0089120c(local_40);
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = local_40 & 0xffffff00;
    local_8c[0] = TiXmlNode::vftable;
    local_8 = 2;
    puVar6 = local_74;
    while (puVar6 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)*puVar6;
      puVar6 = (undefined4 *)puVar6[0x10];
      (*(code *)*puVar2)(1);
    }
    if (0xf < local_58) {
      FUN_0089120c(local_6c);
    }
  }
  else {
    local_8c[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_2c) {
      local_8 = 0xffffffff;
      local_8c[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_40);
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = local_40 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

