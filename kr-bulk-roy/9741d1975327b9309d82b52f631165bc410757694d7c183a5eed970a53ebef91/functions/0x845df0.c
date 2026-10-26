
undefined4 * FUN_00845df0(undefined4 *param_1,void *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  void *_Dst;
  void *_Dst_00;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009182c7;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007846f0(param_1);
  *param_1 = gbGeometry::vftable;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  piVar1 = param_1 + 0x1f;
  *piVar1 = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  local_8 = 4;
  param_1[0x2c] = 0;
  puVar2 = (undefined4 *)param_1[0x1d];
  if (puVar2 != *(undefined4 **)((int)param_2 + 0x74)) {
    if (puVar2 != (undefined4 *)0x0) {
      piVar3 = puVar2 + 1;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        (**(code **)*puVar2)(1,uVar5);
      }
    }
    piVar3 = *(int **)((int)param_2 + 0x74);
    param_1[0x1d] = piVar3;
    if (piVar3 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar3 + 8))();
      if (iVar6 == 0) {
        uVar7 = (**(code **)(*(int *)param_1[0x1d] + 0xc))();
        param_1[0x1d] = uVar7;
      }
      *(int *)(param_1[0x1d] + 4) = *(int *)(param_1[0x1d] + 4) + 1;
    }
  }
  puVar2 = (undefined4 *)param_1[0x1e];
  if (puVar2 != *(undefined4 **)((int)param_2 + 0x78)) {
    if (puVar2 != (undefined4 *)0x0) {
      piVar3 = puVar2 + 1;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        (**(code **)*puVar2)(1);
      }
    }
    piVar3 = *(int **)((int)param_2 + 0x78);
    param_1[0x1e] = piVar3;
    if (piVar3 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar3 + 8))();
      if (iVar6 == 0) {
        uVar7 = (**(code **)(*(int *)param_1[0x1e] + 0xc))();
        param_1[0x1e] = uVar7;
      }
      *(int *)(param_1[0x1e] + 4) = *(int *)(param_1[0x1e] + 4) + 1;
    }
  }
  param_1[0x24] = *(undefined4 *)((int)param_2 + 0x90);
  param_1[0x23] = *(undefined4 *)((int)param_2 + 0x8c);
  param_1[0x2d] = *(undefined4 *)((int)param_2 + 0xb4);
  param_1[0x2e] = *(undefined4 *)((int)param_2 + 0xb8);
  param_1[0x2f] = *(undefined4 *)((int)param_2 + 0xbc);
  if (*piVar1 != param_1[0x20]) {
    uVar7 = FUN_00848b00(param_1[0x20],*piVar1,param_2);
    FUN_00848b60(param_2);
    param_1[0x20] = uVar7;
  }
  uVar7 = *(undefined4 *)((int)param_2 + 0x80);
  uVar4 = *(undefined4 *)((int)param_2 + 0x7c);
  if (*piVar1 != param_1[0x20]) {
    uVar8 = FUN_00848b00(param_1[0x20],*piVar1,param_2);
    FUN_00848b60(param_2);
    param_1[0x20] = uVar8;
  }
  FUN_00848f50(piVar1,*piVar1,uVar4,uVar7,param_2);
  _Dst = (void *)param_1[0x27];
  if (_Dst != (void *)param_1[0x28]) {
    FID_conflict__memcpy(_Dst,(void *)param_1[0x28],0);
    param_1[0x28] = _Dst;
  }
  uVar7 = *(undefined4 *)((int)param_2 + 0xa0);
  uVar4 = *(undefined4 *)((int)param_2 + 0x9c);
  _Dst_00 = (void *)param_1[0x27];
  param_2 = _Dst;
  if (_Dst_00 != (void *)param_1[0x28]) {
    param_2 = (void *)0x0;
    FID_conflict__memcpy(_Dst_00,(void *)param_1[0x28],0);
    param_1[0x28] = _Dst_00;
  }
  FUN_00849120(param_1[0x27],uVar4,uVar7,param_2);
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x2b] = 0;
  ExceptionList = local_10;
  return param_1;
}

