
void FUN_007e57c0(int param_1)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int *piVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int unaff_EDI;
  int *piVar10;
  int *piStack_254;
  int *piStack_250;
  void *pvStack_24c;
  undefined4 local_248;
  int iStack_244;
  int iStack_240;
  int iStack_23c;
  int iStack_238;
  int iStack_234;
  int iStack_230;
  undefined2 *puStack_22c;
  uint uStack_30;
  void *pvStack_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00934b7a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&piStack_254;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffda0;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 2;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
    }
  }
  local_c = 0xffffffff;
  local_248 = FUN_0079a5f0();
  pvVar3 = (void *)FUN_0087dc3d();
  *(void **)(param_1 + 0x178) = pvVar3;
  _memset(pvVar3,0,*(int *)(param_1 + 0x17c) * 6);
  iVar8 = *(int *)(param_1 + 0x174);
  pvVar3 = (void *)FUN_0087dc3d();
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    iVar8 = iVar8 + -1;
    if (-1 < iVar8) {
      puVar7 = (undefined4 *)((int)pvVar3 + 8);
      do {
        puVar7[-2] = 0;
        iVar8 = iVar8 + -1;
        puVar7[-1] = 0;
        *puVar7 = 0;
        puVar7 = puVar7 + 3;
      } while (-1 < iVar8);
    }
  }
  piVar10 = (int *)(param_1 + 0x170);
  *piVar10 = (int)pvVar3;
  _memset(pvVar3,0,*(int *)(param_1 + 0x174) * 0xc);
  pvStack_24c = (void *)FUN_0087dc3d();
  _memset(pvStack_24c,0,*(int *)(param_1 + 0x174) * 0x1c);
  iVar8 = *(int *)(param_1 + 0x17c);
  piStack_250 = (int *)FUN_0087dc3d();
  if (piStack_250 == (int *)0x0) {
    piStack_250 = (int *)0x0;
  }
  else {
    iVar8 = iVar8 + -1;
    if (-1 < iVar8) {
      piVar4 = piStack_250 + 2;
      do {
        piVar4[-2] = 0;
        iVar8 = iVar8 + -1;
        piVar4[-1] = 0;
        *piVar4 = 0;
        piVar4 = piVar4 + 3;
      } while (-1 < iVar8);
    }
  }
  piStack_254 = piStack_250;
  _memset(piStack_250,0,*(int *)(param_1 + 0x17c) * 0xc);
  FUN_007e61e0(param_1 + 0x178,*(undefined4 *)(param_1 + 0x16c),&piStack_254,piVar10,
               *(undefined4 *)(param_1 + 0x150));
  iVar8 = *(int *)(param_1 + 0x174);
  piStack_254 = (int *)FUN_0087dc3d();
  if (piStack_254 == (int *)0x0) {
    piStack_254 = (int *)0x0;
  }
  else {
    iVar8 = iVar8 + -1;
    if (-1 < iVar8) {
      piVar4 = piStack_254 + 5;
      do {
        piVar4[-5] = 0;
        iVar8 = iVar8 + -1;
        piVar4[-4] = 0;
        piVar4[-3] = 0;
        piVar4[-2] = 0;
        piVar4[-1] = 0;
        *piVar4 = 0x3f800000;
        piVar4 = piVar4 + 6;
      } while (-1 < iVar8);
    }
  }
  uVar9 = 0;
  if (*(int *)(param_1 + 0x174) != 0) {
    iVar8 = 0;
    piVar4 = piStack_254;
    do {
      iVar1 = *(int *)(param_1 + 0x16c);
      iStack_244 = *(int *)(iVar1 + iVar8);
      uVar9 = uVar9 + 1;
      iVar8 = iVar8 + 0xc;
      iStack_240 = *(int *)(iVar1 + -8 + iVar8);
      iStack_23c = *(int *)(iVar1 + -4 + iVar8);
      *piVar4 = iStack_244;
      piVar4[1] = iStack_240;
      piVar4[2] = iStack_23c;
      iVar1 = *piVar10;
      iStack_238 = *(int *)(iVar1 + -0xc + iVar8);
      iStack_234 = *(int *)(iVar1 + -8 + iVar8);
      iStack_230 = *(int *)(iVar1 + -4 + iVar8);
      piVar4[3] = iStack_238;
      piVar4[4] = iStack_234;
      piVar4[5] = iStack_230;
      piVar4 = piVar4 + 6;
    } while (uVar9 < *(uint *)(param_1 + 0x174));
  }
  puStack_22c = (undefined2 *)FUN_0087dc3d();
  iVar8 = *(int *)(param_1 + 0x178);
  uVar9 = 0;
  if (*(int *)(param_1 + 0x17c) * 3 != 0) {
    puVar5 = puStack_22c;
    do {
      *puVar5 = *(undefined2 *)((iVar8 - (int)puStack_22c) + (int)puVar5);
      uVar9 = uVar9 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar9 < (uint)(*(int *)(param_1 + 0x17c) * 3));
  }
  puVar7 = (undefined4 *)(param_1 + 8);
  FUN_007cc480(puVar7,piStack_254,puStack_22c);
  piVar10 = (int *)*puVar7;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  uVar6 = (**(code **)(*piVar10 + 0x10))();
  *(undefined4 *)(param_1 + 0x18) = uVar6;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  uVar6 = (**(code **)(*(int *)*puVar7 + 0x14))((int *)*puVar7);
  *(undefined4 *)(param_1 + 0x20) = uVar6;
  _memset(&iStack_230,0,0x208);
  D3DXDeclaratorFromFVF(0x12,&iStack_230);
  (**(code **)(*piStack_250 + 0x158))(piStack_250,&iStack_230,param_1 + 0xc);
  if (piVar10 != (int *)0x0) {
    FUN_00891d3d(piVar10);
  }
  if (iStack_240 != 0) {
    FUN_00891d3d(iStack_240);
  }
  if (uVar2 != 0) {
    FUN_00891d3d(uVar2);
  }
  if (unaff_EDI != 0) {
    FUN_00891d3d(unaff_EDI);
  }
  ExceptionList = pvStack_28;
  __security_check_cookie(uStack_30 ^ (uint)&stack0xfffffd98);
  return;
}

