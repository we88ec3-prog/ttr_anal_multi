
void FUN_00552b00(int param_1,int *param_2,int param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  uVar2 = *(uint *)(param_1 + 0x20);
  uVar7 = FUN_005525e0();
  uVar7 = uVar7 & uVar2;
  if (*(uint *)(param_1 + 0x24) <= uVar7) {
    uVar7 = uVar7 + (-1 - (uVar2 >> 1));
  }
  puVar9 = *(undefined4 **)(param_1 + 4);
  piVar1 = (int *)(*(int *)(param_1 + 0x10) + uVar7 * 8);
  puVar3 = (undefined4 *)*piVar1;
  if ((puVar9 != puVar3) && (puVar9 = *(undefined4 **)piVar1[1], puVar9 != puVar3)) {
    uVar2 = *(uint *)(param_3 + 0x10);
    do {
      puVar9 = (undefined4 *)puVar9[1];
      uVar4 = puVar9[6];
      uVar8 = uVar2;
      if (uVar4 <= uVar2) {
        uVar8 = uVar4;
      }
      uVar8 = FUN_00407e70(uVar8);
      if (uVar8 == 0) {
        if (uVar4 <= uVar2) {
          uVar8 = (uint)(uVar2 != uVar4);
          goto LAB_00552b9e;
        }
      }
      else {
LAB_00552b9e:
        if (-1 < (int)uVar8) {
          cVar6 = FUN_0049ae30();
          if (cVar6 == '\0') {
            FUN_00719b20(&param_3,param_4);
            *param_2 = (int)puVar9;
            *(undefined1 *)(param_2 + 1) = 0;
            return;
          }
          puVar9 = (undefined4 *)*puVar9;
          break;
        }
      }
    } while (puVar9 != puVar3);
  }
  if (puVar9 != (undefined4 *)*param_4) {
    FUN_00552d20(puVar9,param_4,(undefined4 *)*param_4);
  }
  puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x10) + uVar7 * 8);
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x10) + uVar7 * 8);
  if (puVar5 == *(undefined4 **)(param_1 + 4)) {
    *puVar3 = param_4;
    *(int **)(*(int *)(param_1 + 0x10) + 4 + uVar7 * 8) = param_4;
  }
  else if (puVar5 == puVar9) {
    *puVar3 = param_4;
  }
  else {
    piVar1 = *(int **)puVar3[1];
    puVar3[1] = piVar1;
    if (piVar1 != param_4) {
      piVar1 = (int *)(*(int *)(param_1 + 0x10) + 4 + uVar7 * 8);
      *piVar1 = *(int *)(*piVar1 + 4);
    }
  }
  FUN_00552c70(param_1);
  *param_2 = (int)param_4;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}

