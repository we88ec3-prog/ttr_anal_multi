
undefined4 FUN_007fc0f0(float param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char *_String;
  undefined4 *puVar4;
  undefined4 uVar5;
  double dVar6;
  undefined1 local_14 [16];
  
  iVar1 = (int)param_1;
  FUN_00800110(param_1,param_2);
  piVar2 = (int *)FUN_0072e2e0("Animation");
  if (piVar2 == (int *)0x0) goto LAB_007fc1f6;
  (**(code **)(*piVar2 + 0x14))();
  iVar3 = FUN_007300a0("AniSpeed");
  if (iVar3 == 0) {
LAB_007fc158:
    param_1 = 0.0;
  }
  else {
    _String = (char *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      _String = *(char **)_String;
    }
    if (_String == (char *)0x0) goto LAB_007fc158;
    dVar6 = _atof(_String);
    param_1 = (float)dVar6;
  }
  *(float *)(*(int *)(iVar1 + 0x68) + 0x158) = param_1;
  iVar3 = FUN_007300a0("XCount");
  if (iVar3 == 0) {
LAB_007fc190:
    uVar5 = 0;
  }
  else {
    puVar4 = (undefined4 *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 == (undefined4 *)0x0) goto LAB_007fc190;
    uVar5 = FUN_008917b4(puVar4);
  }
  *(undefined4 *)(*(int *)(iVar1 + 0x68) + 0x164) = uVar5;
  iVar3 = FUN_007300a0("YCount");
  if (iVar3 == 0) {
LAB_007fc1c2:
    uVar5 = 0;
  }
  else {
    puVar4 = (undefined4 *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 == (undefined4 *)0x0) goto LAB_007fc1c2;
    uVar5 = FUN_008917b4(puVar4);
  }
  *(undefined4 *)(*(int *)(iVar1 + 0x68) + 0x168) = uVar5;
  *(float *)(*(int *)(iVar1 + 0x68) + 0x15c) = 1.0 / (float)*(int *)(*(int *)(iVar1 + 0x68) + 0x164)
  ;
  *(float *)(*(int *)(iVar1 + 0x68) + 0x160) = 1.0 / (float)*(int *)(*(int *)(iVar1 + 0x68) + 0x168)
  ;
LAB_007fc1f6:
  iVar3 = FUN_0072e2e0("EmitSize");
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)FUN_00800000(local_14);
    iVar3 = *(int *)(iVar1 + 0x68);
    *(undefined4 *)(iVar3 + 0x16c) = *puVar4;
    *(undefined4 *)(iVar3 + 0x170) = puVar4[1];
    *(undefined4 *)(iVar3 + 0x174) = puVar4[2];
    *(undefined4 *)(iVar3 + 0x178) = puVar4[3];
  }
  iVar3 = FUN_0072e2e0("Scale");
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)FUN_00800000(local_14);
    iVar1 = *(int *)(iVar1 + 0x68);
    *(undefined4 *)(iVar1 + 0x17c) = *puVar4;
    *(undefined4 *)(iVar1 + 0x180) = puVar4[1];
    *(undefined4 *)(iVar1 + 0x184) = puVar4[2];
    *(undefined4 *)(iVar1 + 0x188) = puVar4[3];
  }
  return 1;
}

