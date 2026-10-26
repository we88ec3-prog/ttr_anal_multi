
void FUN_0085d0d0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *_Dst;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(int *)(param_1 + 0x68) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 100);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      piVar6 = (int *)puVar3[5];
      for (piVar7 = (int *)puVar3[4]; piVar7 != piVar6; piVar7 = piVar7 + 1) {
        if ((int *)*piVar7 != (int *)0x0) {
          (**(code **)(*(int *)*piVar7 + 8))(1);
        }
      }
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x21) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x21);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x21);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x21);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    FUN_004d3610(*(undefined4 *)(*(int *)(param_1 + 100) + 4));
    *(int *)(*(int *)(param_1 + 100) + 4) = *(int *)(param_1 + 100);
    *(undefined4 *)*(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 100);
    *(int *)(*(int *)(param_1 + 100) + 8) = *(int *)(param_1 + 100);
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  if (*(int *)(param_1 + 0x78) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x74);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      piVar6 = (int *)puVar3[5];
      for (piVar7 = (int *)puVar3[4]; piVar7 != piVar6; piVar7 = piVar7 + 1) {
        if ((int *)*piVar7 != (int *)0x0) {
          (**(code **)(*(int *)*piVar7 + 8))(1);
        }
      }
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x21) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x21);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x21);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x21);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    FUN_004d3610(*(undefined4 *)(*(int *)(param_1 + 0x74) + 4));
    *(int *)(*(int *)(param_1 + 0x74) + 4) = *(int *)(param_1 + 0x74);
    *(undefined4 *)*(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x74);
    *(int *)(*(int *)(param_1 + 0x74) + 8) = *(int *)(param_1 + 0x74);
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  piVar6 = *(int **)(param_1 + 0x50);
  if (piVar6 != *(int **)(param_1 + 0x54)) {
    piVar7 = *(int **)(param_1 + 0x54);
    for (; piVar6 != piVar7; piVar6 = piVar6 + 1) {
      if ((int *)*piVar6 != (int *)0x0) {
        (**(code **)(*(int *)*piVar6 + 8))(1);
      }
    }
    _Dst = *(void **)(param_1 + 0x50);
    if (_Dst != *(void **)(param_1 + 0x54)) {
      FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x54),0);
      *(void **)(param_1 + 0x54) = _Dst;
    }
  }
  return;
}

