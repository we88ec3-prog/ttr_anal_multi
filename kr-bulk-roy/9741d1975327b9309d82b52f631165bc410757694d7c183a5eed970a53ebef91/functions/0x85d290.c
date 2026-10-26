
/* WARNING: Removing unreachable block (ram,0x0085d68c) */
/* WARNING: Removing unreachable block (ram,0x0085d69d) */
/* WARNING: Removing unreachable block (ram,0x0085d9ae) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0085d290(undefined4 param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte ****ppppbVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int *in_ECX;
  byte *pbVar9;
  char *pcVar10;
  int *in_EDX;
  bool bVar11;
  float local_c4;
  float local_c0;
  float local_b8;
  float local_b4;
  int local_b0;
  int local_94;
  int local_8c;
  int local_88;
  undefined1 local_84 [8];
  int local_7c;
  int local_78;
  uint local_6c;
  undefined4 local_5c;
  uint local_58;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  byte ***local_34 [4];
  int local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009180c8;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  (**(code **)(*in_EDX + 0x110))();
  local_88 = 1;
  local_58 = 0xf;
  local_5c = 0;
  local_6c = local_6c & 0xffffff00;
  local_8 = 0;
  iVar3 = FUN_008714b0(param_1,"format");
  if (iVar3 != 0) {
    local_8c = FUN_00858c00();
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (byte ***)((uint)local_34[0] & 0xffffff00);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = FUN_008714b0(param_1,"resourcetype");
  if (iVar3 == 0) {
    FUN_008714b0(param_1,"texturetype");
  }
  if (local_24 != 0) {
    ppppbVar4 = (byte ****)local_34[0];
    if (local_20 < 0x10) {
      ppppbVar4 = local_34;
    }
    pbVar9 = &DAT_00c5487c;
    do {
      bVar1 = *(byte *)ppppbVar4;
      bVar11 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_0085d3a6:
        iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_0085d3ab;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppppbVar4 + 1);
      bVar11 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_0085d3a6;
      ppppbVar4 = (byte ****)((int)ppppbVar4 + 2);
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0085d3ab:
    if (iVar3 == 0) {
      ppppbVar4 = (byte ****)local_34[0];
      if (local_20 < 0x10) {
        ppppbVar4 = local_34;
      }
      pbVar9 = (byte *)((int)ppppbVar4 + 1);
      do {
        bVar1 = *(byte *)ppppbVar4;
        ppppbVar4 = (byte ****)((int)ppppbVar4 + 1);
      } while (bVar1 != 0);
      if ((int)ppppbVar4 - (int)pbVar9 != 2) goto LAB_0085d3ce;
LAB_0085d426:
      local_88 = 3;
    }
    else {
LAB_0085d3ce:
      ppppbVar4 = (byte ****)local_34[0];
      if (local_20 < 0x10) {
        ppppbVar4 = local_34;
      }
      pcVar10 = "volume";
      do {
        bVar1 = *(byte *)ppppbVar4;
        bVar11 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_0085d400:
          iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0085d405;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppbVar4 + 1);
        bVar11 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_0085d400;
        ppppbVar4 = (byte ****)((int)ppppbVar4 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0085d405:
      if (iVar3 == 0) {
        ppppbVar4 = (byte ****)local_34[0];
        if (local_20 < 0x10) {
          ppppbVar4 = local_34;
        }
        pbVar9 = (byte *)((int)ppppbVar4 + 1);
        do {
          bVar1 = *(byte *)ppppbVar4;
          ppppbVar4 = (byte ****)((int)ppppbVar4 + 1);
        } while (bVar1 != 0);
        if ((int)ppppbVar4 - (int)pbVar9 == 6) goto LAB_0085d426;
      }
      ppppbVar4 = (byte ****)local_34[0];
      if (local_20 < 0x10) {
        ppppbVar4 = local_34;
      }
      pbVar9 = &DAT_00c54888;
      do {
        bVar1 = *(byte *)ppppbVar4;
        bVar11 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_0085d463:
          iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_0085d468;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppbVar4 + 1);
        bVar11 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_0085d463;
        ppppbVar4 = (byte ****)((int)ppppbVar4 + 2);
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0085d468:
      if (iVar3 == 0) {
        ppppbVar4 = (byte ****)local_34[0];
        if (local_20 < 0x10) {
          ppppbVar4 = local_34;
        }
        pbVar9 = (byte *)((int)ppppbVar4 + 1);
        do {
          bVar1 = *(byte *)ppppbVar4;
          ppppbVar4 = (byte ****)((int)ppppbVar4 + 1);
        } while (bVar1 != 0);
        local_88 = 4;
        if ((int)ppppbVar4 - (int)pbVar9 == 4) goto LAB_0085d4a2;
      }
      local_88 = 1;
    }
  }
LAB_0085d4a2:
  local_3c = 0xf;
  local_40 = 0;
  local_50 = local_50 & 0xffffff00;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_008714b0(param_1,"function");
  local_c4 = 0.0;
  local_c0 = 0.0;
  FUN_00871670(param_1,"width");
  FUN_00871670(param_1,"height");
  iVar3 = FUN_00871670(param_1,"levels");
  if (iVar3 == 0) {
    FUN_00871670(param_1,"miplevels");
  }
  FUN_00871670(param_1,"depth");
  iVar3 = FUN_008718f0(param_1,"dimensions");
  if (iVar3 != 0) {
    local_c4 = local_b8;
    local_c0 = local_b4;
  }
  local_b0 = (int)(longlong)ROUND(local_c4);
  iVar3 = local_b0;
  local_b0 = (int)(longlong)ROUND(local_c0);
  iVar5 = FUN_008718f0(param_1,"viewportratio");
  iVar8 = local_8c;
  if (iVar5 == 0) {
    if (local_88 == 1) {
      piVar2 = (int *)*in_ECX;
      local_88 = local_8c;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        *in_ECX = 0;
      }
      iVar8 = FUN_00864e70(3,local_8c);
      if (iVar8 == 0) {
        OutputDebugStringA(
                          "GBLENDER WARINING: Defaulting to D3DFMT_A8R8G8B8 , due to missing texture format support\n"
                          );
        local_88 = 0x15;
      }
      local_8c = 0;
      iVar8 = D3DXCreateTexture(0,iVar3,local_b0,0,1,local_88,0,&local_8c);
      if (iVar8 < 0) {
        bVar11 = false;
      }
      else {
        in_ECX[1] = iVar3;
        bVar11 = true;
        *in_ECX = local_8c;
        in_ECX[2] = local_b0;
        in_ECX[4] = 0;
        in_ECX[7] = 0;
        in_ECX[8] = 1;
        in_ECX[5] = 1;
        in_ECX[10] = 0;
        in_ECX[6] = local_88;
      }
      goto LAB_0085d9a4;
    }
    if (local_88 == 3) {
      piVar2 = (int *)*in_ECX;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        *in_ECX = 0;
      }
      bVar11 = true;
      goto LAB_0085d9a4;
    }
    if (local_88 == 4) {
      piVar2 = (int *)*in_ECX;
      local_94 = local_8c;
      local_88 = 0;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        *in_ECX = 0;
      }
      iVar8 = FUN_00864e70(5,local_8c);
      if (iVar8 == 0) {
        OutputDebugStringA(
                          "GBLENDER WARINING: Defaulting to D3DFMT_A8R8G8B8 , due to missing texture format support\n"
                          );
        local_94 = 0x15;
      }
      local_8c = 0;
      iVar8 = D3DXCreateCubeTexture(local_88,iVar3,0,1,in_ECX[6],0,&local_8c);
      if (iVar8 < 0) {
        bVar11 = false;
      }
      else {
        in_ECX[1] = iVar3;
        in_ECX[2] = iVar3;
        bVar11 = true;
        *in_ECX = local_8c;
        in_ECX[4] = 0;
        in_ECX[6] = local_94;
        in_ECX[7] = 0;
        in_ECX[8] = 4;
        in_ECX[5] = 1;
        in_ECX[10] = 0;
      }
      goto LAB_0085d9a4;
    }
  }
  else {
    piVar2 = (int *)*in_ECX;
    local_88 = local_8c;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *in_ECX = 0;
    }
    iVar3 = FUN_00864e70(3,iVar8);
    if (iVar3 == 0) {
      OutputDebugStringA(
                        "GBLENDER WARINING: Defaulting to D3DFMT_A8R8G8B8 , due to missing texture format support\n"
                        );
      local_88 = 0x15;
    }
    iVar3 = (**(code **)(_DAT_00000000 + 0xc0))(0,local_84);
    if (-1 < iVar3) {
      uVar6 = FUN_008fed10();
      uVar7 = FUN_008fed10();
      local_8c = 0;
      iVar3 = D3DXCreateTexture(0,uVar6,uVar7,1,1,local_88,0,&local_8c);
      if (-1 < iVar3) {
        in_ECX[0xb] = 0x3f800000;
        in_ECX[0xc] = 0x3f800000;
        bVar11 = true;
        *in_ECX = local_8c;
        in_ECX[4] = 1;
        in_ECX[8] = 1;
        in_ECX[5] = 1;
        in_ECX[10] = 1;
        in_ECX[1] = local_7c;
        in_ECX[2] = local_78;
        in_ECX[7] = 0;
        in_ECX[6] = local_88;
        goto LAB_0085d9a4;
      }
    }
  }
  bVar11 = false;
LAB_0085d9a4:
  if (bVar11) {
    if (0xf < local_3c) {
      FUN_0089120c(local_50);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50 = local_50 & 0xffffff00;
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (byte ***)((uint)local_34[0] & 0xffffff00);
    if (0xf < local_58) {
      FUN_0089120c(local_6c);
    }
  }
  else {
    if (((in_ECX != (int *)0x0) && (in_ECX[7] == 0)) &&
       (piVar2 = (int *)*in_ECX, piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *in_ECX = 0;
    }
    if (0xf < local_3c) {
      FUN_0089120c(local_50);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50 = local_50 & 0xffffff00;
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (byte ***)((uint)local_34[0] & 0xffffff00);
    if (0xf < local_58) {
      FUN_0089120c(local_6c);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

