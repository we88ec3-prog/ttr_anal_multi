
void FUN_008433e0(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *local_8;
  
  piVar5 = param_2;
  iVar4 = (int)param_1;
  piVar2 = *(int **)((int)param_1 + 0x110);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(iVar4 + 0x110) = 0;
  }
  if ((*(int *)(iVar4 + 8) != 0) ||
     (*(int *)(iVar4 + 0x108) + *(int *)(iVar4 + 0xf8) + *(int *)(iVar4 + 0xe8) +
      *(int *)(iVar4 + 0xd8) + *(int *)(iVar4 + 200) + *(int *)(iVar4 + 0xb8) +
      *(int *)(iVar4 + 0xa8) + *(int *)(iVar4 + 0x98) + *(int *)(iVar4 + 0x88) +
      *(int *)(iVar4 + 0x78) + *(int *)(iVar4 + 0x68) + *(int *)(iVar4 + 0x58) +
      *(int *)(iVar4 + 0x48) + *(int *)(iVar4 + 0x38) + *(int *)(iVar4 + 0x28) +
      *(int *)(iVar4 + 0x18) != 0)) {
    (**(code **)(*piVar5 + 0xf0))(piVar5);
    puVar8 = *(undefined4 **)(iVar4 + 4);
    puVar7 = (undefined4 *)*puVar8;
    while (puVar7 != puVar8) {
      (**(code **)(*piVar5 + 0xe4))(piVar5,puVar7[3],puVar7[4]);
      if (*(char *)((int)puVar7 + 0x15) == '\0') {
        puVar3 = (undefined4 *)puVar7[2];
        if (*(char *)((int)puVar3 + 0x15) == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x15);
          puVar7 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar3 + 0x15);
            puVar7 = puVar3;
            puVar3 = (undefined4 *)*puVar3;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar7[1] + 0x15);
          puVar6 = (undefined4 *)puVar7[1];
          puVar3 = puVar7;
          while ((puVar7 = puVar6, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar7[2]))) {
            cVar1 = *(char *)((int)puVar7[1] + 0x15);
            puVar6 = (undefined4 *)puVar7[1];
            puVar3 = puVar7;
          }
        }
      }
    }
    local_8 = (int *)((int)param_1 + 0x94);
    param_2 = (int *)0x0;
    do {
      puVar8 = (undefined4 *)local_8[-0x20];
      puVar7 = (undefined4 *)*puVar8;
      while (puVar7 != puVar8) {
        (**(code **)(*piVar5 + 0x10c))(piVar5,param_2,puVar7[3],puVar7[4]);
        if (*(char *)((int)puVar7 + 0x15) == '\0') {
          puVar3 = (undefined4 *)puVar7[2];
          if (*(char *)((int)puVar3 + 0x15) == '\0') {
            cVar1 = *(char *)((int)*puVar3 + 0x15);
            puVar7 = puVar3;
            puVar3 = (undefined4 *)*puVar3;
            while (cVar1 == '\0') {
              cVar1 = *(char *)((int)*puVar3 + 0x15);
              puVar7 = puVar3;
              puVar3 = (undefined4 *)*puVar3;
            }
          }
          else {
            cVar1 = *(char *)((int)puVar7[1] + 0x15);
            puVar6 = (undefined4 *)puVar7[1];
            puVar3 = puVar7;
            while ((puVar7 = puVar6, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar7[2]))) {
              cVar1 = *(char *)((int)puVar7[1] + 0x15);
              puVar6 = (undefined4 *)puVar7[1];
              puVar3 = puVar7;
            }
          }
        }
      }
      puVar8 = (undefined4 *)*local_8;
      puVar7 = (undefined4 *)*puVar8;
      while (puVar7 != puVar8) {
        (**(code **)(*piVar5 + 0x114))(piVar5,param_2,puVar7[3],puVar7[4]);
        if (*(char *)((int)puVar7 + 0x15) == '\0') {
          puVar3 = (undefined4 *)puVar7[2];
          if (*(char *)((int)puVar3 + 0x15) == '\0') {
            cVar1 = *(char *)((int)*puVar3 + 0x15);
            puVar7 = puVar3;
            puVar3 = (undefined4 *)*puVar3;
            while (cVar1 == '\0') {
              cVar1 = *(char *)((int)*puVar3 + 0x15);
              puVar7 = puVar3;
              puVar3 = (undefined4 *)*puVar3;
            }
          }
          else {
            cVar1 = *(char *)((int)puVar7[1] + 0x15);
            puVar6 = (undefined4 *)puVar7[1];
            puVar3 = puVar7;
            while ((puVar7 = puVar6, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar7[2]))) {
              cVar1 = *(char *)((int)puVar7[1] + 0x15);
              puVar6 = (undefined4 *)puVar7[1];
              puVar3 = puVar7;
            }
          }
        }
      }
      local_8 = local_8 + 4;
      param_2 = (int *)((int)param_2 + 1);
    } while ((int)param_2 < 8);
    (**(code **)(*piVar5 + 0xf4))(piVar5,(int)param_1 + 0x110);
    iVar4 = (int)param_1;
    param_2 = *(int **)((int)param_1 + 4);
    cVar1 = *(char *)(param_2[1] + 0x15);
    param_1 = param_2;
    puVar8 = (undefined4 *)param_2[1];
    while (cVar1 == '\0') {
      if ((int)puVar8[3] < 0x1b) {
        puVar7 = (undefined4 *)puVar8[2];
        puVar8 = param_1;
      }
      else {
        puVar7 = (undefined4 *)*puVar8;
      }
      param_1 = puVar8;
      puVar8 = puVar7;
      cVar1 = *(char *)((int)puVar7 + 0x15);
    }
    if ((param_1 == param_2) || (0x1b < (int)param_1[3])) {
      puVar8 = &param_2;
    }
    else {
      puVar8 = &param_1;
    }
    if (((undefined4 *)*puVar8 != param_2) && (((undefined4 *)*puVar8)[4] != 0)) {
      *(undefined4 *)(iVar4 + 0x118) = 2;
    }
    *(undefined4 *)(iVar4 + 0x114) = 0;
  }
  return;
}

