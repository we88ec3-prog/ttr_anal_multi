
/* WARNING: Removing unreachable block (ram,0x0082d328) */

void FUN_0082d050(int *param_1,float param_2,float param_3,float param_4,float param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  float *in_ECX;
  undefined4 *puVar6;
  int iVar7;
  code *pcVar8;
  int iVar9;
  float local_cc;
  float local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  float local_b8;
  float *local_b4;
  int local_b0;
  int *local_ac;
  int local_a8;
  int local_a4;
  float local_a0;
  DWORD local_9c;
  CHAR local_98 [128];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar8 = GetTickCount_exref;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009094fb;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_ac = param_1;
  local_b4 = in_ECX;
  local_18 = uVar3;
  local_9c = GetTickCount();
  in_ECX[3] = param_5;
  in_ECX[2] = param_4;
  *in_ECX = (float)(int)param_4 / param_2;
  lVar2 = (ulonglong)(uint)((int)param_5 * (int)param_4) * 0x18;
  in_ECX[1] = (float)(int)param_5 / param_3;
  fVar4 = (float)FUN_0087dc3d(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2,uVar3);
  if (fVar4 == 0.0) {
    fVar4 = 0.0;
  }
  else {
    iVar9 = (int)param_5 * (int)param_4 - 1;
    if (-1 < iVar9) {
      puVar6 = (undefined4 *)((int)fVar4 + 8);
      do {
        puVar6[3] = 0;
        puVar6[-2] = 0;
        puVar6[-1] = 0;
        *puVar6 = 0xffffffff;
        puVar6[1] = 0xffffffff;
        puVar6[2] = 0;
        puVar6 = puVar6 + 6;
        iVar9 = iVar9 + -1;
      } while (-1 < iVar9);
    }
  }
  in_ECX[8] = fVar4;
  local_a0 = 0.0;
  if (param_5 != 0.0) {
    do {
      fVar4 = 0.0;
      if (param_4 != 0.0) {
        do {
          iVar7 = (int)local_a0 * (int)param_4;
          local_a8 = 0;
          local_cc = fVar4;
          local_c8 = local_a0;
          iVar5 = (**(code **)(*local_ac + 4))(&local_cc);
          iVar9 = 1;
          if (iVar5 == 0) {
            iVar9 = local_a8;
          }
          *(int *)((int)in_ECX[8] + (iVar7 + (int)fVar4) * 0x18 + 0x10) = iVar9;
          fVar4 = (float)((int)fVar4 + 1);
          pcVar8 = GetTickCount_exref;
        } while ((uint)fVar4 < (uint)param_4);
      }
      local_a0 = (float)((int)local_a0 + 1);
    } while ((uint)local_a0 < (uint)param_5);
  }
  iVar9 = (*pcVar8)();
  local_c8 = (float)(iVar9 - local_9c);
  local_9c = (*pcVar8)();
  local_b0 = 0;
  local_ac = (int *)0x0;
  local_b8 = 1.4013e-45;
  do {
    fVar4 = in_ECX[2];
    if ((uint)fVar4 < (uint)local_b8) break;
    uVar1 = (ulonglong)(uint)fVar4 / (ulonglong)(uint)local_b8;
    iVar9 = (int)uVar1;
    iVar5 = (int)((uint)in_ECX[3] / uVar1) + -1;
    local_c4 = iVar9;
    if (iVar5 != 0) {
      iVar7 = (int)((uint)fVar4 / uVar1) + -1;
      local_a4 = 0;
      local_bc = iVar7;
      local_a8 = iVar5;
      do {
        if (iVar7 != 0) {
          local_a0 = (float)(local_a4 + iVar9);
          iVar5 = 0;
          local_c0 = iVar7;
          do {
            iVar7 = iVar5 + iVar9;
            iVar9 = FUN_0082d500(local_b4,local_a0);
            if (iVar9 != 0) {
              FUN_0082d560(iVar5,iVar7,local_a0);
              local_8 = 0;
              FUN_0082ee10(local_b4 + 4);
              local_8 = 0xffffffff;
              local_b0 = local_b0 + 1;
            }
            local_c0 = local_c0 + -1;
            iVar9 = local_c4;
            iVar5 = iVar7;
          } while (local_c0 != 0);
          local_c0 = 0;
          iVar7 = local_bc;
          pcVar8 = GetTickCount_exref;
          in_ECX = local_b4;
        }
        local_a4 = local_a4 + iVar9;
        local_a8 = local_a8 + -1;
      } while (local_a8 != 0);
    }
    local_ac = (int *)((int)local_ac + 1);
    local_b8 = (float)((int)local_b8 << 1 | (uint)((int)local_b8 < 0));
  } while (local_ac < 8);
  local_bc = (*pcVar8)();
  local_bc = local_bc - local_9c;
  local_9c = (*pcVar8)();
  FUN_0082d5b0();
  iVar9 = (*pcVar8)();
  iVar9 = iVar9 - local_9c;
  local_9c = (*pcVar8)();
  FUN_0082dfc0(in_ECX);
  iVar5 = (*pcVar8)();
  local_ac = (int *)(iVar5 - local_9c);
  local_9c = (*pcVar8)();
  FUN_0082eaa0(in_ECX,0x40800000,0x3ecccccd);
  local_a8 = (*pcVar8)();
  local_a8 = local_a8 - local_9c;
  (*pcVar8)();
  FUN_006f0490("groupIndex : %d\n",local_b0);
  OutputDebugStringA(local_98);
  FUN_006f0490("movableCheckTime : %d\n",local_c8);
  OutputDebugStringA(local_98);
  FUN_006f0490("conquerTime : %d\n",local_bc);
  OutputDebugStringA(local_98);
  FUN_006f0490("neighborArrangeTime : %d\n",iVar9);
  OutputDebugStringA(local_98);
  FUN_006f0490("arrangeNearestTime : %d\n",local_ac);
  OutputDebugStringA(local_98);
  FUN_006f0490("polluteTime : %d\n",local_a8);
  OutputDebugStringA(local_98);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

