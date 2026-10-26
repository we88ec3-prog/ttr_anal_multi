
/* WARNING: Removing unreachable block (ram,0x0043eb32) */
/* WARNING: Removing unreachable block (ram,0x0043eb3c) */
/* WARNING: Removing unreachable block (ram,0x0043eb40) */
/* WARNING: Removing unreachable block (ram,0x0043eb45) */
/* WARNING: Removing unreachable block (ram,0x0043eb53) */
/* WARNING: Removing unreachable block (ram,0x0043eb6c) */

void FUN_0043e7c0(void)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  char *_Str1;
  int iVar8;
  undefined4 uVar9;
  int in_ECX;
  uint *puVar10;
  uint local_e8;
  uint local_d4;
  undefined **local_cc [19];
  uint local_80;
  undefined4 local_70;
  uint local_6c;
  undefined1 local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  uint *local_24;
  uint *local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925949;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar5;
  FUN_0043f580(*(undefined4 *)(*(int *)(in_ECX + 4) + 4));
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  FUN_0072ee30(local_cc);
  local_8 = 0;
  cVar4 = FUN_0072f110(0);
  if (cVar4 == '\0') {
    local_8 = 0xffffffff;
    local_cc[0] = TiXmlDocument::vftable;
    if (0xf < local_6c) {
      FUN_0089120c(local_80);
    }
    local_6c = 0xf;
    local_70 = 0;
    local_80 = local_80 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    iVar6 = FUN_0072e360(uVar5);
    if (iVar6 == 0) {
      local_8 = 0xffffffff;
      local_cc[0] = TiXmlDocument::vftable;
      if (0xf < local_6c) {
        FUN_0089120c(local_80);
      }
      local_6c = 0xf;
      local_70 = 0;
      local_80 = local_80 & 0xffffff00;
      FUN_0072e040();
    }
    else {
      iVar6 = FUN_0072e360(uVar5);
      while (iVar6 != 0) {
        iVar6 = FUN_007300a0(&DAT_00bfaf5c);
        if (iVar6 != 0) {
          puVar7 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 != (undefined4 *)0x0) {
            FUN_008917b4(puVar7);
          }
        }
        iVar6 = FUN_0072e360();
        local_8._0_1_ = 1;
        while (iVar6 != 0) {
          local_38 = 7;
          local_3c = 0;
          local_4c = local_4c & 0xffff0000;
          local_8 = CONCAT31(local_8._1_3_,2);
          for (iVar2 = *(int *)(iVar6 + 0x94); iVar2 != iVar6 + 0x44; iVar2 = *(int *)(iVar2 + 0x50)
              ) {
            _Str1 = (char *)(iVar2 + 0x14);
            if (0xf < *(uint *)(iVar2 + 0x28)) {
              _Str1 = *(char **)_Str1;
            }
            iVar8 = __stricmp(_Str1,"no");
            if (iVar8 == 0) {
              if (iVar2 != 0) {
                puVar7 = (undefined4 *)(iVar2 + 0x30);
                if (0xf < *(uint *)(iVar2 + 0x44)) {
                  puVar7 = (undefined4 *)*puVar7;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  local_50 = FUN_008917b4(puVar7);
                  goto LAB_0043e9ca;
                }
              }
              break;
            }
          }
          local_50 = 0;
LAB_0043e9ca:
          local_1c = 0xf;
          local_20 = (uint *)0x0;
          local_30 = local_30 & 0xffffff00;
          FUN_00402a70("sentence",8);
          local_8._0_1_ = 3;
          uVar9 = FUN_0072ecf0(&DAT_00bf2375);
          local_8 = CONCAT31(local_8._1_3_,4);
          FUN_00440130(uVar9);
          if (0xf < local_d4) {
            FUN_0089120c(local_e8);
          }
          local_8._0_1_ = 2;
          local_d4 = 0xf;
          local_e8 = local_e8 & 0xffffff00;
          if (0xf < local_1c) {
            FUN_0089120c(local_30);
          }
          FUN_0043f450();
          local_8._0_1_ = 1;
          if (7 < local_38) {
            FUN_0089120c(local_4c);
          }
          iVar6 = FUN_0072e3c0();
        }
        FUN_0043fac0();
        local_8 = CONCAT31(local_8._1_3_,5);
        uVar9 = FUN_004fcae0();
        FUN_0043fae0(in_ECX,uVar9);
        puVar3 = local_20;
        if (local_24 != (uint *)0x0) {
          if (local_24 != local_20) {
            puVar10 = local_24 + 6;
            do {
              if (7 < *puVar10) {
                FUN_0089120c(puVar10[-5]);
              }
              *puVar10 = 7;
              puVar10[-1] = 0;
              *(undefined2 *)(puVar10 + -5) = 0;
              puVar1 = puVar10 + 2;
              puVar10 = puVar10 + 8;
            } while (puVar1 != puVar3);
          }
          FUN_0089120c(local_24);
        }
        local_8 = local_8 & 0xffffff00;
        local_1c = 0;
        local_20 = (uint *)0x0;
        local_24 = (uint *)0x0;
        iVar6 = FUN_0072e3c0();
      }
      local_8 = 0xffffffff;
      local_cc[0] = TiXmlDocument::vftable;
      if (0xf < local_6c) {
        FUN_0089120c(local_80);
      }
      local_6c = 0xf;
      local_70 = 0;
      local_80 = local_80 & 0xffffff00;
      FUN_0072e040();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

