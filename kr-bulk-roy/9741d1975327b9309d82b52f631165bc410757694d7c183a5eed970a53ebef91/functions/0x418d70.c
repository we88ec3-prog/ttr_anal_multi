
void FUN_00418d70(int param_1)

{
  char cVar1;
  void *_Dst;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  undefined1 local_28 [4];
  undefined4 *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941f20;
  local_14 = ExceptionList;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  _Dst = *(void **)(param_1 + 0xc0);
  if (_Dst != *(void **)(param_1 + 0xc4)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0xc4),0);
    *(void **)(param_1 + 0xc4) = _Dst;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar9);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  FUN_00419660(local_28,DAT_00f94308 + 0x10);
  puVar7 = local_24;
  local_c = 1;
  puVar2 = (undefined4 *)*local_24;
  while (puVar2 != puVar7) {
    if ((((int *)puVar2[4])[1] == 0) && (*(int *)puVar2[4] != 0)) {
      FUN_004195a0();
    }
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar8 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar8, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar8 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  iVar4 = *(int *)(param_1 + 0xc4);
  iVar5 = *(int *)(param_1 + 0xc0);
  uVar9 = 0;
  piVar10 = (int *)(param_1 + 0x88);
  do {
    if (uVar9 < (uint)(iVar4 - iVar5 >> 1)) {
      FUN_005dc890(*(undefined2 *)(*(int *)(param_1 + 0xc0) + uVar9 * 2));
    }
    else {
      piVar6 = (int *)*piVar10;
      *(undefined2 *)(piVar6 + 0xa6) = 0;
      (**(code **)(*piVar6 + 0x19c))(0xffffffff,0xffffffff,0,0);
    }
    uVar9 = uVar9 + 1;
    piVar10 = piVar10 + 1;
  } while (uVar9 < 0xb);
  (**(code **)(**(int **)(param_1 + 0x84) + 200))();
  local_c = 3;
  FUN_005540c0(*local_24,local_24);
  FUN_0089120c(local_24);
  ExceptionList = local_14;
  return;
}

