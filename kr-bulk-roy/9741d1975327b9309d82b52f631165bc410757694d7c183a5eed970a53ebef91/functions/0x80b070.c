
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080b070(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c29e;
  local_10 = ExceptionList;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar7 = DAT_00fe33c4 & 1;
  param_1[0x1c] = 0;
  if (uVar7 == 0) {
    DAT_00fe33c4 = DAT_00fe33c4 | 1;
    local_8 = 0;
    FUN_0080e030(uVar9);
    _DAT_00fe33f8 = 0;
    _atexit((_func_4879 *)&LAB_00bd0bd0);
  }
  local_8 = 0xffffffff;
  _DAT_00fe33f8 = 1;
  if (param_1[0x1b] != 0) {
    FUN_004fb7d0();
    param_1[0x1b] = 0;
  }
  if ((_DAT_00fe33fc & 1) == 0) {
    _DAT_00fe33fc = _DAT_00fe33fc | 1;
    DAT_00fe3400 = 0;
    _DAT_00fe3404 = 0;
    _DAT_00fe3408 = 0;
    _DAT_00fe3410 = 4;
    _atexit((_func_4879 *)&LAB_00bd0c00);
  }
  FUN_0080c400();
  puVar2 = (undefined4 *)param_1[0x17];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    puVar4 = (undefined4 *)puVar3[2];
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = MoonSound::SoundChannel::vftable;
      if ((int *)puVar4[2] != (int *)0x0) {
        (**(code **)(*(int *)puVar4[2] + 8))();
        puVar4[2] = 0;
      }
      iVar5 = puVar4[1];
      if (iVar5 != 0) {
        if (*(int *)(iVar5 + 0x38) == 0) {
          FUN_006edb10("Sound::_refCount < 0\n");
        }
        else {
          *(int *)(iVar5 + 0x38) = *(int *)(iVar5 + 0x38) + -1;
        }
        puVar4[1] = 0;
      }
      FUN_0089120c(puVar4);
      puVar3[2] = 0;
    }
  }
  piVar6 = (int *)param_1[0x17];
  piVar10 = (int *)*piVar6;
  *piVar6 = (int)piVar6;
  *(int *)(param_1[0x17] + 4) = param_1[0x17];
  param_1[0x18] = 0;
  if (piVar10 != (int *)param_1[0x17]) {
    do {
      piVar6 = (int *)*piVar10;
      FUN_0089120c(piVar10);
      piVar10 = piVar6;
    } while (piVar6 != (int *)param_1[0x17]);
  }
  puVar2 = (undefined4 *)param_1[0xf];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if ((int *)puVar3[10] != (int *)0x0) {
      (**(code **)(*(int *)puVar3[10] + 0xc))(1);
      puVar3[10] = 0;
    }
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar8 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar8, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar8 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  FUN_007b7d40(*(undefined4 *)(param_1[0xf] + 4));
  *(int *)(param_1[0xf] + 4) = param_1[0xf];
  *(int *)param_1[0xf] = param_1[0xf];
  *(int *)(param_1[0xf] + 8) = param_1[0xf];
  param_1[0x10] = 0;
  puVar2 = (undefined4 *)param_1[0xb];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    iVar5 = puVar3[10];
    if (iVar5 != 0) {
      if (0xf < *(uint *)(iVar5 + 0x70)) {
        FUN_0089120c(*(undefined4 *)(iVar5 + 0x5c));
      }
      *(undefined4 *)(iVar5 + 0x70) = 0xf;
      *(undefined4 *)(iVar5 + 0x6c) = 0;
      *(undefined1 *)(iVar5 + 0x5c) = 0;
      FUN_0089120c(iVar5);
      puVar3[10] = 0;
    }
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar8 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar8, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar8 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  FUN_007b7d40(*(undefined4 *)(param_1[0xb] + 4));
  *(int *)(param_1[0xb] + 4) = param_1[0xb];
  *(int *)param_1[0xb] = param_1[0xb];
  *(int *)(param_1[0xb] + 8) = param_1[0xb];
  param_1[0xc] = 0;
  if (param_1[0x1a] != 0) {
    FUN_0089120c(param_1[0x1a]);
    param_1[0x1a] = 0;
  }
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 0x10))();
    if ((int *)*param_1 != (int *)0x0) {
      (**(code **)(*(int *)*param_1 + 8))();
      *param_1 = 0;
    }
  }
  FID_conflict__wprintf("SOUND_USE_COUNT: %d\n",DAT_00fba864);
  ExceptionList = local_10;
  return;
}

