
void FUN_00757e40(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_EAX;
  int *piVar7;
  int iVar8;
  
  puVar2 = *(undefined4 **)(in_EAX + 0x2c);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (param_2 < (int)puVar3[4]) {
      puVar3[4] = puVar3[4] - param_1;
    }
    if (param_2 < (int)puVar3[5]) {
      puVar3[5] = puVar3[5] - param_1;
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
        puVar6 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  if (*(int *)(in_EAX + 0x20) != 0) {
    piVar5 = *(int **)(in_EAX + 0x1c);
    piVar7 = (int *)*piVar5;
    iVar8 = 0xffffff;
    if (piVar7 != piVar5) {
      do {
        if (param_1 + param_2 < piVar7[2]) break;
        iVar8 = piVar7[3];
        piVar7 = (int *)*piVar7;
      } while (piVar7 != piVar5);
    }
    FUN_00759130(param_2,param_1,1);
    if ((uint)(param_1 + param_2) < *(uint *)(in_EAX + 0x10)) {
      FUN_00759060(iVar8,0);
    }
    FUN_007592c0(in_EAX);
  }
  FUN_00402400(param_2,param_1);
  return;
}

