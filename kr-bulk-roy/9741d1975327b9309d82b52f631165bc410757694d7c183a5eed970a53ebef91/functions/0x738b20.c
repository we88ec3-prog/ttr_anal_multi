
/* WARNING: Removing unreachable block (ram,0x00738b82) */
/* WARNING: Removing unreachable block (ram,0x00738b91) */
/* WARNING: Removing unreachable block (ram,0x00738b93) */

void FUN_00738b20(int *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 ****ppppuVar8;
  int *in_ECX;
  char *pcVar9;
  int *piVar10;
  int *piVar11;
  int local_10c;
  int *local_108;
  int iStack_104;
  undefined1 auStack_100 [4];
  int aiStack_fc [6];
  float fStack_e4;
  float fStack_e0;
  undefined2 uStack_dc;
  undefined **ppuStack_d8;
  undefined4 ***pppuStack_d4;
  int *local_d0;
  uint local_cc;
  uint uStack_c0;
  undefined4 local_bc;
  uint local_b8;
  undefined **local_b0 [19];
  uint local_64;
  undefined4 local_54;
  uint local_50;
  undefined4 **ppuStack_38;
  int iStack_34;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009288b6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_10c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffee8;
  ExceptionList = &local_14;
  local_d0 = param_1;
  local_10c = param_2;
  if (in_ECX[4] != in_ECX[5]) {
    in_ECX[5] = in_ECX[4];
  }
  local_108 = in_ECX;
  FUN_0072ee30(local_b0);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 == '\0') {
    local_c = 0xffffffff;
    local_b0[0] = TiXmlDocument::vftable;
    if (0xf < local_50) {
      FUN_0089120c(local_64);
    }
    local_50 = 0xf;
    local_54 = 0;
    local_64 = local_64 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    piVar3 = (int *)FUN_0072e2e0(&DAT_00c45644);
    if (piVar3 == (int *)0x0) {
      local_c = 0xffffffff;
      local_b0[0] = TiXmlDocument::vftable;
      if (0xf < local_50) {
        FUN_0089120c(local_64);
      }
      local_50 = 0xf;
      local_54 = 0;
      local_64 = local_64 & 0xffffff00;
      FUN_0072e040();
    }
    else {
      local_b8 = 0xf;
      local_bc = 0;
      local_cc = local_cc & 0xffffff00;
      local_c = CONCAT31(local_c._1_3_,1);
      (**(code **)(*piVar3 + 0x14))(uVar2);
      iVar4 = FUN_007300a0("TextureFile");
      if (iVar4 == 0) {
        pcVar9 = (char *)0x0;
      }
      else {
        pcVar9 = (char *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          pcVar9 = *(char **)pcVar9;
        }
      }
      pcVar5 = pcVar9;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar9,(int)pcVar5 - (int)(pcVar9 + 1));
      iVar4 = FUN_0072e2e0("Image");
joined_r0x00738d0b:
      iStack_104 = iVar4;
      if (iStack_104 != 0) {
        fStack_e4 = 0.0;
        aiStack_fc[2] = 1;
        fStack_e0 = 0.0;
        aiStack_fc[3] = 1;
        aiStack_fc[0] = 0;
        aiStack_fc[1] = 0;
        aiStack_fc[4] = 0;
        aiStack_fc[5] = 0;
        uStack_dc = 0;
        iVar4 = FUN_0072e360();
        local_10c = FUN_0072e360();
        ppuStack_d8 = (undefined **)FUN_0072e360();
        iVar6 = FUN_0072e360();
        if (iVar4 != 0) {
          iVar4 = FUN_007300a0(&DAT_00c06928);
          if (iVar4 == 0) {
LAB_00738db0:
            aiStack_fc[0] = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00738db0;
            aiStack_fc[0] = FUN_008917b4(puVar7);
          }
          iVar4 = FUN_007300a0(&DAT_00c0692c);
          if (iVar4 == 0) {
LAB_00738de1:
            aiStack_fc[1] = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00738de1;
            aiStack_fc[1] = FUN_008917b4(puVar7);
          }
        }
        if (local_10c != 0) {
          iVar4 = FUN_007300a0("MaxFrame");
          if (iVar4 == 0) {
LAB_00738e1c:
            aiStack_fc[3] = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00738e1c;
            aiStack_fc[3] = FUN_008917b4(puVar7);
          }
          iVar4 = FUN_007300a0("LinePitch");
          if (iVar4 == 0) {
LAB_00738e4a:
            aiStack_fc[2] = 1;
          }
          else {
            puVar7 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00738e4a;
            aiStack_fc[2] = FUN_008917b4(puVar7);
          }
        }
        if (ppuStack_d8 != (undefined **)0x0) {
          iVar4 = FUN_007300a0(&DAT_00c06928);
          if (iVar4 == 0) {
LAB_00738e86:
            aiStack_fc[4] = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00738e86;
            aiStack_fc[4] = FUN_008917b4(puVar7);
          }
          iVar4 = FUN_007300a0(&DAT_00c0692c);
          if (iVar4 == 0) {
LAB_00738eb4:
            aiStack_fc[5] = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00738eb4;
            aiStack_fc[5] = FUN_008917b4(puVar7);
          }
        }
        if (iVar6 != 0) {
          iVar4 = FUN_007300a0(&DAT_00c06928);
          if (iVar4 == 0) {
LAB_00738eed:
            local_10c = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00738eed;
            local_10c = FUN_008917b4(puVar7);
          }
          fStack_e4 = (float)local_10c;
          iVar4 = FUN_007300a0(&DAT_00c0692c);
          if (iVar4 == 0) {
LAB_00738f25:
            local_10c = 0;
          }
          else {
            puVar7 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 == (undefined4 *)0x0) goto LAB_00738f25;
            local_10c = FUN_008917b4(puVar7);
          }
          fStack_e0 = (float)local_10c;
        }
        piVar3 = local_108;
        if (aiStack_fc[2] == 0) {
          aiStack_fc[2] = 1;
        }
        piVar11 = (int *)local_108[5];
        if (aiStack_fc < piVar11) {
          piVar10 = (int *)local_108[4];
          if (aiStack_fc < piVar10) goto LAB_00738f8b;
          if (piVar11 == (int *)local_108[6]) {
            FUN_0084a0e0();
          }
          piVar11 = (int *)piVar3[5];
          piVar10 = (int *)(piVar3[4] + (((int)aiStack_fc - (int)piVar10) / 0x24) * 0x24);
          if (piVar11 != (int *)0x0) goto LAB_00738fa3;
        }
        else {
LAB_00738f8b:
          if (piVar11 == (int *)local_108[6]) {
            FUN_0084a0e0();
          }
          piVar11 = (int *)piVar3[5];
          if (piVar11 != (int *)0x0) {
            piVar10 = aiStack_fc;
LAB_00738fa3:
            for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
              *piVar11 = *piVar10;
              piVar10 = piVar10 + 1;
              piVar11 = piVar11 + 1;
            }
          }
        }
        piVar3[5] = piVar3[5] + 0x24;
        for (iVar4 = *(int *)(iStack_104 + 0x40); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x40)) {
          pcVar9 = (char *)(iVar4 + 0x20);
          if (0xf < *(uint *)(iVar4 + 0x34)) {
            pcVar9 = *(char **)pcVar9;
          }
          iVar6 = __stricmp(pcVar9,"Image");
          if (iVar6 == 0) goto joined_r0x00738d0b;
        }
        iVar4 = 0;
        goto joined_r0x00738d0b;
      }
      pppuStack_d4 = &ppuStack_38;
      ppuStack_d8 = `long___cdecl_Graphics::GetImageInfoFromFile(char_const*,_D3DXIMAGE_INFO*)'::
                    __l2::GetImageInfoFromFileBox::vftable;
      FUN_00737d40();
      piVar3 = local_108;
      local_108[9] = iStack_34;
      local_108[8] = (int)ppuStack_38;
      (**(code **)(*local_d0 + 0xc))(local_d0,auStack_100);
      ppppuVar8 = (undefined4 ****)pppuStack_d4;
      if (uStack_c0 < 0x10) {
        ppppuVar8 = &pppuStack_d4;
      }
      FUN_00737f40(ppppuVar8,piVar3[9],0,piVar3 + 3);
      *(undefined1 *)(piVar3 + 1) = 1;
      (**(code **)(*local_108 + 8))(local_108);
      if (0xf < local_b8) {
        FUN_0089120c(local_cc);
      }
      local_c = 0xffffffff;
      local_b8 = 0xf;
      local_bc = 0;
      local_cc = local_cc & 0xffffff00;
      local_b0[0] = TiXmlDocument::vftable;
      if (0xf < local_50) {
        FUN_0089120c(local_64);
      }
      local_50 = 0xf;
      local_54 = 0;
      local_64 = local_64 & 0xffffff00;
      FUN_0072e040();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_10c);
  return;
}

