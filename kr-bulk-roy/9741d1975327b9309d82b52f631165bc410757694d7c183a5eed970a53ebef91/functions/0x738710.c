
/* WARNING: Removing unreachable block (ram,0x00738778) */
/* WARNING: Removing unreachable block (ram,0x0073878b) */
/* WARNING: Removing unreachable block (ram,0x0073878d) */
/* WARNING: Type propagation algorithm not settling */

void FUN_00738710(undefined **param_1,undefined **param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  int in_ECX;
  char *pcVar7;
  uint *puVar8;
  uint *puVar9;
  char *local_2a4;
  undefined **local_2a0;
  undefined4 *puStack_29c;
  undefined1 auStack_298 [4];
  int local_294;
  char *local_290;
  int local_28c;
  undefined4 local_288;
  undefined **ppuStack_284;
  undefined **local_280;
  uint auStack_27c [14];
  undefined4 uStack_244;
  undefined4 uStack_240;
  char acStack_228 [264];
  undefined1 auStack_120 [260];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = -1;
  puStack_10 = &LAB_00928906;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_2a4;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffd50;
  ExceptionList = &local_14;
  puVar1 = (uint *)(in_ECX + 0x10);
  pcVar6 = (char *)*puVar1;
  local_280 = param_1;
  local_2a0 = param_2;
  if (pcVar6 != *(char **)(in_ECX + 0x14)) {
    *(char **)(in_ECX + 0x14) = pcVar6;
    local_2a4 = pcVar6;
  }
  local_294 = in_ECX;
  piVar4 = (int *)FUN_00714770(param_2,&DAT_00bed1e0,uVar3);
  if (piVar4 != (int *)0x0) {
    local_290 = (char *)0x0;
    local_28c = 0;
    local_288 = 0;
    local_c = 0;
    while (iVar5 = (**(code **)(*piVar4 + 0x18))(), iVar5 == 0) {
      acStack_228[0] = '\0';
      _memset(acStack_228 + 1,0,0x103);
      (**(code **)(*piVar4 + 8))(acStack_228,0x104);
      if (acStack_228[0] != '\0') {
        pcVar6 = acStack_228;
        auStack_27c[5] = 0xf;
        auStack_27c[4] = 0;
        auStack_27c[0] = auStack_27c[0] & 0xffffff00;
        do {
          cVar2 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        FUN_00402a70(acStack_228,(int)pcVar6 - (int)(acStack_228 + 1));
        local_c._0_1_ = 1;
        FUN_00440c60();
        local_c = (uint)local_c._1_3_ << 8;
        if (0xf < auStack_27c[5]) {
          FUN_0089120c(auStack_27c[0]);
        }
      }
    }
    (**(code **)(*piVar4 + 4))();
    pcVar6 = local_290;
    pcVar7 = local_290;
    if (0xf < *(uint *)(local_290 + 0x14)) {
      pcVar7 = *(char **)local_290;
    }
    FID_conflict__sscanf(pcVar7,"%s",auStack_120);
    iVar5 = (local_28c - (int)pcVar6) / 0x1c;
    if (1 < iVar5) {
      pcVar7 = pcVar6 + 0x1c;
      local_2a0 = (undefined **)(iVar5 + -1);
      do {
        auStack_27c[2] = 1;
        auStack_27c[6] = 0;
        auStack_27c[3] = 1;
        auStack_27c[7] = 0;
        auStack_27c[8] = auStack_27c[8] & 0xffff0000;
        auStack_27c[0] = 0;
        auStack_27c[1] = 0;
        auStack_27c[4] = 0;
        auStack_27c[5] = 0;
        pcVar6 = pcVar7;
        if (0xf < *(uint *)(pcVar7 + 0x14)) {
          pcVar6 = *(char **)pcVar7;
        }
        local_2a4 = pcVar7;
        FID_conflict__sscanf
                  (pcVar6,"%ld %ld %d %d %ld %ld %f %f",auStack_27c,auStack_27c + 1,auStack_27c + 3,
                   auStack_27c + 2,auStack_27c + 4,auStack_27c + 5,auStack_27c + 6,auStack_27c + 7);
        if (auStack_27c[2] == 0) {
          auStack_27c[2] = 1;
        }
        puVar9 = *(uint **)(in_ECX + 0x14);
        if ((auStack_27c < puVar9) && (puVar8 = (uint *)*puVar1, puVar8 <= auStack_27c)) {
          if (puVar9 == *(uint **)(in_ECX + 0x18)) {
            FUN_0084a0e0();
          }
          puVar8 = (uint *)(*puVar1 + (((int)auStack_27c - (int)puVar8) / 0x24) * 0x24);
          puVar9 = *(uint **)(in_ECX + 0x14);
          pcVar7 = local_2a4;
          if (puVar9 != (uint *)0x0) {
LAB_007389da:
            for (iVar5 = 9; pcVar7 = local_2a4, iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar9 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
          }
        }
        else {
          if (puVar9 == *(uint **)(in_ECX + 0x18)) {
            FUN_0084a0e0();
          }
          puVar9 = *(uint **)(in_ECX + 0x14);
          if (puVar9 != (uint *)0x0) {
            puVar8 = auStack_27c;
            goto LAB_007389da;
          }
        }
        *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 0x24;
        pcVar7 = pcVar7 + 0x1c;
        local_2a0 = (undefined **)((int)local_2a0 + -1);
        pcVar6 = local_290;
        local_2a4 = pcVar7;
      } while (local_2a0 != (undefined **)0x0);
    }
    puStack_29c = &uStack_244;
    local_2a0 = `long___cdecl_Graphics::GetImageInfoFromFile(char_const*,_D3DXIMAGE_INFO*)'::__l2::
                GetImageInfoFromFileBox::vftable;
    FUN_00737d40();
    *(undefined4 *)(local_294 + 0x20) = uStack_244;
    *(undefined4 *)(local_294 + 0x24) = uStack_240;
    (**(code **)(*local_280 + 0xc))(local_280,auStack_298);
    auStack_27c[1] = *(undefined4 *)(local_294 + 0x24);
    auStack_27c[0] = *(uint *)(local_294 + 0x20);
    local_280 = local_2a0;
    auStack_27c[2] = -1;
    auStack_27c[7] = 0xffffffff;
    auStack_27c[0xb] = local_294 + 0xc;
    ppuStack_284 = `long___cdecl_Graphics::LoadTextureFromFileEx(IDirect3DDevice9*,char_const*,unsigned_int,unsigned_int,unsigned_int,unsigned_long,_D3DFORMAT,_D3DPOOL,unsigned_long,unsigned_long,unsigned_long,_D3DXIMAGE_INFO*,tagPALETTEENTRY*,IDirect3DTexture9**)'
                   ::__l2::CreateTextureFromFileExBox::vftable;
    auStack_27c[3] = 0;
    auStack_27c[4] = 0;
    auStack_27c[5] = 1;
    auStack_27c[6] = 1;
    auStack_27c[8] = 0;
    auStack_27c[9] = 0;
    auStack_27c[10] = 0;
    iVar5 = FUN_00737d40();
    (**(code **)(*local_2a0 + 8))(local_2a0);
    if ((iVar5 == -0x7789f4a7) || (iVar5 != 0)) {
      FUN_00440a80();
      FUN_0089120c(pcVar6);
    }
    else {
      *(undefined1 *)(local_2a0 + 1) = 1;
      FUN_00440a80();
      FUN_0089120c(pcVar6);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_2a4);
  return;
}

