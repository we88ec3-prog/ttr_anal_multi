
void FUN_00757c60(int param_1,undefined4 *param_2,int param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  puVar5 = param_2;
  if (7 < (uint)param_2[5]) {
    puVar5 = (undefined4 *)*param_2;
  }
  FUN_00448090(param_5,(int)puVar5 + param_3 * 2,param_4);
  puVar5 = *(undefined4 **)(param_1 + 0x2c);
  puVar2 = (undefined4 *)*puVar5;
  while (puVar2 != puVar5) {
    if (param_3 < (int)puVar2[4]) {
      puVar2[4] = puVar2[4] + param_4;
    }
    if (param_3 < (int)puVar2[5]) {
      puVar2[5] = puVar2[5] + param_4;
    }
    if (*(char *)((int)puVar2 + 0x21) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x21);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x21);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x21);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x21);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  puVar5 = (undefined4 *)param_2[7];
  for (puVar2 = (undefined4 *)*puVar5; puVar2 != puVar5; puVar2 = (undefined4 *)*puVar2) {
    if ((param_3 <= (int)puVar2[2]) && ((int)puVar2[2] < param_3 + param_4)) {
      FUN_00759060(puVar2[3],0);
    }
  }
  iVar6 = 0xffffff;
  for (puVar5 = *(undefined4 **)param_2[7];
      (puVar5 != (undefined4 *)param_2[7] && ((int)puVar5[2] <= param_3));
      puVar5 = (undefined4 *)*puVar5) {
    iVar6 = puVar5[3];
  }
  iVar7 = 0xffffff;
  for (puVar5 = (undefined4 *)**(undefined4 **)(param_1 + 0x1c);
      (puVar5 != *(undefined4 **)(param_1 + 0x1c) && ((int)puVar5[2] <= param_3));
      puVar5 = (undefined4 *)*puVar5) {
    iVar7 = puVar5[3];
  }
  if (iVar6 != iVar7) {
    FUN_00759060(iVar6,0);
  }
  if ((uint)(param_3 + param_4) < *(uint *)(param_1 + 0x10)) {
    FUN_00759060(iVar7,1);
  }
  FUN_007592c0(param_1);
  return;
}

