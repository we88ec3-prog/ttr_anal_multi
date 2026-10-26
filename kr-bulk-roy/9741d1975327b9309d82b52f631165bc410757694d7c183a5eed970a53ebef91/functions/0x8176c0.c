
void FUN_008176c0(short param_1,int *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_EAX;
  
  puVar2 = *(undefined4 **)(in_EAX + 4);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if ((*(short *)(puVar3[4] + 0x10) == param_1) && (*(int *)(puVar3[4] + 8) == 2)) {
      puVar4 = (undefined4 *)param_2[1];
      puVar6 = puVar3 + 3;
      if ((puVar6 < puVar4) && (puVar5 = (undefined4 *)*param_2, puVar5 <= puVar6)) {
        if (puVar4 == (undefined4 *)param_2[2]) {
          FUN_006d6240();
        }
        if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
          *(undefined4 *)param_2[1] =
               *(undefined4 *)(*param_2 + ((int)puVar6 - (int)puVar5 >> 2) * 4);
        }
      }
      else {
        if (puVar4 == (undefined4 *)param_2[2]) {
          FUN_006d6240();
        }
        if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
          *(undefined4 *)param_2[1] = *puVar6;
        }
      }
      param_2[1] = param_2[1] + 4;
    }
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar6 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar6 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar6 + 0x15);
        puVar3 = puVar6;
        puVar6 = (undefined4 *)*puVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x15);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar4 = (undefined4 *)puVar3[1];
        puVar6 = puVar3;
        while ((puVar3 = puVar4, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar4 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
        }
      }
    }
  }
  return;
}

