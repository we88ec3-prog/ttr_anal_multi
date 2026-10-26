
void FUN_007d1080(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  int in_ECX;
  undefined4 *puVar8;
  undefined4 *local_c [2];
  
  uVar2 = *(uint *)(in_ECX + 0x20);
  uVar6 = FUN_005525e0();
  uVar6 = uVar6 & uVar2;
  if (*(uint *)(in_ECX + 0x24) <= uVar6) {
    uVar6 = uVar6 + (-1 - (uVar2 >> 1));
  }
  puVar8 = *(undefined4 **)(in_ECX + 4);
  piVar1 = (int *)(*(int *)(in_ECX + 0x10) + uVar6 * 8);
  local_c[0] = (undefined4 *)*piVar1;
  if ((puVar8 != local_c[0]) && (puVar8 = *(undefined4 **)piVar1[1], puVar8 != local_c[0])) {
    uVar2 = *(uint *)(param_2 + 0x10);
    do {
      puVar8 = (undefined4 *)puVar8[1];
      uVar3 = puVar8[6];
      uVar7 = uVar2;
      if (uVar3 <= uVar2) {
        uVar7 = uVar3;
      }
      uVar7 = FUN_00407e70(uVar7);
      if (uVar7 == 0) {
        if (uVar3 <= uVar2) {
          uVar7 = (uint)(uVar2 != uVar3);
          goto LAB_007d113c;
        }
      }
      else {
LAB_007d113c:
        if (-1 < (int)uVar7) {
          cVar5 = FUN_0049ae30();
          if (cVar5 == '\0') {
            FUN_00719b20(local_c,param_3);
            *param_1 = (int)puVar8;
            *(undefined1 *)(param_1 + 1) = 0;
            return;
          }
          puVar8 = (undefined4 *)*puVar8;
          break;
        }
      }
    } while (puVar8 != local_c[0]);
  }
  if (puVar8 != (undefined4 *)*param_3) {
    FUN_00552d20(puVar8,param_3,(undefined4 *)*param_3);
  }
  piVar1 = (int *)(*(int *)(in_ECX + 0x10) + uVar6 * 8);
  if ((undefined4 *)*piVar1 == *(undefined4 **)(in_ECX + 4)) {
    *piVar1 = (int)param_3;
    *(int **)(*(int *)(in_ECX + 0x10) + 4 + uVar6 * 8) = param_3;
  }
  else if ((undefined4 *)*piVar1 == puVar8) {
    *piVar1 = (int)param_3;
  }
  else {
    piVar4 = *(int **)piVar1[1];
    piVar1[1] = (int)piVar4;
    if (piVar4 != param_3) {
      piVar1 = (int *)(*(int *)(in_ECX + 0x10) + 4 + uVar6 * 8);
      *piVar1 = *(int *)(*piVar1 + 4);
    }
  }
  FUN_007d1210();
  *param_1 = (int)param_3;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}

