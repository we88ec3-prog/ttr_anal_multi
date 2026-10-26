
void FUN_00831770(int param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  char *_Str1;
  undefined **local_90 [19];
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925afb;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar3;
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar2 = FUN_0072f110(0);
  if ((cVar2 == '\0') || (iVar4 = FUN_0072e360(uVar3), iVar4 == 0)) {
    local_90[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_30) {
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    iVar4 = FUN_00506a30();
joined_r0x0083185e:
    if (iVar4 != 0) {
      _Str1 = (char *)(iVar4 + 0x20);
      if (0xf < *(uint *)(iVar4 + 0x34)) {
        _Str1 = *(char **)_Str1;
      }
      if (_Str1 != (char *)0x0) {
        iVar5 = __stricmp(_Str1,"ClassDefault");
        if (iVar5 == 0) {
          iVar5 = FUN_007300a0("Class");
          if (iVar5 != 0) {
            puVar6 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 != (undefined4 *)0x0) {
              FUN_008917b4(puVar6);
            }
          }
          iVar5 = FUN_007300a0("SetID");
          if (iVar5 != 0) {
            puVar6 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 != (undefined4 *)0x0) {
              FUN_008917b4(puVar6);
            }
          }
          uVar7 = FUN_00821d70();
          FUN_00832400(param_1 + 0x10,uVar7);
        }
        else {
          iVar5 = __stricmp(_Str1,"Item");
          if (iVar5 == 0) {
            iVar5 = FUN_007300a0(&DAT_00c0dc30);
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                FUN_008917b4(puVar6);
              }
            }
            iVar5 = FUN_007300a0("SetID");
            if (iVar5 != 0) {
              puVar6 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                FUN_008917b4(puVar6);
              }
            }
            uVar7 = FUN_004ca670();
            FUN_008262f0(param_1 + 0x20,uVar7);
          }
          else {
            iVar5 = __stricmp(_Str1,"Product");
            if (iVar5 == 0) {
              iVar5 = FUN_007300a0("ProductID");
              if (iVar5 != 0) {
                puVar6 = (undefined4 *)(iVar5 + 0x30);
                if (0xf < *(uint *)(iVar5 + 0x44)) {
                  puVar6 = (undefined4 *)*puVar6;
                }
                if (puVar6 != (undefined4 *)0x0) {
                  FUN_008917b4(puVar6);
                }
              }
              iVar5 = FUN_007300a0("SetID");
              if (iVar5 != 0) {
                puVar6 = (undefined4 *)(iVar5 + 0x30);
                if (0xf < *(uint *)(iVar5 + 0x44)) {
                  puVar6 = (undefined4 *)*puVar6;
                }
                if (puVar6 != (undefined4 *)0x0) {
                  FUN_008917b4(puVar6);
                }
              }
              uVar7 = FUN_0057ef20();
              FUN_0082f200(param_1 + 0x30,uVar7);
            }
          }
        }
      }
      for (piVar1 = *(int **)(iVar4 + 0x40); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x10]) {
        iVar4 = (**(code **)(*piVar1 + 0x18))();
        if (iVar4 != 0) {
          iVar4 = (**(code **)(*piVar1 + 0x18))();
          goto joined_r0x0083185e;
        }
      }
      iVar4 = 0;
      goto joined_r0x0083185e;
    }
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

